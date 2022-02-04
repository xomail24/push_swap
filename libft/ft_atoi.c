/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icheri <icheri@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 22:56:56 by icheri            #+#    #+#             */
/*   Updated: 2022/01/31 23:25:16 by icheri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi(const char *str)
{
	int		i;
	long	chislo;
	long	znak;

	i = 0;
	znak = 1;
	chislo = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			znak *= (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		chislo = (chislo * 10) + (str[i] - '0');
		i++;
	}
	return (chislo * znak);
}
