/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epenaloz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:27:58 by epenaloz          #+#    #+#             */
/*   Updated: 2024/09/05 16:41:17 by epenaloz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ksort(t_stacks *stacks)
{
	int pivot;

	pivot = ft_sqrt(ft_lstsize(stacks->a)) * 1.4;
	ft_printf("pivot = %d\n", pivot);
}