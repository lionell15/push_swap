/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespinoz <lespinoz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:27:55 by lespinoz          #+#    #+#             */
/*   Updated: 2022/03/01 14:27:57 by lespinoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	check_overflow(char *str)
{
	if (str[0] == '-')
	{
		if (ft_atoi(str) > 0)
			return (1);
	}
	if (str[0] != '-')
	{
		if (ft_atoi(str) < 0)
			return (1);
	}
	return (0);
}

int	check_av(char *str)
{
	int	i;
	int	len;

	i = 0;
	if (str[i] == '-' && !ft_isdigit(str[i + 1]))
		return (1);
	if (str[i] == '-' && ft_isdigit(str[i + 1]))
		i++;
	len = ft_strlen(&str[i]);
	if (len > 10)
		return (1);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	if (len == 10 && check_overflow(str))
		return (1);
	return (0);
}

void	check_doubles(t_stack **stack)
{
	int		*array;
	int		len;
	int		i;

	i = 0;
	len = get_stack_len(*stack);
	array = array_from_list(*stack, len);
	quick_sort(array, 0, len - 1);
	while (i < len - 1)
	{
		if (array[i] >= array[i + 1])
		{
			stack_del(stack);
			free(array);
			return ;
		}
		i++;
	}
	free(array);
}
