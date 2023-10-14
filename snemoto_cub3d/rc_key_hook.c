/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:27:52 by snemoto           #+#    #+#             */
/*   Updated: 2023/10/14 17:35:16 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rc.h"

static void	key_draw_clear(t_vars *var)
{
	unsigned int	row;
	unsigned int	col;

	row = 0;
	col = 0;
	while (row++ < WINW)
	{
		col = 0;
		while (col++ < WINH)
			mlx_pixel_put(var->mlx, var->win, row, col, BLACK);			
	}
}

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
	}
	else if (keycode == KEY_D && var->pos->pos_x + 1 < ROW - 1)
	{
		var->pos->pos_x++;
		var->pos->dis->dis_x++;
	}
	else if (keycode == KEY_LEFT)
	{
		var->dir->angle += M_PI / ANGLE;
		var->dir->dir_x = cos(var->dir->angle);
		var->dir->dir_y = sin(var->dir->angle);
		var->pos->dis->dis_angle += M_PI / ANGLE;
		if (var->pos->dis->dis_angle == 2 * M_PI)
			var->pos->dis->dis_angle = 0;
	}
	else if (keycode == KEY_RIGHT)
	{
		var->dir->angle -= M_PI / ANGLE;
		var->dir->dir_x = cos(var->dir->angle);
		var->dir->dir_y = sin(var->dir->angle);
		var->pos->dis->dis_angle -= M_PI / ANGLE;		
		if (var->pos->dis->dis_angle == -2 * M_PI)
			var->pos->dis->dis_angle = 0;
	}
	else
		return (0);
	print_pos(*var);
	print_dir(*var);
	key_draw_clear(var);
	return (0);
}
