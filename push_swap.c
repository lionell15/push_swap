/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespinoz <lespinoz@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:55:11 by lespinoz          #+#    #+#             */
/*   Updated: 2022/02/27 19:26:54 by lespinoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_com		*result;
	int			len;

	stack_a = args_to_stack(ac, av);
	if (!stack_a)
		error();
	len = get_stack_len(stack_a);
	result = get_new_result();
	if (len < 4)
	{
		short_solution(&stack_a, len);
		stack_del(&stack_a);
	}
	else
		sort_stacks(&stack_a, &stack_b, &result, len);
	print_result(result->final);
	stack_del(&stack_a);
	free(result);
	return (0);
}
