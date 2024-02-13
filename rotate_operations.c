/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:39:53 by fshields          #+#    #+#             */
/*   Updated: 2024/01/15 12:07:53 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_int_list **stack)
{
	t_int_list	*temp;
	t_int_list	*last;

	if (ft_int_lstsize(*stack) <= 1)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	last->next = temp;
	last->next->next = NULL;
}

void	ra(t_int_list **stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
}

void	rb(t_int_list **stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
}

void	rr(t_int_list **stack_a, t_int_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}
