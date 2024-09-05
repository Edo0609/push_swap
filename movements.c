/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epenaloz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 18:13:05 by epenaloz          #+#    #+#             */
/*   Updated: 2024/09/05 15:11:04 by epenaloz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	swap(t_list *stack, char ab, char print)
{
	void	*temp;
	if (ft_lstsize(stack) >= 2)
	{
		temp = stack->content;
		stack->content = stack->next->content;
		stack->next->content = temp;
	}
	if (print == 'y')
		ft_printf("s%c\n", ab);
}

void	ss(t_stacks *stacks)
{
	swap(stacks->a, 'a', 'n');
	swap(stacks->b, 'b', 'n');
	ft_printf("ss\n");
}

void	push(t_list **from, t_list **to, char ab)
{
	t_list *temp;
	if (ft_lstsize(*from) != 0)
	{
		temp = (*from)->next;
		(*from)->next = *to;
		*to = *from;
		*from = temp;
	}
	ft_printf("p%c\n", ab);
}

t_list	*get_tail(t_list *stack)
{
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

void	rotate(t_list **stack, char ab, char print)
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
	if (print == 'y')
		ft_printf("r%c\n", ab);
}

void	reverse_rotate(t_list **stack, char ab, char print)
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
	if (print == 'y')
		ft_printf("rr%c\n", ab);
}

void	rr(t_stacks *stacks)
{
	rotate(&(stacks->a), 'a', 'n');
	rotate(&(stacks->b), 'b', 'n');
	ft_printf("rr\n");
}

void	rrr(t_stacks *stacks)
{
	reverse_rotate(&(stacks->a), 'a', 'n');
	reverse_rotate(&(stacks->b), 'b', 'n');
	ft_printf("rrr\n");
}