/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:50:06 by shmohamm          #+#    #+#             */
/*   Updated: 2024/01/25 13:52:00 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_pa(t_stack *stack)
{
	int	tmp;

	if (stack->stack_b_size <= 0)
		return ;
	tmp = stack->stack_b[0];
	ft_memmove(stack->stack_a + 1, stack->stack_a, sizeof(int)
		* stack->stack_a_size);
	stack->stack_a[0] = tmp;
	stack->stack_b_size--;
	ft_memmove(stack->stack_b, stack->stack_b + 1, sizeof(int)
		* stack->stack_b_size);
	stack->stack_a_size++;
}

void	push_pb(t_stack *stack)
{
	int	tmp;

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

void	push_elements(char *str, t_stack *stack)
{
	if (ft_strncmp(str, "pa", 3) == 0)
		push_pa(stack);
	else if (ft_strncmp(str, "pb", 3) == 0)
		push_pb(stack);
	ft_putendl_fd(str, 1);
}
