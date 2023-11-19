/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_draw_tex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:27:52 by snemoto           #+#    #+#             */
/*   Updated: 2023/11/19 18:57:30 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

void tex_init(t_vars *var)
{
	var->line_height = (int)(SCREEN_H / var->perp_wall_dist);
	var->draw_start = -1 * var->line_height / 2 + SCREEN_H / 2;
	if (var->draw_start < 0)
		var->draw_start = 0;
	var->draw_end = var->line_height / 2 + SCREEN_H / 2;
	if (var->draw_end >= SCREEN_H)
		var->draw_end = SCREEN_H - 1;
	if (var->side == false)
		var->wall_x = var->pos->pos_y + var->perp_wall_dist * var->ray_dir->ray_dir_y;
	else
		var->wall_x = var->pos->pos_x + var->perp_wall_dist * var->ray_dir->ray_dir_x;
	var->wall_x -= floor(var->wall_x);
	var->tex_x = (int)(var->wall_x * (double)TEX_W);
	if (var->side == false && var->ray_dir->ray_dir_x > 0)
		var->tex_x = TEX_W - var->tex_x - 1;
	else if (var->side == true && var->ray_dir->ray_dir_y < 0)
		var->tex_x = TEX_W - var->tex_x - 1;
	var->tex_step = 1.0 * TEX_H / var->line_height;
	var->tex_pos = (var->draw_start - SCREEN_H / 2 + var->line_height / 2) * var->tex_step;
}


void tex_dir(t_vars *var)
{
	if (var->img->kind == DIR_N)
		var->texture->addr = mlx_get_data_addr(var->texture->tex_dir->n, &var->texture->bits_per_pixel, &var->texture->size_line, &var->texture->endian);
	else if (var->img->kind == DIR_S)
		var->texture->addr = mlx_get_data_addr(var->texture->tex_dir->s, &var->texture->bits_per_pixel, &var->texture->size_line, &var->texture->endian);
	else if (var->img->kind == DIR_E)
		var->texture->addr = mlx_get_data_addr(var->texture->tex_dir->e, &var->texture->bits_per_pixel, &var->texture->size_line, &var->texture->endian);
	else if (var->img->kind == DIR_W)
		var->texture->addr = mlx_get_data_addr(var->texture->tex_dir->w, &var->texture->bits_per_pixel, &var->texture->size_line, &var->texture->endian);
}

void tex_draw(t_vars *var, int row)
{
	int	col;

	col = var->draw_start;
	while (col < var->draw_end)
	{
		var->tex_y = (int)var->tex_pos & (TEX_H - 1);
		var->color = *(unsigned int *)(var->texture->addr + var->tex_y * var->texture->size_line + var->tex_x * (var->texture->bits_per_pixel / 8));
		var->img->dst = var->img->addr + col * var->img->size_line + row * (var->img->bits_per_pixel / 8);
		*(unsigned int *)var->img->dst = var->color;
		var->tex_pos += var->tex_step;
		++col;
	}
}
