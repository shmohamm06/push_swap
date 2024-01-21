/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:46:19 by shmohamm          #+#    #+#             */
/*   Updated: 2024/01/21 12:44:22 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atol(const char *n, t_stack *stack)
{
	int			i;
	long		sign;
	long long	res;

	res = 0;
	sign = 1;
	i = 0;
	while (n[i] == ' ' || (n[i] >= '\t' && n[i] <= '\r'))
		i++;
	if (n[i] == '+' || n[i] == '-')
	{
		if (n[i] == '-')
			sign = -1;
		i++;
	}
	while (n[i])
	{
		if (res > 2147483647 || (res * sign) < -2147483648 || ft_strlen(n) > 11)
			exit_program(stack, "Error\n");
		if (!(n[i] >= '0' && n[i] <= '9'))
			exit_program(stack, "Error\n");
		res = res * 10 + (n[i++] - '0');
	}
	return ((int)(res * sign));
}

void	exit_program_if_sorted_or_has_duplicate(t_stack *stack, int i)
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
	stack->stack_a = malloc(stack->stack_a_size * sizeof * stack->stack_a);
	if (stack->stack_a == NULL)
		exit_program(stack, "Error\n");
	stack->stack_b = malloc(stack->stack_a_size * sizeof * stack->stack_b);
	if (stack->stack_b == NULL)
		exit_program(stack, "Error\n");
}

void	create_index(t_stack *stack)
{
	int	i;
	int	j;
	int	k;
	int	*new_a;

	new_a = malloc(stack->stack_a_size * sizeof * new_a);
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
