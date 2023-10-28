/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:58:57 by yokitaga          #+#    #+#             */
/*   Updated: 2023/10/28 17:54:23 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <stdbool.h>
# include <math.h>
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysymdef.h>

# define NO "NO"
# define SO "SO"
# define WE "WE"
# define EA "EA"
# define F "F"
# define C "C"

# define TXT_HEIGHT		50
# define TXT_WIDTH		50

//壁関係は変更する可能性あり
# define WALL 10

# define WINH WALL * 1
# define WINW WINH * 1

# define KEY_LEFT		0xff51 
# define KEY_UP			0xff52  
# define KEY_RIGHT		0xff53  
# define KEY_DOWN		0xff54
# define KEY_ESC		0xff1b

# define KEY_A 97
# define KEY_D 100
# define KEY_S 115
# define KEY_W 119

//nemotoさん分追加ここから
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

// typedef struct	s_map
// {
// 	int	map_x;
// 	int	map_y;
// }	t_map;

typedef struct	s_delta_dist
{
	double	delta_dist_x;
	double	delta_dist_y;
}	t_delta_dist;

typedef struct	s_ray_dir
{
	double	ray_dir_x;
	double	ray_dir_y;
}	t_ray_dir;
//ここまで

typedef struct s_map{
	char	**read_data; //mallocする
	char	**map; //mallocする
	ssize_t	fd;
	size_t 	read_data_height;
	size_t	map_height;
}t_map;

typedef struct s_texture{
	char	*path;//東西南北それぞれmallocする
	void	*texture_ptr;
	int		x;
	int		y;
}t_texture;

typedef struct s_floor_or_ceiling{
	char	*before_split;
	char	**after_split;
	int		r;
	int		g;
	int		b;
}t_floor_or_ceiling;

typedef struct s_data{
	void					*mlx;
	void					*mlx_win;
	bool					judge_valid_map;
	t_map					map_data;
	t_texture				north;
	t_texture				south;
	t_texture				west;
	t_texture				east;
	t_floor_or_ceiling		floor;
	t_floor_or_ceiling		ceiling;
	//nemotoさん分追加ここから
	// t_pos					*pos;
	// t_dir					*dir;
	// t_plane					*plane;
	// t_step					*step;
	// t_side_dist				*side_dist;
	// t_delta_dist			*delta_dist;
	// t_ray_dir				*ray_dir;
	//ここまで
}t_data;//mallocする

bool		check_arg(int argc, char **argv);

bool		read_map(char *argv, t_data *data);
bool		parse_all_identifier(t_data *data);
bool		parse_map(t_data *data);
bool		parse_read_data(t_data *data);

bool		juduge_identifer(char *str);
bool		parse_texture(t_data *data, size_t i, size_t j);
bool		parse_floor_or_ceiling(t_data *data, size_t i, size_t j);
bool		parse_each_identifier(t_data *data, size_t i, size_t j);

bool 		check_valid_map(t_data *data);
void		convert_space_to_X(char **map);

bool		init_other_data(t_data *data);
bool		init_mlx(t_data *data);
bool		init_texture(t_data *data);

int			close_program(t_data *data);

void		free_two_dimensional_array(char **array);
void		free_map_data_and_texture(t_data *data);
void		destroy_textures(t_data *data);
void		free_and_destroy_all(t_data *data);

void		put_error_and_exit(char *str, t_data *data);

#endif