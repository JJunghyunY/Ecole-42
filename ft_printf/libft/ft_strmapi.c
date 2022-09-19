/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyoo <junyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 11:36:43 by junyoo            #+#    #+#             */
/*   Updated: 2022/07/18 16:39:18 by junyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	slen;
	char	*str;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (slen +1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < slen)
	{
		str[i] = (*f)(i, s[i]);
		i++;
	}
	str[slen] = '\0';
	return (str);
}
