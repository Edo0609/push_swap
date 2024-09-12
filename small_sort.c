/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epenaloz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:12:38 by epenaloz          #+#    #+#             */
/*   Updated: 2024/09/08 20:32:31 by epenaloz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

long	get_val_from_index(t_list *stack, int index)
{
	while ( stack != NULL && stack->index != index)
		stack = stack->next;
	return (*(long *)(stack->content));
}

void test(void *content)
{
	ft_printf("%d\n", (int)*(long *)content);
}


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

void	med_sort(t_stacks *stacks)
{
	int	i;
	int	weight;
	int minval;

	i = 0;
	while (!is_ordered(stacks, 'y'))
	{
		minval = get_val_from_index(stacks->a, i);
		weight = get_weight(stacks->a, minval);
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

void	three_sort(t_stacks *stacks, char full)
{
	long	max;

	max = find_max(stacks->a);
	while (!is_ordered(stacks, full))
		{
			if (*((long *)stacks->a->content) == max)
				rotate(&(stacks->a), 'a', 'y');
			if (stacks->a->index > stacks->a->next->index)
				swap(&(stacks->a), 'a', 'y');
			if (!is_ordered(stacks, full))
				rotate(&(stacks->a), 'a', 'y');
		}
}
void	small_sort(t_stacks *stacks)
{
	if (ft_lstsize(stacks->a) == 2)
		swap(&(stacks->a), 'a', 'y');
	else if (ft_lstsize(stacks->a) == 3)
		three_sort(stacks, 'y');
	else
		med_sort(stacks);
}
