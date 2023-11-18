/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:46:42 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/08 23:01:59 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_judge_and_output(va_list ap, int fmt)
{
	int	add_count;

	add_count = 0;
	if (fmt == 'c')
		add_count = ft_count_and_putchar((char)va_arg(ap, int));
	else if (fmt == 's')
		add_count = ft_count_and_putstr((char *)va_arg(ap, char *));
	else if (fmt == 'p')
		add_count = ft_cntputpointer((unsigned long long)va_arg(ap, void *));
	else if (fmt == 'd' || fmt == 'i')
		add_count = ft_count_and_putint((int)va_arg(ap, int));
	else if (fmt == 'u')
		add_count = ft_cntputunsigned((unsigned int)va_arg(ap, unsigned int));
	else if (fmt == 'x' || fmt == 'X')
		add_count = ft_cntputhexa((unsigned int)va_arg(ap, unsigned int), fmt);
	else if (fmt == '%')
		add_count = ft_count_and_putchar('%');
	return (add_count);
}

int	ft_count(va_list ap, const char *fmt)
{
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	while (fmt[i] != '\0')
	{
		if (fmt[i] != '%')
		{
			write(1, &fmt[i], 1);
			count++;
		}
		else if (fmt[i] == '%')
		{
			i++;
			count += ft_judge_and_output(ap, fmt[i]);
		}
		i++;
	}
	return (count);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, fmt);
	count = ft_count(ap, fmt);
	va_end(ap);
	return (count);
}
