/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyoo <junyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 12:17:34 by junyoo            #+#    #+#             */
/*   Updated: 2022/09/25 21:24:36 by junyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		ret_len;

	ret_len = 0;
	va_start(ap, format);
	while(*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c' || *format == '%')
				ret_len += ft_putchar_int(va_arg(ap, int), *format);
			else if (*format == 's')
				ret_len += ft_putstr_int((char *)va_arg(ap, char *));
			else if (*format == 'p')
				ret_len += ft_putptr_int(va_arg(ap, unsigned int *));
			else if (*format == 'd' || *format == 'i')
				ret_len += ft_putnbr_int(va_arg(ap, int));
			else if (*format == 'x' || *format == 'X')
				ret_len += ft_puthex_int(va_arg(ap, int), *format);
			// else if (*format == '%')
			// 	ret_len += ft_putchar_int(*format);
		}
		else
			ret_len += write(1, &(*format), 1);
//			ret_len += ft_putchar_int(*format);
		format++;
	}
	va_end (ap);
	return (ret_len);
}

// int	main(void)
// {
// 	// int	*ptr;
// 	// int	n = 10;
// 	// ptr = &n;
// 	// int	res = 0;

// 	// res = ft_printf("ft_printf = %p\n", ptr);
// 	// printf("ft_printf return = %d\n\n", res);

// 	// res = printf("printf = %p\n", ptr);
// 	// printf("printf return = %d\n\n", res);

// //	printf("%d\n", printf("printf = %X\n\n", 123));
// //	printf("printf = %s\n");
// 	int i = ft_printf("ft_printf = %s\n", "abc");

// 	return (0);
// }
