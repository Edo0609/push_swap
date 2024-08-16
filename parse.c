/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epenaloz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 19:40:26 by epenaloz          #+#    #+#             */
/*   Updated: 2024/08/16 21:04:29 by epenaloz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

// unsigned char	*fake_isspace(unsigned char *str)
// {
// 	while ((*str >= 9 && *str <= 13) || *str == ' ')
// 		str++;
// 	return (str);
// }

// int	ft_atoi(const char *str)
// {
// 	unsigned char	*ptr;
// 	int				sign;
// 	int				num;

// 	sign = 1;
// 	ptr = (unsigned char *)str;
// 	num = 0;
// 	ptr = fake_isspace(ptr);
// 	if (*ptr == '-' || *ptr == '+')
// 	{
// 		if (*ptr == '-')
// 			sign *= -1;
// 		ptr++;
// 	}
// 	while (*ptr >= '0' && *ptr <= '9')
// 	{
// 		num = num * 10 + *ptr - '0';
// 		ptr++;
// 	}
// 	return (num * sign);
// }

void parse_error(t_stacks *stacks)
{
	ft_printf("Error %p\n", stacks);
	exit(EXIT_FAILURE);
}

long ps_atol(char *str, t_stacks *stacks, int *i)
{
	int sign;
	long num;
	
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

void	get_stacks_from_str(char *str, t_stacks *stacks)
{
	int	i;
	long num;
	
	i = 0;
	if (!str[i])
		parse_error(stacks);
	while (str[i])
	{
		num = ps_atol(str, stacks, &i);
		if (num > 2147483647 || num < -2147483648)
			parse_error(stacks);
		ft_printf("%d\n", num);
	}
}

void	parse_args(char **args, t_stacks *stacks)
{
	int	i;

	i = 0;
	while (args[++i])
	{
		get_stacks_from_str(args[i], stacks);
	}
}
