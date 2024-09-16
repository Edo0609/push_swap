/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epenaloz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 19:40:26 by epenaloz          #+#    #+#             */
/*   Updated: 2024/09/16 16:33:36 by epenaloz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	parse_error(t_stacks *stacks)
{
	ft_lstclear(&(stacks->a), del_content);
	ft_lstclear(&(stacks->b), del_content);
	write(STDERR_FILENO, "Error\n", 6);
	exit(EXIT_FAILURE);
}

long	ps_atol(char *str, t_stacks *stacks, int *i)
{
	int		sign;
	long	num;

	sign = 1;
	num = 0;
	while ((str[*i] >= 9 && str[*i] <= 13) || str[*i] == ' ')
		(*i)++;
	if ((str[*i] == '-' || str[*i] == '+') && ((*i) - 1 < 0 || ((*i) - 1 >= 0
				&& str[(*i) - 1] >= 9 && str[(*i) - 1] <= 13)
			|| str[(*i) - 1] == ' '))
	{
		sign = 44 - str[*i];
		(*i)++;
	}
	if (!(str[*i] >= '0' && str[*i] <= '9'))
		parse_error(stacks);
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		num = num * 10 + str[*i] - '0';
		(*i)++;
	}
	while ((str[*i] >= 9 && str[*i] <= 13) || str[*i] == ' ')
		(*i)++;
	return (num * sign);
}

int	is_repeated(t_list *stack, long num)
{
	while (stack != NULL)
	{
		if (*((long *)stack->content) == num)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	get_stacks_from_str(char *str, t_stacks *stacks)
{
	int		i;
	long	num;
	long	*num_ptr;

	i = 0;
	if (!str[i])
		parse_error(stacks);
	while (str[i])
	{
		num = ps_atol(str, stacks, &i);
		if (num > 2147483647 || num < -2147483648
			|| is_repeated(stacks->a, num))
			parse_error(stacks);
		num_ptr = (long *)malloc(sizeof(long));
		if (!num_ptr)
			parse_error(stacks);
		*num_ptr = num;
		ft_lstadd_back(&(stacks->a), ft_lstnew(num_ptr));
	}
}

void	parse_args(char **args, t_stacks *stacks)
{
	int	i;

	i = 0;
	while (args[++i])
		get_stacks_from_str(args[i], stacks);
}
