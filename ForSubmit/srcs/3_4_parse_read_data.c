/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_4_parse_read_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:31:24 by yokitaga          #+#    #+#             */
/*   Updated: 2023/11/25 15:44:50 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	check_leftside_wall(char	**map)
{
	size_t	i;
	size_t	j;
	size_t	left_end_wall_index;

	i = 0;
	j = 0;
	while (map[0][j] == 'X')
		j++;
	left_end_wall_index = j;
	while (map[i + 1] != NULL)
	{
		if (map[i + 1][left_end_wall_index] == '0')
		{
			while (left_end_wall_index > 0)
			{
				if (map[i][left_end_wall_index - 1] == '1' && \
					map[i + 1][left_end_wall_index] == '0')
					left_end_wall_index--;
				else
					break ;
			}
			if (map[i + 1][left_end_wall_index] != '1')
				return (false);
			else
				i++;
		}
		else if (map[i + 1][left_end_wall_index] == 'X')
		{
			while (map[i][left_end_wall_index + 1] == '1' && \
				map[i + 1][left_end_wall_index] == 'X')
				left_end_wall_index++;
			if (map[i + 1][left_end_wall_index] != '1')
				return (false);
			else
				i++;
		}
		else
			i++;
	}
	return (true);
}

bool	check_rightside_wall(char	**map)
{
	size_t	i;
	size_t	j;
	size_t	right_end_wall_index;
	size_t	next_len;

	i = 0;
	j = 0;
	while (map[0][j] != '\0')
		j++;
	j--;
	while (map[0][j] == 'X')
		j--;
	right_end_wall_index = j;
	while (map[i + 1] != NULL)
	{
		next_len = ft_strlen(map[i + 1]);
		if (right_end_wall_index + 1 > next_len)
		{
			while (right_end_wall_index > 0)
			{
				if (map[i][right_end_wall_index - 1] == '1')
					right_end_wall_index--;
				else
					break ;
			}
			if (right_end_wall_index + 1 > next_len)
				return (false);
		}
		if (map[i + 1][right_end_wall_index] == 'X')
		{
			while (right_end_wall_index > 0 && \
				map[i][right_end_wall_index - 1] == '1' \
				&& map[i + 1][right_end_wall_index] == 'X')
				right_end_wall_index--;
			if (map[i + 1][right_end_wall_index] != '1')
				return (false);
			else
				i++;
		}
		else if (map[i + 1][right_end_wall_index] == '0')
		{
			while (map[i][right_end_wall_index + 1] == '1' && \
				map[i + 1][right_end_wall_index] == '0')
				right_end_wall_index++;
			if (map[i + 1][right_end_wall_index] != '1')
				return (false);
			else
				i++;
		}
		else
			i++;
	}
	return (true);
}

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




