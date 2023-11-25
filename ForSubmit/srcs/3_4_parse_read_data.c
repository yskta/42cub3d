/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_4_parse_read_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:31:24 by yokitaga          #+#    #+#             */
/*   Updated: 2023/11/25 15:57:55 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	checj_leftside_wall_zerocase(char **map, size_t i, \
	size_t left_end_wall_index)
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
		return (true);
}

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
			if (checj_leftside_wall_zerocase(map, i, left_end_wall_index) == false)
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
