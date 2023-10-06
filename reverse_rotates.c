/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdejo <averdejo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:44:00 by averdejo          #+#    #+#             */
/*   Updated: 2023/09/27 13:44:05 by averdejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_test **head, char flag)
{
	t_test	*tmp;
	t_test	*a;

	if (!head || ft_lstsize(*head) <= 1)
		return ;
	tmp = *head;
	a = tmp->next;
	while (a->next != NULL)
	{
		a = a->next;
		tmp = tmp->next;
	}
	tmp->next = NULL;
	a->next = *head;
	(*head) = a;
	if (flag == 'a')
		ft_printf("rra\n");
	else if (flag == 'b')
		ft_printf("rrb\n");
}

void	reverse_rotate_r(t_test **head_a, t_test **head_b, char flag)
{
	if (flag == 's')
		ft_printf("rrr\n");
	reverse_rotate(head_a, flag);
	reverse_rotate(head_b, flag);
}
