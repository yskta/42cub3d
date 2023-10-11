/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:27:52 by snemoto           #+#    #+#             */
/*   Updated: 2023/10/11 19:00:47 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rc.h"

int	key_hook(int keycode, t_vars *var)
{
	if (keycode == KEY_W && 0 < var->pos->pos_y - 1)
	{
		var->pos->pos_y--;
		var->pos->dis->dis_y++;
	}
	else if (keycode == KEY_S && var->pos->pos_y + 1 < COL - 1)
	{
		var->pos->pos_y++;
		var->pos->dis->dis_y--;
	}
	else if (keycode == KEY_A && 0 < var->pos->pos_x - 1)
	{
		var->pos->pos_x--;
		var->pos->dis->dis_x--;
		var->pos->dis->dis_left--;
		var->pos->dis->dis_right++;
	}
	else if (keycode == KEY_D && var->pos->pos_x + 1 < ROW - 1)
	{
		var->pos->pos_x++;
		var->pos->dis->dis_x++;
		var->pos->dis->dis_left++;
		var->pos->dis->dis_right--;
	}
	else if (keycode == KEY_LEFT)
	{
		var->dir->angle += M_PI / ANGLE;
		var->pos->dis->dis_angle += M_PI / ANGLE;
		if (var->pos->dis->dis_angle == 2 * M_PI)
			var->pos->dis->dis_angle = 0;
	}
	else if (keycode == KEY_RIGHT)
	{
		var->dir->angle -= M_PI / ANGLE;
		var->pos->dis->dis_angle -= M_PI / ANGLE;		
		if (var->pos->dis->dis_angle == -2 * M_PI)
			var->pos->dis->dis_angle = 0;
	}
	else
		return (0);
	get_pos(*var, map);
	get_dir(*var);
	return (0);
}

static void	key_draw_map_range(t_vars *var)
{
	unsigned int	row;
	unsigned int	col;

	row = 0;
	while (row++ < WINW)
	{
		col = 0;
		while (col++ < WINH)
		{
			if (row == MAPL || row == MAPR)
				mlx_pixel_put(var->mlx, var->win, row, col, RED);
		}
	}
}

static void	key_draw_grid(t_vars *var)
{
	unsigned int	row;
	unsigned int	col;

	row = MAPL + WALL;
	while (row < MAPR)
	{
		col = 0;
		while (col++ < WINH)
		{
			mlx_pixel_put(var->mlx, var->win, row, col, BLUE);
		}
		row += WALL;
	}
}

static void	key_draw_wall(t_vars *var, t_pos *pos)
{
	unsigned int	row;
	unsigned int	row_min;
	unsigned int	row_max;
	unsigned int	col;
	unsigned int	col_min;
	unsigned int	col_max;

	row = 0;
	row_min = WINW / 2 - pos->dis->dis_y * WALL + pos->dis->dis_angle * WALL - pos->dis->dis_x * WALL;
	row_max = WINW / 2 + pos->dis->dis_y * WALL + pos->dis->dis_angle * WALL - pos->dis->dis_x * WALL;
	col_min = WINH / 2 - pos->dis->dis_y * WALL;
	col_max = WINH / 2 + pos->dis->dis_y * WALL;
	while (row++ < WINW)
	{
		col = 0;
		while (col++ < WINH)
		{
			if (row < MAPL || row > MAPR)
				mlx_pixel_put(var->mlx, var->win, row, col, BLACK);			
			else if (row_min < row && row < row_max && col_min < col && col < col_max)
				mlx_pixel_put(var->mlx, var->win, row, col, RED);
			else
				mlx_pixel_put(var->mlx, var->win, row, col, BLACK);			
		}
	}
}

int	key_draw(t_vars *var)
{
	t_pos	*pos;

	key_draw_map_range(var);
	key_draw_grid(var);
	pos = var->pos;
	key_draw_wall(var, pos);
	return (0);
}
