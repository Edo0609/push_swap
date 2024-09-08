/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epenaloz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:36:13 by epenaloz          #+#    #+#             */
/*   Updated: 2024/09/08 19:49:24 by epenaloz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	init_stacks(t_stacks *stacks)
{
	stacks->a = NULL;
	stacks->b = NULL;
}

void	del_content(void *content)
{
	free(content);
}

int	is_ordered(t_stacks *stacks, char full)
{
	long	num;
	t_list	*current;

	num = LONG_MIN;
	current = stacks->a;
	if (stacks->b == NULL || full != 'y')
	{
		while (current != NULL)
		{
			if (num > (*((long *)current->content)))
				return (0);
			else
				num = (*((long *)current->content));
			current = current->next;
		}
		return (1);
	}
	else
		return (0);
}

int	main(int ac, char **av)
{
	t_stacks	stacks;

	if (ac < 2)
	{
		ft_printf("Error\n");
		return (1);
	}
	init_stacks(&stacks);
	parse_args(av, &stacks);
	get_indexes(stacks.a);
	if (!is_ordered(&stacks, 'y'))
	{
		if (ft_lstsize(stacks.a) > 10)
			ksort(&stacks);
		else
			small_sort(&stacks);
	}
	ft_lstclear(&(stacks.a), del_content);
	ft_lstclear(&(stacks.b), del_content);
}
