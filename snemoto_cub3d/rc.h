/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:27:38 by snemoto           #+#    #+#             */
/*   Updated: 2023/10/10 16:57:33 by snemoto          ###   ########.fr       */
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
# define ANGLE 2
# define WINW 1000
# define WINH 1000
# define IMGLEN 10

# define KEY_W 0x077
# define KEY_S 0x073
# define KEY_A 0x061
# define KEY_D 0x064
# define KEY_LEFT 0xFF51
# define KEY_RIGHT 0xFF53

extern unsigned int map[ROW][COL];

typedef enum e_wall
{
	AHEAD,
	LEFT,
	RIGHT,
}	t_wall;

typedef struct s_pos
{
	unsigned int	pos_x;
	unsigned int	pos_y;
	unsigned int	dis;
	char			element;
}	t_pos;

typedef struct s_dir
{
	double	dir_x;
	double	dir_y;
	double	angle;
}	t_dir;

typedef struct s_vars
{
	t_pos	*pos;
	t_dir	*dir;
	void	*mlx;
	void	*win;
	void	*img;
	int		img_len;
}	t_vars;

void	get_pos(t_vars var, unsigned int map[ROW][COL]);
void	get_dir(t_vars var);

// void	key_change_pos(void);
// void	key_change_dir(void);

// void	calc_height(void);
// void	calc_width(void);

// void	draw_wall(void);
// void	draw_ceiling(void);
// void	draw_floor(void);

// void	get_image(void);
// void	draw_image(void);

#endif
