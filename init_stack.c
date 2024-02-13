/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 13:56:08 by fshields          #+#    #+#             */
/*   Updated: 2024/01/15 17:18:17 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*new_arr(char *str, int len)
{
	int	*arr;
	int	*arr_start;

	arr = malloc(len * sizeof(int));
	if (!arr)
		return (NULL);
	arr_start = arr;
	while (*str == 32 && *str)
		str ++;
	while (*str)
	{
		*(arr++) = ft_atoi(str);
		if ((long long) ft_atoi(str) != ft_atoi_long(str))
		{
			free(arr_start);
			return (NULL);
		}
		while (*str != 32 && *str)
			str ++;
		while (*str == 32 && *str)
			str ++;
	}
	arr -= len;
	return (arr);
}

static	void	add_to_stack(t_int_list **stack, int value)
{
	t_int_list	*new;

	new = ft_int_lstnew(value);
	ft_int_lstadd_back(stack, new);
}

static t_int_list	*init_type_1(char *argv[])
{
	t_int_list	*stack;
	int			*values;
	int			len;
	int			i;

	i = 1;
	len = count_numbers(argv[1]);
	if (!len)
		return (NULL);
	stack = NULL;
	values = new_arr(argv[1], len);
	if (!values)
		return (NULL);
	while (i < len + 1)
	{
		add_to_stack(&stack, *values);
		i ++;
		values ++;
	}
	free(values - len);
	if (check_duplicates(stack) == 1)
		return (free_stack(&stack));
	return (stack);
}

static t_int_list	*init_type_2(int argc, char *argv[])
{
	t_int_list	*stack;
	int			value;
	int			i;

	i = 1;
	stack = NULL;
	while (i < argc)
	{
		value = ft_atoi(argv[i]);
		if ((long) value != ft_atoi_long(argv[i]))
			return (free_stack(&stack));
		add_to_stack(&stack, value);
		i ++;
	}
	if (check_duplicates(stack) == 1)
		return (free_stack(&stack));
	return (stack);
}

t_int_list	*init_stack(int argc, char *argv[], int type)
{
	if (type == 0)
		return (NULL);
	else if (type == 1)
		return (init_type_1(argv));
	else if (type == 2)
		return (init_type_2(argc, argv));
	return (NULL);
}
