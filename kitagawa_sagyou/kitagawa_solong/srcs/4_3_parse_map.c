/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_3_parse_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:35:29 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/17 18:23:31 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	change_recursive_process(t_map *copy_map, size_t y, size_t x)
{
	if ((1 <= y - 1) && (1 <= x) && (x <= copy_map->width - 2) \
			&& (copy_map->map[y - 1][x] != 'G'))
		change_recursive (copy_map, y - 1, x);
	if ((1 <= y) && (y <= copy_map->height - 2) && \
			(1 <= x - 1) && (copy_map->map[y][x - 1] != 'G'))
		change_recursive (copy_map, y, x - 1);
	if ((1 <= y) && (y <= copy_map->height - 2) && \
			(x + 1 <= copy_map->width - 2) \
			&& (copy_map->map[y][x + 1] != 'G'))
		change_recursive (copy_map, y, x + 1);
	if ((y + 1 <= copy_map->height - 2) && (1 <= x) && \
			(x <= copy_map->width - 2) && (copy_map->map[y + 1][x] != 'G'))
		change_recursive(copy_map, y + 1, x);
}

void	change_recursive(t_map *copy_map, size_t y, size_t x)
{
	if (copy_map->map[y][x] == COLLECTIBLE)
		copy_map->n_collectibel--;
	if (copy_map->map[y][x] == WALL || copy_map->map[y][x] == 'G')
		return ;
	else if (copy_map->n_collectibel == 0 && copy_map->map[y][x] == EXIT)
	{
		copy_map->map[y][x] = 'G';
		return ;
	}
	else
		copy_map->map[y][x] = 'G';
	change_recursive_process(copy_map, y, x);
	if ((y == 1 && x == 1) || (y == 1 && (x == copy_map->width - 2)) || \
			((y == copy_map->height - 2) && x == 1) || \
			((y == copy_map->height - 2) \
			&& (x == copy_map->width - 2)))
	{
		if (copy_map->map[y][x] == COLLECTIBLE)
			copy_map->n_collectibel--;
		if (copy_map->map[y][x] != WALL && copy_map->map[y][x] != 'G')
			copy_map->map[y][x] = 'G';
		return ;
	}
}

void	free_copy_map_map(t_map *copy_map)
{
	size_t	i;

	i = 0;
	while (i < copy_map->height)
	{
		free(copy_map->map[i]);
		i++;
	}
	free(copy_map->map);
}

bool	check_valid_copy_map(t_map *copy_map)
{
	bool	i;
	size_t	y;

	i = TRUE;
	y = 0;
	while (y < copy_map->height)
	{
		if (ft_strchr(copy_map->map[y], 'C') != NULL || \
			ft_strchr(copy_map->map[y], 'E') != NULL)
		{
			i = FALSE;
			break ;
		}
		y++;
	}
	return (i);
}

void	check_playable(t_data	*data)
{
	t_map	*copy_map;

	copy_map = malloc(sizeof(t_map));
	copy_map_data(data, copy_map);
	copy_map->map = copy_map_contents(data, copy_map);
	change_recursive(copy_map, copy_map->player.y, copy_map->player.x);
	if (check_valid_copy_map(copy_map) == FALSE)
	{
		free_copy_map_map(copy_map);
		free(copy_map);
		put_error_and_exit("INVARID MAP10", data);
	}
	free_copy_map_map(copy_map);
	free(copy_map);
}
