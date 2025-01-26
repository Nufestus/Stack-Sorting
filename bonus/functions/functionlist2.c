/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functionlist2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aammisse <aammisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 21:32:04 by aammisse          #+#    #+#             */
/*   Updated: 2025/01/22 16:02:19 by aammisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	newnode(t_stack **stack, long long content)
{
	t_stack	*node;

	node = ft_lstnew(content);
	ft_lstadd_back(stack, node);
}

void	newop(t_ops **ops, char *content)
{
	t_ops	*op;

	op = ft_newop(content);
	ft_opadd_back(ops, op);
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

void	ft_opclear(t_ops **lst)
{
	t_ops	*copy;
	t_ops	*next;

	if (!lst)
		return ;
	copy = *lst;
	while (copy)
	{
		next = copy->next;
		free(copy->content);
		free(copy);
		copy = next;
	}
	*lst = NULL;
}
