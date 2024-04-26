/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalloux <lgalloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:45:00 by lgalloux          #+#    #+#             */
/*   Updated: 2024/02/28 16:20:14 by lgalloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack	*ft_lstmap(t_stack *lst, int (*f)(int), int (*del)(int))
{
	t_stack	*result;
	t_stack	*node;

	if (!lst || !f || !del)
		return (NULL);
	result = NULL;
	while (lst)
	{
		node = ft_lstnew(0);
		if (!node)
		{
			ft_lstclear(&result, del);
			return (NULL);
		}
		node->data = f(lst->data);
		ft_lstadd_back(&result, node);
		lst = lst->next;
	}
	return (result);
}
