/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epenaloz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:30:32 by epenaloz          #+#    #+#             */
/*   Updated: 2024/09/05 16:37:46 by epenaloz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

double	ft_sqrt(int num)
{
	double	guess;
	double	epsilon;

	guess = num;
	epsilon = 0.00001;
	while ((guess * guess - num) > epsilon
		|| (guess * guess - num) < -epsilon)
		guess = (guess + num / guess) / 2;
	return (guess);
}
