/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:27:38 by snemoto           #+#    #+#             */
/*   Updated: 2023/10/23 18:29:15 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTER_H
# define RAYCASTER_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "minilibx-linux/mlx.h"

# define KEY_W 0x077
# define KEY_S 0x073
# define KEY_A 0x061
# define KEY_D 0x064
# define KEY_LEFT 0xFF51
# define KEY_RIGHT 0xFF53

# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define PURPLE 0xFF00FF

# define ANGLE 16

#define screenWidth 1280
#define screenHeight 960
#define mapWidth 24
#define mapHeight 24

/* ************************************************************************** */

typedef struct s_n_pos
{
	double	pos_x;
	double	pos_y;
}	t_n_pos;

typedef struct s_n_dir
{
	double	dir_x;
	double	dir_y;
}	t_n_dir;

typedef struct s_n_plane
{
	double	plane_x;
	double	plane_y;
}	t_n_plane;

typedef struct s_n_vars
{
	t_n_pos	*pos;
	t_n_dir	*dir;
	t_n_plane	*plane;
	void	*mlx;
	void	*win;
	void	*img;
}	t_n_vars;

/* ************************************************************************** */

#endif
