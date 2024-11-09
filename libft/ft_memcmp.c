/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchencha <nchencha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:22:43 by nchencha          #+#    #+#             */
/*   Updated: 2024/09/11 16:42:04 by nchencha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if ((unsigned char) str1[i] != (unsigned char) str2[i])
			return ((unsigned char) str1[i] - (unsigned char) str2[i]);
		i++;
	}
	return (0);
}

// int main()
// {
// 	char str1[] = "Memory Compare";
// 	char str2[] = "Memory compare";

// 	int result = ft_memcmp(str1, str2, 13);
// 	if (result == 0)
// 	{
// 		printf("The memory blocks are the same");
// 	}
// 	else if (result > 0)
// 	{
// 		printf("The value is positive");
// 	}
// 	else
// 		printf("The value is negative");
// 	return (0);
// }