/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_draw.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:27:52 by snemoto           #+#    #+#             */
/*   Updated: 2023/11/04 08:15:11 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

static	void	calc_one(t_vars	*var)
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

static	void	calc_two(t_vars	*var)
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

static	void	calc_three(t_vars *var)
{
	while (var->hit == false)
	{
		if (var->side_dist->side_dist_x < var->side_dist->side_dist_y)
		{
			var->side_dist->side_dist_x += var->delta_dist->delta_dist_x;
			var->map->map_x += var->step->step_x;
			var->side = false;
		}
		else
		{
			var->side_dist->side_dist_y += var->delta_dist->delta_dist_y;
			var->map->map_y += var->step->step_y;
			var->side = true;
		}
		if (map[var->map->map_x][var->map->map_y] > 0)
			var->hit = true;
	}
	if (var->side == false)
		var->perp_wall_dist = var->side_dist->side_dist_x - var->delta_dist->delta_dist_x;
	else
		var->perp_wall_dist = var->side_dist->side_dist_y - var->delta_dist->delta_dist_y;
}

static void	draw_init(t_vars *var)
{
	var->line_height = (int)(SCREEN_H / var->perp_wall_dist);
	var->draw_start = -1 * var->line_height / 2 + SCREEN_H / 2;
	if (var->draw_start < 0)
		var->draw_start = 0;
	var->draw_end = var->line_height / 2 + SCREEN_H / 2;
	if (var->draw_end >= SCREEN_H)
		var->draw_end = SCREEN_H - 1;
	var->color = BLUE;
	if (map[var->map->map_x][var->map->map_y])
		var->color = RED;
	if (var->side == true)
		var->color /= 3;
}

int	key_draw(t_vars *var)
{
	unsigned int	row;
	unsigned int	col;

	row = 0;
	while (row < (unsigned int)SCREEN_W)
	{
		var->camera_x = 2 * row / (double)SCREEN_W - 1;
		calc_one(var);
		calc_two(var);
		calc_three(var);
		draw_init(var);
		col = var->draw_start;
		while (col < (unsigned int)var->draw_end)
		{
			mlx_pixel_put(var->mlx, var->win, row, col, var->color);
			++col;
		}
		++row;
	}
	return (0);
}
