/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:27:52 by snemoto           #+#    #+#             */
/*   Updated: 2023/10/09 18:09:03 by snemoto          ###   ########.fr       */
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
	if (keycode == 0x077) //w
		var->pos->pos_y++;
	else if (keycode == 0x061) //a
		var->pos->pos_x--;
	else if (keycode == 0x064) //d
		var->pos->pos_x++;
	else if (keycode == 0x073) //s
		var->pos->pos_y--;
	else if (keycode == 0x8fb) //left
		var->dir->angle -= M_PI / ANGLE;
	else if (keycode == 0x8fd) //right
		var->dir->angle += M_PI / ANGLE;
	return (0);
}

int	key_draw(t_vars *var)
{
	get_pos(*var, map);
	get_dir(*var);
	mlx_put_image_to_window(var->mlx, var->win, var->img, 100, 100);
	return (0);
}

int	main(void)
{
	t_vars	var;
	t_pos	*pos;
	t_dir	*dir;
	int	img_len;

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

	img_len = IMGLEN;
	var.img = mlx_xpm_file_to_image(var.mlx, "./1.xpm", &img_len, &img_len);

	mlx_key_hook(var.mlx, key_hook, &var);
	mlx_loop_hook(var.mlx, key_draw, &var);
	mlx_loop(var.mlx);
	return (0);
}
