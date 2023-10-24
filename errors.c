/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdejo <averdejo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:34:14 by averdejo          #+#    #+#             */
/*   Updated: 2023/10/01 00:48:45 by averdejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_digit(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i] != 0)
	{
		j = 0;
		if ((argv[i][0] == '-' || argv[i][0] == '+')
			&& argv[i][1] >= '0' && argv[i][1] <= '9')
			j++;
		else if (argv[i][0] >= '0' && argv[i][0] <= '9')
			j++;
		else
			return (1);
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] >= '0' && argv[i][j] <= '9')
				j++;
			else
				return (1);
		}
		i++;
	}
	return (0);
}

int	check_limits(t_test **head_a)
{
	t_test	*copy;

	copy = *head_a;
	while (copy)
	{
		if (copy->number < INT_MIN || copy->number > INT_MAX)
			return (1);
		copy = copy->next;
	}
	return (0);
}

int	check_repeat(t_test *head_a)
{
	t_test	*copy;
	t_test	*iter;

	copy = head_a;
	while (copy)
	{
		iter = copy->next;
		while (iter)
		{
			if (copy->number == iter->number)
				return (1);
			iter = iter->next;
		}
		copy = copy->next;
	}
	return (0);
}

int	is_order(t_test **stack_a)
{
	t_test	*copy_a;

	if (!stack_a)
		return (0);
	copy_a = *stack_a;
	while (copy_a->next)
	{
		if (copy_a->number > copy_a->next->number)
			return (1);
		copy_a = copy_a->next;
	}
	return (0);
}
