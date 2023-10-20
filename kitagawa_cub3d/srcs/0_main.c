/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:20:59 by yokitaga          #+#    #+#             */
/*   Updated: 2023/10/21 00:07:54 by yokitaga         ###   ########.fr       */
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
    if (init_other_data(data) == false)
        put_error_and_exit("error in init other data", data);
    free_and_destroy_all(data);
    return (0);
}

