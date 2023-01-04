/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyoo <junyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:58:26 by junyoo            #+#    #+#             */
/*   Updated: 2022/07/18 19:07:46 by junyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*temp;

	if (!s || !c)
		return ((char *)s + ft_strlen(s));
	temp = NULL;
	i = 0;
	while (s[i])
	{	
		if (s[i] == (unsigned char)c)
			temp = (char *)s + i;
		i++;
	}
	return (temp);
}
