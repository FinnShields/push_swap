/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:21:39 by fshields          #+#    #+#             */
/*   Updated: 2023/12/21 17:02:32 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Happy new year me! Project is now working! Only problem is that the algorithm is 
a little slow, so the next thing to do is tweek that a bit*/

int	main(int argc, char *argv[])
{
	t_int_list	*stack_a;
	t_int_list	*stack_b;

	if (argc == 1)
		return (0);
	stack_a = init_stack(argc, argv, valid_input(argc, argv));
	stack_b = NULL;
	if (!stack_a)
		return (ft_printf("Error\n"));
	algorithm(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
