/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_init_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 21:50:14 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/15 18:09:42 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map(t_map *map)
{
	map->width = 0;
	map->n_exit = 0;
	map->n_player = 0;
	map->n_collectibel = 0;
	map->steps = 0;
	map->player.x = 0;
	map->player.y = 0;
	map->exit.x = 0;
	map->exit.y = 0;
}
