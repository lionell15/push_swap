/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespinoz <lespinoz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:41:37 by lespinoz          #+#    #+#             */
/*   Updated: 2022/03/01 14:41:39 by lespinoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	add_pa_pb(char **origin, char **res, int i)
{
	int		pa;
	int		pb;
	int		x;

	pa = 0;
	pb = 0;
	x = 0;
	while (origin[i] && (ft_strequ(origin[i], "pa")
			|| ft_strequ(origin[i], "pb")))
	{
		if (ft_strequ(origin[i], "pa"))
			pa++;
		if (ft_strequ(origin[i], "pb"))
			pb++;
		i++;
	}
	x = compare(pa, pb, (pa - pb), 0);
	while (x-- > 0)
		*res = add_to_string(*res, "pa\n");
	x = compare(pb, pa, (pb - pa), 0);
	while (x-- > 0)
		*res = add_to_string(*res, "pb\n");
	return (i);
}

int	add_ra_rra(char **origin, char **res, int i)
{
	int		ra;
	int		rra;
	int		x;

	ra = 0;
	rra = 0;
	x = 0;
	while (origin[i] && (ft_strequ(origin[i], "ra")
			|| ft_strequ(origin[i], "rra")))
	{
		if (ft_strequ(origin[i], "ra"))
			ra++;
		if (ft_strequ(origin[i], "rra"))
			rra++;
		i++;
	}
	x = compare(ra, rra, (ra - rra), 0);
	while (x-- > 0)
		*res = add_to_string(*res, "ra\n");
	x = compare(rra, ra, (rra - ra), 0);
	while (x-- > 0)
		*res = add_to_string(*res, "rra\n");
	return (i);
}

int	add_rb_rrb(char **origin, char **res, int i)
{
	int		rb;
	int		rrb;
	int		x;

	rb = 0;
	rrb = 0;
	x = 0;
	while (origin[i] && (ft_strequ(origin[i], "rb")
			|| ft_strequ(origin[i], "rrb")))
	{
		if (ft_strequ(origin[i], "rb"))
			rb++;
		if (ft_strequ(origin[i], "rrb"))
			rrb++;
		i++;
	}
	x = compare(rb, rrb, (rb - rrb), 0);
	while (x-- > 0)
		*res = add_to_string(*res, "rb\n");
	x = compare(rrb, rb, (rrb - rb), 0);
	while (x-- > 0)
		*res = add_to_string(*res, "rrb\n");
	return (i);
}

int	add_others(char **tmp, char **res, int i)
{
	while (tmp[i] && !(ft_strequ(tmp[i], "pa") || ft_strequ(tmp[i], "pb")
			|| ft_strequ(tmp[i], "ra") || ft_strequ(tmp[i], "rb")
			|| ft_strequ(tmp[i], "rra") || ft_strequ(tmp[i], "rrb")))
	{
		*res = add_to_string(*res, tmp[i]);
		*res = add_to_string(*res, "\n");
		i++;
	}
	return (i);
}
