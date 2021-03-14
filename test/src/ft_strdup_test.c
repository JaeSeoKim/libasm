/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 19:38:10 by jaeskim           #+#    #+#             */
/*   Updated: 2021/03/14 22:09:10 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_test.h"

static void	do_test(char *s)
{
	char	*dup_s;

	printf("try... ft_strdup(\"%s\");\n", s);
	dup_s = ft_strdup(s);
	if (strcmp(dup_s, s) != 0)
	{
		printf("KO: diff src: %s, dup: %s\n", s, dup_s);
		free(dup_s);
		exit(1);
	}
	free(dup_s);
}

void	ft_strdup_test(void)
{
	int	i;

	printf("===================================================\n");
	printf("ft_strdup_test();\n");
	i = 0;
	while (i < 10)
		do_test(g_string[i++]);
	printf("SUCCESS!\n");
}
