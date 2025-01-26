/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aammisse <aammisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 22:35:29 by aammisse          #+#    #+#             */
/*   Updated: 2025/01/26 15:58:57 by aammisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <string.h>
# include <math.h>

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;
}				t_stack;

// list control
int			ft_lstsize(t_stack *lst);
void		ft_lstadd_back(t_stack **lst, t_stack *new);
void		ft_lstadd_front(t_stack **lst, t_stack *new);
t_stack		*ft_lstnew(long long content);
t_stack		*ft_lstlast(t_stack *lst);
void		newnode(t_stack **stack, long long content);
void		ft_lstclear(t_stack **lst);

// libft
long long	ft_atoi(char *str);
char		**ft_split(char *s, char *delims);
size_t		ft_strlcpy(char *dst, char *src, size_t dstsize);
size_t		ft_strlen(char *s);

// operations
void		pa(t_stack **a, t_stack **b);
void		pb(t_stack **a, t_stack **b);
void		sa(t_stack **a);
void		sb(t_stack **b);
void		ss(t_stack **a, t_stack **b);
void		ra(t_stack **a);
void		rb(t_stack **b);
void		rr(t_stack **a, t_stack **b);
void		rra(t_stack **a);
void		rrb(t_stack **b);
void		rrr(t_stack **a, t_stack **b);
void		swap(t_stack **stack);
void		push(t_stack **to, t_stack **from);
void		rotate(t_stack **stack);
void		reverserotate(t_stack **stack);

// stack control
void		index_stack(t_stack **a);
void		sort_three(t_stack **stack);
void		sort_five_four(t_stack **a, t_stack **b);
void		free_stack(t_stack **a, t_stack **b);
void		push_swap(t_stack **a, t_stack **b);
void		push_b(t_stack **a, t_stack **b);
void		push_a(t_stack **a, t_stack **b);
int			getchunksize(t_stack *a);
int			check(t_stack *a);
int			getmaxpos(t_stack *stack, int max);
int			getmax(t_stack *stack);

// parsing
void		get_param(char *str, t_stack **stack);
int			checkinput(char *str);
void		mallocerror(char **s, t_stack **stack);
void		errorreturn(t_stack **stack_a, t_stack **stack_b);
int			checkdupli(t_stack *stack);
int			issorted(t_stack *stack);

#endif