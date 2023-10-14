/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_key_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:27:52 by snemoto           #+#    #+#             */
/*   Updated: 2023/10/14 17:09:24 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rc.h"

static void	key_draw_wall_horizontal(t_vars *var, t_pos *pos)
{
	unsigned int	row;
	unsigned int	row_l;
	unsigned int	row_r;
	unsigned int	col;
	unsigned int	col_l;
	unsigned int	col_h;
	int				color;
	double			vertical;

	row = pos->pos_x;
	row_l = WINW / 2 - row / 2 * WALL - pos->dis->dis_y * WALL + pos->dis->dis_angle * WALL - pos->dis->dis_x * WALL;
	if (row_l <= MAPL)
		row_l = MAPL;
	row_r = WINW / 2 + (ROW - row) / 2 * WALL + pos->dis->dis_y * WALL + pos->dis->dis_angle * WALL - pos->dis->dis_x * WALL;
	if (row_r >= MAPR)
		row_r = MAPR;
	row = MAPL;
	while (MAPL <= row && row <= MAPR)
	{
		color = BLACK;
		col_l = WINH / 2 - pos->dis->dis_y * WALL;
		col_h = WINH / 2 + pos->dis->dis_y * WALL;
		if (MAPL < row && row < row_l)
		{
			color = YELLOW;
			vertical = (row_l - row) * sin(M_PI / ANGLE);
			col_l -= vertical;
			col_h += vertical;
		}
		else if (row_l < row && row < row_r)
			color = RED;
		else if (row_r < row && row < MAPR)
		{
			color = YELLOW;
			vertical = (row - row_r) * sin(M_PI / ANGLE);
			col_l -= vertical;
			col_h += vertical;
		}
		col = col_l;
		while (color != BLACK && col < col_h)
			mlx_pixel_put(var->mlx, var->win, row, col++, color);
		row++;
	}
}

static void	key_draw_map_range(t_vars *var)
{
	unsigned int	row;
	unsigned int	col;
	int				color;

	row = 0;
	while (row++ < WINW)
	{
		color = BLACK;
		if (row == MAPL || row == MAPR)
			color = RED;
		col = 0;
		while (color != BLACK && col < WINH)
			mlx_pixel_put(var->mlx, var->win, row, col++, color);
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
		while (col < WINH)
			mlx_pixel_put(var->mlx, var->win, row, col++, BLUE);
		row += WALL;
	}
}

int	key_draw(t_vars *var)
{
	t_pos	*pos;

	pos = var->pos;
	key_draw_wall_horizontal(var, pos);
	key_draw_map_range(var);
	key_draw_grid(var);
	return (0);
}
