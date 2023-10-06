/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdejo <averdejo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:42:34 by averdejo          #+#    #+#             */
/*   Updated: 2023/09/27 13:43:46 by averdejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_test **head_a, t_test **head_b)
{
	t_test	*a;
	t_test	*b;
	t_test	*node_to_free;

	a = *head_a;
	b = *head_b;
	if (b == NULL)
		return ;
	node_to_free = b;
	b = b->next;
	if (a == NULL)
	{
		node_to_free->next = NULL;
		a = node_to_free;
	}
	else
	{
		node_to_free->next = a;
		a = node_to_free;
	}
	(*head_b) = b;
	(*head_a) = a;
	ft_printf("pa\n");
}

void	push_b(t_test **head_b, t_test **head_a)
{
	t_test	*a;
	t_test	*b;
	t_test	*node_to_free;

	a = *head_a;
	b = *head_b;
	if (a == NULL)
		return ;
	node_to_free = a;
	a = a->next;
	if (b == NULL)
	{
		node_to_free->next = NULL;
		b = node_to_free;
	}
	else
	{
		node_to_free->next = b;
		b = node_to_free;
	}
	(*head_b) = b;
	(*head_a) = a;
	ft_printf("pb\n");
}
