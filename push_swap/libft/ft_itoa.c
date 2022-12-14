/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyoo <junyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 08:45:46 by junyoo            #+#    #+#             */
/*   Updated: 2022/07/18 11:59:57 by junyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char		*str;
	size_t		slen;
	char		temp[15];
	long long	i;

	if (n == 0)
		return (ft_strdup("0"));
	i = (long long)n;
	if (i < 0)
		i *= -1;
	slen = 0;
	while (i)
	{
		temp[slen++] = i % 10 + '0';
		i = i / 10;
	}
	if (n < 0)
		temp[slen++] = '-';
	str = (char *)malloc(sizeof(char) * (slen + 1));
	if (!str)
		return (NULL);
	while (slen)
		str[i++] = temp[(slen--) - 1];
	str[i] = '\0';
	return (str);
}
