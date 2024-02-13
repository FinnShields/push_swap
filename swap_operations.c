/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:51:57 by fshields          #+#    #+#             */
/*   Updated: 2024/01/15 12:07:58 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_int_list *stack)
{
	int	temp;

	if (!stack || ft_int_lstsize(stack) <= 1)
		return ;
	temp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = temp;
}

void	sa(t_int_list *stack_a)
{
	swap(stack_a);
	ft_printf("sa\n");
}

void	sb(t_int_list *stack_b)
{
	swap(stack_b);
	ft_printf("sb\n");
}

void	ss(t_int_list *stack_a, t_int_list *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}
