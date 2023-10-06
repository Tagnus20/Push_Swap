/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdejo <averdejo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:47:57 by averdejo          #+#    #+#             */
/*   Updated: 2023/09/27 13:49:23 by averdejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(const char *str)
{
	long	num;
	int		sign;
	int		i;

	sign = 1;
	num = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] != '\0')
	{
		if (str[i] <= 47 || str[i] >= 58)
			return (num * sign);
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * sign);
}

void	free_nodes(t_test **list)
{
	t_test	*node_to_free;

	while (*list != NULL)
	{
		node_to_free = *list;
		*list = (*list)->next;
		free(node_to_free);
	}
}

int	ft_lstsize(t_test *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

void	find_min(t_test **head)
{
	int		i;
	int		index;
	t_test	*list;
	t_test	*node_to_change;
	int		list_size;

	list_size = ft_lstsize(*head);
	index = 0;
	i = 0;
	list = *head;
	node_to_change = list;
	while (i < list_size)
	{
		while (list != NULL)
		{
			if (node_to_change->number > list->number)
				index++;
			list = list->next;
		}
		node_to_change->index = index;
		node_to_change = node_to_change->next;
		list = *head;
		i++;
		index = 0;
	}
}

t_test	*lstlast(t_test *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst -> next)
	{
		lst = lst -> next;
	}
	return (lst);
}
