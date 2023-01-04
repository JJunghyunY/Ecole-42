/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyoo <junyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:56:09 by junyoo            #+#    #+#             */
/*   Updated: 2022/07/18 19:47:08 by junyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*src;
	size_t	i;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start > slen)
		return (ft_strdup(""));
	if (slen > len)
		src = (char *)malloc(sizeof(char) * len + 1);
	if (slen <= len)
		src = (char *)malloc(sizeof(char) * slen - start + 1);
	if (!src)
		return (NULL);
	i = 0;
	while (i < len && s[i])
	{
		src[i] = s[start];
		start++;
		i++;
	}
	src[i] = '\0';
	return (src);
}
