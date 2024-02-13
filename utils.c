/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:15:24 by fshields          #+#    #+#             */
/*   Updated: 2024/01/15 12:28:07 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*free_stack(t_int_list **stack)
{
	t_int_list	*temp;

	while (*stack)
	{
		(*stack)->value = 0;
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	return (NULL);
}

int	count_numbers(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (ft_isdigit(*str) > 0 && (*(str + 1) == ' ' || *(str + 1) == '\0'))
			count ++;
		str ++;
	}
	return (count);
}

static int	get_next_smallest(t_int_list *stack, int small)
{
	int	rtn;

	rtn = INT_MAX;
	while (stack)
	{
		if (stack->value < rtn && stack->value > small)
			rtn = stack->value;
		stack = stack->next;
	}
	return (rtn);
}

static void	bring_up(t_int_list **stack)
{
	t_int_list	*ptr;

	ptr = *stack;
	while (ptr)
	{
		ptr->value += INT_MAX;
		ptr->value ++;
		ptr = ptr->next;
	}
}

void	format_stack(t_int_list **stack)
{
	int			small;
	int			i;
	t_int_list	*ptr;

	ptr = *stack;
	i = 0;
	small = get_smallest(*stack);
	while (i < ft_int_lstsize(*stack))
	{
		if (ptr->value == small)
		{
			ptr->value = INT_MIN + i;
			i ++;
			small = get_next_smallest(*stack, small);
		}
		ptr = ptr->next;
		if (!ptr)
			ptr = *stack;
	}
	bring_up(stack);
}
