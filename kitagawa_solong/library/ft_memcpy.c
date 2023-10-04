/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 19:49:18 by yokitaga          #+#    #+#             */
/*   Updated: 2022/10/19 20:33:57 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*udest;
	const unsigned char	*usrc;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	udest = (unsigned char *)dest;
	usrc = (const unsigned char *)src;
	while (i < n)
	{
		udest[i] = usrc[i];
		i++;
	}
	return (dest);
}
