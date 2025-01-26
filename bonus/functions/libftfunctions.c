/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftfunctions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aammisse <aammisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 21:33:10 by aammisse          #+#    #+#             */
/*   Updated: 2025/01/24 01:10:52 by aammisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (src[len] != '\0')
		len++;
	if (dstsize == 0)
		return (len);
	while (src[i] != '\0' && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize > 0)
		dst[i] = '\0';
	return (len);
}

int	checkdupli(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = stack;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp->content == tmp2->content)
				return (0);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (1);
}

int	issorted(t_stack *stack)
{
	if (!stack || !stack->next)
		return (0);
	while (stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}
