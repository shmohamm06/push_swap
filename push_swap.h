/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:00:03 by shmohamm          #+#    #+#             */
/*   Updated: 2024/01/23 10:07:02 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include "limits.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int		*stack_a;
	int		*stack_b;
	int		stack_a_size;
	int		stack_b_size;
	char	*join_args;
}			t_stack;

// Sort functions
void		three_nbrs(t_stack *stack);
void		four_or_five_nbrs(t_stack *stack);

// Rotate and Swap
void		rotate_up(int *array, int size, char *list);
void		rotate_down(int *array, int size, char *list);
void		rotate_elements(int *array, int size, char *direction, char *list);
void		swap_elements(char *str, int *array, int size);

//Push
void		push_pa(t_stack *stack);
void		push_pb(t_stack *stack);
void		push_elements(char *str, t_stack *stack);

// Radix
void		radix_sort_stack_b(t_stack *stack, int b_size, int bit_size, int j);
void		apply_radix_sort(t_stack *stack);

// Parsing
void		dup_or_sorted(t_stack *stack, int i);
void		exit_program(t_stack *stack, char *msg);
void		validate_arguments(int argc, char **argv);
void		combine_arguments(int argc, char **argv, t_stack *stack);
int			is_stack_sorted(t_stack *stack);

// Utilities
int			ft_atol(const char *n, t_stack *stack);
void		read_numbers(t_stack *stack);
void		initialize_stacks(int argc, char **argv, t_stack *stack);
void		initialize_index(int *new_a, t_stack *stack);
void		create_index(t_stack *stack);

#endif
