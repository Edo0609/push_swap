/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epenaloz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:37:03 by epenaloz          #+#    #+#             */
/*   Updated: 2024/09/16 16:44:56 by epenaloz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"
# include <limits.h>

typedef struct s_stacks
{
	t_list	*a;
	t_list	*b;
}	t_stacks;

void	parse_args(char **args, t_stacks *stacks);
void	del_content(void *content);
void	swap(t_list **stack, char ab, char print);
void	ss(t_stacks *stacks);
void	push(t_list **from, t_list **to, char ab);
void	rotate(t_list **stack, char ab, char print);
void	reverse_rotate(t_list **stack, char ab, char print);
void	rr(t_stacks *stacks);
void	rrr(t_stacks *stacks);
void	get_indexes(t_list *stack);
void	put_index(t_list *stack, long num, int i);
long	find_min(t_list *stack);
void	ksort(t_stacks *stacks);
int		is_ordered(t_stacks *stacks, char full);
int		find_max(t_list *stack);
void	small_sort(t_stacks *stacks);
int		get_weight(t_list *stack, long max);
void	three_sort(t_stacks *stacks, char full);
#endif