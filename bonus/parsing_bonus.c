/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aammisse <aammisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:59:24 by aammisse          #+#    #+#             */
/*   Updated: 2025/01/23 23:52:46 by aammisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

long long	ft_atoi(char *str, t_stack **stack)
{
	int			i;
	long long	nb;
	long long	sign;

	nb = 0;
	sign = 1;
	i = 0;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - '0');
		if (nb > INT_MAX || nb < INT_MIN)
			errorreturn(0, stack, 0);
		i++;
	}
	return (nb * sign);
}

void	errorreturn(t_ops **ops, t_stack **stack_a, t_stack **stack_b)
{
	write(1, "Error\n", 6);
	free_stack(ops, stack_a, stack_b);
	exit(1);
}

void	freee(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

int	checkinput(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
		return (0);
	if ((str[i] == '-' || str[i] == '+') && (ft_getstrlen(str) > 1))
		i++;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	get_param(char *str, t_stack **stack)
{
	int			i;
	char		**param;
	long long	n;

	i = 0;
	if (str && str[0] == '\0')
		errorreturn(NULL, stack, NULL);
	param = ft_split(str, " 	");
	if (!param)
		errorreturn(NULL, stack, NULL);
	while (param[i])
	{
		if (checkinput(param[i]))
		{
			n = ft_atoi(param[i], stack);
			newnode(stack, n);
		}
		else
			errorreturn(0, stack, 0);
		i++;
	}
	freee(param);
}
