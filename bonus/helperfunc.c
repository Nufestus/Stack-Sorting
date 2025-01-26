/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helperfunc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aammisse <aammisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:55:58 by aammisse          #+#    #+#             */
/*   Updated: 2025/01/22 16:01:53 by aammisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_ops	*ft_newop(char *content)
{
	t_ops	*newnode;

	newnode = malloc (sizeof(t_ops));
	if (!newnode)
		return (NULL);
	newnode->content = content;
	newnode->next = NULL;
	return (newnode);
}

void	free_stack(t_ops **op, t_stack **a, t_stack **b)
{
	ft_lstclear(a);
	ft_lstclear(b);
	ft_opclear(op);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_opadd_back(t_ops **lst, t_ops *new)
{
	if (!lst || !new)
		return ;
	if (*lst)
		ft_oplast(*lst)->next = new;
	else
		*lst = new;
}

t_ops	*ft_oplast(t_ops *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
