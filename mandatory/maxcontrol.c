/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maxcontrol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aammisse <aammisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:34:49 by aammisse          #+#    #+#             */
/*   Updated: 2025/01/22 15:51:41 by aammisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	getmax(t_stack *stack)
{
	int	max;

	max = stack->content;
	while (stack)
	{
		if (stack->content > max)
			max = stack->content;
		stack = stack->next;
	}
	return (max);
}

int	getmaxpos(t_stack *stack, int max)
{
	int		pos;
	t_stack	*ptr;

	pos = 0;
	ptr = stack;
	while (ptr->content != max)
	{
		ptr = ptr->next;
		pos++;
	}
	return (pos);
}
