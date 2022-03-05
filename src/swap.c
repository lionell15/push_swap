/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespinoz <lespinoz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 16:27:48 by lespinoz          #+#    #+#             */
/*   Updated: 2022/03/04 13:50:29 by lespinoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	compa(t_stack **stack, t_com **res, int num_com, int num_com_f)
{
	if (get_stack_len(*stack) > 3)
	{
		if (num_com == 1)
			comb_1(stack, res);
		else if (num_com == 2)
			comb_2(stack, res);
		else if (num_com == 3)
			comb_3(stack, res);
		else if (num_com == 4)
			comb_4(stack, res);
		else if (num_com == 5)
			comb_5(stack, res);
	}
	if (num_com_f == 6)
		comb_6(stack, res);
	else if (num_com_f == 7)
		comb_7(stack, res);
	else if (num_com_f == 8)
		comb_8(stack, res);
	else if (num_com_f == 9)
		comb_9(stack, res);
	else if (num_com_f == 0)
		swap_two(stack, res);
}

void	swap_three_a(t_stack **stack, t_com **res)
{
	if ((*stack)->num < (*stack)->next->num
		&& (*stack)->next->num < (*stack)->next->next->num)
		return ;
	else if ((*stack)->num > (*stack)->next->num
		&& (*stack)->next->num < (*stack)->next->next->num
		&& (*stack)->num < (*stack)->next->next->num)
		compa(stack, res, 1, 0);
	else if ((*stack)->num < (*stack)->next->num
		&& (*stack)->next->num > (*stack)->next->next->num
		&& (*stack)->num < (*stack)->next->next->num)
		compa(stack, res, 2, 6);
	else if ((*stack)->num > (*stack)->next->num
		&& (*stack)->num > (*stack)->next->next->num
		&& (*stack)->next->num < (*stack)->next->next->num)
		compa(stack, res, 3, 7);
	else if ((*stack)->num < (*stack)->next->num
		&& (*stack)->num > (*stack)->next->next->num
		&& (*stack)->next->num > (*stack)->next->next->num)
		compa(stack, res, 4, 8);
	else if ((*stack)->num > (*stack)->next->num
		&& (*stack)->next->num > (*stack)->next->next->num)
		compa(stack, res, 5, 9);
}

void	swap_three_b(t_stack **stack, t_com **res)
{
	if ((*stack)->num > (*stack)->next->num
		&& (*stack)->next->num > (*stack)->next->next->num)
		return ;
	else if ((*stack)->num < (*stack)->next->num
		&& (*stack)->num > (*stack)->next->next->num
		&& (*stack)->next->num > (*stack)->next->next->num)
		compa(stack, res, 1, 0);
	else if ((*stack)->num > (*stack)->next->num
		&& (*stack)->num > (*stack)->next->next->num
		&& (*stack)->next->num < (*stack)->next->next->num)
		compa(stack, res, 2, 6);
	else if ((*stack)->num < (*stack)->next->num
		&& (*stack)->next->num > (*stack)->next->next->num
		&& (*stack)->num < (*stack)->next->next->num)
		compa(stack, res, 3, 7);
	else if ((*stack)->num > (*stack)->next->num
		&& (*stack)->next->num < (*stack)->next->next->num
		&& (*stack)->num < (*stack)->next->next->num)
		compa(stack, res, 4, 8);
	else if ((*stack)->num < (*stack)->next->num
		&& (*stack)->next->num < (*stack)->next->next->num)
		compa(stack, res, 5, 9);
}

void	swap_three(t_stack **stack, t_com **result)
{
	if ((*stack)->diff == 1)
		swap_three_a(stack, result);
	else
		swap_three_b(stack, result);
}

void	swap_two(t_stack **stack, t_com **result)
{
	if ((*stack)->diff == 1 && ((*stack)->num > (*stack)->next->num))
	{
		sab(stack);
		(*result)->final = add_to_string((*result)->final, "sa\n");
	}
	else if ((*stack)->diff == 2 && ((*stack)->num < (*stack)->next->num))
	{
		sab(stack);
		(*result)->final = add_to_string((*result)->final, "sb\n");
	}
}
