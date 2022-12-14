/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyoo <junyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 11:18:32 by junyoo            #+#    #+#             */
/*   Updated: 2022/07/18 16:24:24 by junyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long	num;
	char		temp[15];
	int			i;

	if (n == 0)
		write(fd, "0", 1);
	i = 0;
	num = (long long)n;
	if (n < 0)
	{
		write(fd, "-", 1);
		num *= -1;
	}
	while (num)
	{
		temp[i++] = num % 10 + '0';
		num = num / 10;
	}
	while (i--)
		write(fd, &temp[i], 1);
}
