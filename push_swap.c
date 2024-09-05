/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epenaloz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:36:13 by epenaloz          #+#    #+#             */
/*   Updated: 2024/09/05 18:42:46 by epenaloz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void init_stacks(t_stacks *stacks)
{
	stacks->a = NULL;
	stacks->b = NULL;
}

void	del_content(void *content)
{
	free(content);
}

void test(void *content)
{
	ft_printf("%d\n", *(int *)content);
}

int main(int ac, char **av)
{
	t_stacks	stacks;
	if (ac < 2)
	{
		ft_printf("Error\n");
		return (1);
	}
	init_stacks(&stacks);
    parse_args(av, &stacks);
	// ft_printf("stack a inicial: \n");
	// ft_lstiter(stacks.a,test);
	// ft_printf("\nstack b inicial: \n");
	// ft_lstiter(stacks.b,test);
	get_indexes(stacks.a);
	ksort(&stacks);
	// ft_printf("stack a: \n");
	// ft_lstiter(stacks.a,test);
	// ft_printf("\nstack b: \n");
	// ft_lstiter(stacks.b,test);
	ft_lstclear(&(stacks.a), del_content);
	ft_lstclear(&(stacks.b), del_content);
}
