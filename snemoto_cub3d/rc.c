/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:27:52 by snemoto           #+#    #+#             */
/*   Updated: 2023/10/11 19:08:50 by snemoto          ###   ########.fr       */
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

int	main(void)
{
	t_vars	var;

	var.pos = (t_pos *)malloc(sizeof(t_pos));
	var.pos->pos_x = 2;
	var.pos->pos_y = 4;
	var.pos->element = 0;

	var.pos->dis = (t_dis *)malloc(sizeof(t_dis));
	var.pos->dis->dis_x = 1;
	var.pos->dis->dis_left = 2;
	var.pos->dis->dis_right = 3;
	var.pos->dis->dis_y = 1;
	var.pos->dis->dis_angle = 0;

	var.dir = (t_dir *)malloc(sizeof(t_dir));;
	var.dir->dir_x = 1;
	var.dir->dir_y = 0;
	var.dir->angle = atan(var.dir->dir_y / var.dir->angle);

	var.mlx = mlx_init();
	var.win = mlx_new_window(var.mlx, WINW, WINH, "rc");
	mlx_key_hook(var.win, key_hook, &var);
	mlx_loop_hook(var.mlx, key_draw, &var);
	mlx_loop(var.mlx);

	return (0);
}
