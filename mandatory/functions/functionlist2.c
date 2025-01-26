/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functionlist2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aammisse <aammisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 21:32:04 by aammisse          #+#    #+#             */
/*   Updated: 2025/01/18 13:53:37 by aammisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	newnode(t_stack **stack, long long content)
{
	t_stack	*node;

	node = ft_lstnew(content);
	ft_lstadd_back(stack, node);
}

void	ft_lstclear(t_stack **lst)
{
	t_stack	*copy;
	t_stack	*next;

	if (!lst)
		return ;
	copy = *lst;
	while (copy)
	{
		next = copy->next;
		free(copy);
		copy = next;
	}
	*lst = NULL;
}
