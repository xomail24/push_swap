/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icheri <icheri@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 11:50:43 by ychet             #+#    #+#             */
/*   Updated: 2022/02/04 23:10:01 by icheri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_next_line(char *buff, char	**str)
{
	char	*next_line;
	char	*newstr;

	next_line = ft_strchr(*str, '\n');
	if (next_line != NULL)
	{
		newstr = ft_substr(*str, 0, next_line - (*str) + 1);
		next_line++;
		while (*next_line != '\0')
			*buff++ = *next_line++;
		free(*str);
		*str = newstr;
		return (0);
	}
	return (1);
}

static char	*getbuff(char	*buff)
{
	char	*str;
	int		i;

	i = 0;
	if (*buff)
	{
		str = malloc((ft_strlen(buff) + 1) * sizeof(char));
		ft_bzero(str, ft_strlen(buff) + 1);
		while (buff[i] != '\0')
		{
			str[i] = buff[i];
			i++;
		}
	}
	else
	{
		str = malloc(sizeof(char));
		ft_bzero(str, 1);
	}
	ft_bzero(buff, ft_strlen(buff));
	return (str);
}

int	ft_read_file(int fd, char *dop, char	**str)
{
	char	buff[BUFFER_SIZE + 1];
	int		flag;
	int		flag2;
	char	*resbuff;

	resbuff = *str;
	ft_bzero(buff, BUFFER_SIZE + 1);
	flag = read(fd, buff, BUFFER_SIZE);
	*str = ft_strjoin(resbuff, buff);
	free(resbuff);
	flag2 = find_next_line(dop, str);
	if (flag == -1 || **str == '\0')
		return (-1);
	if (flag == 0)
		return (0);
	return (flag2);
}

char	*get_next_line(int fd)
{
	static char	dop[BUFFER_SIZE];
	char		*res;
	int			flag;

	res = getbuff(dop);
	ft_bzero(dop, BUFFER_SIZE);
	flag = find_next_line(dop, &res);
	while (flag)
	{
		flag = ft_read_file(fd, dop, &res);
		if (flag == -1)
		{
			free(res);
			return (NULL);
		}
	}
	return (res);
}
