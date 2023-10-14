/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_get_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:27:52 by snemoto           #+#    #+#             */
/*   Updated: 2023/10/14 14:21:56 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rc.h"

void	get_dir(t_vars var)
{
	var.dir->dir_x = cos(var.dir->angle);
	var.dir->dir_y = sin(var.dir->angle);

	// printf("X;%f Y;%f\n", var.dir->dir_x, var.dir->dir_y);
	// printf("angle;%f\n", var.dir->angle);
	// printf("dis_angle;%f\n", var.pos->dis->dis_angle);

	// printf("---------------------\n");
}
