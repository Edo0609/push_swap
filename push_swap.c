/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epenaloz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:36:13 by epenaloz          #+#    #+#             */
/*   Updated: 2024/09/18 17:39:44 by epenaloz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
//initializes both stacks to null.
void	init_stacks(t_stacks *stacks)
{
	stacks->a = NULL;
	stacks->b = NULL;
}

//frees the content of a node
void	del_content(void *content)
{
	free(content);
}

//checks if stack "a" is sorted and stack "b" is empty.
//if "full" is not "y", it checks even if "b" is not empty.
int	is_sorted(t_stacks *stacks, char full)
{
	long	num;
	t_list	*current;

	num = LONG_MIN;
	current = stacks->a;
	if (ft_lstsize(stacks->b) == 0 || full != 'y')
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

//creates "stacks" variable that contains both stacks
int	main(int ac, char **av)
{
	t_stacks	stacks;

	if (ac < 2)
		exit(EXIT_SUCCESS);
	init_stacks(&stacks);
	parse_args(av, &stacks);
	get_indexes(stacks.a);
	if (!is_sorted(&stacks, 'y'))
	{
		if (ft_lstsize(stacks.a) > 10)
			ksort(&stacks);
		else
			small_sort(&stacks);
	}
	ft_lstclear(&(stacks.a), del_content);
	ft_lstclear(&(stacks.b), del_content);
}
