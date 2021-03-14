/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim.student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 15:47:55 by jaeskim           #+#    #+#             */
/*   Updated: 2021/03/14 16:39:09 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_test.h"

static void	do_test(char *s1, char *s2)
{
	int	a;
	int	b;

	printf("try... ft_strcmp(\"%s\", \"%s\");\n", s1, s2);
	a = strcmp(s1, s2);
	b = ft_strcmp(s1, s2);
	if ((a < 0 && b >= a) || (a > 0 && b <= 0))
	{
		printf("diff ori: %d, ft: %d\n", a, b);
		exit(1);
	}
}

void	ft_strcmp_test(void)
{
	int	i;

	printf("==========================================\n");
	printf("ft_strlen_test();\n");
	i = 0;
	while (i < 10)
	{
		do_test(g_string[i], g_string[9 - i]);
		do_test(g_string[i], g_string[i]);
		++i;
	}
	printf("SUCCESS!\n");
}
