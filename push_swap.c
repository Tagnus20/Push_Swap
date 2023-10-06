/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdejo <averdejo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 19:29:32 by averdejo          #+#    #+#             */
/*   Updated: 2023/09/29 14:18:32 by averdejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_node(long num, t_test **head)
{
	t_test	*new_node;

	new_node = malloc(sizeof(t_test));
	new_node->number = num;
	new_node->index = -1;
	new_node->next = *head;
	*head = new_node;
}

void	add_node_back(long num, t_test **head)
{
	t_test	*new_node;
	t_test	*node_it;

	if (*head == NULL)
		add_node(num, head);
	else
	{
		new_node = malloc(sizeof(t_test));
		new_node->number = num;
		new_node->index = -1;
		new_node->next = NULL;
		node_it = *head;
		while ((node_it)-> next != NULL)
			node_it = node_it -> next;
		node_it->next = new_node;
	}
}

void	radix(t_test **stack_a, t_test **stack_b)
{
	int		i;
	int		j;
	int		size;

	i = 0;
	size = ft_lstsize(*stack_a);
	while (is_order(stack_a))
	{
		j = 0;
		while (j++ < size)
		{
			if (((*stack_a)->index >> i & 1) == 1)
				rotate(stack_a, 'a');
			else
				push_b(stack_b, stack_a);
		}
		while (ft_lstsize(*stack_b) != 0)
		{
			push_a(stack_a, stack_b);
		}
		i++;
	}
}

void	sort_list(t_test **head_a, t_test **head_b)
{
	if (ft_lstsize(*head_a) == 2)
		two_elements(head_a);
	if (ft_lstsize(*head_a) == 3)
		three_elements(head_a);
	if (ft_lstsize(*head_a) == 4)
		four_elements(head_a, head_b);
	if (ft_lstsize(*head_a) == 5)
		five_elements(head_a, head_b);
	else
		radix(head_a, head_b);
}

int	main(int argc, char *argv[])
{
	t_test	*stack_a;
	t_test	*stack_b;
	int		i;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	i = 1;
	if (check_digit(argv))
		return (write(2, "Error\n", 7), 0);
	while (i < argc && argv[i] != NULL)
		add_node_back(ft_atoi(argv[i++]), &stack_a);
	if (check_limits(&stack_a) || check_repeat(stack_a))
		return (write(2, "Error\n", 7), free_nodes(&stack_a), 0);
	find_min(&stack_a);
	sort_list(&stack_a, &stack_b);
	free_nodes(&stack_a);
	free_nodes(&stack_b);
}
