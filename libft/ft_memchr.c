/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchencha <nchencha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:13:35 by nchencha          #+#    #+#             */
/*   Updated: 2024/09/11 16:30:52 by nchencha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	uc;
	size_t			i;

	str = (unsigned char *) s;
	uc = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (str[i] == uc)
			return ((void *) &str[i]);
		i++;
	}
	return (NULL);
}

// #include <string.h>
// int main()
// {
// 	char str[] = "Hello, World";
// 	char *result;
// 	int c = 87;

// 	result = (char *)ft_memchr(str, c, 13);
// 	if (result)
// 	{
// 		printf("Fount 'W' at position: %ld\n", result - str);
// 	}
// 	else
// 		printf("'W is not found");
// 	return (0);
// }