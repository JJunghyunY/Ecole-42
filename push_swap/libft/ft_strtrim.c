/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyoo <junyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:20:15 by junyoo            #+#    #+#             */
/*   Updated: 2022/07/18 16:48:42 by junyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	slen;

	if (!s1)
		return (NULL);
	i = 0;
	slen = ft_strlen(s1);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (slen && ft_strchr(set, s1[slen -1]))
		slen--;
	if (slen < i)
		return (ft_strdup(""));
	str = ft_substr(s1, i, slen - i);
	return (str);
}
