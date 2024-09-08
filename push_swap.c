/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epenaloz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:36:13 by epenaloz          #+#    #+#             */
/*   Updated: 2024/09/08 17:27:30 by epenaloz         ###   ########.fr       */
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

void	test(void *content)
{
	ft_printf("%d\n", *(int *)content);
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
	ksort(&stacks);
	ft_lstclear(&(stacks.a), del_content);
	ft_lstclear(&(stacks.b), del_content);
}
