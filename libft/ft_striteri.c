/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchencha <nchencha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 22:38:00 by nchencha          #+#    #+#             */
/*   Updated: 2024/09/07 22:57:01 by nchencha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}

// char	to_upper(int c)
// {
// 	if (c >= 'a' && c <= 'z')
// 		return (c - 32);
// 	return (c);
// }

// void	to_uppercase(unsigned int index, char *c)
// {
// 	(void)index;
// 	*c = to_upper(*c);
// }

// int main()
// {
// 	char	str[] = "hello, world!";
// 	printf("Before: %s\n", str);
// 	ft_striteri(str, to_uppercase);
// 	printf("After: %s\n", str);
	// 	return 0;
// }