/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:32:13 by yokitaga          #+#    #+#             */
/*   Updated: 2023/10/20 23:52:33 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	put_error_and_exit(char *str, t_data *data)
{
	if (data)
		free(data);
	printf("%s\n", str);
	exit (1);
}