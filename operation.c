/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icheri <icheri@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 05:41:35 by icheri            #+#    #+#             */
/*   Updated: 2022/02/03 22:23:28 by icheri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **stack_a, char *str)
{
	t_list	*head;
	t_list	*second;

	if (stack_a == NULL || *stack_a == NULL)
		return ;
	if ((*stack_a)->next == NULL)
		return ;
	if (str)
		ft_putstr_fd(str, 1);
	head = *stack_a;
	second = (*stack_a)->next;
	while ((*stack_a)->next)
		*stack_a = (*stack_a)->next;
	(*stack_a)->next = head;
	(*stack_a)->next->next = NULL;
	*stack_a = second;
}

void	rra(t_list **stack_a, char *str)
{
	t_list	*head;
	t_list	*tmp;
	t_list	*last;

	if (str)
		ft_putstr_fd(str, 1);
	head = *stack_a;
	if (stack_len(*stack_a) <= 1)
		return ;
	while ((*stack_a)->next->next)
		*stack_a = (*stack_a)->next;
	tmp = *stack_a;
	last = tmp->next;
	tmp->next = NULL;
	last->next = head;
	*stack_a = last;
}

void	sa(t_list **stack_a, char *str)
{
	int	index;
	int	value;

	if (stack_len(*stack_a) < 1 || *stack_a == NULL)
		return ;
	index = (*stack_a)->index;
	value = (*stack_a)->value;
	(*stack_a)->index = (*stack_a)->next->index;
	(*stack_a)->value = (*stack_a)->next->value;
	(*stack_a)->next->index = index;
	(*stack_a)->next->value = value;
	if (str)
		ft_putstr_fd(str, 1);
}

void	pa(t_list **stack_a, t_list **stack_b, char *str)
{
	t_list	*tmp;

	tmp = *stack_b;
	if (stack_len(*stack_b) == 0)
		return ;
	if (str)
		ft_putstr_fd(str, 1);
	*stack_b = (*stack_b)->next;
	tmp->next = *stack_a;
	*stack_a = tmp;
}

void	pb(t_list **stack_a, t_list **stack_b, char *str)
{
	t_list	*tmp;

	tmp = *stack_a;
	if (stack_len(*stack_a) == 0)
		return ;
	if (str)
		ft_putstr_fd(str, 1);
	*stack_a = (*stack_a)->next;
	tmp->next = *stack_b;
	*stack_b = tmp;
}
