/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyoo <junyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:39:40 by junyoo            #+#    #+#             */
/*   Updated: 2022/07/18 16:28:26 by junyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void	*b, int c, size_t	len)
{
	int				i;
	unsigned char	*temp;
	unsigned char	ch;

	temp = b;
	ch = c;
	i = 0;
	while (len--)
	{
		temp[i] = ch;
		i++;
	}
	return (b);
}
