/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_put_error_exit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 21:50:44 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/15 19:06:52 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_error_and_exit(char *str, t_data *data)
{
	if (data->map_flag == TRUE)
		free_map(data);
	free(data);
	ft_printf("%s\n", str);
	exit (1);
}
