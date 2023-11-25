/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_5_parse_read_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:26:33 by yokitaga          #+#    #+#             */
/*   Updated: 2023/11/25 15:46:32 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	check_num_of_player_and_invalid_char(char	**map)
{
	size_t	i;
	size_t	j;
	size_t	num_of_player;

	i = 0;
	num_of_player = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || \
				map[i][j] == 'W' || map[i][j] == 'E')
				num_of_player++;
			else if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'X')
				return (false);
			j++;
		}
		i++;
	}
	if (num_of_player == 1)
		return (true);
	else
		return (false);
}

bool	check_playable_or_not(char **map, size_t	x, size_t	y)
{
	size_t	above_line_len;
	size_t	under_line_len;

	above_line_len = ft_strlen(map[y - 1]);
	under_line_len = ft_strlen(map[y + 1]);
	if ((above_line_len > x + 1) && \
		(map[y - 1][x] == '1' || \
			map[y - 1][x] == '0'))
	{
		if ((under_line_len > x + 1) && \
			(map[y + 1][x] == '1' || \
				map[y + 1][x] == '0'))
		{
			if (map[y][x - 1] == '1' || \
				map[y][x - 1] == '0')
			{
				if (map[y][x + 1] == '1' || \
					map[y][x + 1] == '0')
					return (true);
			}
		}
	}
	return (false);
}

bool	check_playable_map(char **map)
{
	size_t	i;
	size_t	j;
	size_t	player_pos_x;
	size_t	player_pos_y;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || \
				map[i][j] == 'W' || map[i][j] == 'E')
			{
				player_pos_x = j;
				player_pos_y = i;
			}
			j++;
		}
		i++;
	}
	return (check_playable_or_not(map, player_pos_x, player_pos_y));
}
