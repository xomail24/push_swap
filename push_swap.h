/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icheri <icheri@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 04:53:56 by icheri            #+#    #+#             */
/*   Updated: 2022/02/04 23:07:00 by icheri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_list
{
	int				value;
	unsigned int	index;
	struct s_list	*next;
}					t_list;

void	check_input(int argc, char **argv, t_list **stack_a);
void	make_linked_list(t_list **stack_a, char **massive, int num);
void	sort_for_index(t_list **stack_a);
void	sort_small_stack(t_list **stack_a, t_list **stack_b, int stack_len);
void	radix_sort(t_list **stack_a, t_list **stack_b, int len);
int		is_sorted(t_list *head);
void	exit_str(char *str_error, int i);
int		stack_len(t_list *head);
void	free_stack(t_list **stack_a);
char	*get_next_line(int fd);

void	ra(t_list **stack_a, char *str);
void	rra(t_list **stack_a, char *str);
void	sa(t_list **stack_a, char *str);
void	pa(t_list **stack_a, t_list **stack_b, char *str);
void	pb(t_list **stack_a, t_list **stack_b, char *str);

#endif
