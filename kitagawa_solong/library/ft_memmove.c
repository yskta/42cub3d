/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 19:48:55 by yokitaga          #+#    #+#             */
/*   Updated: 2022/10/19 20:35:13 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*udest;
	const unsigned char	*usrc;
	size_t				i;

	if ((dest == NULL) && (src == NULL))
		return (NULL);
	udest = (unsigned char *)dest;
	usrc = (const unsigned char *)src;
	i = 1;
	if (usrc < udest)
	{
		while (i <= n)
		{
			udest[n - i] = usrc[n - i];
			i++;
		}
		return (dest);
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
