/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epenaloz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:37:03 by epenaloz          #+#    #+#             */
/*   Updated: 2024/09/18 18:19:07 by epenaloz         ###   ########.fr       */
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

//push_swap.c
void	init_stacks(t_stacks *stacks);
void	del_content(void *content);
int		is_sorted(t_stacks *stacks, char full);

//parse.c
void	parse_error(t_stacks *stacks);
long	ps_atol(char *str, t_stacks *stacks, int *i);
int		is_repeated(t_list *stack, long num);
void	get_stacks_from_str(char *str, t_stacks *stacks);
void	parse_args(char **args, t_stacks *stacks);

//indexes.c
long	find_min(t_list *stack);
void	put_index(t_list *stack, long num, int i);
void	get_indexes(t_list *stack);

//swap_and_push.c
void	swap(t_list **stack, char ab, char print);
void	ss(t_stacks *stacks);
void	push(t_list **from, t_list **to, char ab);

//rotate.c
void	rotate(t_list **stack, char ab, char print);
void	reverse_rotate(t_list **stack, char ab, char print);
void	rr(t_stacks *stacks);
void	rrr(t_stacks *stacks);

//ksort.c
void	pass_to_b(t_stacks *stacks, int pivot, int *i);
int		find_max(t_list *stack);
int		get_weight(t_list *stack, long max);
void	pass_to_a(t_stacks *stacks, int max);
void	ksort(t_stacks *stacks);

//small_sort.c
void	rotate_or_rr(t_stacks *stacks, int *do_rr);
void	go_to_min(t_stacks *stacks, int weight, int i);
void	med_sort(t_stacks *stacks);
void	three_sort(t_stacks *stacks, char full);
void	small_sort(t_stacks *stacks);
#endif