/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_or_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:46:14 by shmohamm          #+#    #+#             */
/*   Updated: 2024/01/23 10:04:49 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_up(int *array, int size, char *list)
{
	int	tmp;

	if (size <= 0)
		return ;
	tmp = array[0];
	ft_memmove(array, array + 1, sizeof(int) * (size - 1));
	array[size - 1] = tmp;
	write(1, "r", 1);
	ft_putendl_fd(list, 1);
}

void	rotate_down(int *array, int size, char *list)
{
	int	tmp;

	if (size <= 0)
		return ;
	tmp = array[size - 1];
	ft_memmove(array + 1, array, sizeof(int) * (size - 1));
	array[0] = tmp;
	write(1, "rr", 2);
	ft_putendl_fd(list, 1);
}

void	rotate_elements(int *array, int size, char *direction, char *list)
{
	if (ft_strncmp(direction, "up", 5) == 0)
		rotate_up(array, size, list);
	else if (ft_strncmp(direction, "down", 5) == 0)
		rotate_down(array, size, list);
}

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
