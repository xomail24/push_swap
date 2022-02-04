/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icheri <icheri@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 01:58:33 by icheri            #+#    #+#             */
/*   Updated: 2022/02/04 23:09:37 by icheri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_strcmp2(char	*str1, char	*str2)
{
	while (*str1 != '\0' && *str1 != '\n')
	{
		if (*str1 != *str2)
			return (1);
		str1++;
		str2++;
	}
	if (*str2 != '\0' && *str2 != '\n')
		return (1);
	return (0);
}

int	run_operation(t_list **stack_a, t_list **stack_b, char *str2)
{
	if (ft_strcmp2(str2, "ra") == 0)
		ra(stack_a, "");
	else if (ft_strcmp2(str2, "rra") == 0)
		rra(stack_a, "");
	else if (ft_strcmp2(str2, "sa") == 0)
		sa(stack_a, "");
	else if (ft_strcmp2(str2, "pa") == 0)
		pa(stack_a, stack_b, "");
	else if (ft_strcmp2(str2, "pb") == 0)
		pb(stack_a, stack_b, "");
	else
		return (0);
	return (1);
}

void	read_oprations(t_list **stack_a, t_list **stack_b)
{
	char	*str;
	char	*str2;

	str = get_next_line(0);
	while (str)
	{
		str2 = ft_strtrim(str, " ");
		free(str);
		if (!run_operation(stack_a, stack_b, str2))
		{
			ft_putstr_fd("Error\n", 2);
			free(str2);
			exit(127);
		}
		free(str2);
		str = get_next_line(0);
	}
}

int	main(int argc, char **argv)
{
	t_list		*stack_a;
	t_list		*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	check_input(argc, argv, &stack_a);
	read_oprations(&stack_a, &stack_b);
	if (is_sorted(stack_a) && stack_len(stack_b) == 0)
	{
		ft_putstr_fd("OK\n", 1);
	}
	else
	{
		ft_putstr_fd("KO\n", 1);
	}
	free_stack(&stack_a);
}
