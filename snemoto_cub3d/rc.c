/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:27:52 by snemoto           #+#    #+#             */
/*   Updated: 2023/10/10 16:57:43 by snemoto          ###   ########.fr       */
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
		var->pos->pos_y--;
	else if (keycode == KEY_S && var->pos->pos_y + 1 < COL - 1)
		var->pos->pos_y++;
	else if (keycode == KEY_A && 0 < var->pos->pos_x - 1)
		var->pos->pos_x--;
	else if (keycode == KEY_D && var->pos->pos_x + 1 < ROW - 1)
		var->pos->pos_x++;
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
	unsigned int	row = 0;
	unsigned int	col = 0;

	while (row++ < WINW)
	{
		while (col++ < WINH)
		{
			if (col < WINH / 2)
			{
				if (WINW / 2 - var->pos->dis * 50 <= row && row <= WINW / 2 + var->pos->dis * 50 \
					&& WINH / 2 - var->pos->dis * 50 <= col && col <= WINH / 2)
					mlx_pixel_put(var->mlx, var->win, row, col, 0xFF0000);
				else
					mlx_pixel_put(var->mlx, var->win, row, col, 0x000000);			
			}
			else
			{
				if (WINW / 2 - var->pos->dis * 50 <= row && row <= WINW / 2 + var->pos->dis * 50 \
					&& WINH / 2 <= col && col <= WINH / 2 + var->pos->dis * 50)
					mlx_pixel_put(var->mlx, var->win, row, col, 0xFF0000);
				else
					mlx_pixel_put(var->mlx, var->win, row, col, 0x000000);			
			}
		}
		col = 0;
	}
	// mlx_put_image_to_window(var->mlx, var->win, var->img, 500, 500);
	return (0);
}

int	main(void)
{
	t_vars	var;
	t_pos	*pos;
	t_dir	*dir;

	pos = (t_pos *)malloc(sizeof(t_pos));
	var.pos = pos;
	var.pos->pos_x = 2;
	var.pos->pos_y = 4;
	var.pos->element = 0;

	dir = (t_dir *)malloc(sizeof(t_dir));
	var.dir = dir;
	var.dir->dir_x = 1;
	var.dir->dir_y = 0;
	var.dir->angle = atan(var.dir->dir_y / var.dir->angle);

	var.mlx = mlx_init();
	var.win = mlx_new_window(var.mlx, WINW, WINH, "rc");

	get_pos(var, map);
	mlx_pixel_put(var.mlx, var.win, var.pos->dis * 100, var.pos->dis * 100, 0xFF0000);
	// var.img_len = IMGLEN;
	// var.img = mlx_xpm_file_to_image(var.mlx, "./1.xpm", &(var.img_len), &(var.img_len));

	mlx_key_hook(var.win, key_hook, &var);
	mlx_loop_hook(var.mlx, key_draw, &var);
	mlx_loop(var.mlx);
	return (0);
}
