/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortbig.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aammisse <aammisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:21:41 by aammisse          #+#    #+#             */
/*   Updated: 2025/01/22 20:18:59 by aammisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	push_a(t_stack **a, t_stack **b)
{
	int	size;
	int	max;
	int	maxpos;

	size = ft_lstsize(*b);
	while (size)
	{
		max = getmax(*b);
		maxpos = getmaxpos(*b, max);
		if (maxpos <= size / 2)
		{
			while (maxpos--)
				rb(b);
		}
		else
		{
			while (maxpos != size)
			{
				rrb(b);
				maxpos++;
			}
		}
		pa(a, b);
		size--;
	}
}

int	check(t_stack *a)
{
	int	i;
	int	first;
	int	second;

	i = 0;
	while (a->next)
	{
		first = a->content;
		second = a->next->content;
		if (first - second == 3 || first - second == 2 || first - second == 4)
			i++;
		a = a->next;
	}
	if ((i >= 50 && ft_lstsize(a) < 100) || i >= 250)
		return (1);
	return (0);
}

int	getchunksize(t_stack *a)
{
	int	listsize;
	int	chunksize;

	chunksize = 0;
	listsize = ft_lstsize(a);
	if (listsize > 6 && listsize <= 100)
		chunksize = listsize / 6;
	else if (listsize > 100)
		chunksize = listsize / 14;
	return (chunksize);
}

void	push_b(t_stack **a, t_stack **b)
{
	int		i;
	int		chunksize;
	t_stack	*cpy;

	i = 0;
	chunksize = getchunksize(*a);
	while (*a)
	{
		cpy = *a;
		if (cpy->index <= i)
		{
			pb(a, b);
			i++;
		}
		else if (cpy->index <= i + chunksize)
		{
			pb(a, b);
			rb(b);
			i++;
		}
		else if (check(*a))
			rra(a);
		else
			ra(a);
	}
}

void	push_swap(t_stack **a, t_stack **b)
{
	if (ft_lstsize(*a) <= 3 && ft_lstsize(*a) > 1)
		sort_three(a);
	else if ((ft_lstsize(*a) == 5 || ft_lstsize(*a) == 4)
		&& ft_lstsize(*a) > 1)
		sort_five_four(a, b);
	else if (ft_lstsize(*a) > 5)
	{
		push_b(a, b);
		push_a(a, b);
	}
}
