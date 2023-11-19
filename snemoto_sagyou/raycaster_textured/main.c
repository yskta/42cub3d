/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:00:01 by snemoto           #+#    #+#             */
/*   Updated: 2023/11/12 17:09:55 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

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
  var.texture->dir = (t_tex_dir *)malloc(sizeof(t_tex_dir));
  var.texture->dir->n = mlx_xpm_file_to_image(var.mlx, "./texture/north.xpm", &len_w, &len_h);
  var.texture->dir->s = mlx_xpm_file_to_image(var.mlx, "./texture/south.xpm", &len_w, &len_h);
  var.texture->dir->e = mlx_xpm_file_to_image(var.mlx, "./texture/east.xpm", &len_w, &len_h);
  var.texture->dir->w = mlx_xpm_file_to_image(var.mlx, "./texture/west.xpm", &len_w, &len_h);

  void  *tmp = var.texture->dir->e;
  var.texture->addr = mlx_get_data_addr(tmp, &var.texture->bits_per_pixel, &var.texture->size_line, &var.texture->endian);
	// mlx_put_image_to_window(var.mlx, var.win, tmp, 0, 0);

/* ************************************************************************** */

	mlx_key_hook(var.win, key_hook, &var);
	mlx_loop_hook(var.mlx, key_draw, &var);
	mlx_loop(var.mlx);

	return (0);
}
