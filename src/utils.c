/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespinoz <lespinoz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:20:45 by lespinoz          #+#    #+#             */
/*   Updated: 2022/03/10 13:20:47 by lespinoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_error(char *msg)
{
	ft_putstr_fd(msg, 1);
	ft_putstr_fd("\n", 1);
	exit(0);
}

void	del_stack(t_stack **stack)
{
	t_stack	*head;
	t_stack	*tmp;

	head = *stack;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(stack);
}

void	free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
		free(str[i--]);
}

int	is_sorted(t_stack **stack)
{
	t_stack	*first;

	first = *stack;
	while (first && first->next)
	{
		if (first->value > first->next->value)
			return (0);
		first = first->next;
	}
	return (1);
}

int	get_distance(t_stack **stack, int index)
{
	t_stack	*first;
	int		distance;

	distance = 0;
	first = *stack;
	while (first)
	{
		if (first->index == index)
			break ;
		distance++;
		first = first->next;
	}
	return (distance);
}
