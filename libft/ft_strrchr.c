/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchencha <nchencha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:08:59 by nchencha          #+#    #+#             */
/*   Updated: 2024/09/08 19:23:17 by nchencha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			*ptr;
	char			cc;

	cc = (char) c;
	ptr = NULL;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == cc)
			ptr = (char *) &s[i];
		i++;
	}
	if (cc == '\0')
		ptr = (char *)&s[i];
	return (ptr);
}

/*
int main()
{
	const char *str = "fitst,sencond, last";
	char ch = ',';

	char *result = ft_strrchr(str,ch);
	printf("%s", result);
}
*/
