/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 03:16:00 by jaeskim           #+#    #+#             */
/*   Updated: 2021/03/14 19:08:12 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_test.h"

static void	do_test(char *s)
{
	int	ori;
	int	ft;

	printf("try... ft_strlen(\"%s\");\n", s);
	ori = strlen(s);
	ft = ft_strlen(s);
	if (ori != ft)
	{
		printf("KO: diff ori: %d, ft: %d\n", ori, ft);
		exit(1);
	}
}

void	ft_strlen_test(void)
{
	int		i;

	printf("===================================================\n");
	printf("testing ft_strlen();\n");
	i = 0;
	while (i < 10)
		do_test(g_string[i++]);
	printf("SUCCESS!\n");
}
