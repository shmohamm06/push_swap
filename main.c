/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:43:05 by shmohamm          #+#    #+#             */
/*   Updated: 2024/03/06 19:59:14 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack;

	if (argc < 2)
		return (0);
	validate_arguments(argc, argv);
	initialize_stacks(argc, argv, &stack);
	combine_arguments(argc, argv, &stack);
	read_numbers(&stack);
	check_for_dup_or_sorted(&stack, 0);
	create_index(&stack);
	if (stack.stack_a_size == 2 && stack.stack_a[0] > stack.stack_a[1])
		swap_elements("sa", stack.stack_a, stack.stack_a_size);
	else if (stack.stack_a_size == 3)
		sort_three_items(&stack);
	else if (stack.stack_a_size >= 4 && stack.stack_a_size <= 5)
		sort_four_to_five_items(&stack);
	else
		apply_radix_sort(&stack);
	check_for_dup_or_sorted(&stack, 1);
	exit_program(&stack, "Error\n");
	return (0);
}
