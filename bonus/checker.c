/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aammisse <aammisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:46:26 by aammisse          #+#    #+#             */
/*   Updated: 2025/01/24 01:11:14 by aammisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check_op(char *line, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(line, "ra\n"))
		ra(a);
	else if (!ft_strcmp(line, "rb\n"))
		rb(b);
	else if (!ft_strcmp(line, "rr\n"))
		rr(a, b);
	else if (!ft_strcmp(line, "pa\n"))
		pa(a, b);
	else if (!ft_strcmp(line, "pb\n"))
		pb(a, b);
	else if (!ft_strcmp(line, "sa\n"))
		sa(a);
	else if (!ft_strcmp(line, "sb\n"))
		sb(b);
	else if (!ft_strcmp(line, "ss\n"))
		ss(a, b);
	else if (!ft_strcmp(line, "rra\n"))
		rra(a);
	else if (!ft_strcmp(line, "rrb\n"))
		rrb(b);
	else if (!ft_strcmp(line, "rrr\n"))
		rrr(a, b);
}

void	apply_ops(t_ops **op, t_stack **a, t_stack **b)
{
	t_ops	*copy;

	copy = *op;
	while (copy)
	{
		check_op(copy->content, a, b);
		copy = copy->next;
	}
}

void	parse_inp(t_ops **ops, char *line, t_stack **a, t_stack **b)
{
	if ((!ft_strcmp(line, "ra\n")) || (!ft_strcmp(line, "rb\n")))
		return ;
	else if (!ft_strcmp(line, "rr\n"))
		return ;
	else if (!ft_strcmp(line, "pa\n"))
		return ;
	else if (!ft_strcmp(line, "pb\n"))
		return ;
	else if (!ft_strcmp(line, "sa\n"))
		return ;
	else if (!ft_strcmp(line, "sb\n"))
		return ;
	else if (!ft_strcmp(line, "ss\n"))
		return ;
	else if (!ft_strcmp(line, "rra\n"))
		return ;
	else if (!ft_strcmp(line, "rrb\n"))
		return ;
	else if (!ft_strcmp(line, "rrr\n"))
		return ;
	else
	{
		free(line);
		errorreturn(ops, a, b);
	}
}

void	parse(int ac, char **av, t_stack **stack_a)
{
	int	i;

	i = 1;
	if (ac == 1)
		exit(0);
	while (i < ac)
	{
		get_param(av[i], stack_a);
		i++;
	}
	if (!checkdupli(*stack_a))
		errorreturn(NULL, stack_a, NULL);
}

int	main(int ac, char **av)
{
	char	*line;
	t_ops	*operations;
	t_stack	*stack_a;
	t_stack	*stack_b;

	operations = NULL;
	stack_a = NULL;
	stack_b = NULL;
	parse(ac, av, &stack_a);
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		parse_inp(&operations, line, &stack_a, &stack_b);
		newop(&operations, line);
	}
	apply_ops(&operations, &stack_a, &stack_b);
	if ((issorted(stack_a) && !ft_lstsize(stack_b))
		|| (ft_lstsize(stack_a) == 1 && !ft_lstsize(stack_b)))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&operations, &stack_a, &stack_b);
	return (0);
}
