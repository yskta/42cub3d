/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 19:44:35 by yokitaga          #+#    #+#             */
/*   Updated: 2022/10/19 20:38:38 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	size_t	src_len;

	src_len = ft_strlen(src);
	dest = (char *)malloc(sizeof(char) * (src_len + 1));
	if (dest == NULL)
		return (NULL);
	ft_strlcpy(dest, src, src_len + 1);
	return (dest);
}
