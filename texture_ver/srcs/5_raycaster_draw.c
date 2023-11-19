/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_raycaster_draw.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 23:41:22 by yokitaga          #+#    #+#             */
/*   Updated: 2023/11/20 00:50:31 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static	void draw_celling_fllor(t_data *data)
{
	unsigned int	row;
	unsigned int	col;

	col = SCREEN_H / 2 + 1;
	while (col < SCREEN_H)
	{
		row = 0;
		while (row < SCREEN_W)
		{
			data->img->dst = data->img->addr + col * data->img->size_line + row * (data->img->bits_per_pixel / 8);
			*(unsigned int *)data->img->dst = BLUE / 2;
			data->img->dst = data->img->addr + (SCREEN_H - col - 1) * data->img->size_line + row * (data->img->bits_per_pixel / 8);
			*(unsigned int *)data->img->dst = GREEN / 2;
			++row;
		}
		++col;
	}
}

int	key_draw(t_data *data)
{
	int	row;

	data->img = (t_img *)malloc(sizeof(t_img));
	data->img->img = mlx_new_image(data->mlx, SCREEN_W, SCREEN_H);
	data->img->addr = mlx_get_data_addr(data->img->img, &data->img->bits_per_pixel, &data->img->size_line, &data->img->endian);
	draw_celling_fllor(data);
	row = 0;
	while (row < SCREEN_W)
	{
		data->camera_x = 2 * row / (double)SCREEN_W - 1;
		calc_init(data);
		calc_side_dist(data);
		calc_hit_wall(data);
		tex_init(data);
		tex_dir(data);
		tex_draw(data, row);
		calc_free(data);
		++row;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img->img, 0, 0);
	mlx_destroy_image(data->mlx, data->img->img);
	free(data->img);
	return (0);
}