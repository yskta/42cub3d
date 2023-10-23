/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:27:52 by snemoto           #+#    #+#             */
/*   Updated: 2023/10/23 18:27:29 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

int map[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

static void	key_draw_clear(t_n_vars *var)
{
	unsigned int	row;
	unsigned int	col;

	row = 0;
	col = 0;
	while (row++ < screenWidth)
	{
		col = 0;
		while (col++ < screenWidth)
			mlx_pixel_put(var->mlx, var->win, row, col, BLACK);			
	}
}

static int	n_key_hook(int keycode, t_n_vars *var)
{
	double	sign = 1;
	double	angle_x = 1;
	double	angle_y = 1;
	double	move = 1;
	double	rot = M_PI / ANGLE;
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
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
	{
		if (keycode == KEY_RIGHT)
			rot *= -1;
		var->dir->dir_x = var->dir->dir_x * cos(rot) - var->dir->dir_y * sin(rot);
		var->dir->dir_y = old_dir_x * sin(rot) + var->dir->dir_y * cos(rot);
		var->plane->plane_x = var->plane->plane_x * cos(rot) - var->plane->plane_y * sin(rot);
		var->plane->plane_y = old_plane_x * sin(rot) + var->plane->plane_y * cos(rot);
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
	else
		return (0);
	key_draw_clear(var);
	return (0);
}

static int	n_key_draw(t_n_vars *var)
{
	int	x = 0;
	while (x < screenWidth)
	{
		double camera_x = 2 * x / (double)screenWidth - 1;
		double ray_dir_x = var->dir->dir_x + var->plane->plane_x * camera_x;
		double ray_dir_y = var->dir->dir_y + var->plane->plane_y * camera_x;
		int		map_x = (int)var->pos->pos_x;
		int		map_y = (int)var->pos->pos_y;
		double	delta_dist_x = (ray_dir_x == 0) ? 1e30 : fabs(1 / ray_dir_x);
		double	delta_dist_y = (ray_dir_y == 0) ? 1e30 : fabs(1 / ray_dir_y);

		int		step_x;
		int		step_y;
		double	side_dist_x;
		double	side_dist_y;
		if (ray_dir_x < 0)
		{
			step_x = -1;
			side_dist_x = (var->pos->pos_x - map_x) * delta_dist_x;
		}
		else
		{
			step_x = 1;
			side_dist_x = (map_x + 1.0 - var->pos->pos_x) * delta_dist_x;
		}
		if (ray_dir_y < 0)
		{
			step_y = -1;
			side_dist_y = (var->pos->pos_y - map_y) * delta_dist_y;
		}
		else
		{
			step_y = 1;
			side_dist_y = (map_y + 1.0 - var->pos->pos_y) * delta_dist_y;
		}

		int		hit = 0;
		int		side;
		while (hit == 0)
		{
			if (side_dist_x < side_dist_y)
			{
				side_dist_x += delta_dist_x;
				map_x += step_x;
				side = 0;
			}
			else
			{
				side_dist_y += delta_dist_y;
				map_y += step_y;
				side = 1;
			}
			if (map[map_x][map_y] > 0)
				hit = 1;
		}
		
		double	perp_wall_dist;
		if (side == 0)
			perp_wall_dist = side_dist_x - delta_dist_x;
		else
			perp_wall_dist = side_dist_y - delta_dist_y;
		
		int	line_height = (int)(screenHeight / perp_wall_dist);
		int	draw_start = -line_height / 2 + screenHeight / 2;
		if (draw_start < 0)
			draw_start = 0;
		int	draw_end = line_height / 2 + screenHeight / 2;
		if (draw_end >= screenHeight)
			draw_end = screenHeight - 1;

		int	color;
		switch (map[map_x][map_y])
		{
			case 1: color = RED; break ;
			case 2: color = GREEN; break ;
			case 3: color = BLUE; break ;
			case 4: color = WHITE; break ;
			default: color = PURPLE; break ;
		}
		if (side == 1)
			color /= 2;

		int	col = draw_start;
		while (col < draw_end)
			mlx_pixel_put(var->mlx, var->win, x, col++, color);
		x++;
	}
	return (0);
}

int	main(void)
{
	t_n_vars	var;

	var.pos = (t_n_pos *)malloc(sizeof(t_n_pos));
	var.pos->pos_x = 22;
	var.pos->pos_y = 12;

	var.dir = (t_n_dir *)malloc(sizeof(t_n_dir));
	var.dir->dir_x = -1;
	var.dir->dir_y = 0;

	var.plane = (t_n_plane *)malloc(sizeof(t_n_plane));
	var.plane->plane_x = 0;
	var.plane->plane_y = 0.66;

	var.mlx = mlx_init();
	var.win = mlx_new_window(var.mlx, screenWidth, screenHeight, "rc");
	mlx_key_hook(var.win, n_key_hook, &var);
	mlx_loop_hook(var.mlx, n_key_draw, &var);
	mlx_loop(var.mlx);

	return (0);
}
