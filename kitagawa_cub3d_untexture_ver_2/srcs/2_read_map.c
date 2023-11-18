/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_read_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 20:43:39 by yokitaga          #+#    #+#             */
/*   Updated: 2023/10/28 15:56:13 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool    read_map(char *argv, t_data *data)
{
    char    *read_data;
    char    *line;

    data->map_data.read_data_height = 0;
    data->map_data.fd = open(argv, O_RDONLY);
    if (data->map_data.fd == -1)
        return (false);
    read_data = ft_strdup("");
    while(1)
    {
        line = get_next_line(data->map_data.fd);
        if (line == NULL)
            break ;
        read_data = ft_strjoin_for_gnl(read_data, line);
        free(line);
    }
    close(data->map_data.fd);
    data->map_data.read_data = ft_split(read_data, '\n');
    while (data->map_data.read_data[data->map_data.read_data_height] != NULL)
        data->map_data.read_data_height++;
    // int i = 0;
    // while (data->map_data.read_data[i] != NULL)
    // {
    //     printf("%s\n", data->map_data.read_data[i]);
    //     i++;
    // }
    free(read_data);
    return (true);
}