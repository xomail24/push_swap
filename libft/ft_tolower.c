/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icheri <icheri@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 22:58:24 by icheri            #+#    #+#             */
/*   Updated: 2021/10/21 18:39:52 by icheri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}
