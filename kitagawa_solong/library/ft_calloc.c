/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 19:52:21 by yokitaga          #+#    #+#             */
/*   Updated: 2022/10/19 20:31:14 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t number, size_t size)
{
	void	*p;
	size_t	total;

	if (number == 0 || size == 0)
		return (ft_calloc(1, 1));
	total = number * size;
	if (number != total / size)
		return (NULL);
	p = malloc(number * size);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, total);
	return (p);
}
