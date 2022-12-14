/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyoo <junyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 09:06:47 by junyoo            #+#    #+#             */
/*   Updated: 2022/07/19 14:44:30 by junyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*allo;

	if (!count || !size)
	{
		size = 1;
		count = 1;
	}
	if (size > (size * count) || count > (size * count))
		return (NULL);
	allo = malloc(size * count);
	if (!allo)
		return (NULL);
	ft_bzero(allo, size * count);
	return (allo);
}
