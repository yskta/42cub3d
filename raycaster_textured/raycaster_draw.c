/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_draw.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:27:52 by snemoto           #+#    #+#             */
/*   Updated: 2023/11/19 18:56:57 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

static	void draw_celling_floor(t_vars *var)
{
	int	row;
	int	col;
	
	col = SCREEN_H / 2 + 1;
	while (col < SCREEN_H)
	{
		row = 0;
		while (row < SCREEN_W)
		{
			var->img->dst = var->img->addr + col * var->img->size_line + row * (var->img->bits_per_pixel / 8);
			*(unsigned int *)var->img->dst = var->color_f;
			var->img->dst = var->img->addr + (SCREEN_H - col - 1) * var->img->size_line + row * (var->img->bits_per_pixel / 8);
			*(unsigned int *)var->img->dst = var->color_c;
			++row;
		}
		++col;
	}
}

int	key_draw(t_vars *var)
{
	int	row;

	var->img = (t_img *)malloc(sizeof(t_img));
	var->img->img = mlx_new_image(var->mlx, SCREEN_W, SCREEN_H);
	var->img->addr = mlx_get_data_addr(var->img->img, &var->img->bits_per_pixel, &var->img->size_line, &var->img->endian);
	draw_celling_floor(var);
	row = 0;
	while (row < SCREEN_W)
	{
		var->camera_x = 2 * row / (double)SCREEN_W - 1;
		calc_init(var);
		calc_side_dist(var);
		calc_hit_wall(var);
		tex_init(var);
		tex_dir(var);
		tex_draw(var, row);
		calc_free(var);
		++row;
	}
	mlx_put_image_to_window(var->mlx, var->win, var->img->img, 0, 0);
	free(var->img);
	return (0);
}
