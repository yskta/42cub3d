/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:27:52 by snemoto           #+#    #+#             */
/*   Updated: 2023/10/14 15:00:42 by snemoto          ###   ########.fr       */
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

t_pos	*init_pos(unsigned int row, unsigned int col)
{
	t_pos	*pos;

	pos = (t_pos *)malloc(sizeof(t_pos));
	pos->pos_x = row;
	pos->pos_y = col;

	pos->dis = (t_dis *)malloc(sizeof(t_dis));
	pos->dis->dis_x = 0;
	pos->dis->dis_y = 1;
	pos->dis->dis_angle = 0;
	// pos->dis->dis_left = 2;
	// pos->dis->dis_right = 3;
	return (pos);
}

int	main(void)
{
	t_vars	var;
	unsigned int	row = 2;
	unsigned int	col = 4;

	var.pos = init_pos(row, col);

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
