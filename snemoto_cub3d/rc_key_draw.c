/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_key_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:27:52 by snemoto           #+#    #+#             */
/*   Updated: 2023/10/14 14:43:26 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rc.h"

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
			if (row < MAPL || row > MAPR)
				mlx_pixel_put(var->mlx, var->win, row, col, BLACK);			
			else if (row == MAPL || row == MAPR)
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

static void	key_draw_wall(t_vars *var, t_pos *pos, unsigned int row)
{
	unsigned int	row_l;
	unsigned int	row_r;
	unsigned int	col;
	unsigned int	col_l;
	unsigned int	col_h;

	row_l = WINW / 2 - (ROW - row) / 2 * WALL - pos->dis->dis_y * WALL + pos->dis->dis_angle * WALL - pos->dis->dis_x * WALL;
	if (row_l <= MAPL)
		row_l = MAPL;
	row_r = WINW / 2 - (ROW - row) / 2 * WALL + pos->dis->dis_y * WALL + pos->dis->dis_angle * WALL - pos->dis->dis_x * WALL;
	if (row_r >= MAPR)
		row_r = MAPR;
	col_l = WINH / 2 - pos->dis->dis_y * WALL;
	col_h = WINH / 2 + pos->dis->dis_y * WALL;
	while (row++ < WINW)
	{
		col = 0;
		while (col++ < WINH)
		{
			if (row_l < row && row < row_r && col_l < col && col < col_h)
				mlx_pixel_put(var->mlx, var->win, row, col, RED);
		}
	}
}

int	key_draw(t_vars *var)
{
	t_pos	*pos;
	unsigned int	row;

	pos = var->pos;
	row = 0;
	while (1)
	{
		if (row < ROW)
		{
			key_draw_wall(var, pos, row);
			key_draw_map_range(var);
			key_draw_grid(var);
			row++;
		}
		else
			break ;
	}
	return (0);
}
