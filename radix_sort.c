/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:43:58 by shmohamm          #+#    #+#             */
/*   Updated: 2024/03/06 16:12:03 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort_stack_b(t_stack *stack, int b_size, int bit_size, int j)
{
	int	current_element;

	while (b_size-- > 0 && j <= bit_size && !is_stack_sorted(stack))
	{
		current_element = stack->stack_b[0];
		if (((current_element >> j) & 1) == 0)
			rotate_elements(stack->stack_b, stack->stack_b_size, "up", "b");
		else
			push_elements("pa", stack);
	}
	if (is_stack_sorted(stack))
		while (stack->stack_b_size != 0)
			push_elements("pa", stack);
}

void	apply_radix_sort(t_stack *stack)
{
	int	j;
	int	bit_size;
	int	size;

	bit_size = 0;
	size = stack->stack_a_size;
	while (size > 1 && ++bit_size)
		size /= 2;
	j = -1;
	while (++j <= bit_size)
	{
		size = stack->stack_a_size;
		while (size-- && !is_stack_sorted(stack))
		{
			if (((stack->stack_a[0] >> j) & 1) == 0)
				push_elements("pb", stack);
			else
				rotate_elements(stack->stack_a, stack->stack_a_size, "up", "a");
		}
		radix_sort_stack_b(stack, stack->stack_b_size, bit_size, j + 1);
	}
	while (stack->stack_b_size != 0)
		push_elements("pa", stack);
}
