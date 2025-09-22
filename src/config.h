/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 00:00:00 by ioleinik          #+#    #+#             */
/*   Updated: 2025/09/22 00:00:00 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

/*
** =============================================================================
** WINDOW AND DISPLAY CONSTANTS
** =============================================================================
*/

/* Window dimensions */
# define WINDOW_WIDTH		500
# define WINDOW_HEIGHT		500

/* Field of view settings */
# define FOV_RAYS			250		/* Number of rays to cast for FOV */

/*
** =============================================================================
** MAP AND GRID CONSTANTS  
** =============================================================================
*/

/* Map constraints */
# define MAX_MAP_WIDTH		500		/* Maximum map width */
# define MAX_MAP_HEIGHT		500		/* Maximum map height */

/* Grid system */
# define TILE_SIZE			100		/* Size of each map tile in pixels */
# define HALF_TILE			50		/* Half tile size for centering */

/* Map validation characters */
# define EMPTY_SPACE		'0'		/* Empty walkable space */
# define WALL				'1'		/* Wall tile */
# define PLAYER_NORTH		'N'		/* Player starting position facing North */
# define PLAYER_SOUTH		'S'		/* Player starting position facing South */
# define PLAYER_EAST		'E'		/* Player starting position facing East */
# define PLAYER_WEST		'W'		/* Player starting position facing West */

/*
** =============================================================================
** RAYCASTING CONSTANTS
** =============================================================================
*/

/* Distance calculations */
# define MAX_RAY_DISTANCE	20000	/* Maximum ray casting distance */
# define ANGLE_PRECISION	0.02	/* Angle precision for calculations */
# define ROTATION_SPEED		0.1		/* Camera rotation speed */

/* Ray casting grid offsets */
# define GRID_OFFSET		1		/* Offset for grid boundary checking */

/*
** =============================================================================
** COLOR CONSTANTS
** =============================================================================
*/

/* Wall colors (for debugging/fallback) */
# define COLOR_WALL_WEST	0xff0000	/* Red for west walls */
# define COLOR_WALL_NORTH	0x00ff00	/* Green for north walls */
# define COLOR_WALL_EAST	0x0000ff	/* Blue for east walls */
# define COLOR_WALL_SOUTH	0xffff00	/* Yellow for south walls */

/* RGB value constraints */
# define RGB_MIN			0		/* Minimum RGB value */
# define RGB_MAX			255		/* Maximum RGB value */
# define RGB_COMPONENTS		3		/* Number of RGB components */

/*
** =============================================================================
** INPUT AND CONTROL CONSTANTS
** =============================================================================
*/

/* Key codes (Linux X11) */
# define KEY_ESC			65307	/* Escape key */
# define KEY_ESC_MAC		53		/* Escape key (macOS) */
# define KEY_W				119		/* Move forward */
# define KEY_A				97		/* Move left */
# define KEY_S				115		/* Move backward */
# define KEY_D				100		/* Move right */
# define KEY_LEFT			65361	/* Turn left arrow */
# define KEY_LEFT_MAC		123		/* Turn left arrow (macOS) */
# define KEY_RIGHT			65363	/* Turn right arrow */
# define KEY_RIGHT_MAC		124		/* Turn right arrow (macOS) */

/*
** =============================================================================
** PARSING CONSTANTS
** =============================================================================
*/

/* Configuration identifiers */
# define ID_NORTH			"NO"	/* North texture identifier */
# define ID_SOUTH			"SO"	/* South texture identifier */
# define ID_WEST			"WE"	/* West texture identifier */
# define ID_EAST			"EA"	/* East texture identifier */
# define ID_FLOOR			"F"		/* Floor color identifier */
# define ID_CEILING			"C"		/* Ceiling color identifier */

/* File validation */
# define CUB_EXTENSION		".cub"	/* Required file extension */
# define MIN_FILENAME_LEN	5		/* Minimum filename length */
# define REQUIRED_PARAMS	6		/* Number of required parameters */

/*
** =============================================================================
** ERROR MESSAGES
** =============================================================================
*/

# define ERR_USAGE			"Error\nCorrect format: ./cub3D map.cub\n"
# define ERR_MAP_FILE		"Error\nNot valid map file"
# define ERR_MAP_INVALID	"Error\nNot valid map\n"
# define ERR_COLOR_INVALID	"Error\nNot valid color specification\n"
# define ERR_PARAM_LIST		"Error\nWrong parameter list"

/*
** =============================================================================
** MATHEMATICAL CONSTANTS  
** =============================================================================
*/

# ifndef M_PI
#  define M_PI				3.14159265358979323846
# endif

# define TWO_PI				(2 * M_PI)		/* Full circle in radians */
# define HALF_PI			(M_PI / 2)		/* Quarter circle in radians */

/*
** =============================================================================
** MEMORY AND PERFORMANCE
** =============================================================================
*/

# define BUFFER_SIZE		1024	/* General buffer size */
# define MAX_LINE_LENGTH	2048	/* Maximum line length in config files */

#endif