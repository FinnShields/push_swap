/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_operations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:52:39 by fshields          #+#    #+#             */
/*   Updated: 2024/01/15 12:08:06 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate(t_int_list **stack)
{
	t_int_list	*temp;
	t_int_list	*last;

	if (ft_int_lstsize(*stack) <= 1)
		return ;
	temp = *stack;
	while ((*stack)->next->next != NULL)
		*stack = (*stack)->next;
	last = *stack;
	*stack = (*stack)->next;
	(*stack)->next = temp;
	last->next = NULL;
}

void	rra(t_int_list **stack_a)
{
	rev_rotate(stack_a);
	ft_printf("rra\n");
}

void	rrb(t_int_list **stack_b)
{
	rev_rotate(stack_b);
	ft_printf("rrb\n");
}

void	rrr(t_int_list **stack_a, t_int_list **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	ft_printf("rrr\n");
}
