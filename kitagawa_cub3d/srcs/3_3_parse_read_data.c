/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_3_parse_read_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:22:36 by yokitaga          #+#    #+#             */
/*   Updated: 2023/10/27 23:20:09 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// char	**copy_map_contents(t_data *data)
// {
// 	char	**copied_map;
// 	size_t	i;

// 	i = 0;
// 	copied_map = malloc(sizeof(char *) * (data->map_data.map_height + 1));
// 	if (!copied_map)
// 		put_error_and_exit("malloc error in copy_map_contents", data);
// 	while (i < data->map_data.map_height)
// 	{
// 		copied_map[i] = ft_strdup(data->map_data.map[i]);
// 		i++;
// 	}
// 	copied_map[i] = NULL;
// 	return (copied_map);
// }

bool	check_row(t_data *data)
{
	size_t	i;

	i = 0;
	while (data->map_data.map[data->map_data.map_height - 1][i] != '\0')
	{
		if (data->map_data.map[data->map_data.map_height - 1][i] != '1' && data->map_data.map[data->map_data.map_height - 1][i] != ' ')
			return (false);
		i++;
	}
	return (true);
}

bool	check_valid_map(t_data *data)
{
	// char **copied_map;

	// copied_map = copy_map_contents(data);
	if(data->map_data.map[0] == NULL)
		return (false);
	if (check_row(data) == false))
		return (false);
	// if (check_line(data) == false)
	// 	return (false);
	return (true);
}