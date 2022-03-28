/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespinoz <lespinoz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:15:41 by lespinoz          #+#    #+#             */
/*   Updated: 2022/03/10 13:15:44 by lespinoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	pa(t_stack **stack_a, t_stack **stack_b)
{
	if (push(stack_a, stack_b) == -1)
		return (-1);
	ft_putstr_fd("pa", 1);
	ft_putstr_fd("\n", 1);
	return (0);
}

int	pb(t_stack **stack_a, t_stack **stack_b)
{
	if (push(stack_b, stack_a) == -1)
		return (-1);
	ft_putstr_fd("pb", 1);
	ft_putstr_fd("\n", 1);
	return (0);
}

int	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*tail;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	first = *stack;
	tail = ft_lstlast(first);
	*stack = first->next;
	first->next = NULL;
	tail->next = first;
	return (0);
}

int	ra(t_stack **stack_a)
{
	if (rotate(stack_a) == -1)
		return (-1);
	ft_putstr_fd("ra", 1);
	ft_putstr_fd("\n", 1);
	return (0);
}

int	rb(t_stack **stack_b)
{
	if (rotate(stack_b) == -1)
		return (-1);
	ft_putstr_fd("rb", 1);
	ft_putstr_fd("\n", 1);
	return (0);
}
