/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 19:41:40 by yokitaga          #+#    #+#             */
/*   Updated: 2022/10/19 20:41:51 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_min(size_t len, size_t s1_len);

static size_t	ft_min(size_t len, size_t s1_len)
{
	if (len >= s1_len)
		return (s1_len);
	else
		return (len);
}

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	s1_len;

	if (s1 == NULL && len == 0)
		return (NULL);
	if (s2[0] == '\0')
		return ((char *)s1);
	i = 0;
	s1_len = ft_strlen(s1);
	len = ft_min(len, s1_len);
	while (s1[i] != '\0' && i < len)
	{
		j = 0;
		while ((i + j) < len && (s1[i + j] == s2[j]))
		{
			if (s2[j + 1] == '\0')
				return ((char *)&s1[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
