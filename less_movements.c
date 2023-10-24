/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_movements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdejo <averdejo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:35:26 by averdejo          #+#    #+#             */
/*   Updated: 2023/10/01 00:48:17 by averdejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_elements(t_test **head)
{
	if (!head)
		return ;
	if (!is_order(head))
		return ;
	else
		swap(head, 'a');
}

void	three_elements(t_test **head)
{
	if (!is_order(head))
		return ;
	else if ((*head)->number > (*head)->next->number)
	{
		if ((*head)->number < (*head)->next->next->number)
			swap(head, 'a');
		else if ((*head)->next->number > (*head)->next->next->number)
		{
			swap(head, 'a');
			reverse_rotate(head, 'a');
		}
		else
			rotate(head, 'a');
	}
	else if ((*head)->number < (*head)->next->number)
	{
		if ((*head)->number > (*head)->next->next->number)
			reverse_rotate(head, 'a');
		else
		{
			swap(head, 'a');
			rotate(head, 'a');
		}
	}
}

void	four_elements(t_test **head_a, t_test **head_b)
{
	t_test	*copy_a;

	copy_a = *head_a;
	if (!is_order(head_a))
		return ;
	if (copy_a->index == 0)
	{
		push_b(head_b, head_a);
		three_elements(head_a);
		push_a(head_a, head_b);
	}
	else
	{
		rotate(head_a, 'a');
		four_elements(head_a, head_b);
	}
}

void	five_elements(t_test **head_a, t_test **head_b)
{
	t_test	*copy_a;

	copy_a = *head_a;
	if (!is_order(head_a) && ft_lstsize(*head_b) == 0)
		return ;
	if (copy_a->index < 2 && ft_lstsize(*head_b) != 2)
		push_b(head_b, head_a);
	else if (ft_lstsize(*head_b) == 2)
	{
		if (!is_order(head_b))
			swap(head_b, 'b');
		three_elements(head_a);
		push_a(head_a, head_b);
		push_a(head_a, head_b);
	}
	else
		rotate(head_a, 'a');
	five_elements(head_a, head_b);
}
