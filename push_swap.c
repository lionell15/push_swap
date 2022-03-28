/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespinoz <lespinoz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:59:45 by lespinoz          #+#    #+#             */
/*   Updated: 2022/03/10 13:40:05 by lespinoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*get_min(t_stack **stack)
{
	t_stack	*first;
	t_stack	*minim;
	int		has_min;

	minim = NULL;
	has_min = 0;
	first = *stack;
	if (first)
	{
		while (first)
		{
			if ((first->index == -1)
				&& (!has_min || first->value < minim->value))
			{
				minim = first;
				has_min = 1;
			}
			first = first->next;
		}
	}
	return (minim);
}

static void	get_index(t_stack **stack)
{
	t_stack	*first;
	int		index;

	index = 0;
	first = get_min(stack);
	while (first)
	{
		first->index = index++;
		first = get_min(stack);
	}
}

static void	initialize_stack(t_stack **stack, int ac, char **av)
{
	t_stack	*new;
	char	**arguments;
	int		i;

	i = 0;
	if (ac == 2)
		arguments = ft_split(av[1], ' ');
	else
	{
		i = 1;
		arguments = av;
	}
	while (arguments[i])
	{
		new = ft_lstnew((int)ft_atoi(arguments[i]));
		ft_lstadd_back(stack, new);
		i++;
	}
	get_index(stack);
	if (ac == 2)
		free_str(arguments);
}

int	main(int ac, char **av)
{
	t_stack	**stack_a;
	t_stack	**stack_b;

	if (ac > 2)
	{
		ft_check_args(ac, av);
		stack_a = (t_stack **)malloc(sizeof(t_stack));
		stack_b = (t_stack **)malloc(sizeof(t_stack));
		initialize_stack(stack_a, ac, av);
		if (is_sorted(stack_a))
		{
			del_stack(stack_a);
			del_stack(stack_b);
		}
		else
		{
			sort_stack(stack_a, stack_b);
			del_stack(stack_a);
			del_stack(stack_b);
		}
	}
	return (0);
}
