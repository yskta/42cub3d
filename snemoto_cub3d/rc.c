/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:27:52 by snemoto           #+#    #+#             */
/*   Updated: 2023/10/09 17:07:45 by snemoto          ###   ########.fr       */
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
	t_pos	*pos;
	t_dir	*dir;

	pos = (t_pos *)malloc(sizeof(t_pos));
	var.pos = pos;
	var.pos->pos_x = 2;
	var.pos->pos_y = 4;
	var.pos->element = 0;
	get_pos(var);

	dir = (t_dir *)malloc(sizeof(t_dir));
	var.dir = dir;
	var.dir->dir_x = 1;
	var.dir->dir_y = 0;
	var.dir->angle = atan(var.dir->dir_y / var.dir->angle);
	get_dir(var, M_PI / ANGLE); //keyで+π/2移動

	var.mlx = mlx_init();
	var.win = mlx_new_window(var.mlx, WINW, WINH, "rc");
	mlx_loop(var.mlx);
	return (0);
}
