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
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int				num;
	int				diff;
	struct s_stack	*next;
}t_stack;

typedef struct s_com
{
	int		rotator;
	char	*final;
}t_com;

int		error(void);
int		compare(int a, int b, int ifsi, int ifno);
int		get_stack_len(t_stack *stack);
void	stack_del(t_stack **stack);
t_stack	*create_node(void);
t_stack	*args_to_stack(int ac, char **av);
char	*add_to_string(char *to, char *add);
void	ft_strdel(char **as);
int		find_mid_value(t_stack *stack, int len);
int		*array_from_list(t_stack *stack, int len);
void	check_doubles(t_stack **stack);
void	quick_sort(int *stack1, int start, int end);
int		check_av(char *str);
t_com	*new_result(void);
void	print_result(char *sr);
void	short_solution(t_stack **stack, int len);
void	sort_stacks(t_stack **stack1, t_stack **stack2, t_com **result,
			int len);
int		ft_strequ(char const *s1, char const *s2);
int		div_stack_a(t_stack **stack1, t_stack **stack2, t_com **result,
			int len);
int		div_stack_b(t_stack **stack1, t_stack **stack2,	t_com **result,
			int len);
void	push_back(t_stack **stack1, t_stack **stack2, t_com **result, int half);
void	rotate_back(t_stack **stack, t_com **result, int back);
void	swap_elements(t_stack **stack1, t_stack **stack2, t_com **result,
			int len);
int		add_pa_pb(char **origin, char **res, int i);
int		add_ra_rra(char **origin, char **res, int i);
int		add_rb_rrb(char **origin, char **res, int i);
int		add_others(char **tmp, char **res, int i);
int		sab(t_stack **head);
int		pab(t_stack **head_to, t_stack **head_from);
int		rab(t_stack **head);
int		rrab(t_stack **head);
int		ss(t_stack **stack1, t_stack **stack2);
int		rr(t_stack **stack1, t_stack **stack2);
int		rrr(t_stack **stack1, t_stack **stack2);
void	ft_swap(int *a, int *b);
void	swap_three_a(t_stack **stack, t_com **res);
void	swap_three_b(t_stack **stack, t_com **res);
void	swap_three(t_stack **stack, t_com **result);
void	swap_two(t_stack **stack, t_com **result);
void	comb_1(t_stack **stack, t_com **result);
void	comb_2(t_stack **stack, t_com **result);
void	comb_3(t_stack **stack, t_com **result);
void	comb_4(t_stack **stack, t_com **result);
void	comb_5(t_stack **stack, t_com **result);
void	comb_6(t_stack **stack, t_com **result);
void	comb_7(t_stack **stack, t_com **result);
void	comb_8(t_stack **stack, t_com **result);
void	comb_9(t_stack **stack, t_com **result);
#endif