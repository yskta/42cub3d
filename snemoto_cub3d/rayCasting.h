/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayCasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:27:38 by snemoto           #+#    #+#             */
/*   Updated: 2023/10/09 14:54:05 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# define MAPROW 6
# define MAPCOL 6

# include <stdio.h>
# include <stdlib.h>

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

typedef struct s_vars
{
	t_pos	*pos;
}	t_vars;

t_pos	*get_pos(t_vars var);
t_pos	*get_pos_wall(t_pos *pos, unsigned int map[MAPROW][MAPCOL], t_wall wallKild);

// void	get_dir(void);

// void	calc_height(void);
// void	calc_width(void);

// void	draw_wall(void);
// void	draw_ceiling(void);
// void	draw_floor(void);

// void	key_change_pos(void);
// void	key_change_dir(void);

// void	get_image(void);
// void	draw_image(void);

#endif
