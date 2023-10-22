/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:27:38 by snemoto           #+#    #+#             */
/*   Updated: 2023/10/22 11:04:46 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RC_H
# define RC_H

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

# define BLACK 0x000000

# define NORTH 0xFF0000
# define EAST 0x0000FF
# define SOUTH 0x00FF00
# define WEST 0x00FFFF

# define ROW 6
# define COL 6

extern unsigned int map[ROW][COL];

# define WALL 100

# define WINH WALL * 10
# define WINW WINH * 2

#define MAPL WINW / 2 - ROW / 2 * WALL
#define MAPR WINW / 2 + ROW / 2 * WALL

# define ANGLE 16

typedef struct s_pos	t_pos;

typedef struct s_dir
{
	double	dir_x;
	double	dir_y;
	double	angle;
}	t_dir;

typedef struct s_dis
{
	unsigned int	dis_x;
	unsigned int	dis_y;
}	t_dis;

struct s_pos
{
	t_dis			*dis;
	unsigned int	pos_x;
	unsigned int	pos_y;
};

typedef struct s_vars
{
	t_pos	*pos;
	t_dir	*dir;
	void	*mlx;
	void	*win;
	void	*img;
}	t_vars;

int		key_hook(int keycode, t_vars *var);
int		key_draw(t_vars *var);

void	print_pos(t_vars var);
void	print_dir(t_vars var);
void	key_draw_grid(t_vars *var);
void	key_draw_map_range(t_vars *var);

#endif
