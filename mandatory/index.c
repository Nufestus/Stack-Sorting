/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aammisse <aammisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 21:19:59 by aammisse          #+#    #+#             */
/*   Updated: 2025/01/26 15:58:33 by aammisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	index_stack(t_stack **a)
{
	t_stack	*temp1;
	t_stack	*temp2;

	if (!a || !*a)
		return (errorreturn(a, NULL));
	if (issorted(*a))
	{
		printf("Already Sorted !!! (⌒_⌒;)");
		free_stack(a, NULL);
		exit (0);
	}
	temp1 = *a;
	while (temp1)
	{
		temp1->index = 0;
		temp2 = *a;
		while (temp2)
		{
			if (temp1->content > temp2->content)
				temp1->index++;
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
}
