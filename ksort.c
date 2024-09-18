/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epenaloz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:27:58 by epenaloz          #+#    #+#             */
/*   Updated: 2024/09/18 18:12:16 by epenaloz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

//passes to b given certain parameters until a is empty
//do_rr: checks if it should use an "rr" (saves operations)
//if the index is lower than our total movements to b, push and rotate b
//if it's higher than that but ower to it * our pivot, it only pushes
//else, it rotates or rr's accordingly.
//this makes the higher index values end up on the edges of stack b
//and the lower index values closer to the middle, making a "k" shape
void	pass_to_b(t_stacks *stacks, int pivot, int *i)
{
	int	do_rr;

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
			rotate_or_rr(stacks, &do_rr);
	}
}

//finds the maximum index element of a stack
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

//checks the distance from the first element to max index element of a stack
//returns positive value if it's equal or lower than half the size
//returns negative value if not
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

//passes elements back to a, sorted
//rots or rev rots until the max index is at the head, and pushes to b
//uses get_weight to know whether it should rotate or reverse rotate
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

//uses a ksort algorithm to sort the numbers
//pivot: searches for a middle ground to use as reference point
//first passes to b, making the "k" shape, then back to a
void	ksort(t_stacks *stacks)
{
	int		pivot;
	int		movements;
	long	max;

	pivot = ft_sqrt(ft_lstsize(stacks->a));
	movements = 0;
	pass_to_b(stacks, pivot, &movements);
	while (stacks->b != NULL)
	{
		max = find_max(stacks->b);
		pass_to_a(stacks, max);
	}
}
