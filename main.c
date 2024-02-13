/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:21:39 by fshields          #+#    #+#             */
/*   Updated: 2024/01/15 17:35:06 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_int_list	*stack_a;
	t_int_list	*stack_b;

	if (argc == 1)
		return (0);
	if (argc == 2 && all_space(argv[1]))
		return (0);
	stack_a = init_stack(argc, argv, valid_input(argc, argv));
	stack_b = NULL;
	if (!stack_a)
		return (write(2, "Error\n", 6));
	format_stack(&stack_a);
	if (ft_int_lstsize(stack_a) < 50)
		algorithm_small(&stack_a, &stack_b);
	else
		algorithm_large(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
