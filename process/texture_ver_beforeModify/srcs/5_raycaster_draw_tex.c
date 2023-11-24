/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_raycaster_draw_tex.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 00:23:14 by yokitaga          #+#    #+#             */
/*   Updated: 2023/11/20 00:42:05 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	tex_init(t_data *data)
{
	data->line_height = (int)(SCREEN_H / data->perp_wall_dist);
	data->draw_start = -1 * data->line_height / 2 + SCREEN_H / 2;
	if (data->draw_start < 0)
		data->draw_start = 0;
	data->draw_end = data->line_height / 2 + SCREEN_H / 2;
	if (data->draw_end >= SCREEN_H)
		data->draw_end = SCREEN_H - 1;
	if (data->side == false)
		data->wall_x = data->cur_pos->pos_y + data->perp_wall_dist * data->ray_dir->ray_dir_y;
	else
		data->wall_x = data->cur_pos->pos_x + data->perp_wall_dist * data->ray_dir->ray_dir_x;
	data->wall_x -= floor(data->wall_x);
	data->tex_x = (int)(data->wall_x * (double)TEX_W);
	if (data->side == false && data->ray_dir->ray_dir_x > 0)
		data->tex_x = TEX_W - data->tex_x - 1;
	else if (data->side == true && data->ray_dir->ray_dir_y < 0)
		data->tex_x = TEX_W - data->tex_x - 1;
	data->tex_step = 1.0 * TEX_H / data->line_height;
	data->tex_pos = (data->draw_start - SCREEN_H / 2 + data->line_height / 2) * data->tex_step;
}


void tex_dir(t_data *data)
{
	if (data->img->kind == DIR_N)
		data->texture->addr = mlx_get_data_addr(data->texture->tex_dir->north.texture_ptr, &data->texture->bits_per_pixel, &data->texture->size_line, &data->texture->endian);
	else if (data->img->kind == DIR_S)
		data->texture->addr = mlx_get_data_addr(data->texture->tex_dir->south.texture_ptr, &data->texture->bits_per_pixel, &data->texture->size_line, &data->texture->endian);
	else if (data->img->kind == DIR_E)
		data->texture->addr = mlx_get_data_addr(data->texture->tex_dir->east.texture_ptr, &data->texture->bits_per_pixel, &data->texture->size_line, &data->texture->endian);
	else if (data->img->kind == DIR_W)
		data->texture->addr = mlx_get_data_addr(data->texture->tex_dir->west.texture_ptr, &data->texture->bits_per_pixel, &data->texture->size_line, &data->texture->endian);
}

void tex_draw(t_data *data, int row)
{
	int	col;

	col = data->draw_start;
	while (col < data->draw_end)
	{
		data->tex_y = (int)data->tex_pos & (TEX_H - 1);
		data->color = *(unsigned int *)(data->texture->addr + data->tex_y * data->texture->size_line + data->tex_x * (data->texture->bits_per_pixel / 8));
		data->img->dst = data->img->addr + col * data->img->size_line + row * (data->img->bits_per_pixel / 8);
		*(unsigned int *)data->img->dst = data->color;
		data->tex_pos += data->tex_step;
		++col;
	}
}