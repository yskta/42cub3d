/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:00:01 by snemoto           #+#    #+#             */
/*   Updated: 2023/11/20 16:43:34 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int map[MAP_W][MAP_H]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,1,0,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

int	main(void)
{
	t_vars	var;

	var.pos = (t_pos *)malloc(sizeof(t_pos));
	var.pos->pos_x = 22;
	var.pos->pos_y = 12;

	var.dir = (t_dir *)malloc(sizeof(t_dir));
	var.dir->dir_x = -1;
	var.dir->dir_y = 0;

	var.plane = (t_plane *)malloc(sizeof(t_plane));
	var.plane->plane_x = 0;
	var.plane->plane_y = 0.66;

	var.mlx = mlx_init();
	var.win = mlx_new_window(var.mlx, SCREEN_W, SCREEN_H, "rc");

/* ************************************************************************** */

  var.color = BLACK;
	
  int len_w = TEX_W;
  int len_h = TEX_H;

  var.texture = (t_tex *)malloc(sizeof(t_tex));
  var.texture->tex_dir = (t_tex_dir *)malloc(sizeof(t_tex_dir));
  var.texture->tex_dir->n = mlx_xpm_file_to_image(var.mlx, "./texture/north.xpm", &len_w, &len_h);
  var.texture->tex_dir->s = mlx_xpm_file_to_image(var.mlx, "./texture/south.xpm", &len_w, &len_h);
  var.texture->tex_dir->e = mlx_xpm_file_to_image(var.mlx, "./texture/east.xpm", &len_w, &len_h);
  var.texture->tex_dir->w = mlx_xpm_file_to_image(var.mlx, "./texture/west.xpm", &len_w, &len_h);

/* ************************************************************************** */

  var.color_c = BLUE / 2;
  var.color_f = GREEN / 2;

/* ************************************************************************** */

	mlx_key_hook(var.win, key_hook, &var);
	mlx_loop_hook(var.mlx, key_draw, &var);
	mlx_loop(var.mlx);

	return (0);
}
