/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_draw_calc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:27:52 by snemoto           #+#    #+#             */
/*   Updated: 2023/11/19 18:54:42 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

void	calc_free(t_vars	*var)
{
	free(var->map);
	free(var->ray_dir);
	free(var->delta_dist);
	free(var->step);
	free(var->side_dist);
}

void	calc_init(t_vars	*var)
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

void	calc_side_dist(t_vars	*var)
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

void	calc_hit_wall(t_vars *var)
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
