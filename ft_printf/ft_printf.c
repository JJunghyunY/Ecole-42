/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyoo <junyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 12:17:34 by junyoo            #+#    #+#             */
/*   Updated: 2022/09/19 14:51:23 by junyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_putchar_int(char c)
{
	return write(1, &c, 1);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;			// 가변인자 포인터 선언
	int		ret_len;	// 총 출력 길이 저장할 변수 선언
	
	ret_len = 0;
	va_start(ap, format);
	while(*format)
	{
		if (*format == '%')
		{
			//cspdiuxX%
			format++;
			if (*format == 'c')
				ret_len += ft_putchar_int(va_arg(ap, int));
//			else if (*format == 's')
//				ft_putstr();
//			else if (*format == 'p')
//				ft_putstr();
//			else if (*format == 'd')
//				ft_putstr();
//			else if (*format == 'i')
//				ft_putstr();
//			else if (*format == 'x')
//				ft_putstr();
//			else if (*format == 'X')
//				ft_putstr();
//			else if (*format == '%')
//				ft_putchar_fd();
		}
		else /* format[i] 가 '%' 안만났다면 */
			ret_len += ft_putchar_int(va_arg(ap, int));
		format++;
	}
	va_end (ap);
	return (ret_len);
}

int	main(void)
{
	char c = 'a';

	ft_printf("bbbb%c%c%c", c, c, c);

	return (0);
}