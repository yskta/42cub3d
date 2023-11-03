/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:27:38 by snemoto           #+#    #+#             */
/*   Updated: 2023/11/04 08:16:53 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTER_H
# define RAYCASTER_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <stdbool.h>
# include "minilibx-linux/mlx.h"

# define KEY_W 0x077
# define KEY_S 0x073
# define KEY_A 0x061
# define KEY_D 0x064
# define KEY_LEFT 0xFF51
# define KEY_RIGHT 0xFF53

# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define PURPLE 0xFF00FF

# define SCREEN_W 1280
# define SCREEN_H 960
# define MAP_W 24
# define MAP_H 24

# define ANGLE 16

/* ************************************************************************** */

extern int	map[MAP_W][MAP_H];

/* ************************************************************************** */

typedef struct s_pos
{
	double	pos_x;
	double	pos_y;
}	t_pos;

typedef struct s_dir
{
	double	dir_x;
	double	dir_y;
}	t_dir;

typedef struct s_plane
{
	double	plane_x;
	double	plane_y;
}	t_plane;

typedef struct s_step
{
	int	step_x;
	int	step_y;
}	t_step;

typedef struct s_side_dist
{
	double	side_dist_x;
	double	side_dist_y;
}	t_side_dist;

typedef struct s_map
{
	int	map_x;
	int	map_y;
}	t_map;

typedef struct s_delta_dist
{
	double	delta_dist_x;
	double	delta_dist_y;
}	t_delta_dist;

typedef struct s_ray_dir
{
	double	ray_dir_x;
	double	ray_dir_y;
}	t_ray_dir;

typedef struct s_vars
{
	t_pos			*pos;
	t_dir			*dir;
	t_plane			*plane;
	t_step			*step;
	t_side_dist		*side_dist;
	t_delta_dist	*delta_dist;
	t_ray_dir		*ray_dir;
	t_map			*map;
	double			camera_x;
	double			perp_wall_dist;
	bool			hit;
	bool			side;
	int				line_height;
	int				draw_start;
	int				draw_end;
	int				color;
	void			*mlx;
	void			*win;
	void			*img;
}	t_vars;

/* ************************************************************************** */

int	key_draw(t_vars *var);
int	key_hook(int keycode, t_vars *var);

#endif
