/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_raycaster_draw.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 23:41:22 by yokitaga          #+#    #+#             */
/*   Updated: 2023/11/26 14:11:34 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	draw_celling_floor(t_data *data)
{
	unsigned int	row;
	unsigned int	col;

	col = SCREEN_H / 2 + 1;
	while (col < SCREEN_H)
	{
		row = 0;
		while (row < SCREEN_W)
		{
			data->img->dst = data->img->addr \
				+ row * (data->img->bits / 8) + col * data->img->size;
			*(unsigned int *)data->img->dst = data->floor.color;
			data->img->dst = data->img->addr + (SCREEN_H - col - 1) \
				* data->img->size + row * (data->img->bits / 8);
			*(unsigned int *)data->img->dst = data->ceiling.color;
			++row;
		}
		++col;
	}
}

static void	img_init(t_data *data)
{
	data->img->img = mlx_new_image(data->mlx, SCREEN_W, SCREEN_H);
	data->img->addr = mlx_get_data_addr(data->img->img, \
		&data->img->bits, &data->img->size, &data->img->endian);
	draw_celling_floor(data);
}

static void	img_draw(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img->img, 0, 0);
	mlx_destroy_image(data->mlx, data->img->img);
	free(data->img);
}

int	key_draw(t_data *data)
{
	int	row;

	data->img = (t_img *)malloc(sizeof(t_img));
	if (data->img == NULL)
		return (0);
	img_init(data);
	row = 0;
	while (row < SCREEN_W)
	{
		data->camera_x = 2.0 * row / (double)SCREEN_W - 1.0;
		if (calc_init(data) == false)
		{
			calc_free(data);
			break ;
		}
		calc_side_dist(data);
		calc_hit_wall(data);
		tex_init(data);
		tex_dir(data);
		tex_draw(data, row);
		calc_free(data);
		++row;
	}
	img_draw(data);
	return (0);
}
