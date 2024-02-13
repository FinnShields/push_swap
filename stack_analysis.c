/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_analysis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:40:39 by fshields          #+#    #+#             */
/*   Updated: 2024/01/15 12:28:40 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_smallest(t_int_list *stack)
{
	int	smallest;

	smallest = stack->value;
	if (ft_int_lstsize(stack) == 1)
		return (smallest);
	while (stack)
	{
		if ((stack->value) < smallest)
			smallest = stack->value;
		stack = stack->next;
	}
	return (smallest);
}

int	get_largest(t_int_list *stack)
{
	int	largest;

	largest = stack->value;
	while (stack)
	{
		if (stack->value > largest)
			largest = stack->value;
		stack = stack->next;
	}
	return (largest);
}

int	n_in_first_half(t_int_list *stack, int n)
{
	int	count;
	int	len;

	len = ft_int_lstsize(stack);
	count = 0;
	while ((stack->value) != n)
	{
		count ++;
		stack = stack->next;
	}
	return ((len / 2) >= count);
}

int	stack_ascending(t_int_list *stack)
{
	int	n;

	if (!stack)
		return (0);
	n = stack->value;
	stack = stack->next;
	while (stack)
	{
		if (stack->value < n)
			return (0);
		n = stack->value;
		stack = stack->next;
	}
	return (1);
}

int	stack_descending(t_int_list *stack)
{
	int	n;

	if (!stack)
		return (0);
	n = stack->value;
	stack = stack->next;
	while (stack)
	{
		if (stack->value > n)
			return (0);
		n = stack->value;
		stack = stack->next;
	}
	return (1);
}
