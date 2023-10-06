/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdejo <averdejo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:39:32 by averdejo          #+#    #+#             */
/*   Updated: 2023/09/27 14:58:24 by averdejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "ft_printf/ft_printf.h"
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_test
{
	long			number;
	int				index;
	struct s_test	*next;
}	t_test;

void	swap(t_test **head, char flag);
void	swap_s(t_test **head_a, t_test **head_b, char flag);
void	push_a(t_test **head_a, t_test **head_b);
void	push_b(t_test **head_b, t_test **head_a);
void	rotate(t_test **head, char flag);
void	rotate_r(t_test **head_a, t_test **head_b, char flag);
void	reverse_rotate(t_test **head, char flag);
void	reverse_rotate_r(t_test **head_a, t_test **head_b, char flag);
int		is_order(t_test **stack_a);
long	ft_atoi(const char *str);
void	free_nodes(t_test **list);
void	add_node_back(long num, t_test **head);
void	add_node(long num, t_test **head);
void	ft_advance(t_test **kabesa);
void	print_stacks(t_test *stack_a, t_test *stack_b);
int		ft_lstsize(t_test *lst);
void	find_min(t_test **head);
void	radix(t_test **stack_a, t_test **stack_b);
void	two_elements(t_test **head);
void	three_elements(t_test **head);
void	four_elements(t_test **head_a, t_test **head_b);
void	five_elements(t_test **head_a, t_test **head_b);
t_test	*lstlast(t_test *lst);
int		check_digit(char *argv[]);
int		check_limits(t_test **head_a);
int		check_repeat(t_test *head_a);
void	sort_list(t_test **head_a, t_test **head_b);

#endif
