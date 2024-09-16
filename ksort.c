/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epenaloz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:27:58 by epenaloz          #+#    #+#             */
/*   Updated: 2024/09/16 18:34:18 by epenaloz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	pass_to_b(t_stacks *stacks, int pivot, int *i)
{
	int do_rr;

	do_rr = 0;
	while (stacks->a != NULL)
	{
		if (stacks->a->index <= *i)
		{
			push(&(stacks->a), &(stacks->b), 'b');
			(*i)++;
			if (stacks->a != NULL && stacks->a->index <= *i + pivot)
				rotate(&(stacks->b), 'b', 'y');
			else
				do_rr = 1;
		}
		else if (stacks->a->index <= *i + pivot)
		{
			push(&(stacks->a), &(stacks->b), 'b');
			(*i)++;
		}
		else
		{
			if (do_rr == 1)
			{
				rr(stacks);
				do_rr = 0;	
			}
			else
                rotate(&(stacks->a), 'a', 'y');
		}
	}
}

int	find_max(t_list *stack)
{
	long	max;

	max = LONG_MIN;
	while (stack != NULL)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}

int	get_weight(t_list *stack, long max)
{
	int	size;
	int	result;

	size = ft_lstsize(stack);
	result = 0;
	while (stack != NULL && max != stack->index)
	{
		stack = stack->next;
		result++;
	}
	if (result <= size / 2)
		return (result);
	else
		return (result - size);
}

void	pass_to_a(t_stacks *stacks, int max)
{
	int	weight;

	weight = get_weight(stacks->b, max);
	if (weight == 1)
		swap(&(stacks->b), 'b', 'y');
	else if (weight > 1)
	{
		while (weight > 0)
		{
			rotate(&(stacks->b), 'b', 'y');
			weight--;
		}
	}
	else if (weight < 0)
	{
		while (weight < 0)
		{
			reverse_rotate(&(stacks->b), 'b', 'y');
			weight++;
		}
	}
	push(&(stacks->b), &(stacks->a), 'a');
}


void	ksort(t_stacks *stacks)
{
	int		pivot;
	int		movements;
	long	max;

	pivot = ft_sqrt(ft_lstsize(stacks->a)) * 1.4;
	movements = 0;
	pass_to_b(stacks, pivot, &movements);
	while (stacks->b != NULL)
	{
		max = find_max(stacks->b);
		pass_to_a(stacks, max);
	}
}
