/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespinoz <lespinoz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:05:38 by lespinoz          #+#    #+#             */
/*   Updated: 2022/03/10 14:26:16 by lespinoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}t_stack;

size_t	ft_strlen(const char *str);
void	ft_error(char *msg);
char	**ft_split(char const *s, char c);
t_stack	*ft_lstnew(int value);
long	ft_atoi(const char *str);
void	ft_lstadd_front(t_stack **stack, t_stack *new);
t_stack	*ft_lstlast(t_stack *head);
void	ft_lstadd_back(t_stack **stack, t_stack *new);
int		ft_lstsize(t_stack *head);
void	del_stack(t_stack **stack);
void	free_str(char **str);
void	ft_putnbr_fd(int n, int fd);
int		ft_isdigit(int c);
void	ft_putstr_fd(char *s, int fd);
int		is_sorted(t_stack **stack);
void	sort_stack(t_stack **stack_a, t_stack **stack_b);
void	short_sort(t_stack **stack_a, t_stack **stack_b);
void	large_sort(t_stack **stack_a, t_stack **stack_b);
void	ft_check_args(int argc, char **argv);
int		get_distance(t_stack **stack, int index);
int		swap(t_stack **stack);
int		sa(t_stack **stack_a);
int		sb(t_stack **stack_b);
int		ss(t_stack **stack_a, t_stack **stack_b);
int		push(t_stack **stack_to, t_stack **stack_from);
int		pa(t_stack **stack_a, t_stack **stack_b);
int		pb(t_stack **stack_a, t_stack **stack_b);
int		rotate(t_stack **stack);
int		ra(t_stack **stack_a);
int		rb(t_stack **stack_b);
int		rr(t_stack **stack_a, t_stack **stack_b);
int		reverse_rotate(t_stack **stack);
int		rra(t_stack **stack_a);
int		rrb(t_stack **stack_b);
int		rrr(t_stack **stack_a, t_stack **stack_b);
void	sort_3(t_stack **stack_a);
void	sort_4(t_stack **stack_a, t_stack **stack_b);
void	sort_5(t_stack **stack_a, t_stack **stack_b);

#endif
