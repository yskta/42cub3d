/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayCasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:27:52 by snemoto           #+#    #+#             */
/*   Updated: 2023/10/09 14:59:03 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rayCasting.h"

unsigned int map[MAPROW][MAPCOL]=
{
  {1,1,1,1,1,1},
  {1,0,0,0,0,1},
  {1,0,0,0,0,1},
  {1,0,0,0,0,1},
  {1,0,0,0,0,1},
  {1,1,1,1,1,1}
};

t_pos	*get_pos(t_vars var)
{
	t_pos	*rv;

	rv = (t_pos *)malloc(sizeof(t_pos));
	rv->pos_x = var.pos->pos_x;
	rv->pos_y = var.pos->pos_y;
	return (rv);
}

t_pos	*get_pos_wall(t_pos *pos, unsigned int map[MAPROW][MAPCOL], t_wall wallkind)
{
	t_pos			*rv;
	int				row;
	int				col;

	rv = (t_pos *)malloc(sizeof(t_pos));
	row = pos->pos_x;
	col = pos->pos_y;
	while ((map[row][col] + '0') != '1' && 0 < col)
		col--;
	rv->pos_y = col;
	if (wallkind == AHEAD)
		rv->pos_x = pos->pos_x;
	else if (wallkind == LEFT)
		while ((map[row][col] + '0') != '0' && 0 < row)
			row--;
	else if (wallkind == RIGHT)
		while ((map[row][col] + '0') != '0' && row < MAPROW - 1)
			row++;
	rv->pos_x = row;
	return (rv);
}

int	main(void)
{
	t_vars	var;
	t_pos	*pos;
	t_wall	wallkind;
	t_pos	*pos_wall_ahead;
	t_pos	*pos_wall_left;
	t_pos	*pos_wall_right;

	var.pos->pos_x = 2;
	var.pos->pos_y = 4;
	var.pos->element = 0;

	pos = get_pos(var);
	printf("X;%d Y;%d\n", pos->pos_x, pos->pos_y);

	wallkind = AHEAD;
	pos_wall_ahead = get_pos_wall(pos, map, wallkind);
	printf("X;%d Y;%d\n", pos_wall_ahead->pos_x, pos_wall_ahead->pos_y);

	wallkind = LEFT;
	pos_wall_left = get_pos_wall(pos, map, wallkind);
	printf("X;%d Y;%d\n", pos_wall_left->pos_x, pos_wall_left->pos_y);

	wallkind = RIGHT;
	pos_wall_right = get_pos_wall(pos, map, wallkind);
	printf("X;%d Y;%d\n", pos_wall_right->pos_x, pos_wall_right->pos_y);

	return (0);
}
