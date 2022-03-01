/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespinoz <lespinoz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 13:27:19 by lespinoz          #+#    #+#             */
/*   Updated: 2022/03/01 13:27:21 by lespinoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	compare(int a, int b, int ifsi, int ifno)
{
	if (a > b)
		return (ifsi);
	else
		return (ifno);
}

int	error(void)
{
	write(1, "Error: ", 7);
	return (0);
}

int	find_mid_value(t_stack *stack, int len)
{
	int		*array;
	int		mid_value;

	len = compare(len, get_stack_len(stack), get_stack_len(stack), len);
	array = array_from_list(stack, len);
	quick_sort(array, 0, len - 1);
	mid_value = array[len / 2];
	free(array);
	return (mid_value);
}
