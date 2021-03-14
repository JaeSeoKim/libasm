/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 03:33:59 by jaeskim           #+#    #+#             */
/*   Updated: 2021/03/14 19:28:34 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_test.h"

static void	do_test(char *dst, char *src)
{
	printf("try... ft_strcpy(dst, \"%s\");\n", src);
	ft_strcpy(dst, src);
	if (strcmp(src, dst) != 0)
	{
		printf("KO: diff src: \"%s\", dst: \"%s\"\n", src, dst);
		exit(1);
	}
}

void	ft_strcpy_test(void)
{
	int		i;
	char	dst[100];

	printf("===================================================\n");
	printf("test ft_strcpy();\n");
	i = 0;
	while (i < 10)
		do_test(&dst[0], g_string[i++]);
	printf("SUCCESS!\n");
}
