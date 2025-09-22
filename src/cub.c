/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 11:26:35 by ioleinik          #+#    #+#             */
/*   Updated: 2021/11/23 12:59:02 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/**
 * @brief Handles keyboard input events
 * 
 * Processes all keyboard input including movement (WASD), rotation (arrows),
 * and exit commands (ESC). Updates player position and orientation, then
 * triggers a re-render of the scene.
 * 
 * @param button Key code of the pressed button
 * @param param Pointer to main data structure (t_cub)
 * @return Always returns 0
 */
static int	key_event(int button, void *param)
{
	t_cub	*d;

	d = param;
	if (button == KEY_ESC || button == KEY_ESC_MAC)
	{
		clean_up(d);
		exit(0);
	}
	keys_aw(button, d, 0, 0);
	keys_ds(button, d, 0, 0);
	if (button == KEY_LEFT || button == KEY_LEFT_MAC)
		d->g_player.o = angle_change(0, d->g_player.o);
	if (button == KEY_RIGHT || button == KEY_RIGHT_MAC)
		d->g_player.o = angle_change(1, d->g_player.o);
	render(d);
	return (0);
}

/**
 * @brief Puts a pixel at specified coordinates with given color
 * 
 * Directly manipulates the image buffer to set a pixel color at the
 * specified coordinates. Used for all rendering operations.
 * 
 * @param d Main data structure containing image buffer
 * @param x X coordinate
 * @param y Y coordinate
 * @param color Color value in hex format
 */
void	put_pix(t_cub *d, int x, int y, int color)
{
	char	*dst;

	dst = d->addr + (y * d->line_length + x * (d->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

/**
 * @brief Validates command line argument format
 * 
 * Checks if the provided filename has the correct .cub extension
 * and meets minimum length requirements.
 * 
 * @param str Filename string to validate
 * @return 1 if invalid, 0 if valid
 */
static int	ft_checkarg(char *str)
{
	int	i;

	i = ft_strlen(str);
	if (i < MIN_FILENAME_LEN)
		return (1);
	if (str[i - 1] != 'b' || str[i - 2] != 'u'
		|| str[i - 3] != 'c' || str[i - 4] != '.')
		return (1);
	return (0);
}

/**
 * @brief Initializes the main data structure
 * 
 * Sets all fields in the main data structure to their default values,
 * ensuring clean initial state before parsing and rendering.
 * 
 * @param d Main data structure to initialize
 */
static void	init_data(t_cub *d)
{
	d->map = NULL;
	d->map_h = 0;
	d->map_w = 0;
	d->quant_par = 0;
	d->flag = 0;
	d->map_strings = ft_strarrnew();
	d->img = NULL;
	d->win = NULL;
	d->g_player.startx = 0;
	d->g_player.starty = 0;
	d->f_color[0] = 0;
	d->f_color[1] = 0;
	d->f_color[2] = 0;
	d->c_color[0] = 0;
	d->c_color[1] = 0;
	d->c_color[2] = 0;
}

/**
 * @brief Main program entry point
 * 
 * Orchestrates the entire program flow:
 * 1. Validates command line arguments
 * 2. Initializes data structures and graphics
 * 3. Parses configuration file and map
 * 4. Sets up player spawn point and orientation
 * 5. Performs initial ray-casting and rendering
 * 6. Sets up event hooks for user interaction
 * 7. Enters the main event loop
 * 
 * @param argc Argument count
 * @param argv Argument vector
 * @return 0 on successful completion
 */
int	main(int argc, char **argv)
{
	t_cub	d;

	if (argc != 2 || ft_checkarg(argv[1]))
		ft_terror(ERR_USAGE);
	init_data(&d);
	init_graphics(&d);
	read_config(argv[1], &d);
	fill_map_color(&d);
	coord_to_pixel(&d);
	d.g_player.o = spawn_angle(d.g_player.start_dir);
	cast_rays(0, 0, 0, &d);
	mlx_put_image_to_window(d.mlx, d.win, d.img, 0, 0);
	mlx_do_key_autorepeatoff(d.mlx);
	mlx_hook(d.win, 2, 1L << 0, &key_event, &d);
	mlx_hook(d.win, 17, 0, &exit_hook, &d);
	mlx_loop(d.mlx);
	clean_up(&d);
	return (0);
}
