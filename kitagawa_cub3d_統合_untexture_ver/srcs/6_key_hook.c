/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_key_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 23:42:40 by yokitaga          #+#    #+#             */
/*   Updated: 2023/10/28 19:30:36 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

//一旦コピーしただけ
static void	key_draw_clear(t_vars *var)
{
	unsigned int	row;
	unsigned int	col;

	row = 0;
	while (row < screenWidth)
	{
		col = 0;
		while (col < screenHeight)
		{
			mlx_pixel_put(var->mlx, var->win, row, col, BLACK);
			++col;
		}
		++row;
	}
}

int	key_hook(int keycode, t_vars *var)
{
	double	rot = M_PI / ANGLE;
	double	sign = 1;
	double	move = 1;
	double	angle_x = 1;
	double	angle_y = 1;
	double	old_dir_x = var->dir->dir_x;
	double	old_plane_x = var->plane->plane_x;

	if (keycode == KEY_W || keycode == KEY_S)
	{
		if (keycode == KEY_S)
			sign = -1;
		if (map[(int)(var->pos->pos_x + sign * var->dir->dir_x * move)][(int)var->pos->pos_y] == 0)
			var->pos->pos_x += sign * var->dir->dir_x * move;
		if (map[(int)var->pos->pos_x][(int)(var->pos->pos_y + sign * var->dir->dir_y * move)] == 0)
			var->pos->pos_y += sign * var->dir->dir_y * move;
	}
	else if (keycode == KEY_A || keycode == KEY_D)
	{
		angle_x = var->dir->dir_x * cos(M_PI / 2) - var->dir->dir_y * sin(M_PI / 2);
		angle_y = old_dir_x * sin(M_PI / 2) + var->dir->dir_y * cos(M_PI / 2);
		if (keycode == KEY_D)
			sign = -1;
		if (map[(int)(var->pos->pos_x + angle_x * sign * move)][(int)var->pos->pos_y] == 0)
			var->pos->pos_x += angle_x * sign * move;
		if (map[(int)var->pos->pos_x][(int)(var->pos->pos_y + angle_y * sign * move)] == 0)
			var->pos->pos_y += angle_y * sign * move;
	}
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
	{
		if (keycode == KEY_RIGHT)
			rot *= -1;
		var->dir->dir_x = var->dir->dir_x * cos(rot) - var->dir->dir_y * sin(rot);
		var->dir->dir_y = old_dir_x * sin(rot) + var->dir->dir_y * cos(rot);
		var->plane->plane_x = var->plane->plane_x * cos(rot) - var->plane->plane_y * sin(rot);
		var->plane->plane_y = old_plane_x * sin(rot) + var->plane->plane_y * cos(rot);
	}
	else
		return (0);
	key_draw_clear(var);
	return (0);
}
