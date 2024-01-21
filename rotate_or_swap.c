/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_or_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:46:14 by shmohamm          #+#    #+#             */
/*   Updated: 2024/01/21 12:49:35 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_elements(char *str, int *array, int size)
{
	int	tmp;

	if (size <= 0)
		return ;
	tmp = array[0];
	array[0] = array[1];
	array[1] = tmp;
	ft_putendl_fd(str, 1);
}

void	push_elements(char *str, t_stack *stack)
{
	int	tmp;

	if (ft_strncmp(str, "pa", 3) == 0)
	{
		if (stack->stack_b_size <= 0)
			return ;
		tmp = stack->stack_b[0];
		ft_memmove(stack->stack_b + 1, stack->stack_b, sizeof(int)
			* stack->stack_b_size);
		stack->stack_a[0] = tmp;
		stack->stack_b_size--;
		ft_memmove(stack->stack_b, stack->stack_b + 1, sizeof(int)
			* stack->stack_b_size);
		stack->stack_a_size++;
	}
	else if (ft_strncmp(str, "pb", 3) == 0)
	{
		if (stack->stack_a_size <= 0)
			return ;
		tmp = stack->stack_a[0];
		ft_memmove(stack->stack_b + 1, stack->stack_b, sizeof(int)
			* stack->stack_b_size);
		stack->stack_b[0] = tmp;
		stack->stack_a_size--;
		ft_memmove(stack->stack_a, stack->stack_a + 1, sizeof(int)
			* stack->stack_a_size);
		stack->stack_b_size++;
	}
	ft_putendl_fd(str, 1);
}

void	rotate_elements(int *array, int size, char *direction, char *list)
{
	int	tmp;

	if (size < 0)
		return ;
	if (ft_strncmp(direction, "up", 5) == 0)
	{
		tmp = array[0];
		ft_memmove(array, array + 1, sizeof(int) * (size - 1));
		array[size - 1] = tmp;
		write(1, "r", 1);
	}
	else if (ft_strncmp(direction, "down", 5) == 0)
	{
		tmp = array[size - 1];
		ft_memmove(array + 1, array, sizeof(int) * (size - 1));
		array[0] = tmp;
		write(1, "rr", 2);
	}
	ft_putendl_fd(list, 1);
}
