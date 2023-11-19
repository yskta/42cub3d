/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_draw.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:27:52 by snemoto           #+#    #+#             */
/*   Updated: 2023/11/19 18:51:31 by snemoto          ###   ########.fr       */
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

static	void	calc_free(t_vars	*var)
{
	free(var->map);
	free(var->ray_dir);
	free(var->delta_dist);
	free(var->step);
	free(var->side_dist);
}

static	void	calc_init(t_vars	*var)
{
	var->hit = false;
	var->side = false;
	var->map = (t_map *)malloc(sizeof(t_map));
	var->map->map_x = (int)var->pos->pos_x;
	var->map->map_y = (int)var->pos->pos_y;
	var->ray_dir = (t_ray_dir *)malloc(sizeof(t_ray_dir));
	var->ray_dir->ray_dir_x = var->dir->dir_x + var->plane->plane_x * var->camera_x;
	var->ray_dir->ray_dir_y = var->dir->dir_y + var->plane->plane_y * var->camera_x;
	var->delta_dist = (t_delta_dist *)malloc(sizeof(t_delta_dist));
	if (var->ray_dir->ray_dir_x == 0)
		var->delta_dist->delta_dist_x = 1e30;
	else
		var->delta_dist->delta_dist_x = fabs(1 / var->ray_dir->ray_dir_x);
	if (var->ray_dir->ray_dir_y == 0)
		var->delta_dist->delta_dist_y = 1e30;
	else
		var->delta_dist->delta_dist_y = fabs(1 / var->ray_dir->ray_dir_y);
	var->step = (t_step *)malloc(sizeof(t_step));
	var->side_dist = (t_side_dist *)malloc(sizeof(t_side_dist));
}

static	void	calc_side_dist(t_vars	*var)
{
	if (var->ray_dir->ray_dir_x < 0)
	{
		var->step->step_x = -1;
		var->side_dist->side_dist_x = (var->pos->pos_x - var->map->map_x) * var->delta_dist->delta_dist_x;
	}
	else
	{
		var->step->step_x = 1;
		var->side_dist->side_dist_x = (var->map->map_x + 1.0 - var->pos->pos_x) * var->delta_dist->delta_dist_x;
	}
	if (var->ray_dir->ray_dir_y < 0)
	{
		var->step->step_y = -1;
		var->side_dist->side_dist_y = (var->pos->pos_y - var->map->map_y) * var->delta_dist->delta_dist_y;
	}
	else
	{
		var->step->step_y = 1;
		var->side_dist->side_dist_y = (var->map->map_y + 1.0 - var->pos->pos_y) * var->delta_dist->delta_dist_y;
	}
}

static	void	calc_hit_wall(t_vars *var)
{
	while (var->hit == false)
	{
		if (var->side_dist->side_dist_x < var->side_dist->side_dist_y)
		{
			var->side_dist->side_dist_x += var->delta_dist->delta_dist_x;
			var->map->map_x += var->step->step_x;
			var->side = false;
			if (var->ray_dir->ray_dir_y < 0)
				var->img->kind = DIR_S;
			else
				var->img->kind = DIR_N;
		}
		else
		{
			var->side_dist->side_dist_y += var->delta_dist->delta_dist_y;
			var->map->map_y += var->step->step_y;
			var->side = true;
			if (var->ray_dir->ray_dir_x < 0)
				var->img->kind = DIR_W;
			else
				var->img->kind = DIR_E;
		}
		if (map[var->map->map_x][var->map->map_y] != 0)
			var->hit = true;
	}
	if (var->side == false)
		var->perp_wall_dist = var->side_dist->side_dist_x - var->delta_dist->delta_dist_x;
	else
		var->perp_wall_dist = var->side_dist->side_dist_y - var->delta_dist->delta_dist_y;
}

static	void tex_init(t_vars *var)
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


static	void tex_dir(t_vars *var)
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

static	void tex_draw(t_vars *var, int row)
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
