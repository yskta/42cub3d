/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_key_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:27:52 by snemoto           #+#    #+#             */
/*   Updated: 2023/10/22 11:03:04 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rc.h"

static unsigned int	calc_row_l(t_vars *var, t_pos *pos)
{
	unsigned int	row_l;
	
	row_l = WINW / 2 \
			- pos->pos_x / 2 * WALL \
			- pos->dis->dis_x * WALL \
			- pos->dis->dis_y * WALL \
			+ var->dir->angle * WALL;
	if (row_l <= MAPL)
		row_l = MAPL;
	return (row_l);
}

static unsigned int	calc_row_r(t_vars *var, t_pos *pos)
{
	unsigned int	row_r;
	
	row_r = WINW / 2 \
			+ (ROW - 1 - pos->pos_x) / 2 * WALL \
			- pos->dis->dis_x * WALL \
			+ pos->dis->dis_y * WALL \
			+ var->dir->angle * WALL;
	if (row_r >= MAPR)
		row_r = MAPR;
	return (row_r);
}

static void	key_draw_wall(t_vars *var, t_pos *pos)
{
	unsigned int	row;
	unsigned int	row_l;
	unsigned int	row_r;
	unsigned int	col;
	unsigned int	col_l;
	unsigned int	col_h;
	int				color;
	double			vertical;

	row_l = calc_row_l(var, pos);
	row_r = calc_row_r(var, pos);
	row = MAPL;
	while (MAPL <= row && row <= MAPR)
	{
		color = BLACK;
		col_l = WINH / 2 - pos->dis->dis_y * WALL;
		col_h = WINH / 2 + pos->dis->dis_y * WALL;
		if (MAPL < row && row < row_l)
		{
			color = WEST;
			vertical = (row_l - row) * fabs(sin(var->dir->angle));
			col_l -= vertical;
			col_h += vertical;
		}
		else if (row_l <= row && row <= row_r)
		{
			color = NORTH;
			vertical = 0;
			col_l -= vertical;
			col_h += vertical;			
		}
		else if (row_r < row && row < MAPR)
		{
			color = EAST;
			vertical = (row - row_r) * fabs(sin(var->dir->angle));
			col_l -= vertical;
			col_h += vertical;
		}
		col = col_l;
		while (color != BLACK && col < col_h)
			mlx_pixel_put(var->mlx, var->win, row, col++, color);
		row++;
	}
}

int	key_draw(t_vars *var)
{
	t_pos	*pos;

	pos = var->pos;
	key_draw_wall(var, pos);
	key_draw_map_range(var); //not require
	key_draw_grid(var); //not require
	return (0);
}
