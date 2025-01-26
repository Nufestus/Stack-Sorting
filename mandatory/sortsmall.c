/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortsmall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aammisse <aammisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 21:47:29 by aammisse          #+#    #+#             */
/*   Updated: 2025/01/22 15:44:37 by aammisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	getindex(t_stack **a, int index)
{
	t_stack	*copy;
	int		i;

	i = 0;
	copy = *a;
	while (copy)
	{
		if (copy->index == index)
			break ;
		i++;
		copy = copy->next;
	}
	return (i);
}

void	second_id(t_stack **a, t_stack **b, int index)
{
	int	i;

	i = getindex(a, index);
	if (i == 0)
		pb(a, b);
	else
	{
		if (i == 1)
			sa(a);
		else if (i == 2)
		{
			ra(a);
			sa(a);
		}
		else if (i == 3)
		{
			rra(a);
		}
		pb(a, b);
	}
}

void	first_id(t_stack **a, t_stack **b, int index)
{
	int	i;

	i = getindex(a, index);
	if (i == 0)
		pb(a, b);
	else
	{
		if (i == 1)
			sa(a);
		else if (i == 2)
			ra(a);
		else if (i == 3)
		{
			rra(a);
			rra(a);
		}
		else if (i == 4)
			rra(a);
		pb(a, b);
	}
}

void	sort_three(t_stack **stack)
{
	int	third;

	if ((*stack)->next->next)
		third = (*stack)->next->next->content;
	if (!issorted(*stack))
	{
		if (ft_lstsize(*stack) == 3)
		{
			while (!issorted(*stack))
			{
				if ((*stack)->content > (*stack)->next->next->content)
					ra(stack);
				else if ((*stack)->content > (*stack)->next->content)
					sa(stack);
				else if ((*stack)->next->content > third)
					sa(stack);
			}
		}
		else
			while (!issorted(*stack))
				if ((*stack)->content > (*stack)->next->content)
					sa(stack);
	}
}

void	sort_five_four(t_stack **a, t_stack **b)
{
	int	i;

	i = 0;
	if (ft_lstsize(*a) == 5)
	{
		first_id(a, b, 0);
		second_id(a, b, 1);
	}
	else
		second_id(a, b, 0);
	sort_three(a);
	if ((*b)->next)
		pa(a, b);
	pa(a, b);
}
