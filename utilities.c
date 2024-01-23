/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:46:19 by shmohamm          #+#    #+#             */
/*   Updated: 2024/01/23 09:52:30 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atol(const char *str, t_stack *stack)
{
	int			i;
	long		sign;
	long long	result;

	result = 0;
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
	while (str[i])
	{
		if (result > INT_MAX || (result * sign) < INT_MIN || ft_strlen(str) > 11)
			exit_program(stack, "Error\n");
		if (!(str[i] >= '0' && str[i] <= '9'))
			exit_program(stack, "Error\n");
		result = result * 10 + (str[i++] - '0');
	}
	return ((int)(result * sign));
}

void	read_numbers(t_stack *stack)
{
	char	**tmp;
	int		i;
	int		z;

	z = 0;
	tmp = ft_split(stack->join_args, ' ');
	i = 0;
	while (tmp[i] != NULL && tmp[i][0] != '\0')
	{
		stack->stack_a[z++] = ft_atol(tmp[i++], stack);
		free(tmp[i - 1]);
	}
	free(tmp);
}

void	initialize_stacks(int argc, char **argv, t_stack *stack)
{
	int	i;

	i = 0;
	stack->stack_a_size = 0;
	stack->stack_b_size = 0;
	while (--argc)
	{
		if (ft_wordcount(argv[i + 1], ' '))
			stack->stack_a_size += ft_wordcount(argv[i + 1], ' ');
		else
			stack->stack_a_size++;
		i++;
	}
	stack->stack_a = malloc(stack->stack_a_size * sizeof(int));
	if (stack->stack_a == NULL)
		exit_program(stack, "Error\n");
	stack->stack_b = malloc(stack->stack_a_size * sizeof(int));
	if (stack->stack_b == NULL)
		exit_program(stack, "Error\n");
}

void	initialize_index(int *new_a, t_stack *stack)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < stack->stack_a_size)
	{
		k = 0;
		j = 0;
		while (j < stack->stack_a_size)
		{
			if (stack->stack_a[i] > stack->stack_a[j])
				k++;
			j++;
		}
		new_a[i] = k;
	}
}

void	create_index(t_stack *stack)
{
	int	*new_a;
	int	i;

	new_a = malloc(stack->stack_a_size * sizeof(int));
	if (new_a == NULL)
		exit_program(stack, "Error\n");
	initialize_index(new_a, stack);
	i = stack->stack_a_size;
	while (i--)
		stack->stack_a[i] = new_a[i];
	free(new_a);
}
