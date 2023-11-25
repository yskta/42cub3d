/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_5_parse_read_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:07:44 by yokitaga          #+#    #+#             */
/*   Updated: 2023/11/25 16:55:31 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

size_t	check_rightside_wall_check_nextlen(char **map, \
	size_t i, size_t right_end_wall_index)
{
	size_t	next_len;

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
			return (0);
	}
	return (right_end_wall_index);
}

bool	check_rightside_wall_xcase(char **map, size_t i, \
	size_t right_end_wall_index)
{
	while (right_end_wall_index > 0 && map[i][right_end_wall_index - 1] == '1' \
		&& map[i + 1][right_end_wall_index] == 'X')
		right_end_wall_index--;
	if (map[i + 1][right_end_wall_index] != '1')
		return (false);
	else
		return (true);
}

bool	check_rightside_wall_for_zerocase(char **map, size_t i, \
	size_t right_end_wall_index)
{
	while (map[i][right_end_wall_index + 1] == '1' && \
		map[i + 1][right_end_wall_index] == '0')
		right_end_wall_index++;
	if (map[i + 1][right_end_wall_index] != '1')
		return (false);
	else
		return (true);
}

bool	check_rightside_wall_for_norm(char	**map, size_t right_end_wall_index)
{
	size_t	i;

	i = 0;
	while (map[i + 1] != NULL)
	{
		right_end_wall_index = check_rightside_wall_check_nextlen(map, \
			i, right_end_wall_index);
		if (right_end_wall_index == 0)
			return (false);
		if (map[i + 1][right_end_wall_index] == 'X')
		{
			if (check_rightside_wall_xcase(map, i, \
				right_end_wall_index) == false)
				return (false);
		}
		else if (map[i + 1][right_end_wall_index] == '0')
		{
			if (check_rightside_wall_for_zerocase(map, i, \
				right_end_wall_index) == false)
				return (false);
		}
		i++;
	}
	return (true);
}

bool	check_rightside_wall(char	**map)
{
	size_t	j;
	size_t	right_end_wall_index;

	j = 0;
	while (map[0][j] != '\0')
		j++;
	j--;
	while (map[0][j] == 'X')
		j--;
	right_end_wall_index = j;
	return (check_rightside_wall_for_norm(map, right_end_wall_index));
}
