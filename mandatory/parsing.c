/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aammisse <aammisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 21:33:46 by aammisse          #+#    #+#             */
/*   Updated: 2025/01/26 15:59:31 by aammisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

long long	ft_atoi(char *str)
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
			return (nb);
		i++;
	}
	return (nb * sign);
}

void	errorreturn(t_stack **stack_a, t_stack **stack_b)
{
	write(2, "Error\n", 6);
	ft_lstclear(stack_a);
	ft_lstclear(stack_b);
	exit(1);
}

void	mallocerror(char **s, t_stack **stack)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	errorreturn(stack, NULL);
}

int	checkinput(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
		return (0);
	if ((str[i] == '-' || str[i] == '+') && (strlen(str) > 1))
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
		errorreturn(stack, NULL);
	param = ft_split(str, " 	");
	if (!param)
		errorreturn(stack, NULL);
	while (param[i])
	{
		if (checkinput(param[i]))
		{
			n = ft_atoi(param[i]);
			if (n > INT_MAX || n < INT_MIN)
				mallocerror(param, stack);
			newnode(stack, n);
		}
		else
			errorreturn(0, 0);
		free(param[i]);
		i++;
	}
	free(param);
}
