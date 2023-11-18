/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_key_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 23:41:22 by yokitaga          #+#    #+#             */
/*   Updated: 2023/11/11 19:52:39 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static	void	calc_one(t_data *data)
{
	data->hit = false;
	data->side = false;
	data->map_pos = (t_map_pos *)malloc(sizeof(t_map_pos));
	data->map_pos->map_x = (int)data->pos->pos_x;
	data->map_pos->map_y = (int)data->pos->pos_y;
	data->ray_dir = (t_ray_dir *)malloc(sizeof(t_ray_dir));
	data->ray_dir->ray_dir_x = data->dir->dir_x + data->plane->plane_x * data->camera_x;
	data->ray_dir->ray_dir_y = data->dir->dir_y + data->plane->plane_y * data->camera_x;
	data->delta_dist = (t_delta_dist *)malloc(sizeof(t_delta_dist));
	if (data->ray_dir->ray_dir_x == 0)
		data->delta_dist->delta_dist_x = 1e30;
	else
		data->delta_dist->delta_dist_x = fabs(1 / data->ray_dir->ray_dir_x);
	if (data->ray_dir->ray_dir_y == 0)
		data->delta_dist->delta_dist_y = 1e30;
	else
		data->delta_dist->delta_dist_y = fabs(1 / data->ray_dir->ray_dir_y);
}

static	void	calc_two(t_data *data)
{
	data->step = (t_step *)malloc(sizeof(t_step));
	data->side_dist = (t_side_dist *)malloc(sizeof(t_side_dist));
	if (data->ray_dir->ray_dir_x < 0)
	{
		data->step->step_x = -1;
		data->side_dist->side_dist_x = (data->pos->pos_x - data->map_pos->map_x) * data->delta_dist->delta_dist_x;
	}
	else
	{
		data->step->step_x = 1;
		data->side_dist->side_dist_x = (data->map_pos->map_x + 1.0 - data->pos->pos_x) * data->delta_dist->delta_dist_x;
	}
	if (data->ray_dir->ray_dir_y < 0)
	{
		data->step->step_y = -1;
		data->side_dist->side_dist_y = (data->pos->pos_y - data->map_pos->map_y) * data->delta_dist->delta_dist_y;
	}
	else
	{
		data->step->step_y = 1;
		data->side_dist->side_dist_y = (data->map_pos->map_y + 1.0 - data->pos->pos_y) * data->delta_dist->delta_dist_y;
	}
}

static	void	calc_three(t_data *data)
{
	while (data->hit == false)
	{
		if (data->side_dist->side_dist_x < data->side_dist->side_dist_y)
		{
			data->side_dist->side_dist_x += data->delta_dist->delta_dist_x;
			data->map_pos->map_x += data->step->step_x;
			data->side = false;
		}
		else
		{
			data->side_dist->side_dist_y += data->delta_dist->delta_dist_y;
			data->map_pos->map_y += data->step->step_y;
			data->side = true;
		}
		if (data->map_data.map[data->map_pos->map_x][data->map_pos->map_y] > 0)
			data->hit = true;
	}
	if (data->side == false)
		data->perp_wall_dist = data->side_dist->side_dist_x - data->delta_dist->delta_dist_x;
	else
		data->perp_wall_dist = data->side_dist->side_dist_y - data->delta_dist->delta_dist_y;
	data->line_height = (int)(screenHeight / data->perp_wall_dist);
}

static void	draw_init(t_data *data)
{
	data->draw_start = -1 * data->line_height / 2 + screenHeight / 2;
	if (data->draw_start < 0)
		data->draw_start = 0;
	data->draw_end = data->line_height / 2 + screenHeight / 2;
	if (data->draw_end >= screenHeight)
		data->draw_end = screenHeight - 1;
	// need change switch statement
	switch (data->map_data.map[data->map_pos->map_x][data->map_pos->map_y])
	{
		case 1: data->color = RED; break ;
		case 2: data->color = GREEN; break ;
		case 3: data->color = BLUE; break ;
		case 4: data->color = WHITE; break ;
		default: data->color = PURPLE; break ;
	}
	if (data->side == true)
		data->color /= 2;
}

int	key_draw(t_data *data)
{
	unsigned int	row;
	unsigned int	col;

	row = 0;
	printf("key_draw\n");
	while (row < (unsigned int)screenWidth)
	{
		data->camera_x = 2 * row / (double)screenWidth - 1;
		calc_one(data);
		calc_two(data);
		calc_three(data);
		draw_init(data);
		col = data->draw_start;
		while (col < (unsigned int)data->draw_end)
		{
			mlx_pixel_put(data->mlx, data->mlx_win, row, col, data->color);
			++col;
		}
		++row;
	}
	return (0);
}