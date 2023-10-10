/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:27:52 by snemoto           #+#    #+#             */
/*   Updated: 2023/10/10 18:01:29 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rc.h"

unsigned int map[ROW][COL]=
{
{1,1,1,1,1,1},
{1,0,0,0,0,1},
{1,0,0,0,0,1},
{1,0,0,0,0,1},
{1,0,0,0,0,1},
{1,1,1,1,1,1}
};

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
		var->dir->angle += M_PI / ANGLE;
	else if (keycode == KEY_RIGHT)
		var->dir->angle -= M_PI / ANGLE;
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
				if (row <= WINW / 2 + var->dis->dis_x * WALL + var->dis->dis_y * WALL \
				&& WINW / 2 + var->dis->dis_x * WALL - var->dis->dis_y * WALL <= row \
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

int	main(void)
{
	t_vars	var;

	var.pos = (t_pos *)malloc(sizeof(t_pos));
	var.pos->pos_x = 2;
	var.pos->pos_y = 4;
	var.pos->element = 0;

	var.dir = (t_dir *)malloc(sizeof(t_dir));;
	var.dir->dir_x = 1;
	var.dir->dir_y = 0;
	var.dir->angle = atan(var.dir->dir_y / var.dir->angle);

	var.dis = (t_dis *)malloc(sizeof(t_dis));
	var.dis->dis_x = 0;
	var.dis->dis_y = 1;

	var.mlx = mlx_init();
	var.win = mlx_new_window(var.mlx, WINW, WINH, "rc");

	mlx_key_hook(var.win, key_hook, &var);
	mlx_loop_hook(var.mlx, key_draw, &var);
	mlx_loop(var.mlx);
	return (0);
}
