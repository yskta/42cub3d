/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 19:40:47 by yokitaga          #+#    #+#             */
/*   Updated: 2022/10/19 20:42:30 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	size;

	start = 0;
	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	while (ft_strchr(set, s1[start]) != NULL && s1[start] != '\0')
		start++;
	size = ft_strlen((char *)s1);
	while (ft_strchr(set, s1[size - 1]) != NULL && size != 0)
		size--;
	return (ft_substr(s1, start, size - start));
}
