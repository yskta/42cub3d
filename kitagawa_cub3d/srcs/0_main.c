/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:20:59 by yokitaga          #+#    #+#             */
/*   Updated: 2023/10/20 11:28:10 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int main(int argc, char *argv[])
{
    t_data  *data;
    
    data = malloc(sizeof(t_data));
    if (!data)
        put_error_and_exit("malloc error in main", data);
    if (check_arg(argc, argv) == false)
        put_error_and_exit("invalid arg", data);
    if (read_map(argv[1], data) == false)
        put_error_and_exit("error in read map", data);
    if (parse_read_data(data) == false)
        put_error_and_exit("error in parse read data", data);
    printf("north: %s\n", data->north.path);
    printf("south: %s\n", data->south.path);
    printf("west: %s\n", data->west.path);
    printf("east: %s\n", data->east.path);
    printf("floor: %d, %d, %d\n", data->floor.r, data->floor.g, data->floor.b);
    printf("ceiling: %d, %d, %d\n", data->ceiling.r, data->ceiling.g, data->ceiling.b);
    printf("map:\n");
    for (size_t i = 0; data->map_data.map[i] != NULL; i++)
        printf("%s\n", data->map_data.map[i]);
    free(data);
    return (0);
}

