/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdejo <averdejo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:44:23 by averdejo          #+#    #+#             */
/*   Updated: 2023/09/27 13:44:26 by averdejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_test **head, char flag)
{
	t_test	*a;
	t_test	*node_to_move;

	if (!head || ft_lstsize(*head) <= 1)
		return ;
	a = *head;
	node_to_move = a;
	a = a->next;
	(*head) = a;
	while (a->next != NULL)
		a = a->next;
	node_to_move->next = NULL;
	a->next = node_to_move;
	if (flag == 'a')
		ft_printf("ra\n");
	else if (flag == 'b')
		ft_printf("rb\n");
}

void	rotate_r(t_test **head_a, t_test **head_b, char flag)
{
	if (flag == 's')
		ft_printf("rr\n");
	rotate(head_a, flag);
	rotate(head_b, flag);
}
