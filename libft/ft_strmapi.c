/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchencha <nchencha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 22:03:06 by nchencha          #+#    #+#             */
/*   Updated: 2024/09/07 22:36:05 by nchencha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*res;

	res = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s))
	{
		res[i] = (*f)(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}

// char example_func(unsigned int i, char c)
// {
//     return (c + i);
// }

// int main(void)
// {
//     char *str = "a";
//     char *result;

//     result = ft_strmapi(str, &example_func);
//     if (result)
//     {
//         printf("Original string: %s\n", str);
//         printf("Modified string: %s\n", result);
//         free(result);
//     }
//     else
//     {
//         printf("Memory allocation failed or input was NULL.\n");
//     }
//     return 0;
// }