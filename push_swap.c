/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epenaloz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:36:13 by epenaloz          #+#    #+#             */
/*   Updated: 2024/08/16 18:43:11 by epenaloz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int main(int ac, char **av)
{
	if (ac < 2)
	{
		ft_printf("Error\n");
		return (1);
	}
	t_stacks	stacks;
    parse_args(av, &stacks);
}