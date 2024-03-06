/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:45:26 by shmohamm          #+#    #+#             */
/*   Updated: 2024/03/06 15:49:11 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_stack_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->stack_a_size - 1)
	{
		if (stack->stack_a[i] > stack->stack_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	check_for_dup_or_sorted(t_stack *stack, int i)
{
	int	j;

	j = 0;
	if (i == 0)
	{
		while (i < stack->stack_a_size)
		{
			j = i + 1;
			while (j < stack->stack_a_size)
			{
				if (stack->stack_a[i] == stack->stack_a[j])
					exit_program(stack, "Error\n");
				j++;
			}
			i++;
		}
	}
	if (is_stack_sorted(stack))
		exit_program(stack, NULL);
}

void	create_index(t_stack *stack)
{
	int	i;
	int	j;
	int	k;
	int	*new_a;

	new_a = malloc(stack->stack_a_size * sizeof(int));
	if (new_a == NULL)
		exit_program(stack, "Error\n");
	i = -1;
	while (++i < stack->stack_a_size)
	{
		k = 0;
		j = -1;
		while (++j < stack->stack_a_size)
			if (stack->stack_a[i] > stack->stack_a[j])
				k++;
		new_a[i] = k;
	}
	i = stack->stack_a_size;
	while (i--)
		stack->stack_a[i] = new_a[i];
	free(new_a);
}

long	ft_atoi2(const char *str, t_stack *stack)
{
	long long	sign;
	long long	res;
	int			i;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] == '0')
		i++;
	if (ft_strlen(str + i) > 10)
		exit_program(stack, "Error\n");
	res = calculate_value(str, i, sign, stack);
	return ((res * sign));
}

long long	calculate_value(const char *str, int i, long long sign,
		t_stack *stack)
{
	long long	res;

	res = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			exit_program(stack, "Error\n");
		res = res * 10 + (str[i++] - '0');
		if (res > 2147483648 || (res * sign) < INT_MIN)
			exit_program(stack, "Error\n");
	}
	return (res);
}
