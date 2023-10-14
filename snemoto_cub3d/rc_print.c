/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:27:52 by snemoto           #+#    #+#             */
/*   Updated: 2023/10/14 17:34:51 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rc.h"

void	print_dir(t_vars var)
{
	printf("X;%f Y;%f\n", var.dir->dir_x, var.dir->dir_y);
	printf("angle;%f\n", var.dir->angle);
	printf("dis_angle;%f\n", var.pos->dis->dis_angle);
	printf("---------------------\n");
}

void	print_pos(t_vars var)
{
	printf("HERE X;%d Y;%d\n", var.pos->pos_x, var.pos->pos_y);
	printf("dis_x;%d\n", var.pos->dis->dis_x);
	printf("dis_y;%d\n", var.pos->dis->dis_y);
	printf("---------------------\n");
}
