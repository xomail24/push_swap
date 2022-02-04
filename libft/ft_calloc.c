/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icheri <icheri@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 22:57:07 by icheri            #+#    #+#             */
/*   Updated: 2021/10/23 13:59:43 by icheri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void			*str;
	unsigned int	nbytes;

	nbytes = count * size;
	str = malloc(nbytes);
	if (str)
		ft_memset(str, 0, nbytes);
	return (str);
}
