/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epenaloz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:12:38 by epenaloz          #+#    #+#             */
/*   Updated: 2024/09/19 13:53:38 by epenaloz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

//helps ksort save operations by doing rr when necessary
void	rotate_or_rr(t_stacks *stacks, int *do_rr)
{
	if (*do_rr == 1)
	{
		rr(stacks);
		*do_rr = 0;
	}
	else
		rotate(&(stacks->a), 'a', 'y');
}

//checks if it's better to rotate or reverse rotate to push to b
void	go_to_min(t_stacks *stacks, int weight, int i)
{
	while (weight != 0 && stacks->a->index != i)
	{
		if (weight > 0 && stacks->a->index != i)
		{
			rotate(&(stacks->a), 'a', 'y');
			weight--;
		}
		else if (weight < 0 && stacks->a->index != i)
		{
			reverse_rotate(&(stacks->a), 'a', 'y');
			weight++;
		}
	}
}

//gets all but the 3 highest index elements to b
//it puts the elements in b sorted backwards, then
//sorts the leftover elements with threesort;
//finally, it pushes everything back to a, sorted.
void	med_sort(t_stacks *stacks)
{
	int	i;
	int	weight;

	i = 0;
	while (!is_sorted(stacks, 'y'))
	{
		weight = get_weight(stacks->a, i);
		go_to_min(stacks, weight, i);
		if (ft_lstsize(stacks->a) > 3)
		{
			push(&(stacks->a), &(stacks->b), 'b');
			i++;
		}
		else
		{
			three_sort(stacks, 'n');
			while (stacks->b != NULL)
				push(&(stacks->b), &(stacks->a), 'a');
		}
	}
}

//sorts based on the index of the head of the list
//and the index of the next element
void	three_sort(t_stacks *stacks, char full)
{
	long	max;

	max = find_max(stacks->a);
	while (!is_sorted(stacks, full))
	{
		if (stacks->a->index == max)
			rotate(&(stacks->a), 'a', 'y');
		if (stacks->a->index > stacks->a->next->index)
			swap(&(stacks->a), 'a', 'y');
		if (!is_sorted(stacks, full))
			rotate(&(stacks->a), 'a', 'y');
	}
}

//used to sort a number of elements fewer than 11
//sorts differently if it's 3 numbers to if it's between 4 and 10
void	small_sort(t_stacks *stacks)
{
	if (ft_lstsize(stacks->a) == 2)
		swap(&(stacks->a), 'a', 'y');
	else if (ft_lstsize(stacks->a) == 3)
		three_sort(stacks, 'y');
	else
		med_sort(stacks);
}
