/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aammisse <aammisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 21:30:15 by aammisse          #+#    #+#             */
/*   Updated: 2025/01/23 19:29:04 by aammisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	rb(t_stack **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}

void	rra(t_stack **a)
{
	reverserotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	reverserotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	reverserotate(a);
	reverserotate(b);
	write(1, "rrr\n", 4);
}
