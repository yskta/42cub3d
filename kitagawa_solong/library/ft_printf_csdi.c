/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_csdi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:45:36 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/08 23:02:31 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//c
int	ft_count_and_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

//s
int	ft_count_and_putstr(char *s)
{
	if (s == NULL)
		s = "(null)";
	write(1, s, ft_strlen(s));
	return (ft_strlen(s));
}

//d,i
int	ft_count_and_putint(int i)
{
	char	*num;
	int		add_count;

	num = ft_itoa(i);
	add_count = ft_count_and_putstr(num);
	free(num);
	return (add_count);
}
