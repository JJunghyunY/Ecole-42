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

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_putchar_int(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr_int(char *s)
{
	if (!s)
		return (-1);
	return (write(1, s, ft_strlen(s)));
}

int	ft_putnbr_int(int n)
{
	long long	num;
	char		temp[15];
	int			i;
	int			ret_num;

	if (n == 0)
		return (write(1, "0", 1));
	i = 0;
	ret_num = 0;
	num = (long long)n;
	if (n < 0)
	{
		write(1, "-", 1);
		num *= -1;
	}
	while (num)
	{
		temp[i++] = num % 10 + '0';
		num = num / 10;
	}
	ret_num = i;
	while (i)
		write(1, &temp[i--], 1);
	return (ret_num);
}

int	ft_puthex_int(int n)
{
	int		i;
	char	*table;
	char	temp[9];

	table = "0123456789abcdef";
	i = 0;
	while(n > 0)
	{
//		i += ft_putchar_int((table[n % 16]));
		temp[i++] = table[n % 16];
		n /= 16;
	}
	while(i--)
		n += ft_putchar_int(temp[i]);
	return (n);
}

int ft_puthex_up_int(int n)
{
	int		i;
	char	*table;
	char	temp[9];

	table = "0123456789ABCDEF";
	i = 0;
	while(n > 0)
	{
//		i += ft_putchar_int((table[n % 16]));
		temp[i++] = table[n % 16];
		n /= 16;
	}
	while(i--)
		n += ft_putchar_int(temp[i]);
	return (n);
}

int	ft_putptr_int(unsigned int *ptr)
{
	char	*table;
	int		i;
	unsigned long	num;
	char	temp[16];


	num = (unsigned long long )ptr;
	table = "0123456789abcdef";
	i = 0;
	while (num > 0)
	{
//		i += ft_putchar_int(table[num % 16]);
		temp[i++] = table[num % 16];
		num /= 16;
	}
	temp[i++] = 'x';
	temp[i++] = '0';
	while (i--)
		num += ft_putchar_int(temp[i]);
	return (num);
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
			else if (*format == 's')
				ret_len += ft_putstr_int((char *)va_arg(ap, char *));
			else if (*format == 'p')
				ret_len += ft_putptr_int(va_arg(ap, unsigned int *));
			else if (*format == 'd' || *format == 'i')
				ret_len += ft_putnbr_int(va_arg(ap, int));
			else if (*format == 'x')
				ret_len += ft_puthex_int(va_arg(ap, int));
			else if (*format == 'X')
				ret_len += ft_puthex_up_int(va_arg(ap, int));
			else if (*format == '%')
				ret_len += ft_putchar_int(*format);
		}
		else /* *format이 '%' 안만났다면 */
			ret_len += ft_putchar_int(*format);
		format++;
	}
	va_end (ap);
	return (ret_len);
}
/*
int	main(void)
{
	int	*ptr;
	int	n = 10;
	ptr = &n;
	int	res = 0;

//	printf("printf return : %d\n\n", printf("printf = %p\n", ptr));
	res = ft_printf("ft_printf = %p\n", ptr);
	printf("ft_printf return = %d\n\n", res);

	res = printf("printf = %p\n", ptr);
	printf("printf return = %d\n\n", res);

	return (0);
}
*/
