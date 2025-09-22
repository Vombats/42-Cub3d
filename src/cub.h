/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanakgulati <khanakgulati@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 12:05:16 by ioleinik          #+#    #+#             */
/*   Updated: 2021/11/23 17:21:38 by khanakgulat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "config.h"
# include "libft/libft.h"
# include "mlx-linux/mlx.h"
# include <math.h>
# include <stdio.h>
# include <fcntl.h>

# define MAX_X WINDOW_WIDTH
# define MAX_Y WINDOW_HEIGHT

/*
** =============================================================================
** DATA STRUCTURES
** =============================================================================
*/

/**
 * @brief Player position and orientation data
 * 
 * Contains all information about the player's current state including
 * position, orientation, and spawn point data.
 */
typedef struct s_player
{
	int		posx;			/* Current X position in pixels */
	int		posy;			/* Current Y position in pixels */
	float	o;				/* Player orientation angle (radians) */
	int		startx;			/* Initial spawn X coordinate (grid) */
	int		starty;			/* Initial spawn Y coordinate (grid) */
	char	start_dir;		/* Initial spawn direction (N/S/E/W) */
}		t_player;

/**
 * @brief Texture data structure
 * 
 * Stores texture image data and properties for wall rendering.
 */
typedef struct s_tex
{
	void	*img;			/* MLX image pointer */
	int		img_w;			/* Image width */
	int		img_h;			/* Image height */
	char	*path;			/* Path to texture file */
	char	*addr;			/* Image data address */
	int		bits_per_pixel;	/* Bits per pixel */
	int		line_length;	/* Line length in bytes */
	int		endian;			/* Endianness */
}			t_tex;

/**
 * @brief Main game data structure
 * 
 * Central structure containing all game state, configuration,
 * graphics context, and parsed map data.
 */
typedef struct s_cub
{
	/* Color configuration */
	int			f_color[3];		/* Floor RGB color values */
	int			c_color[3];		/* Ceiling RGB color values */
	int			hex_floor;		/* Floor color as hex */
	int			hex_ceil;		/* Ceiling color as hex */
	
	/* Map data */
	char		**map_strings;	/* Raw map lines from file */
	int			**map;			/* Parsed map as 2D int array */
	int			map_h;			/* Map height */
	int			map_w;			/* Map width */
	
	/* Parsing state */
	int			quant_par;		/* Number of parsed parameters */
	int			flag;			/* General purpose flag */
	
	/* Graphics context */
	void		*mlx;			/* MLX connection */
	void		*win;			/* Window pointer */
	void		*img;			/* Main image buffer */
	char		*addr;			/* Image data address */
	int			bits_per_pixel;	/* Bits per pixel */
	int			line_length;	/* Line length in bytes */
	int			endian;			/* Endianness */
	
	/* Wall textures */
	t_tex		no;				/* North wall texture */
	t_tex		so;				/* South wall texture */
	t_tex		we;				/* West wall texture */
	t_tex		ea;				/* East wall texture */
	
	/* Player data */
	t_player	g_player;		/* Player state */
}			t_cub;

/*
** =============================================================================
** FUNCTION PROTOTYPES
** =============================================================================
*/

/* Configuration and map parsing */
void		read_config(char *path, t_cub *d);
void		parse_path(char **str, t_cub *d);
void		parse_map(int fd, t_cub *d);
void		parse_floor(char **arr, t_cub *d);
void		parse_ceil(char **arr, t_cub *d);
void		parse_doubles(char **a, t_cub *d);

/* Memory management and cleanup */
void		clean_up(t_cub *d);
void		exit_color(char **arr, char **col, t_cub *d);

/* Error handling */
void		inv_map(t_cub *d);
void		inv_color(t_cub *d);

/* Graphics and rendering */
void		init_graphics(t_cub *d);
void		put_pix(t_cub *d, int x, int y, int color);
void		render(t_cub *d);
void		fill_map_color(t_cub *d);

/* Mathematical utilities */
int			max(int a, int b);
int			min(int a, int b);
float		check_limits(float o);
float		angle_change(int dir, float ang);
float		spawn_angle(char dir);

/* Player movement and controls */
void		keys_aw(int key, t_cub *d, int x, int y);
void		keys_ds(int key, t_cub *d, int x, int y);
void		coord_to_pixel(t_cub *d);

/* Ray-casting engine - Quadrant 1 (NE) */
int			xdist_quad1(float o, int x, int y, t_cub *d);
int			ydist_quad1(float o, int x, int y, t_cub *d);

/* Ray-casting engine - Quadrant 2 (NW) */
int			xdist_quad2(float o, int x, int y, t_cub *d);
int			ydist_quad2(float o, int x, int y, t_cub *d);

/* Ray-casting engine - Quadrant 3 (SW) */
int			xdist_quad3(float o, int x, int y, t_cub *d);
int			ydist_quad3(float o, int x, int y, t_cub *d);

/* Ray-casting engine - Quadrant 4 (SE) */
int			xdist_quad4(float o, int x, int y, t_cub *d);
int			ydist_quad4(float o, int x, int y, t_cub *d);

/* Ray-casting core functions */
int			which_wall(int dists_fov[250][2], int i, int j, t_cub *d);
void		paint_screen(int dists_fov[250][2], int i, t_cub *d);
int			set_dists_wall(int *x_d, int *y_d, float o, t_cub *d);
int			set_dists_wall2(int *x_d, int *y_d, float o, t_cub *d);
int			cast_rays(int x_dist, int y_dist, int mindist, t_cub *d);

/* Event handling */
int			exit_hook(t_cub *d);

/* Debug utilities */
void		print_arr(char **arr);

#endif
