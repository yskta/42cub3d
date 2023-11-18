/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 19:43:37 by yokitaga          #+#    #+#             */
/*   Updated: 2022/10/19 20:39:32 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (dest == NULL && size == 0)
		return (size + src_len);
	dest_len = ft_strlen((const char *)dest);
	if (size <= dest_len)
		return (size + src_len);
	ft_strlcpy(dest + dest_len, src, size - dest_len);
	return (dest_len + src_len);
}
