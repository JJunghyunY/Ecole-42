/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyoo <junyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:56:09 by junyoo            #+#    #+#             */
/*   Updated: 2022/09/19 14:51:02 by junyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*src;
	size_t	i;
	size_t	slen;

	if (!s || len <= 0)
		return (NULL);
	i = 0;
	slen = 0;
	if (start < ft_strlen(s))
		slen = ft_strlen(s) - (size_t)start;
	if (len < slen)
		slen = len;
	src = (char *)malloc(sizeof(char) * slen + 1);
	if (!src)
		return (NULL);
	while (slen && s[start])
	{
		src[i] = ((char *)s)[start++];
		i++;
		slen--;
	}
	src[i] = '\0';
	return (src);
}
