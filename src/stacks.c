/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespinoz <lespinoz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 16:28:57 by lespinoz          #+#    #+#             */
/*   Updated: 2022/03/01 16:29:00 by lespinoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_stack_len(t_stack *stack)
{
	int		len;
	t_stack	*tmp;

	len = 0;
	tmp = stack;
	while (tmp)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}

void	stack_del(t_stack **stack)
{
	t_stack	*del;
	t_stack	*tmp;

	tmp = *stack;
	while (tmp)
	{
		del = tmp;
		tmp = tmp->next;
		free(del);
	}
	*stack = NULL;
}

t_stack	*create_node(void)
{
	t_stack	*first_element;

	first_element = (t_stack *)malloc(sizeof(t_stack));
	first_element->num = 0;
	first_element->diff = 1;
	first_element->next = NULL;
	return (first_element);
}

t_stack	*args_to_stack(int ac, char **av)
{
	t_stack		*first_element;
	t_stack		*aux;
	int			index;

	index = 1;
	first_element = create_node();
	aux = first_element;
	while (index < ac)
	{
		if (check_av(av[index]))
		{
			stack_del(&first_element);
			return (NULL);
		}
		aux->num = ft_atoi(av[index]);
		if (index < ac -1)
		{
			aux->next = create_node();
			aux = aux->next;
			aux->diff = 1;
		}
		index++;
	}
	check_doubles(&first_element);
	return (first_element);
}
