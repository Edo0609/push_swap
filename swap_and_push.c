/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_and_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epenaloz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 18:13:05 by epenaloz          #+#    #+#             */
/*   Updated: 2024/09/08 20:30:36 by epenaloz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	swap(t_list **stack, char ab, char print)
{
	t_list	*first;
	t_list	*second;

	if (ft_lstsize(*stack) >= 2)
	{
		first = *stack;
		second = (*stack)->next;
		*stack = second;
		first->next = second->next;
		second->next = first;
	}
	if (print == 'y')
		ft_printf("s%c\n", ab);
}

void	ss(t_stacks *stacks)
{
	swap(&(stacks->a), 'a', 'n');
	swap(&(stacks->b), 'b', 'n');
	ft_printf("ss\n");
}

void	push(t_list **from, t_list **to, char ab)
{
	t_list	*temp;

	if (ft_lstsize(*from) != 0)
	{
		temp = (*from)->next;
		(*from)->next = *to;
		*to = *from;
		*from = temp;
	}
	ft_printf("p%c\n", ab);
}
