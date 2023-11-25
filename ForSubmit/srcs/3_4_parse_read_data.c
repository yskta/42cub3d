/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_4_parse_read_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:31:24 by yokitaga          #+#    #+#             */
/*   Updated: 2023/11/25 16:07:59 by yokitaga         ###   ########.fr       */
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

bool	check_leftside_wall_xcase(char **map, size_t i, \
	size_t left_end_wall_index)
{
	while (map[i][left_end_wall_index + 1] == '1' && \
		map[i + 1][left_end_wall_index] == 'X')
		left_end_wall_index++;
	if (map[i + 1][left_end_wall_index] != '1')
		return (false);
	else
		return (true);
}

bool	check_leftside_wall_for_norm(char	**map, size_t left_end_wall_index)
{
	size_t	i;

	i = 0;
	while (map[i + 1] != NULL)
	{
		if (map[i + 1][left_end_wall_index] == '0')
		{
			if (checj_leftside_wall_zerocase(map, i, \
				left_end_wall_index) == false)
				return (false);
			else
				i++;
		}
		else if (map[i + 1][left_end_wall_index] == 'X')
		{
			if (check_leftside_wall_xcase(map, i, \
				left_end_wall_index) == false)
				return (false);
			else
				i++;
		}
		else
			i++;
	}
	return (true);
}

bool	check_leftside_wall(char	**map)
{
	size_t	j;
	size_t	left_end_wall_index;

	j = 0;
	while (map[0][j] == 'X')
		j++;
	left_end_wall_index = j;
	return (check_leftside_wall_for_norm(map, left_end_wall_index));
}
