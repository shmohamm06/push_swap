/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:45:26 by shmohamm          #+#    #+#             */
/*   Updated: 2024/01/25 14:04:10 by shmohamm         ###   ########.fr       */
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
			exit_program(stack, "Atol Failed\n");
		if (!(n[i] >= '0' && n[i] <= '9'))
			exit_program(stack, "Atol Failed\n");
		res = res * 10 + (n[i++] - '0');
	}
	return ((int)(res * sign));
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
		exit_program(stack, "Malloc Failed\n");
	stack->stack_b = malloc(stack->stack_a_size * sizeof(int));
	if (stack->stack_b == NULL)
		exit_program(stack, "Malloc Failed\n");
}

void	create_index(t_stack *stack)
{
	int	i;
	int	j;
	int	k;
	int	*new_a;

	new_a = malloc(stack->stack_a_size * sizeof(int));
	if (new_a == NULL)
		exit_program(stack, "Malloc Failed\n");
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
