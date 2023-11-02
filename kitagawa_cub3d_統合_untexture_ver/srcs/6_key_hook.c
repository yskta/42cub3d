/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_key_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 23:42:40 by yokitaga          #+#    #+#             */
/*   Updated: 2023/11/03 01:32:26 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	key_draw_clear(t_data *data)
{
	unsigned int	row;
	unsigned int	col;

	row = 0;
	while (row < screenWidth)
	{
		col = 0;
		while (col < screenHeight)
		{
			mlx_pixel_put(data->mlx, data->mlx_win, row, col, BLACK);
			++col;
		}
		++row;
	}
}

int	key_hook(int keycode, t_data *data)
{
	double	rot = M_PI / ANGLE;
	double	sign = 1;
	double	move = 1;
	double	angle_x = 1;
	double	angle_y = 1;
	double	old_dir_x = data->dir->dir_x;
	double	old_plane_x = data->plane->plane_x;

	printf("keycode: %d\n", keycode);
	if (keycode == KEY_W || keycode == KEY_S)
	{
		if (keycode == KEY_S)
			sign = -1;
		if (data->map_data.map[(int)(data->pos->pos_x + sign * data->dir->dir_x * move)][(int)data->pos->pos_y] == 0)
			data->pos->pos_x += sign * data->dir->dir_x * move;
		if (data->map_data.map[(int)data->pos->pos_x][(int)(data->pos->pos_y + sign * data->dir->dir_y * move)] == 0)
			data->pos->pos_y += sign * data->dir->dir_y * move;
	}
	else if (keycode == KEY_A || keycode == KEY_D)
	{
		angle_x = data->dir->dir_x * cos(M_PI / 2) - data->dir->dir_y * sin(M_PI / 2);
		angle_y = old_dir_x * sin(M_PI / 2) + data->dir->dir_y * cos(M_PI / 2);
		if (keycode == KEY_D)
			sign = -1;
		if (data->map_data.map[(int)(data->pos->pos_x + angle_x * sign * move)][(int)data->pos->pos_y] == 0)
			data->pos->pos_x += angle_x * sign * move;
		if (data->map_data.map[(int)data->pos->pos_x][(int)(data->pos->pos_y + angle_y * sign * move)] == 0)
			data->pos->pos_y += angle_y * sign * move;
	}
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
	{
		if (keycode == KEY_RIGHT)
			rot *= -1;
		data->dir->dir_x = data->dir->dir_x * cos(rot) - data->dir->dir_y * sin(rot);
		data->dir->dir_y = old_dir_x * sin(rot) + data->dir->dir_y * cos(rot);
		data->plane->plane_x = data->plane->plane_x * cos(rot) - data->plane->plane_y * sin(rot);
		data->plane->plane_y = old_plane_x * sin(rot) + data->plane->plane_y * cos(rot);
	}
	else
		return (0);
	key_draw_clear(data);
	return (0);
}
