/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_key_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:27:52 by snemoto           #+#    #+#             */
/*   Updated: 2023/10/22 14:26:24 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rc.h"

static unsigned int	calc_row_l(t_vars *var)
{
	unsigned int	row_l;
	
	row_l = WINW / 2 \
			- var->pos->pos_x / 2 * WALL \
			- var->pos->dis->dis_x * WALL \
			- var->pos->dis->dis_y * WALL \
			+ var->dir->angle * WALL;
	if (row_l <= MAPL)
		row_l = MAPL;
	return (row_l);
}

static unsigned int	calc_row_r(t_vars *var)
{
	unsigned int	row_r;
	
	row_r = WINW / 2 \
			+ ((ROW - 1) - var->pos->pos_x) / 2 * WALL \
			- var->pos->dis->dis_x * WALL \
			+ var->pos->dis->dis_y * WALL \
			+ var->dir->angle * WALL;
	if (row_r >= MAPR)
		row_r = MAPR;
	return (row_r);
}

static double	calc_vertical(t_vars *var, unsigned int row_l, unsigned int row_r, unsigned int row)
{
	double	vertical;

	if (var->dir->angle < 0)
		vertical = (row_r - row) / 2 * fabs(sin(var->dir->angle));
	else if (0 < var->dir->angle)
		vertical = (row - row_l) / 2 * fabs(sin(var->dir->angle));
	else
		vertical = 0;
	return (vertical);
}

static void	key_draw_wall(t_vars *var)
{
	unsigned int	row;
	unsigned int	row_l;
	unsigned int	row_r;
	unsigned int	col;
	unsigned int	col_l;
	unsigned int	col_h;
	double			vertical;

	row_l = calc_row_l(var);
	row_r = calc_row_r(var);
	row = MAPL;
	while (MAPL <= row && row <= MAPR)
	{
		var->dir->color = BLACK;
		col_l = WINH / 2 - var->pos->dis->dis_y * WALL;
		col_h = WINH / 2 + var->pos->dis->dis_y * WALL;
		if (MAPL < row && row < row_l)
		{
			var->dir->color = RED;
			vertical = (row_l - row) * fabs(cos(var->dir->angle));
			col_l -= vertical;
			col_h += vertical;
		}
		else if (row_l <= row && row <= row_r)
		{
			var->dir->color = PURPLE;
			vertical = calc_vertical(var, row_l, row_r, row);
			col_l -= vertical;
			col_h += vertical;			
		}
		else if (row_r < row && row < MAPR)
		{
			var->dir->color = GREEN;
			vertical = (row - row_r) * fabs(cos(var->dir->angle));
			col_l -= vertical;
			col_h += vertical;
		}
		col = 0;
		while (col < col_l)
			mlx_pixel_put(var->mlx, var->win, row, col++, FLOOR);
		col = col_l;
		while (col <= col_h)
			mlx_pixel_put(var->mlx, var->win, row, col++, var->dir->color);
		col = col_h;
		while (col < WINH)
			mlx_pixel_put(var->mlx, var->win, row, col++, CEILING);
		row++;
	}
}

int	key_draw(t_vars *var)
{
	key_draw_wall(var);
	key_draw_map_range(var); //not require
	key_draw_grid(var); //not require
	return (0);
}
