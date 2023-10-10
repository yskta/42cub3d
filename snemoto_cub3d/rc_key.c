/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:27:52 by snemoto           #+#    #+#             */
/*   Updated: 2023/10/10 18:21:08 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rc.h"

int	key_hook(int keycode, t_vars *var)
{
	if (keycode == KEY_W && 0 < var->pos->pos_y - 1)
	{
		var->pos->pos_y--;
		var->dis->dis_y++;
	}
	else if (keycode == KEY_S && var->pos->pos_y + 1 < COL - 1)
	{
		var->pos->pos_y++;
		var->dis->dis_y--;
	}
	else if (keycode == KEY_A && 0 < var->pos->pos_x - 1)
	{
		var->pos->pos_x--;
		var->dis->dis_x--;
	}
	else if (keycode == KEY_D && var->pos->pos_x + 1 < ROW - 1)
	{
		var->pos->pos_x++;
		var->dis->dis_x++;
	}
	else if (keycode == KEY_LEFT)
	{
		var->dir->angle += M_PI / ANGLE;
		var->dis->dis_angle += M_PI / ANGLE;
		if (var->dis->dis_angle == 2 * M_PI)
			var->dis->dis_angle = 0;
	}
	else if (keycode == KEY_RIGHT)
	{
		var->dir->angle -= M_PI / ANGLE;
		var->dis->dis_angle -= M_PI / ANGLE;		
		if (var->dis->dis_angle == -2 * M_PI)
			var->dis->dis_angle = 0;
	}
	else
		return (0);
	get_pos(*var, map);
	get_dir(*var);
	return (0);
}

int	key_draw(t_vars *var)
{
	unsigned int	row;
	unsigned int	col;

	row = 0;
	col = 0;
	while (row++ < WINW)
	{
		while (col++ < WINH)
		{
				if (row <= WINW / 2 + var->dis->dis_angle * WALL + var->dis->dis_x * WALL + var->dis->dis_y * WALL \
				&& WINW / 2 + var->dis->dis_angle * WALL + var->dis->dis_x * WALL - var->dis->dis_y * WALL <= row \
				&& col <= WINH / 2 + var->dis->dis_y * WALL \
				&& WINH / 2 - var->dis->dis_y * WALL <= col)
				mlx_pixel_put(var->mlx, var->win, row, col, RED);
			else
				mlx_pixel_put(var->mlx, var->win, row, col, BLACK);			
		}
		col = 0;
	}
	return (0);
}
