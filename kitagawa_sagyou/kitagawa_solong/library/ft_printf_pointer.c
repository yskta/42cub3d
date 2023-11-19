/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:45:56 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/11 15:39:04 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_showhex_forull(unsigned long long pointer)
{
	char				*num;
	unsigned long long	p_mod;
	unsigned long long	p_dev;
	unsigned int		i;

	if (pointer == 0)
		return (ft_strdup("0"));
	i = ft_hex_plen(pointer);
	num = (char *)malloc(sizeof(char) * (i + 1));
	if (num == NULL)
		return (NULL);
	p_dev = pointer;
	num[i] = '\0';
	while (p_dev > 0)
	{
		i--;
		p_mod = p_dev % 16;
		if (p_mod <= 9)
			num[i] = p_mod + '0';
		else
			num[i] = p_mod - 10 + 'a';
		p_dev /= 16;
	}
	return (num);
}

unsigned int	ft_hex_plen(unsigned long long pointer)
{
	unsigned int	p_len;

	p_len = 0;
	while (pointer != 0)
	{
		p_len++;
		pointer /= 16;
	}
	return (p_len);
}

int	ft_cntputpointer(unsigned long long pointer)
{
	char	*p;
	int		add_count;

	add_count = 0;
	add_count += ft_count_and_putstr("0x");
	p = ft_showhex_forull(pointer);
	add_count += ft_count_and_putstr(p);
	free(p);
	return (add_count);
}
