/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:27:38 by snemoto           #+#    #+#             */
/*   Updated: 2023/10/11 17:16:21 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RC_H
# define RC_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "minilibx-linux/mlx.h"

# define ROW 6
# define COL 6

extern unsigned int map[ROW][COL];

# define WALL 100

# define WINW WALL * 10
# define WINH WALL * 10

#define MAPL WINW / 2 - ROW / 2 * WALL
#define MAPR WINW / 2 + ROW / 2 * WALL

# define ANGLE 4

# define KEY_W 0x077
# define KEY_S 0x073
# define KEY_A 0x061
# define KEY_D 0x064
# define KEY_LEFT 0xFF51
# define KEY_RIGHT 0xFF53

# define BLACK 0x000000
# define RED 0xFF0000
# define BLUE 0x0000FF

typedef enum e_wall
{
	AHEAD,
	LEFT,
	RIGHT,
}	t_wall;

typedef struct s_pos	t_pos;

struct s_pos
{
	unsigned int	pos_x;
	unsigned int	pos_y;
	char			element;
	t_pos			*pos_here;
	t_pos			*pos_wall_ahead;
	t_pos			*pos_wall_left;
	t_pos			*pos_wall_right;
};

typedef struct s_dir
{
	double	dir_x;
	double	dir_y;
	double	angle;
}	t_dir;

typedef struct s_dis
{
	unsigned int	dis_x;
	unsigned int	dis_left;
	unsigned int	dis_right;
	unsigned int	dis_y;
	double			dis_angle;
}	t_dis;

typedef struct s_vars
{
	t_pos	*pos;
	t_dir	*dir;
	t_dis	*dis;
	void	*mlx;
	void	*win;
	void	*img;
	int		img_len;
}	t_vars;

void	get_pos(t_vars var, unsigned int map[ROW][COL]);
void	get_dir(t_vars var);
int		key_hook(int keycode, t_vars *var);
int		key_draw(t_vars *var);

#endif
