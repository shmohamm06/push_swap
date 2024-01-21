/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:46:16 by shmohamm          #+#    #+#             */
/*   Updated: 2024/01/21 12:01:00 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_items(t_stack *stack)
{
	if (stack->stack_a[2] != 2)
	{
		if (stack->stack_a[0] == 2)
			rotate_elements(stack->stack_a, stack->stack_a_size, "up", "a");
		else
			rotate_elements(stack->stack_a, stack->stack_a_size, "down", "a");
	}
	if (stack->stack_a[0] > stack->stack_a[1])
		swap_elements("sa", stack->stack_a, stack->stack_a_size);
}

void	sort_four_to_five_items(t_stack *stack)
{
	while (stack->stack_b_size <= 1)
	{
		if (stack->stack_a[0] == 0 || stack->stack_a[0] == 1)
			push_elements("pb", stack);
		else
			rotate_elements(stack->stack_a, stack->stack_a_size, "up", "a");
	}
	if (stack->stack_b[0] == 0)
		swap_elements("sb", stack->stack_b, stack->stack_b_size);
	if (stack->stack_a[2] != 4)
	{
		if (stack->stack_a[0] == 4)
			rotate_elements(stack->stack_a, stack->stack_a_size, "up", "a");
		else
			rotate_elements(stack->stack_a, stack->stack_a_size, "down", "a");
	}
	if (stack->stack_a[0] > stack->stack_a[1])
		swap_elements("sa", stack->stack_a, stack->stack_a_size);
	push_elements("pa", stack);
	push_elements("pa", stack);
}
