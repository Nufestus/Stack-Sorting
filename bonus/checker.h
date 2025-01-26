/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aammisse <aammisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:59:47 by aammisse          #+#    #+#             */
/*   Updated: 2025/01/23 23:52:42 by aammisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "GNL/get_next_line.h"

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}				t_stack;

typedef struct s_ops
{
	char			*content;
	struct s_ops	*next;
}				t_ops;

// list control
int			ft_lstsize(t_stack *lst);
void		ft_lstadd_back(t_stack **lst, t_stack *new);
void		ft_lstadd_front(t_stack **lst, t_stack *new);
t_stack		*ft_lstnew(long long content);
t_ops		*ft_newop(char *content);
t_stack		*ft_lstlast(t_stack *lst);
void		newnode(t_stack **stack, long long content);
void		newop(t_ops **ops, char *content);
void		ft_lstclear(t_stack **lst);
void		ft_opadd_back(t_ops **lst, t_ops *new);
t_ops		*ft_oplast(t_ops *lst);
void		ft_opclear(t_ops **lst);

// libft
long long	ft_atoi(char *str, t_stack **stack);
char		**ft_split(char *s, char *delims);
size_t		ft_strlcpy(char *dst, char *src, size_t dstsize);
size_t		ft_strlen(char *s);
int			ft_strcmp(char *s1, char *s2);

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
void		parse(int ac, char **av, t_stack **stack_a);
void		parse_inp(t_ops **ops, char *line, t_stack **a, t_stack **b);
void		apply_ops(t_ops **op, t_stack **a, t_stack **b);
void		free_stack(t_ops **op, t_stack **a, t_stack **b);

// parsing
void		get_param(char *str, t_stack **stack);
int			checkinput(char *str);
void		mallocerror(char **s, t_stack **stack);
void		errorreturn(t_ops **ops, t_stack **stack_a, t_stack **stack_b);
int			checkdupli(t_stack *stack);
int			issorted(t_stack *stack);

#endif