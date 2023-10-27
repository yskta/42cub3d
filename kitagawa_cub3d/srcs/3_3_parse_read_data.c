/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_3_parse_read_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:22:36 by yokitaga          #+#    #+#             */
/*   Updated: 2023/10/27 23:07:57 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// bool	check_map_wall(t_data *data)
// {
// 	size_t	i;
// 	size_t	j;

// 	i = 0;
// 	j = 0;
// 	while (data->map_data.map[0][j] != '\0')
// 	{
// 		if (data->map_data.map[0][j] != '1' && data->map_data.map[i][j] != ' ')
// 			return (false);
// 		j++;
// 	}
// 	while (data->map_data.map[i] != NULL)
// 	{
// 		j = 0;
// 	}
// 	return (true);
// }

bool	check_valid_map(t_data *data)
{
	if(data->map_data.map[0] == NULL)
		return (false);
	// if (check_map_wall(data) == false)
	// 	return (false);
	return (true);
}