/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_get_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:27:52 by snemoto           #+#    #+#             */
/*   Updated: 2023/10/11 18:47:17 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rc.h"

static t_pos	*get_pos_here(t_vars var)
{
	t_pos	*rv;

	rv = (t_pos *)malloc(sizeof(t_pos));
	rv->pos_x = var.pos->pos_x;
	rv->pos_y = var.pos->pos_y;
	return (rv);
}

static t_pos	*get_pos_wall(t_pos *pos, unsigned int map[ROW][COL], t_wall wallkind)
{
	t_pos	*rv;
	int		row;
	int		col;

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
		while ((map[row][col] + '0') != '0' && row < ROW - 1)
			row++;
	rv->pos_x = row;
	return (rv);
}

void	get_pos(t_vars var, unsigned int map[ROW][COL])
{
	t_pos	*pos;
	t_pos	*pos_wall_ahead;
	t_pos	*pos_wall_left;
	t_pos	*pos_wall_right;
	t_wall	wallkind;

	pos = get_pos_here(var);
	var.pos->pos_here = pos;
	printf("HERE X;%d Y;%d\n", pos->pos_x, pos->pos_y);

	wallkind = AHEAD;
	pos_wall_ahead = get_pos_wall(pos, map, wallkind);
	var.pos->pos_wall_ahead = pos_wall_ahead;
	printf("AHEAD X;%d Y;%d\n", pos_wall_ahead->pos_x, pos_wall_ahead->pos_y);

	printf("dis_x;%d\n", var.pos->dis->dis_x);
	printf("dis_y;%d\n", var.pos->dis->dis_y);
	printf("dis_left;%d\n", var.pos->dis->dis_left);
	printf("dis_right;%d\n", var.pos->dis->dis_right);

	wallkind = LEFT;
	pos_wall_left = get_pos_wall(pos, map, wallkind);
	var.pos->pos_wall_left = pos_wall_left;
	printf("LEFT X;%d Y;%d\n", pos_wall_left->pos_x, pos_wall_left->pos_y);

	wallkind = RIGHT;
	pos_wall_right = get_pos_wall(pos, map, wallkind);
	var.pos->pos_wall_right = pos_wall_right;
	printf("RIGHT X;%d Y;%d\n", pos_wall_right->pos_x, pos_wall_right->pos_y);

	printf("---------------------\n");
}
