/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespinoz <lespinoz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:47:23 by lespinoz          #+#    #+#             */
/*   Updated: 2022/03/01 14:47:29 by lespinoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int	partition(int *stack1, int start, int end)
{
	int	end_value;
	int	strt_indx;
	int	curr_indx;

	end_value = stack1[end];
	strt_indx = start - 1;
	curr_indx = start;
	while (curr_indx <= end - 1)
	{
		if (stack1[curr_indx] <= end_value)
		{
			strt_indx++;
			ft_swap(&stack1[strt_indx], &stack1[curr_indx]);
		}
		curr_indx++;
	}
	ft_swap(&stack1[strt_indx + 1], &stack1[end]);
	return (strt_indx + 1);
}

void	quick_sort(int *stack1, int start, int end)
{
	int	*stack2;
	int	top;
	int	pivot;

	stack2 = malloc(end + 1);
	top = -1;
	stack2[++top] = start;
	stack2[++top] = end;
	while (top >= 0)
	{
		end = stack2[top--];
		start = stack2[top--];
		pivot = partition(stack1, start, end);
		if (pivot - 1 > start)
		{
			stack2[++top] = start;
			stack2[++top] = pivot - 1;
		}
		if (pivot + 1 < end)
		{
			stack2[++top] = pivot + 1;
			stack2[++top] = end;
		}
	}
}
