/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icheri <icheri@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 05:53:03 by icheri            #+#    #+#             */
/*   Updated: 2022/02/04 23:12:47 by icheri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_swap(t_list **stack_a, t_list **stack_b)
{
	int	len;

	len = stack_len(*stack_a);
	sort_for_index(stack_a);
	if (len < 6 && len > 1)
		sort_small_stack(stack_a, stack_b, len);
	else if (len < 2)
		exit_str("", 1);
	radix_sort(stack_a, stack_b, len);
}

int	main(int argc, char **argv)
{
	t_list		*stack_a;
	t_list		*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	check_input(argc, argv, &stack_a);
	push_swap(&stack_a, &stack_b);
	free_stack(&stack_a);
	return (0);
}
