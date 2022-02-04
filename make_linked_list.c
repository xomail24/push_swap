/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_linked_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icheri <icheri@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 04:45:27 by icheri            #+#    #+#             */
/*   Updated: 2022/02/04 23:12:59 by icheri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_str(char *str_error, int i)
{
	ft_putstr_fd(str_error, 2);
	if (i == 0)
		ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}

void	free_stack(t_list **stack_a)
{
	t_list	*tmp;

	while (*stack_a)
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		free(tmp);
	}
}

static t_list	*add_list(int value)
{
	t_list	*new_list;

	new_list = (t_list *)malloc(sizeof(*new_list));
	if (new_list == NULL)
		exit_str("memory allocation error", 0);
	new_list->value = value;
	new_list->next = NULL;
	return (new_list);
}

static void	add_list_back(t_list **stack_a, int value)
{
	t_list	*new_list;
	t_list	*tmp;

	new_list = add_list(value);
	tmp = *stack_a;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new_list;
}

void	make_linked_list(t_list **stack_a, char **massive, int num)
{
	*stack_a = add_list(ft_atoi(massive[num]));
	while (massive[++num])
		add_list_back(stack_a, ft_atoi(massive[num]));
}
