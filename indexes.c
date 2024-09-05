/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epenaloz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:49:02 by epenaloz          #+#    #+#             */
/*   Updated: 2024/09/05 16:14:10 by epenaloz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

// void lst_to_array(t_list *stack, long *array)
// {
// 	int i = 0;
// 	while (stack != NULL)
// 	{
// 		array[i] = *((long *)(stack->content));
// 		i++;
// 		stack = stack->next;
// 	}
// }

// void array_sort(long *array)
// {
// 	int i;
// 	while (!is_sorted(array))
// 	{
		
// 	}
// }

// void	insort(t_list *stack)
// {
// 	long	*array;
// 	array = (long *)malloc(sizeof(long) * (ft_lstsize(stack) + 1));
// 	array[ft_lstsize(stack)] = '\0';
// 	lst_to_array(stack, array);
// 	int i = -1;
// 	while (array[++i])
// 	{
// 		ft_printf("%d, ", (int)array[i]);
// 	}
// 	array_sort(array);
	
// 	free(array);
// }

long	find_min(t_list *stack)
{
	long min;
	min = LONG_MAX;
	while (stack != NULL)
	{
		if (stack->index == -1 && *((long *)stack->content) < min)
			min = *((long *)stack->content);
		stack = stack->next;
	}
	return (min);
}

void	put_index(t_list *stack, long num, int i)
{
	while (*((long *)stack->content) != num)
		stack = stack->next;
	stack->index = i;
}

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
	while (stack != NULL)
	{
		ft_printf("index of %d = %d\n", *((long *)stack->content), stack->index);
		stack = stack->next;
	}
}