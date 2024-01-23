/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 12:32:23 by shmohamm          #+#    #+#             */
/*   Updated: 2024/01/23 10:02:40 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	exit(1);
}

void	validate_arguments(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (argc < 2)
		exit_program(NULL, "");
	while (i < argc)
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
		i++;
	}
}

void	combine_arguments(int argc, char **argv, t_stack *stack)
{
	char	*tmp;
	char	*tmp2;
	int		i;

	i = 0;
	tmp2 = ft_strdup("");
	while (++i < argc && argv[i] != NULL)
	{
		tmp = ft_strjoin(tmp2, argv[i]);
		if (tmp2)
			free(tmp2);
		if (i != argc - 1)
		{
			tmp2 = ft_strjoin(tmp, " ");
			if (tmp)
				free(tmp);
			tmp = tmp2;
		}
	}
	stack->join_args = ft_strdup(tmp);
	if (stack->join_args == NULL)
		exit_program(stack, "Error\n");
	if (tmp)
		free(tmp);
}

void	dup_or_sorted(t_stack *stack, int i)
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
