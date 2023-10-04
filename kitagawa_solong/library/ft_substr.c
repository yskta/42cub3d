/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 19:40:15 by yokitaga          #+#    #+#             */
/*   Updated: 2022/10/19 20:42:46 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	s_len;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen((char *)s);
	if (start + len > s_len)
		len = s_len - start;
	if (start >= s_len || len == 0)
		return (ft_strdup(""));
	str = malloc (sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, (s + start), (len + 1));
	return (str);
}
