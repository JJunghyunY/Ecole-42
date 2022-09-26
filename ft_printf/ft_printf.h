
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_putchar_int(char c, char format);
int	ft_putnbr_int(int n);
int	ft_putstr_int(char *s);
int	ft_puthex_int(int n, char format);
int	ft_putptr_int(unsigned int *ptr);

#endif
