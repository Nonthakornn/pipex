/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchencha <nchencha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 19:26:22 by nchencha          #+#    #+#             */
/*   Updated: 2024/09/11 22:33:33 by nchencha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	length_s;

	if (s == NULL)
		return (NULL);
	length_s = ft_strlen(s);
	if (start > ft_strlen(s))
		len = 0;
	if (len > length_s - start)
		len = length_s - start;
	str = ft_calloc(len + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[len] = '\0';
	return (str);
}

// int	main()
// {
// 	//printf("%s\n", ft_substr("0123456", 8, 4));
// 	//printf("%s\n", ft_substr("0123456", 0, 4));
// 	//printf("%s\n", ft_substr("0123456", 5, 4));
// 	printf("%s\n", ft_substr("0123456", 0, 10));
// }