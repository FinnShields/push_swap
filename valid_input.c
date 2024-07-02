/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 13:34:00 by fshields          #+#    #+#             */
/*   Updated: 2024/01/15 17:24:12 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	input_1(char *argv[])
{
	int	i;

	i = 0;
	if (argv[1][i] == '\0')
		return (1);
	if (argv[1][i] == '-')
	{
		if (ft_isdigit(argv[1][i + 1]) == 0)
			return (0);
		i ++;
	}
	while (argv[1][i] != '\0')
	{
		if (ft_isdigit(argv[1][i]) == 0 && argv[1][i] \
		!= ' ' && argv[1][i] != '-')
			return (0);
		if (argv[1][i] == '-')
		{
			if (argv[1][i - 1] != ' ' || ft_isdigit(argv[1][i + 1]) == 0)
				return (0);
		}
		i ++;
	}
	return (1);
}

static int	input_2(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		if (argv[i][j] == '-')
		{
			if (ft_isdigit(argv[i][j + 1]) == 0)
				return (0);
			j ++;
		}
		while (argv[i][j] != '\0')
		{
			if (ft_isdigit(argv[i][j]) == 0)
				return (0);
			j ++;
		}
		i ++;
		j = 0;
	}
	return (2);
}

//returns 0 if input is invalid, 1 if input is one valid string
//and 2 if the input is many strings
int	valid_input(int argc, char *argv[])
{
	if (argc == 2)
		return (input_1(argv));
	else if (argc > 2)
		return (input_2(argc, argv));
	return (0);
}

int	check_duplicates(t_int_list *stack)
{
	t_int_list	*check;

	check = stack;
	stack = stack->next;
	while (check->next != NULL)
	{
		while (stack)
		{
			if (stack->value == check->value)
				return (1);
			stack = stack->next;
		}
		check = check->next;
		stack = check->next;
	}
	return (0);
}

int	all_space(char *str)
{
	while (*str)
	{
		if (*str != ' ')
			return (0);
		str ++;
	}
	return (1);
}
