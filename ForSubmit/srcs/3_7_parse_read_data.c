/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_7_parse_read_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:06:35 by yokitaga          #+#    #+#             */
/*   Updated: 2023/12/03 17:07:47 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	check_around(char **map, size_t i, size_t j)
{
	if (map[i - 1][j] == '1' || map[i - 1][j] == '0' || map[i - 1][j] == 'S' || \
		map[i - 1][j] == 'N' || map[i - 1][j] == 'W' || map[i - 1][j] == 'E')
	{
		if (map[i + 1][j] == '1' || map[i + 1][j] == '0' || \
			map[i + 1][j] == 'S' || map[i + 1][j] == 'N' || \
			map[i + 1][j] == 'W' || map[i + 1][j] == 'E')
		{
			if (map[i][j - 1] == '1' || map[i][j - 1] == '0' || \
				map[i][j - 1] == 'S' || map[i][j - 1] == 'N' || \
				map[i][j - 1] == 'W' || map[i][j - 1] == 'E')
			{
				if (map[i][j + 1] == '1' || map[i][j + 1] == '0' || \
					map[i][j + 1] == 'S' || map[i][j + 1] == 'N' || \
					map[i][j + 1] == 'W' || map[i][j + 1] == 'E')
					return (true);
			}
		}
	}
	return (false);
}

bool	check_inside_wall(char **copied_map)
{
	size_t	i;
	size_t	j;

	i = 1;
	while (copied_map[i] != NULL)
	{
		j = 1;
		while (copied_map[i][j] != '\0')
		{
			if (copied_map[i][j] == '0')
			{
				if (check_around(copied_map, i, j) == false)
					return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}
