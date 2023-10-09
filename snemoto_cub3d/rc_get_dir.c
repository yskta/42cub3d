/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_get_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:27:52 by snemoto           #+#    #+#             */
/*   Updated: 2023/10/09 17:58:58 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rc.h"

void	get_dir(t_vars var)
{
	t_dir	*dir;

	dir = (t_dir *)malloc(sizeof(t_dir));
	dir->angle = var.dir->angle;
	dir->dir_x = cos(dir->angle);
	dir->dir_y = sin(dir->angle);
	
	printf("X;%f Y;%f\n", dir->dir_x, dir->dir_y);
	printf("angle;%f\n", dir->angle);
}
