/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icheri <icheri@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:51:19 by icheri            #+#    #+#             */
/*   Updated: 2022/02/04 23:31:30 by icheri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_digit(char **massive)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (massive[i])
	{
		j = 0;
		while (massive[i][j])
		{
			if (massive[i][j] == '-')
				j++;
			if (!ft_isdigit(massive[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_repeat(char **massive)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (massive[i])
	{
		j = i + 1;
		while (massive[j])
		{
			if (!ft_strcmp(massive[i], massive[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_int(char **massive)
{
	size_t	i;

	i = 0;
	while (massive[i])
	{
		if ((ft_atoi(massive[i]) > INT_MAX)
			|| (ft_atoi(massive[i]) < INT_MIN))
			return (0);
		i++;
	}
	return (1);
}

static int	check_argv(char **massive, int i)
{
	if (!check_digit(&massive[i]) || !check_repeat(&massive[i])
		|| !check_int(&massive[i]))
		return (0);
	return (1);
}

void	check_input(int argc, char **argv, t_list **stack_a)
{
	int			i;
	char		**massive;

	i = 0;
	massive = NULL;
	if (argc == 2)
	{
		massive = ft_split(argv[1], ' ');
		if (massive == NULL)
			exit_str("Error", 0);
	}
	else if (argc > 2)
	{
		massive = argv;
		i = 1;
	}
	else
		exit_str("", 1);
	if (!check_argv(massive, i))
		exit_str("Error", 0);
	make_linked_list(stack_a, massive, i);
}
