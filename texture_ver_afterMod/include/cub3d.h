/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:58:57 by yokitaga          #+#    #+#             */
/*   Updated: 2023/11/24 15:36:37 by yokitaga         ###   ########.fr       */
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

# define KEY_W 0x077
# define KEY_S 0x073
# define KEY_A 0x061
# define KEY_D 0x064
# define KEY_LEFT		0xff51
//# define KEY_UP			0xff52
# define KEY_RIGHT		0xff53
//# define KEY_DOWN		0xff54
# define KEY_ESC		0xff1b

# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define PURPLE 0xFF00FF

# define SCREEN_W 1280
# define SCREEN_H 960

# define ANGLE 16

# define TEX_W 64 // 1280 = 64 * 20
# define TEX_H 64 // 960 = 64 * 15

typedef struct s_cur_pos
{
	double	pos_x;
	double	pos_y;
}	t_cur_pos;

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

typedef struct s_box_pos_for_calc
{
	int	map_x;
	int	map_y;
}	t_box_pos_for_calc;

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

typedef struct s_map{
	char	**read_data; //mallocする
	char	**map; //mallocする
	ssize_t	fd;
	size_t 	read_data_height;
	size_t	map_height;
}t_map;

typedef struct s_each_texture{
	void	*texture_ptr;
	int		x;
	int		y;
}t_each_texture;

typedef enum e_kind_dir
{
	DIR_N,
	DIR_S,
	DIR_E,
	DIR_W,
}	t_kind_dir;

typedef struct s_tex_dir
{
	t_each_texture	north;
	t_each_texture	south;
	t_each_texture	east;
	t_each_texture	west;
}	t_tex_dir;

typedef struct s_tex
{
	t_tex_dir	*tex_dir;//mallocする
	char		*addr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
}	t_tex;

typedef struct s_img
{
	void		*img;
	char		*addr;
	char		*dst;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	t_kind_dir	kind;
}	t_img;

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
	char					*north_path;//mallocする@3_2_parse_read_data
	char					*south_path;//mallocする@3_2_parse_read_data
	char					*west_path;//mallocする@3_2_parse_read_data
	char					*east_path;//mallocする@3_2_parse_read_data
	//nemotoさん分追加ここから
	t_cur_pos				*cur_pos;//4_2_init_other_data.cで初期化。free_pos_dir_plane関数でfreeする
	t_dir					*dir;//4_2_init_other_data.cで初期化。free_pos_dir_plane関数でfreeする
	t_plane					*plane;//4_2_init_other_data.cで初期化。free_pos_dir_plane関数でfreeする
	t_step					*step;//calc_one関数で初期化。描画する毎回mallocするので毎回freeする必要あり。
	t_side_dist				*side_dist;//calc_one関数で初期化。描画する毎回mallocするので毎回freeする必要あり
	t_delta_dist			*delta_dist;//calc_one関数で初期化。描画する毎回mallocするので毎回freeする必要あり
	t_ray_dir				*ray_dir;//calc_one関数で初期化。描画する毎回mallocするので毎回freeする必要あり
	t_box_pos_for_calc		*box_pos;//calc_one関数で初期化。描画する毎回mallocするので毎回freeする必要あり
	double					camera_x;
	double					perp_wall_dist;
	bool					hit;//calc_one関数で初期化
	bool					side;//calc_one関数で初期化
	int						line_height;
	int						draw_start;
	int						draw_end;
	int						color;
	//teture関連
	t_tex					*texture;//mallocする@4_1
	t_img					*img;
	double					wall_x;
	int						tex_x;
	int						tex_y;
	int						old_tex_x;
	double					tex_step;
	double					tex_pos;
	//天井,床関連
	t_floor_or_ceiling		floor;
	t_floor_or_ceiling		ceiling;
	// int						color_c;
	// int						color_f;
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
bool		init_pos_dir_plane(t_data *data);

int			key_draw(t_data *data);

void		calc_free(t_data	*data);
void		calc_init(t_data	*data);
void		calc_side_dist(t_data	*data);
void		calc_hit_wall(t_data *data);

void 		tex_init(t_data *data);
void 		tex_dir(t_data *data);
void 		tex_draw(t_data *data, int row);

int			key_hook(int keycode, t_data *data);

int			close_program(t_data *data);

void		free_two_dimensional_array(char **array);
void		free_map_data_and_texture(t_data *data);
void		destroy_textures(t_data *data);
void		free_pos_dir_plane(t_data *data);
void		free_and_destroy_all(t_data *data);

void		put_error_and_exit(char *str, t_data *data);

#endif