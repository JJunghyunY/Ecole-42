/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyoo <junyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 15:50:14 by junyoo            #+#    #+#             */
/*   Updated: 2022/07/18 16:54:32 by junyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*tmpoftmp;

	if (!lst)
		return (NULL);
	tmp = NULL;
	while (lst)
	{
		tmpoftmp = ft_lstnew((f)(lst -> content));
		if (!tmpoftmp)
		{
			ft_lstclear(&tmp, (del));
			return (NULL);
		}
		ft_lstadd_back(&tmp, tmpoftmp);
		lst = lst -> next;
	}
	tmpoftmp = NULL;
	return (tmp);
}
