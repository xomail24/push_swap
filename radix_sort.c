/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icheri <icheri@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 21:11:14 by icheri            #+#    #+#             */
/*   Updated: 2022/02/04 17:41:15 by icheri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *head)
{
	while (head->value < head->next->value)
	{
		head = head->next;
		if (head->next == NULL)
			return (1);
	}
	return (0);
}

void	radix_sort(t_list **stack_a, t_list **stack_b, int len)
{
	int				bit;
	int				k;
	unsigned int	index;

	bit = 0;
	while (!is_sorted(*stack_a))
	{
		k = 0;
		while (k < len && !is_sorted(*stack_a))
		{
			index = (*stack_a)->index;
			if ((index >> bit) & 1)
				ra(stack_a, "ra\n");
			else
				pb(stack_a, stack_b, "pb\n");
			k++;
		}
		while (*stack_b)
			pa(stack_a, stack_b, "pa\n");
		bit++;
	}
}
