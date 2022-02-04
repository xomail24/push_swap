/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icheri <icheri@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 02:55:58 by icheri            #+#    #+#             */
/*   Updated: 2022/02/03 22:23:41 by icheri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_two(t_list **stack_a)
{
	if ((*stack_a)->index > (*stack_a)->next->index)
		sa(stack_a, "sa\n");
}

static void	sort_three(t_list **stack_a, int i)
{
	int	list1;
	int	list3;

	list1 = (*stack_a)->index;
	list3 = (*stack_a)->next->next->index;
	if (list1 == 1 + i && list3 == 2 + i)
		sa(stack_a, "sa\n");
	else if (list1 == 2 + i && list3 == 1 + i)
		ra(stack_a, "ra\n");
	else if (list1 == 1 + i && list3 == 0 + i)
		rra(stack_a, "rra\n");
	else if (list1 == 2 + i && list3 == 0 + i)
	{
		sa(stack_a, "sa\n");
		rra(stack_a, "rra\n");
	}
	else if (list1 == 0 + i && list3 == 1 + i)
	{
		sa(stack_a, "sa\n");
		ra(stack_a, "ra\n");
	}
}

static void	sort_four(t_list **stack_a, t_list **stack_b, int i)
{
	int	list1;
	int	list4;

	while (stack_len(*stack_a) == 4)
	{
		list1 = (*stack_a)->index;
		list4 = (*stack_a)->next->next->next->index;
		if (list4 == 0 + i)
			rra(stack_a, "rra\n");
		else if (is_sorted(*stack_a) == 1)
			return ;
		else if (list1 == 0 + i)
			pb(stack_a, stack_b, "pb\n");
		else
			ra(stack_a, "ra\n");
	}
	sort_three(stack_a, i + 1);
	pa(stack_a, stack_b, "pa\n");
}

static void	sort_five(t_list **stack_a, t_list **stack_b)
{
	int	list1;
	int	list4;
	int	list5;

	list1 = (*stack_a)->index;
	list4 = (*stack_a)->next->next->next->index;
	list5 = (*stack_a)->next->next->next->next->index;
	while (list1 != 0)
	{
		if (list5 == 0 || list4 == 0)
			rra(stack_a, "rra\n");
		else
			ra(stack_a, "ra\n");
		list1 = (*stack_a)->index;
	}
	if (is_sorted(*stack_a) == 1)
		return ;
	pb(stack_a, stack_b, "pb\n");
	sort_four(stack_a, stack_b, 1);
	pa(stack_a, stack_b, "pa\n");
}

void	sort_small_stack(t_list **stack_a, t_list **stack_b, int stack_len)
{
	if (stack_len == 2)
		sort_two(stack_a);
	if (stack_len == 3)
		sort_three(stack_a, 0);
	if (stack_len == 4)
		sort_four(stack_a, stack_b, 0);
	if (stack_len == 5)
		sort_five(stack_a, stack_b);
}
