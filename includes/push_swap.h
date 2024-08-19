/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epenaloz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:37:03 by epenaloz          #+#    #+#             */
/*   Updated: 2024/08/19 20:07:01 by epenaloz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"

typedef struct s_stacks
{
	t_list	*a;
	t_list	*b;
}	t_stacks;

void	parse_args(char **args, t_stacks *stacks);
void	del_content(void *content);
void	sa(t_list *a);
void	pb(t_stacks *stacks);
void	push(t_list **from, t_list **to);
void	rotate(t_list **stack);
void	reverse_rotate(t_list **stack);

#endif