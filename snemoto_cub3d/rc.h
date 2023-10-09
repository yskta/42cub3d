/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:27:38 by snemoto           #+#    #+#             */
/*   Updated: 2023/10/09 18:04:49 by snemoto          ###   ########.fr       */
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
# define WINW 300
# define WINH 300
# define IMGLEN 100

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
