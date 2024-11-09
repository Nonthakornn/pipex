/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchencha <nchencha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 20:45:38 by nchencha          #+#    #+#             */
/*   Updated: 2024/09/07 21:23:38 by nchencha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char *str, char c);
static char	*fill_word(char *str, int start, int end);
static void	ft_free(char **str_array, int count);

char	**ft_split(char *s, char c)
{
	char	**array;
	int		i;
	int		start;
	int		end;

	array = malloc((word_count(s, c) + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	i = 0;
	start = 0;
	end = 0;
	while (i < word_count(s, c))
	{
		while (s[end] == c)
			end++;
		start = end;
		while (s[end] != c && s[end] != '\0')
			end++;
		array[i] = fill_word(s, start, end);
		if (!array[i])
			ft_free(array, i);
		i++;
	}
	array[i] = NULL;
	return (array);
}

static int	word_count(char *str, char c)
{
	int	count;
	int	split;

	count = 0;
	split = 0;
	while (*str)
	{
		if (*str != c && split == 0)
		{
			split = 1;
			count++;
		}
		else if (*str == c)
			split = 0;
		str++;
	}
	return (count);
}

static char	*fill_word(char *str, int start, int end)
{
	char	*word;
	int		i;

	word = (char *)malloc((end - start + 1) * sizeof(char));
	i = 0;
	if (!word)
		return (NULL);
	while (start < end)
	{
		word[i] = str[start];
		start++;
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	ft_free(char **str_array, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(str_array[i]);
		i++;
	}
	free(str_array);
}

// int main()
// {
// 	char **res;
// 	res = ft_split("aaaaabnnnnnnnbmmmmbsss", 'b');
// 	int i = 0;
// 	while (res[i])
// 	{
// 		printf("'%s'\n", res[i]);
// 		i++;
// 	}
// 	ft_free(res, i);
// }