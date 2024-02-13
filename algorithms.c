/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:38:33 by fshields          #+#    #+#             */
/*   Updated: 2024/01/15 17:32:40 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(t_int_list *stack)
{
	int	max_num;
	int	max_bits;

	max_num = get_largest(stack);
	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		max_bits ++;
	return (max_bits);
}

static void	send_to_b(t_int_list **a, t_int_list **b, int i)
{
	int	size;
	int	j;

	size = ft_int_lstsize(*a);
	j = 0;
	while (j < size)
	{
		if ((((*a)->value >> i) & 1) == 1)
			ra(a);
		else
			pb(a, b);
		j ++;
	}
}

static int	ready_for_final(t_int_list **a, t_int_list **b)
{
	if (stack_ascending(*a))
	{
		if (!*b || stack_descending(*b))
		{
			if ((*a) && (*b))
			{
				if (get_smallest(*a) > get_largest(*b))
					return (1);
				return (0);
			}
			return (1);
		}
	}
	if (!(*a))
	{
		if (stack_descending(*b))
			return (1);
	}
	return (0);
}

void	algorithm_large(t_int_list **a, t_int_list **b)
{
	int	max_bits;
	int	i;

	i = 0;
	if (stack_ascending(*a))
		return ;
	max_bits = get_max_bits(*a);
	while (i < max_bits)
	{
		send_to_b(a, b, i);
		while (*b)
			pa(a, b);
		i ++;
	}
}

void	algorithm_small(t_int_list **a, t_int_list **b)
{
	int	small;

	while (!ready_for_final(a, b))
	{
		small = get_smallest(*a);
		if ((*a)->value == small)
			pb(a, b);
		else if ((*a)->value == get_largest(*a) && (*a)->next->value == small)
			ra(a);
		else if ((*a)->value > (*a)->next->value)
			sa(*a);
		else
		{
			if (n_in_first_half(*a, small))
			{
				ra(a);
				ra(a);
			}
			else
				rra(a);
		}
	}
	while (*b)
		pa(a, b);
}
