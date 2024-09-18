/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epenaloz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:49:02 by epenaloz          #+#    #+#             */
/*   Updated: 2024/09/18 18:08:55 by epenaloz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

//finds the minimum value of the stack's list of numbers
long	find_min(t_list *stack)
{
	long	min;

	min = LONG_MAX;
	while (stack != NULL)
	{
		if (stack->index == -1 && *((long *)stack->content) < min)
			min = *((long *)stack->content);
		stack = stack->next;
	}
	return (min);
}

//sets all the indexes on the correct numbers
void	put_index(t_list *stack, long num, int i)
{
	while (*((long *)stack->content) != num)
		stack = stack->next;
	stack->index = i;
}

//gets the value of the index of all elements
void	get_indexes(t_list *stack)
{
	long	min;
	int		i;

	i = 0;
	while (i != ft_lstsize(stack))
	{
		min = find_min(stack);
		put_index(stack, min, i);
		i++;
	}
}
