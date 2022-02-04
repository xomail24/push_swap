/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_for_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icheri <icheri@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 04:43:23 by icheri            #+#    #+#             */
/*   Updated: 2022/02/03 22:23:37 by icheri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_list *head)
{
	int		len;
	t_list	*tmp;

	tmp = head;
	len = 0;
	while (tmp)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}

static int	search_min(t_list *head)
{
	int	first_min;

	first_min = INT_MAX;
	while (head)
	{
		if (head->value < first_min)
			first_min = head->value;
		head = head->next;
	}
	return (first_min);
}

static int	search_next_min(t_list *head, int previous_min)
{
	int	next_min;

	next_min = INT_MAX;
	while (head)
	{
		if (head->value < next_min && head->value > previous_min)
			next_min = head->value;
		head = head->next;
	}
	return (next_min);
}

void	sort_for_index(t_list **stack_a)
{
	t_list	*head;
	int		index;
	int		len_a;
	int		min;

	index = 0;
	head = *stack_a;
	len_a = stack_len(*stack_a);
	min = search_min(*stack_a);
	while (len_a != index)
	{
		while ((*stack_a)->value != min)
			*stack_a = (*stack_a)->next;
		(*stack_a)->index = index;
		index++;
		*stack_a = head;
		min = search_next_min(*stack_a, min);
	}
}
