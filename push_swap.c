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
	t_com		*combi_result;
	int			size_args;

	stack_a = args_to_stack(ac, av);
	if (!stack_a)
		error();
	size_args = get_stack_len(stack_a);
	combi_result = new_result();
	if (size_args > 3)
		sort_stacks(&stack_a, &stack_b, &combi_result, size_args);
	else
		short_solution(&stack_a, size_args);
	print_result(combi_result->final);
	stack_del(&stack_a);
	free(combi_result);
	return (0);
}
