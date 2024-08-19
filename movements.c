/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epenaloz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 18:13:05 by epenaloz          #+#    #+#             */
/*   Updated: 2024/08/19 20:29:46 by epenaloz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	swap(t_list *stack)
{
	void	*temp;
	if (ft_lstsize(stack) >= 2)
	{
		temp = stack->content;
		stack->content = stack->next->content;
		stack->next->content = temp;
	}
}

void	push(t_list **from, t_list **to)
{
	t_list *temp;
	if (ft_lstsize(*from) != 0)
	{
		temp = (*from)->next;
		(*from)->next = *to;
		*to = *from;
		*from = temp;
	}
}

t_list	*get_tail(t_list *stack)
{
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

void	rotate(t_list **stack)
{
	t_list	*temp;
	t_list	*tail;
	if (ft_lstsize(*stack) != 0)
	{
		temp = *stack;
		*stack = (*stack)->next;
		tail = get_tail(*stack);
		temp->next = NULL;
		tail->next = temp;
	}
}

void	reverse_rotate(t_list **stack)
{
	t_list	*temp;
	t_list	*tail;
	if (ft_lstsize(*stack) > 1)
	{
		tail = get_tail(*stack);
		temp = *stack;
		while (temp->next != tail)
			temp = temp->next;
		temp->next = NULL;
		tail->next = *stack;
		*stack = tail;
	}
}