/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:43:48 by shmohamm          #+#    #+#             */
/*   Updated: 2024/03/04 22:56:47 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	validate_arguments(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	if (argc < 2)
		exit_program(NULL, "");
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
