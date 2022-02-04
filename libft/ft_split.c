/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icheri <icheri@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:06:29 by icheri            #+#    #+#             */
/*   Updated: 2022/02/04 23:28:47 by icheri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char *s, char c)
{
	size_t	w_count;

	w_count = 0;
	while (*s == c && *s)
		s++;
	while (*s)
	{
		w_count++;
		while (*s && *s != c)
			s++;
		while (*s && *s == c)
			s++;
	}
	return (w_count);
}

static size_t	ft_len_word(char *s, char c)
{
	size_t	w_len;

	w_len = 0;
	while (s[w_len] && s[w_len] != c)
		w_len++;
	return (w_len);
}

static char	*ft_alloc_word(char *s, char c)
{
	size_t	w_len;
	size_t	i;
	char	*word;

	w_len = ft_len_word(s, c);
	word = (char *)malloc(sizeof(char) * (w_len + 1));
	if (word == NULL)
		return (NULL);
	word[w_len] = '\0';
	i = 0;
	while (i < w_len)
	{
		word[i] = s[i];
		i++;
	}
	return (word);
}

static void	ft_compile_massive(char **massive, char *s, char c)
{
	size_t	ind_str;

	ind_str = 0;
	while (*s && *s == c)
		s++;
	while (*s)
	{
		massive[ind_str] = ft_alloc_word(s, c);
		if (!massive[ind_str] && massive[0])
		{
			while (ind_str != 0)
			{
				free(massive[ind_str]);
				massive[ind_str] = NULL;
				ind_str--;
			}
			return ;
		}
		ind_str++;
		while (*s && *s != c)
			s++;
		while (*s && *s == c)
			s++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**massive;
	size_t	w_count;

	if (s)
	{
		w_count = ft_count_words((char *)s, c);
		if (w_count == 0)
			return (NULL);
		massive = (char **)malloc(sizeof(char *) * (w_count + 1));
		if (massive == NULL)
			return (NULL);
		massive[w_count] = NULL;
		ft_compile_massive(massive, (char *)s, c);
		return (massive);
	}
	return (NULL);
}
