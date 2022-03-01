/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespinoz <lespinoz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 13:26:08 by lespinoz          #+#    #+#             */
/*   Updated: 2022/03/01 13:26:11 by lespinoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_com	*get_new_result(void)
{
	t_com	*new;
	int		i;

	i = 0;
	new = (t_com *)malloc(sizeof(t_com));
	new->rotator = 0;
	new->final = ft_strdup("\0");
	return (new);
}

void	ft_strdel(char **as)
{
	if (as == NULL)
		return ;
	free(*as);
	*as = NULL;
}

int	ft_strequ(char const *s1, char const *s2)
{
	if (s1 == NULL || s2 == NULL)
		return (0);
	if (ft_strlen(s1) != ft_strlen(s2))
		return (0);
	else if (ft_strncmp(s1, s2, ft_strlen(s1)) != 0)
		return (0);
	else
		return (1);
}

static void	free_memory(char **tmp, char **origin, char **result)
{
	int		i;

	i = 0;
	while (tmp[i])
	{
		free(tmp[i]);
		i++;
	}
	free(tmp);
	ft_strdel(origin);
	ft_strdel(result);
}

void	print_result(char *origin)
{
	char	**tmp;
	char	*result;
	int		i;

	i = 0;
	result = ft_strdup("\0");
	tmp = ft_split(origin, '\n');
	while (tmp[i])
	{
		if (tmp[i] && (ft_strequ(tmp[i], "pa") || ft_strequ(tmp[i], "pb")))
			i = add_pa_pb(tmp, &result, i);
		if (tmp[i] && (ft_strequ(tmp[i], "ra") || ft_strequ(tmp[i], "rra")))
			i = add_ra_rra(tmp, &result, i);
		if (tmp[i] && (ft_strequ(tmp[i], "rb") || ft_strequ(tmp[i], "rrb")))
			i = add_rb_rrb(tmp, &result, i);
		if (tmp[i] && !(ft_strequ(tmp[i], "pa") || ft_strequ(tmp[i], "pb")
				|| ft_strequ(tmp[i], "ra") || ft_strequ(tmp[i], "rb")
				|| ft_strequ(tmp[i], "rra") || ft_strequ(tmp[i], "rrb")))
			i = add_others(tmp, &result, i);
	}
	ft_putstr_fd(result, 1);
	free_memory(tmp, &origin, &result);
}
