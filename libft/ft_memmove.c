/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchencha <nchencha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:59:07 by nchencha          #+#    #+#             */
/*   Updated: 2024/09/11 15:55:00 by nchencha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*c_src;
	char	*c_dst;
	size_t	i;

	if (!dst && !src)
		return (NULL);
	c_src = (char *) src;
	c_dst = (char *) dst;
	i = 0;
	if (c_dst > c_src)
	{
		while (len-- > 0)
			c_dst[len] = c_src[len];
	}
	else
	{
		while (i < len)
		{
			c_dst[i] = c_src[i];
			i++;
		}
	}
	return (dst);
}

// #include <string.h>
// int main() //character
// {
// 	char str_overlap[]  =  "Hello, World";
// 	char str_noverlap[] = "Hello, World" ;
// 	char str[] =  "Hello, World";
// 	//Use memmove to copy overlapping memory
// 	//Copy the string staring from index 0 to 7 (overlaping)
// 	ft_memmove(str_overlap + 9, str_overlap, 6);
// 	printf("Result of overlap: %s\n", str_overlap); //Hello, Hello,

// 	ft_memmove(str_noverlap, str_noverlap, 6);
// 	printf("Result of noverlap: %s\n", str_noverlap);

// 	memmove(str + 7, str, 6);
// 	printf("Result: %s\n", str);
// 	return (0);
// }

// int main() //integer
// {
// 	int source[10] = {1,2,3,4,5,6,7,8,9,10};
// 	int destination[10];

// 	//Not overlap
// 	// ft_memmove(destination, source, sizeof(int) * 10);
// 	// for (int i = 0; i < 10; i++)
// 	// 	printf("destination[%d]=%d\n", i, destination[i]);
// 	// for (int i = 0; i < 10; i++)
// 	// 	printf("source[%d]=%d\n", i, source[i]);
// 	//Overlap
// 	ft_memmove(destination, source, sizeof(int) * 10);
// 	//ft_memmove(source + 2, source, sizeof(int) * 8);
// 	for (int i = 0; i < 10; i++)
// 		printf("destination[%d]=%d\n", i, destination[i]);
// 	for (int i = 0; i < 10; i++)
// 		printf("source[%d]=%d\n", i, source[i]);
// }