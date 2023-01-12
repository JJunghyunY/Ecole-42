/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyoo <junyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 12:17:34 by junyoo            #+#    #+#             */
/*   Updated: 2023/01/12 13:05:24 by junyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_format(const char *format, va_list ap)
{
	int	ret_len;

	ret_len = 0;
	if (*format == 'c')
		ret_len += ft_putchar_int(va_arg(ap, int));
	else if (*format == 's')
		ret_len += ft_putstr_int(va_arg(ap, char *));
	else if (*format == 'p')
		ret_len += ft_putptr_int(va_arg(ap, unsigned int *));
	else if (*format == 'd' || *format == 'i')
		ret_len += ft_putnbr_int(va_arg(ap, int));
	else if (*format == 'u')
		ret_len += ft_putuint_int(va_arg(ap, unsigned int));
	else if (*format == 'x' || *format == 'X')
		ret_len += ft_puthex_int(va_arg(ap, unsigned int), *format);
	else if (*format == '%')
		ret_len += ft_putchar_int(*format);
	return (ret_len);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		ret_len;

	ret_len = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ret_len += ft_check_format(format, ap);
		}
		else
			ret_len += write(1, &(*format), 1);
		format++;
	}
	va_end (ap);
	return (ret_len);
}

int	ft_putchar_int(char c)
{
	return (write(1, &c, 1));
}
