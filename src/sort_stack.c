/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespinoz <lespinoz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 15:42:55 by lespinoz          #+#    #+#             */
/*   Updated: 2022/03/01 15:42:57 by lespinoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	div_stacks(t_stack **stack1, t_stack **stack2, t_com **result, int len)
{
	int	div;

	if ((*stack1)->diff == 1)
		div = div_stack_a(stack1, stack2, result, len);
	else
		div = div_stack_b(stack1, stack2, result, len);
	return (div);
}

void	sort_stacks(t_stack **stack1, t_stack **stack2, t_com **result,
	int len)
{
	int	div;

	if (len == 2 || len == 3)
		return ;
	div = div_stacks(stack1, stack2, result, len);
	if ((*result)->rotator == 1)
		rotate_back(stack1, result, div);
	if ((*stack1)->diff == 1 && (len / 2 == 3 || len / 2 == 2))
		swap_elements(stack1, stack2, result, len);
	else if ((*stack1)->diff == 2 && (len / 2 == 3 || len / 2 == 2))
		swap_elements(stack1, stack2, result, len);
	if ((*stack1)->diff != 1)
		sort_stacks(stack1, stack2, result, (len / 2));
	else
		sort_stacks(stack1, stack2, result, (len - len / 2));
	if ((*stack1)->diff == 1)
		sort_stacks(stack2, stack1, result, (len / 2));
	else
		sort_stacks(stack2, stack1, result, (len - len / 2));
	if ((*stack1)->diff == 1)
		push_back(stack1, stack2, result, len / 2);
	else
		push_back(stack1, stack2, result, len - len / 2);
}
