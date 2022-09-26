
#include "ft_printf.h"

int	ft_putchar_int(char c, char format)
{
	if (format == '%')
		return (write(1, "%", 1));
	return (write(1, &c, 1));
}

int	ft_putstr_int(char *s)
{
	int	i;

	i = 0;
	if (!s)
		s = "(null)";
	while (s[i])
		i++;
	return (write(1, s, i));
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
	while (i--)
		write(1, &temp[i], 1);
	return (ret_num);
}

int	ft_puthex_int(int n, char format)
{
	int		i;
	char	*table;
	char	temp[9];
	
	if (format == 'x')
		table = "0123456789abcdef";
	else
		table = "0123456789ABCDEF";
	i = 0;
	while(n > 0)
	{
		temp[i++] = table[n % 16];
		n /= 16;
	}
	while(i--)
		n += write(1, &temp[i], 1);
//		n += ft_putchar_int(temp[i]);
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
		temp[i++] = table[num % 16];
		num /= 16;
	}
	temp[i++] = 'x';
	temp[i++] = '0';
	while (i--)
		num += write(1, &temp[i], 1);
//		num += ft_putchar_int(temp[i]);
	return (num);
}

// else if (*format == 'X')
// 	ret_len += ft_puthex_up_int(va_arg(ap, int));
// int ft_puthex_up_int(int n)
// {
// 	int		i;
// 	char	*table;
// 	char	temp[9];

// 	table = "0123456789ABCDEF";
// 	i = 0;
// 	while(n > 0)
// 	{
// 		temp[i++] = table[n % 16];
// 		n /= 16;
// 	}
// 	while(i--)
// 		n += ft_putchar_int(temp[i]);
// 	return (n);
// }