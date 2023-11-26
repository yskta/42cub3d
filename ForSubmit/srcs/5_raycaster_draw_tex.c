/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_raycaster_draw_tex.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 00:23:14 by yokitaga          #+#    #+#             */
/*   Updated: 2023/11/26 13:21:34 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	tex_init(t_data *data)
{
	data->line_height = (int)((double)SCREEN_H / data->perp_wall_dist);
	data->draw_start = SCREEN_H / 2 - data->line_height / 2;
	if (data->draw_start < 0)
		data->draw_start = 0;
	data->draw_end = SCREEN_H / 2 + data->line_height / 2;
	if (data->draw_end >= SCREEN_H)
		data->draw_end = SCREEN_H - 1;
	if (data->side == false)
		data->wall_x = data->cur_pos->y + \
			data->perp_wall_dist * data->ray_dir->y;
	else
		data->wall_x = data->cur_pos->x + \
			data->perp_wall_dist * data->ray_dir->x;
	data->wall_x -= floor(data->wall_x);
	data->tex_x = (int)(data->wall_x * (double)TEX_W);
	if (data->side == false && data->ray_dir->x > 0)
		data->tex_x = TEX_W - data->tex_x - 1;
	else if (data->side == true && data->ray_dir->y < 0)
		data->tex_x = TEX_W - data->tex_x - 1;
	data->tex_step = 1.0 * TEX_H / data->line_height;
	data->tex_pos = (data->draw_start - SCREEN_H / 2 + \
		data->line_height / 2) * data->tex_step;
}

void	tex_dir(t_data *data)
{
	if (data->side == false)
	{
		data->img->kind = DIR_N;
		if (data->step->x > 0)
			data->img->kind = DIR_S;
	}
	else
	{
		data->img->kind = DIR_E;
		if (data->step->y < 0)
			data->img->kind = DIR_W;
	}
	if (data->img->kind == DIR_N)
		data->tex->addr = mlx_get_data_addr(data->tex->tex_dir->north.tex_ptr, \
			&data->tex->bits, &data->tex->size, &data->tex->endian);
	else if (data->img->kind == DIR_S)
		data->tex->addr = mlx_get_data_addr(data->tex->tex_dir->south.tex_ptr, \
			&data->tex->bits, &data->tex->size, &data->tex->endian);
	else if (data->img->kind == DIR_E)
		data->tex->addr = mlx_get_data_addr(data->tex->tex_dir->east.tex_ptr, \
			&data->tex->bits, &data->tex->size, &data->tex->endian);
	else if (data->img->kind == DIR_W)
		data->tex->addr = mlx_get_data_addr(data->tex->tex_dir->west.tex_ptr, \
			&data->tex->bits, &data->tex->size, &data->tex->endian);
}

void	tex_draw(t_data *data, int row)
{
	int	col;

	col = data->draw_start;
	while (col < data->draw_end)
	{
		data->tex_y = (int)data->tex_pos & (TEX_H - 1);
		data->color = *(unsigned int *)(data->tex->addr + data->tex_y * \
			data->tex->size + data->tex_x * (data->tex->bits / 8));
		data->tex_pos += data->tex_step;
		data->img->dst = data->img->addr \
			+ col * data->img->size + row * (data->img->bits / 8);
		*(unsigned int *)data->img->dst = data->color;
		++col;
	}
}
