/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comb.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespinoz <lespinoz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:32:10 by lespinoz          #+#    #+#             */
/*   Updated: 2022/03/01 14:32:14 by lespinoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	comb_1(t_stack **stack, t_com **result)
{
	sab(stack);
	if ((*stack)->diff == 1)
		(*result)->final = add_to_string((*result)->final, "sa\n");
	else
		(*result)->final = add_to_string((*result)->final, "sb\n");
}

void	comb_2(t_stack **stack, t_com **result)
{
	rab(stack);
	sab(stack);
	rrab(stack);
	if ((*stack)->diff == 1)
		(*result)->final = add_to_string((*result)->final, "ra\nsa\nrra\n");
	else
		(*result)->final = add_to_string((*result)->final, "rb\nsb\nrrb\n");
}

void	comb_3(t_stack **stack, t_com **result)
{
	sab(stack);
	rab(stack);
	sab(stack);
	rrab(stack);
	if ((*stack)->diff == 1)
		(*result)->final = add_to_string((*result)->final, "sa\nra\nsa\nrra\n");
	else
		(*result)->final = add_to_string((*result)->final, "sb\nrb\nsb\nrrb\n");
}

void	comb_4(t_stack **stack, t_com **result)
{
	rab(stack);
	sab(stack);
	rrab(stack);
	sab(stack);
	if ((*stack)->diff == 1)
		(*result)->final = add_to_string((*result)->final, "ra\nsa\nrra\nsa\n");
	else
		(*result)->final = add_to_string((*result)->final, "rb\nsb\nrrb\nsb\n");
}

void	comb_5(t_stack **stack, t_com **result)
{
	sab(stack);
	rab(stack);
	sab(stack);
	rrab(stack);
	sab(stack);
	if ((*stack)->diff == 1)
		(*result)->final = add_to_string((*result)->final,
				"sa\nra\nsa\nrra\nsa\n");
	else
		(*result)->final = add_to_string((*result)->final,
				"sb\nrb\nsb\nrrb\nsb\n");
}
