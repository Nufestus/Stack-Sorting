/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aammisse <aammisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 21:16:06 by aammisse          #+#    #+#             */
/*   Updated: 2025/01/20 18:59:12 by aammisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	swap(t_stack **stack)
{
	t_stack	*head;
	t_stack	*copy;

	if (!stack || !*stack || ft_lstsize(*stack) < 2)
		return ;
	head = *stack;
	*stack = (*stack)->next;
	copy = (*stack)->next;
	(*stack)->next = head;
	head->next = copy;
}

void	push(t_stack **to, t_stack **from)
{
	t_stack	*temp;

	if (!from || !*from)
		return ;
	temp = *from;
	*from = (*from)->next;
	temp->next = *to;
	*to = temp;
}

void	rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*head;

	if (!stack || !*stack || ft_lstsize(*stack) < 2)
		return ;
	head = (*stack)->next;
	temp = ft_lstlast(*stack);
	temp->next = *stack;
	(*stack)->next = NULL;
	*stack = head;
}

void	reverserotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*tail;

	if (!stack || !*stack || ft_lstsize(*stack) < 2)
		return ;
	last = *stack;
	while (last->next->next != NULL)
		last = last->next;
	tail = last->next;
	last->next = NULL;
	tail->next = (*stack);
	(*stack) = tail;
}

void	ss(t_stack **a, t_stack **b)
{
	if (ft_lstsize(*a) < 2 || ft_lstsize(*b) < 2)
		return ;
	swap(a);
	swap(b);
}
