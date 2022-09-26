/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyoo <junyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:39:13 by junyoo            #+#    #+#             */
/*   Updated: 2022/09/26 16:45:02 by junyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_putchar_int(char c);
int	ft_putstr_int(char *s);
int	ft_putnbr_int(int n);
int	ft_puthex_int(unsigned int n, char format);
int	ft_putptr_int(unsigned int *ptr);
int	ft_putuint_int(unsigned int num);

#endif
