/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyoo <junyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 09:08:38 by junyoo            #+#    #+#             */
/*   Updated: 2022/07/18 16:42:15 by junyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (!ft_strlen(needle))
		return ((char *)haystack);
	i = 0;
	while (i < len && haystack[i])
	{
		j = 0;
		if (needle[j] == haystack[i])
		{
			while (needle[j] && haystack[i + j])
			{
				if (needle[j] != haystack[i + j] || i + j >= len)
					break ;
				j++;
			}
			if (!needle[j])
				return ((char *)haystack + i);
		}
		i++;
	}
	return (0);
}
