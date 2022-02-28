/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespinoz <lespinoz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:05:38 by lespinoz          #+#    #+#             */
/*   Updated: 2022/02/28 14:16:21 by lespinoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"

typedef struct	s_stack
{
	int				num;
	int				diff;
	struct s_stack	*next;
}t_stack;

typedef struct	s_com
{
	int		rotator;
	char	*final;
}t_com;

int 	error(void);
int		get_stack_len(t_stack *stack);
void 	stack_del (t_stack **stack);
t_stack	*new_node(void);
t_stack	*args_to_stack(int ac, char **av);
void 	check_doubles(t_stack **stack);
void	quick_sort(int *stack1, int start, int end);
int		check_av(char *str);
t_com	*get_new_result(void);
void	print_result(char *sr);
void	short_solution(t_stack **stack, int len);
void	sort_stack(t_stack **stack1, t_stack **stack2, t_com **result, int len);
int		ft_strequ(char const *s1, char const *s2);
#endif
