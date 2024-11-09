/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchencha <nchencha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:44:37 by nchencha          #+#    #+#             */
/*   Updated: 2024/09/11 00:04:17 by nchencha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*tmp_ptr;

	tmp_ptr = (char *) s;
	while (n > 0)
	{
		*(tmp_ptr++) = 0;
		n--;
	}
}

// #include <string.h>
// int	main()
// {
// 	//for str it set to null \0
// 	char buffer[10] = "123456789";
// 	char buffer2[10] = "123456789";
// 	//for int it set to 0
// 	// int arr[3] = {1, 2, 3}

// 	printf("Before ft_bzero: %s\n", buffer);
// 	//Clear the first 5 bytes 
// 	ft_bzero(buffer, 5);
// 	printf("After ft_bzero: ");
// 	for (int i = 0; i < 10; i++)
// 	{
// 		if (buffer[i] == 0)
// 			printf("\\0 ");
// 		else
// 			printf("%c ", buffer[i]);
// 	}
// 	printf("\n");
// 	printf("------------------\n");
// 	printf("Before bzero: %s\n", buffer2);
// 	bzero(buffer, 5);
// 	printf("After bzero: ");
// 	for (int i = 0; i < 10; i++)
// 	{
// 		if (buffer[i] == 0)
// 			printf("\\0 ");
// 		else
// 			printf("%c ", buffer[i]);
// 	}
// 	printf("\n");
// 	return (0);
// }