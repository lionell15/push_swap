/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespinoz <lespinoz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 15:38:36 by lespinoz          #+#    #+#             */
/*   Updated: 2022/03/01 15:38:39 by lespinoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	do_three(t_stack **stack)
{
	if ((*stack)->num < (*stack)->next->num
		&& (*stack)->next->num < (*stack)->next->next->num)
		return ;
	if ((*stack)->num > (*stack)->next->num
		&& (*stack)->next->num < (*stack)->next->next->num
		&& (*stack)->num < (*stack)->next->next->num)
		ft_putstr_fd("sa\n", 1);
	else if ((*stack)->num < (*stack)->next->num
		&& (*stack)->next->num > (*stack)->next->next->num
		&& (*stack)->num < (*stack)->next->next->num)
		ft_putstr_fd("rra\nsa\n", 1);
	else if ((*stack)->num > (*stack)->next->num
		&& (*stack)->num > (*stack)->next->next->num
		&& (*stack)->next->num < (*stack)->next->next->num)
		ft_putstr_fd("ra\n", 1);
	else if ((*stack)->num < (*stack)->next->num
		&& (*stack)->num > (*stack)->next->next->num
		&& (*stack)->next->num > (*stack)->next->next->num)
		ft_putstr_fd("rra\n", 1);
	else if ((*stack)->num > (*stack)->next->num
		&& (*stack)->next->num > (*stack)->next->next->num)
		ft_putstr_fd("ra\nsa\n", 1);
}

void	short_solution(t_stack **stack, int len)
{
	if (len == 1)
		return ;
	if (len == 2 && (*stack)->num > (*stack)->next->num)
		ft_putstr_fd("sa\n", 1);
	if (len == 3)
		do_three(stack);
	return ;
}
