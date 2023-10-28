/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:27:52 by snemoto           #+#    #+#             */
/*   Updated: 2023/10/23 17:16:05 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rc.h"

/* ************************************************************************** */

void	print_dir(t_vars var)
{
	printf("Xcos ;%f Ysin ;%f\n", var.dir->dir_x, var.dir->dir_y);
	printf("angle;%f\n", var.dir->angle);
	printf("---------------------\n");
}

void	print_pos(t_vars var)
{
	printf("HERE X;%d Y;%d\n", var.pos->pos_x, var.pos->pos_y);
	printf("dis_x;%d\n", var.pos->dis->dis_x);
	printf("dis_y;%d\n", var.pos->dis->dis_y);
	printf("---------------------\n");
}

/* ************************************************************************** */

void	key_draw_map_range(t_vars *var)
{
	unsigned int	row;
	unsigned int	col;
	int				color;

	row = 0;
	while (row++ < WINW)
	{
		color = BLACK;
		if (row == MAPL || row == MAPR)
			color = WATER;
		col = 0;
		while (color != BLACK && col < WINH)
			mlx_pixel_put(var->mlx, var->win, row, col++, color);
	}
}

void	key_draw_grid(t_vars *var)
{
	unsigned int	row;
	unsigned int	col;

	row = MAPL + WALL;
	while (row < MAPR)
	{
		col = 0;
		while (col < WINH)
			mlx_pixel_put(var->mlx, var->win, row, col++, WHITE);
		row += WALL;
	}
}

/* ************************************************************************** */

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
	pos->dis->dis_x = row - 1;
	pos->dis->dis_y = COL - 1 - col;
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
	var.dir->color = BLUE;
	var.dir->angle = atan(var.dir->dir_y / var.dir->angle);

	var.mlx = mlx_init();
	var.win = mlx_new_window(var.mlx, WINW, WINH, "rc");
	mlx_key_hook(var.win, key_hook, &var);
	mlx_loop_hook(var.mlx, key_draw, &var);
	mlx_loop(var.mlx);

	return (0);
}
