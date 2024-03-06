/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:44:43 by shmohamm          #+#    #+#             */
/*   Updated: 2024/03/06 15:49:35 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <limits.h>
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
void		swap_elements(char *str, int *array, int size);
void		sort_three_items(t_stack *stack);
void		sort_four_to_five_items(t_stack *stack);

// Rotate
void		rotate_up(int *array, int size);
void		rotate_down(int *array, int size);
void		rotate_elements(int *array, int size, char *direction, char *list);
void		rotate_elements(int *array, int size, char *direction, char *list);

// Push
void		push_pa(t_stack *stack);
void		push_pb(t_stack *stack);
void		push_elements(char *str, t_stack *stack);

// Radix Sort
void		radix_sort_stack_b(t_stack *stack, int b_size, int bit_size, int j);
void		apply_radix_sort(t_stack *stack);

// Utilities_1
void		validate_arguments(int argc, char **argv);
void		initialize_stacks(int argc, char **argv, t_stack *stack);
void		combine_arguments(int argc, char **argv, t_stack *stack);
void		read_numbers(t_stack *stack);
void		exit_program(t_stack *stack, char *msg);

// Utilities_2
int			is_stack_sorted(t_stack *stack);
void		check_for_dup_or_sorted(t_stack *stack, int i);
void		create_index(t_stack *stack);
long		ft_atoi2(const char *str, t_stack *stack);
long long	calculate_value(const char *str, int i, long long sign,
				t_stack *stack);

#endif
