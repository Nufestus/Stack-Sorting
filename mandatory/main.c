/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aammisse <aammisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 22:33:36 by aammisse          #+#    #+#             */
/*   Updated: 2025/01/26 15:58:30 by aammisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	free_stack(t_stack **a, t_stack **b)
{
	ft_lstclear(a);
	ft_lstclear(b);
}

int	main(int ac, char **av)
{
	int		i;
	t_stack	*stack_a;
	t_stack	*stack_b;

	i = 1;
	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1)
		return (0);
	while (i < ac)
	{
		get_param(av[i], &stack_a);
		i++;
	}
	if (!checkdupli(stack_a))
		errorreturn(&stack_a, NULL);
	index_stack(&stack_a);
	push_swap(&stack_a, &stack_b);
	free_stack(&stack_a, &stack_b);
	return (0);
}
