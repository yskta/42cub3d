/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:32:13 by yokitaga          #+#    #+#             */
/*   Updated: 2023/10/14 16:51:40 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_read_data(t_data *data)
{
	size_t i;

	i = 0;
	while (data->map_data.read_data[i] != NULL)
	{
		free(data->map_data.read_data[i]);
		i++;
	}
	free(data->map_data.read_data);
}

void	put_error_and_exit(char *str, t_data *data)
{
	if (data)
		free(data);
	printf("%s\n", str);
	exit (1);
}