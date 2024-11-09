/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchencha <nchencha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:54:43 by nchencha          #+#    #+#             */
/*   Updated: 2024/09/11 16:01:43 by nchencha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char			*tmp_dst;
	unsigned char			*tmp_src;

	if (dst == (void *)0 && src == (void *)0)
		return (dst);
	tmp_dst = (unsigned char *) dst;
	tmp_src = (unsigned char *) src;
	while (n > 0)
	{
		*(tmp_dst++) = *(tmp_src)++;
		n--;
	}
	return (dst);
}

// #include <string.h>
// int main()
// {
// 	char src[] = "Hello, World!";
// 	char dst[20];
// 	char src2[] = "Hello, World!";
// 	char dst2[20];

// 	ft_memcpy(dst, src, 12);
// 	dst[12] = '\0';
// 	printf("Source of ft_memcpy: %s\n", src);
// 	printf("Destination of ft_memcpy: %s\n", dst);
// 	printf("\n");
// 	memcpy(dst2, src2, 12);
// 	dst[12] = 0;
// 	printf("Source of memcpy: %s\n", src2);
// 	printf("Destination of memcpy: %s\n", dst2);
// 	return 0;
// }