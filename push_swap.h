/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:25:00 by fshields          #+#    #+#             */
/*   Updated: 2024/01/15 17:22:33 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "_LIBFT/libft.h"
# include <limits.h>

//init_stack.c
t_int_list	*init_stack(int argc, char *argv[], int type);

//utils.c
void		*free_stack(t_int_list **stack);
int			count_numbers(char *str);
void		format_stack(t_int_list **stack);

//valid_input.c
int			valid_input(int argc, char *argv[]);
int			check_duplicates(t_int_list *stack);
int			all_space(char *str);

//stack_analysis.c
int			get_smallest(t_int_list *stack);
int			get_largest(t_int_list *stack);
int			n_in_first_half(t_int_list *stack, int n);
int			stack_ascending(t_int_list *stack);
int			stack_descending(t_int_list *stack);

//algorithms.c
void		algorithm_small(t_int_list **a, t_int_list **b);
void		algorithm_large(t_int_list **a, t_int_list **b);

//operations
void		sa(t_int_list *stack_a);
void		sb(t_int_list *stack_b);
void		ss(t_int_list *stack_a, t_int_list *stack_b);
void		pa(t_int_list **stack_a, t_int_list **stack_b);
void		pb(t_int_list **stack_a, t_int_list **stack_b);
void		ra(t_int_list **stack_a);
void		rb(t_int_list **stack_b);
void		rr(t_int_list **stack_a, t_int_list **stack_b);
void		rra(t_int_list **stack_a);
void		rrb(t_int_list **stack_b);
void		rrr(t_int_list **stack_a, t_int_list **stack_b);

#endif