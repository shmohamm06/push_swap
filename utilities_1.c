/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:43:48 by shmohamm          #+#    #+#             */
/*   Updated: 2024/03/06 15:46:47 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	validate_arguments(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = 0;
		if (!argv[i][0] || (argv[i][0] && argv[i][0] == ' '))
			exit_program(NULL, "Error\n");
		while (argv[i][j] != '\0')
		{
			if ((!(ft_isdigit(argv[i][j])) && (argv[i][j] != ' ')
					&& (argv[i][j] != '-' && argv[i][j] != '+'))
				|| (argv[i][j] == '-' && argv[i][j + 1] == '\0')
				|| (argv[i][j] == '+' && argv[i][j + 1] == '\0')
				|| (argv[i][j] == '-' && argv[i][j + 1] == ' ')
				|| (argv[i][j] == '+' && argv[i][j + 1] == ' '))
				exit_program(NULL, "Error\n");
			j++;
		}
	}
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

void	combine_arguments(int argc, char **argv, t_stack *stack)
{
	char	*tmp_string1;
	char	*tmp_string2;
	int		index;

	index = 1;
	tmp_string2 = ft_strdup("");
	while (index < argc && argv[index] != NULL)
	{
		tmp_string1 = ft_strjoin(tmp_string2, argv[index]);
		if (tmp_string2)
			free(tmp_string2);
		if (index != argc - 1)
		{
			tmp_string2 = ft_strjoin(tmp_string1, " ");
			if (tmp_string1)
				free(tmp_string1);
			tmp_string1 = tmp_string2;
		}
		index++;
	}
	stack->join_args = ft_strdup(tmp_string1);
	if (stack->join_args == NULL)
		exit_program(stack, "Error\n");
	if (tmp_string1)
		free(tmp_string1);
}

void	read_numbers(t_stack *stack)
{
	char	**tmp;
	int		i;
	int		z;
	long	num;

	z = 0;
	tmp = ft_split(stack->join_args, ' ');
	i = 0;
	while (tmp[i] != NULL && tmp[i][0] != '\0')
	{
		num = ft_atoi2(tmp[i], stack);
		if (num > INT_MAX)
			exit_program(stack, "Error\n");
		stack->stack_a[z++] = num;
		free(tmp[i]);
		i++;
	}
	free(tmp);
}

void	exit_program(t_stack *stack, char *msg)
{
	if (msg)
		write(2, msg, ft_strlen(msg));
	if (stack != NULL)
	{
		if (stack->stack_a != NULL)
			free(stack->stack_a);
		if (stack->stack_b != NULL)
			free(stack->stack_b);
		if (stack->join_args != NULL)
			free(stack->join_args);
	}
	exit(0);
}
