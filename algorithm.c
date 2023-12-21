/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:38:33 by fshields          #+#    #+#             */
/*   Updated: 2023/12/21 16:57:22 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_smallest_to_up(t_int_list **stack)
{
	int	smallest;
	int	i;

	i = 0;
	smallest = get_smallest(*stack);
	if (smallest == (*stack)->value)
		return ;
	if (n_in_first_half(*stack, smallest) == 1)
	{
		while ((*stack)->value != smallest)
		{
			ra(stack);
			ft_printf("ra\n");
		}
		return ;
	}
	while ((*stack)->value != smallest)
	{
		rra(stack);
		ft_printf("rra\n");
	}
}

void	algorithm(t_int_list **a, t_int_list **b)
{
	while (!stack_ascending(*a))
	{
		move_smallest_to_up(a);
		pb(a, b);
		ft_printf("pb\n");
	}
	while (*b)
	{
		pa(a, b);
		ft_printf("pa\n");
	}
}
