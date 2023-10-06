/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdejo <averdejo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:52:32 by averdejo          #+#    #+#             */
/*   Updated: 2023/09/27 13:47:43 by averdejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_test **head, char flag)
{
	t_test	*swap_a;
	t_test	*swap_b;
	t_test	*tmp;

	tmp = NULL;
	swap_a = *head;
	swap_b = NULL;
	if (ft_lstsize(*head) <= 1)
		return ;
	tmp = swap_a;
	swap_b = swap_a->next;
	tmp->next = swap_b->next;
	swap_b->next = tmp;
	(*head) = swap_b;
	if (flag == 'a')
		ft_printf("sa\n");
	else if (flag == 'b')
		ft_printf("sb\n");
}

void	swap_s(t_test **head_a, t_test **head_b, char flag)
{
	if (flag == 's')
		ft_printf("ss\n");
	swap(head_a, flag);
	swap(head_b, flag);
}
