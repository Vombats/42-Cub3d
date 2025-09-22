/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanakgulati <khanakgulati@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 10:08:06 by khanakgulat       #+#    #+#             */
/*   Updated: 2021/11/22 14:26:12 by khanakgulat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

float	check_limits(float o)
{
	if (o < 0)
		o += TWO_PI;
	else if (o > TWO_PI)
		o -= TWO_PI;
	return (o);
}

float	angle_change(int dir, float ang)
{
	if (dir == 0)
		ang -= ROTATION_SPEED;
	else if (dir == 1)
		ang += ROTATION_SPEED;
	if (ang < 0)
		ang += TWO_PI;
	else if (ang > TWO_PI)
		ang -= TWO_PI;
	return (ang);
}

void	coord_to_pixel(t_cub *d)
{
	d->g_player.posx = (d->g_player.startx * TILE_SIZE) + HALF_TILE;
	d->g_player.posy = (d->g_player.starty * TILE_SIZE) + HALF_TILE;
}
