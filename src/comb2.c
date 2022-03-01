/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comb2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespinoz <lespinoz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:32:50 by lespinoz          #+#    #+#             */
/*   Updated: 2022/03/01 14:32:53 by lespinoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	comb_6(t_stack **stack, t_com **result)
{
	rrab(stack);
	sab(stack);
	if ((*stack)->diff == 1)
		(*result)->final = add_to_string((*result)->final, "rra\nsa\n");
	else
		(*result)->final = add_to_string((*result)->final, "rrb\nsb\n");
}

void	comb_7(t_stack **stack, t_com **result)
{
	rab(stack);
	if ((*stack)->diff == 1)
		(*result)->final = add_to_string((*result)->final, "ra\n");
	else
		(*result)->final = add_to_string((*result)->final, "rb\n");
}

void	comb_8(t_stack **stack, t_com **result)
{
	rrab(stack);
	if ((*stack)->diff == 1)
		(*result)->final = add_to_string((*result)->final, "rra\n");
	else
		(*result)->final = add_to_string((*result)->final, "rrb\n");
}

void	comb_9(t_stack **stack, t_com **result)
{
	rab(stack);
	sab(stack);
	if ((*stack)->diff == 1)
		(*result)->final = add_to_string((*result)->final, "ra\nsa\n");
	else
		(*result)->final = add_to_string((*result)->final, "rb\nsb\n");
}
