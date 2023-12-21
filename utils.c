/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:15:24 by fshields          #+#    #+#             */
/*   Updated: 2023/12/21 16:53:39 by fshields         ###   ########.fr       */
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

//returns 1 if stack is correctly sorted
//and 0 otherwise
int	solution_valid(t_int_list *a, t_int_list *b)
{
	if (stack_ascending(a) == 1 && !b)
		return (1);
	return (0);
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
