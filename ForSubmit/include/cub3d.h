/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:58:57 by yokitaga          #+#    #+#             */
/*   Updated: 2023/12/03 17:07:40 by yokitaga         ###   ########.fr       */
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

# define KEY_W 0x077
# define KEY_S 0x073
# define KEY_A 0x061
# define KEY_D 0x064
# define KEY_LEFT		0xff51
# define KEY_RIGHT		0xff53
# define KEY_ESC		0xff1b

# define BLACK 0x000000

# define SCREEN_W 1280
# define SCREEN_H 960

# define TEX_W 64
# define TEX_H 64

typedef struct s_cur_pos
{
	double	x;
	double	y;
}	t_cur_pos;

typedef struct s_dir
{
	double	x;
	double	y;
}	t_dir;

typedef struct s_plane
{
	double	x;
	double	y;
}	t_plane;

typedef struct s_box_pos_for_calc
{
	int	x;
	int	y;
}	t_box_pos_for_calc;

typedef struct s_step
{
	int	x;
	int	y;
}	t_step;

typedef struct s_side_dist
{
	double	x;
	double	y;
}	t_side_dist;

typedef struct s_delta_dist
{
	double	x;
	double	y;
}	t_delta_dist;

typedef struct s_ray_dir
{
	double	x;
	double	y;
}	t_ray_dir;

typedef struct s_map{
	char	**read_data;
	char	**map;
	ssize_t	fd;
	size_t	read_data_height;
	size_t	map_height;
}	t_map;

typedef struct s_each_texture{
	void	*tex_ptr;
	int		x;
	int		y;
}	t_each_texture;

typedef struct s_tex_dir
{
	t_each_texture	north;
	t_each_texture	south;
	t_each_texture	east;
	t_each_texture	west;
}	t_tex_dir;

typedef struct s_tex
{
	t_tex_dir	*tex_dir;
	char		*addr;
	int			bits;
	int			size;
	int			endian;
}	t_tex;

typedef enum e_kind_dir
{
	DIR_N,
	DIR_S,
	DIR_E,
	DIR_W,
}	t_kind_dir;

typedef struct s_img
{
	void		*img;
	char		*addr;
	char		*dst;
	int			bits;
	int			size;
	int			endian;
	t_kind_dir	kind;
}	t_img;

typedef struct s_floor_or_ceiling{
	char	*before_split;
	char	**after_split;
	int		r;
	int		g;
	int		b;
	int		color;
	bool	done_flag;
}	t_floor_or_ceiling;

typedef struct s_data{
	void					*mlx;
	void					*mlx_win;
	bool					judge_valid_map;
	t_map					map_data;
	char					*north_path;
	char					*south_path;
	char					*west_path;
	char					*east_path;
	t_cur_pos				*cur_pos;
	t_dir					*dir;
	t_plane					*plane;
	t_step					*step;
	t_side_dist				*side_dist;
	t_delta_dist			*delta_dist;
	t_ray_dir				*ray_dir;
	t_box_pos_for_calc		*box_pos;
	double					camera_x;
	double					perp_wall_dist;
	bool					hit;
	bool					side;
	int						line_height;
	int						draw_start;
	int						draw_end;
	int						color;
	t_tex					*tex;
	t_img					*img;
	double					wall_x;
	int						tex_x;
	int						tex_y;
	double					tex_step;
	double					tex_pos;
	t_floor_or_ceiling		floor;
	t_floor_or_ceiling		ceiling;
	int						num_of_id;
}t_data;

bool		check_arg(int argc, char **argv);

bool		read_map(char *argv, t_data *data);

bool		parse_read_data(t_data *data);

int			juduge_identifer(char *str);
bool		parse_all_identifier(t_data *data);
bool		judge_space_or_wall(char *line);
void		parse_map(t_data *data);
void		init_data_for_parse(t_data *data);

bool		parse_path(t_data *data, size_t i, size_t j, int id_num);
bool		parse_floor(t_data *data, size_t i, size_t j);
bool		parse_ceiling(t_data *data, size_t i, size_t j);
bool		parse_each_identifier(t_data *data, size_t i, size_t j);

bool		check_valid_map(t_data *data);

bool		check_leftside_wall(char	**map);
bool		check_rightside_wall(char	**map);
bool		check_num_of_player_and_invalid_char(char	**map);
bool		check_playable_map(char **map);
bool		check_inside_wall(char **copied_map);

void		convert_space_to_x(char **map);

bool		init_other_data(t_data *data);
bool		init_mlx(t_data *data);
bool		init_texture(t_data *data);
bool		init_pos_dir_plane(t_data *data);

int			key_draw(t_data *data);

void		calc_free(t_data	*data);
bool		calc_init(t_data	*data);
void		calc_side_dist(t_data	*data);
void		calc_hit_wall(t_data *data);

void		tex_init(t_data *data);
void		tex_dir(t_data *data);
void		tex_draw(t_data *data, int row);

int			key_hook(int keycode, t_data *data);

int			close_program(t_data *data);

void		free_two_dimensional_array(char **array);
void		free_map_data_and_path(t_data *data);
void		free_texture(t_data *data);
void		destroy_textures(t_data *data);
void		free_pos_dir_plane(t_data *data);
void		free_and_destroy_all(t_data *data);

void		put_error_and_exit(char *str, t_data *data);

#endif