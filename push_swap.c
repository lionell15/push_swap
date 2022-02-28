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

int error(void)
{
	write(1, "Error: ", 7);
	return (0);
}

int	main(int ac, char **av)
{
	t_stack		*stackA;
	t_stack		*stackB;
	t_com		*result;
	int			len;

	stackA = args_to_stack(ac, av);
	if (!stackA)
		error();
	len = get_stack_len(stackA);
	result = get_new_result();
	if (len < 4)
	{
		short_solution(&stackA, len);
		stack_del(&stackA);
	}
	else
		sort_stack(&stackA, &stackB, &result, len);
	print_result(result->final);
	stack_del(&stackA);
	free(result);
	return(0);
}
