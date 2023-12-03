/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_0_parse_read_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:09:55 by yokitaga          #+#    #+#             */
/*   Updated: 2023/12/03 17:11:38 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	parse_read_data(t_data *data)
{
	init_data_for_parse(data);
	parse_map(data);
	if (data->map_data.map_height < 3)
	{
		free_map_data_and_path(data);
		return (false);
	}
	if (parse_all_identifier(data) == false || \
		data->north_path == NULL || data->south_path == NULL || \
		data->west_path == NULL || data->east_path == NULL || \
		data->num_of_id != 6 || check_valid_map(data) == false || \
		data->ceiling.done_flag == false || data->floor.done_flag == false)
	{
		free_map_data_and_path(data);
		return (false);
	}
	return (true);
}
