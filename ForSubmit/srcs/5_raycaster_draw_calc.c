/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_raycaster_draw_calc.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 00:17:30 by yokitaga          #+#    #+#             */
/*   Updated: 2023/11/26 14:06:04 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	calc_free(t_data *data)
{
	free(data->box_pos);
	free(data->ray_dir);
	free(data->delta_dist);
	free(data->step);
	free(data->side_dist);
}

bool	calc_init(t_data	*data)
{
	data->hit = false;
	data->side = false;
	data->box_pos = (t_box_pos_for_calc *)malloc(sizeof(t_box_pos_for_calc));
	data->box_pos->x = (int)data->cur_pos->x;
	data->box_pos->y = (int)data->cur_pos->y;
	data->ray_dir = (t_ray_dir *)malloc(sizeof(t_ray_dir));
	data->ray_dir->x = data->dir->x + data->plane->x * data->camera_x;
	data->ray_dir->y = data->dir->y + data->plane->y * data->camera_x;
	data->delta_dist = (t_delta_dist *)malloc(sizeof(t_delta_dist));
	if (data->ray_dir->x == 0)
		data->delta_dist->x = 1e30;
	else
		data->delta_dist->x = fabs(1.0 / data->ray_dir->x);
	if (data->ray_dir->y == 0)
		data->delta_dist->y = 1e30;
	else
		data->delta_dist->y = fabs(1.0 / data->ray_dir->y);
	data->step = (t_step *)malloc(sizeof(t_step));
	data->side_dist = (t_side_dist *)malloc(sizeof(t_side_dist));
	if (data->box_pos == NULL || data->ray_dir == NULL || data->delta_dist \
		== NULL || data->step == NULL || data->side_dist == NULL)
		return (false);
	return (true);
}

void	calc_side_dist(t_data	*data)
{
	if (data->ray_dir->x < 0)
	{
		data->step->x = -1;
		data->side_dist->x = (data->cur_pos->x - data->box_pos->x) \
			* data->delta_dist->x;
	}
	else
	{
		data->step->x = 1;
		data->side_dist->x = (data->box_pos->x + 1.0 - data->cur_pos->x) \
			* data->delta_dist->x;
	}
	if (data->ray_dir->y < 0)
	{
		data->step->y = -1;
		data->side_dist->y = (data->cur_pos->y - data->box_pos->y) \
			* data->delta_dist->y;
	}
	else
	{
		data->step->y = 1;
		data->side_dist->y = (data->box_pos->y + 1.0 - data->cur_pos->y) \
			* data->delta_dist->y;
	}
}

void	calc_hit_wall(t_data *data)
{
	while (data->hit == false)
	{
		if (data->side_dist->x < data->side_dist->y)
		{
			data->side_dist->x += data->delta_dist->x;
			data->box_pos->x += data->step->x;
			data->side = false;
		}
		else
		{
			data->side_dist->y += data->delta_dist->y;
			data->box_pos->y += data->step->y;
			data->side = true;
		}
		if (data->map_data.map[data->box_pos->x][data->box_pos->y] != '0')
			data->hit = true;
	}
	if (data->side == false)
		data->perp_wall_dist = data->side_dist->x - data->delta_dist->x + 0.01;
	else
		data->perp_wall_dist = data->side_dist->y - data->delta_dist->y + 0.01;
}
