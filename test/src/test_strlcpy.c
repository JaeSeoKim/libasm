/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlcpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 03:33:59 by jaeskim           #+#    #+#             */
/*   Updated: 2021/03/13 04:31:30 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_test.h"

static void	do_test(char *dst, char *src)
{
	printf("try... $%s$\n", src);
	ft_strcpy(dst, src);
	if (strcmp(src, dst) != 0)
		exit(1);
	printf("SUCCESS!\n");
}

void	test_strcpy()
{
	char	dst[100];
		
	printf("test ft_strcpy();\n");
	do_test(&dst[0], CASE_1);
	do_test(&dst[0], CASE_2);
	do_test(&dst[0], CASE_3);
}
