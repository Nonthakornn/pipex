/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchencha <nchencha@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-04 13:28:15 by nchencha          #+#    #+#             */
/*   Updated: 2024-09-04 13:28:15 by nchencha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dest;
	size_t	i;

	dest = (char *) malloc(ft_strlen(s1) +1);
	if (!dest)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
// int main() 
// {
// 	char *str = "Hello World!";
// 	char *dup_str;

// 	dup_str = ft_strdup(str);
// 	printf("Original string %s\n", str);
// 	printf("Duplicate string: %s\n", dup_str);

// 	free(dup_str);
// 	return (0);
// }