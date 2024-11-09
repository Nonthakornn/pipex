/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchencha <nchencha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 21:26:12 by nchencha          #+#    #+#             */
/*   Updated: 2024/09/07 21:57:38 by nchencha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	intlen(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
	{
		i++;
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*int2char(char *str, int n)
{
	int	i;
	int	is_negative;

	i = intlen(n);
	str[i--] = '\0';
	is_negative = (n < 0);
	if (is_negative)
	{
		n = -n;
		str[0] = '-';
	}
	if (n == 0)
	{
		str[i] = '0';
	}
	while (n > 0)
	{
		str[i--] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	str = malloc(sizeof(char) * (intlen(n) + 1));
	if (!str)
		return (NULL);
	return (int2char(str, n));
}

// int main(void)
// {
//     int numbers[] = {0, 123, -456, 7890, -2147483648, 2147483647};
//     char *result;
//     size_t i;
//     size_t count = sizeof(numbers) / sizeof(numbers[0]);

//     for (i = 0; i < count; i++)
//     {
//         result = ft_itoa(numbers[i]);
//         if (result)
//         {
//             printf("ft_itoa(%d) = %s\n", numbers[i], result);
//             free(result);
//         }
//         else
//         {
//             printf("Memory allocation failed for %d\n", numbers[i]);
//         }
//     }

//     return 0;
// }