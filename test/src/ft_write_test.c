/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 18:28:25 by jaeskim           #+#    #+#             */
/*   Updated: 2021/03/14 18:50:38 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_test.h"

static void	do_test(int fd, char *s)
{
	int	ori[2];
	int	ft[2];
	int	s_len;

	printf("try... ft_write(%d, \"%s\", %d);\n", fd, s, s_len);
	s_len = strlen(s);
	ori[0] = write(fd, s, s_len);
	ori[1] = errno;
	ft[0] = ft_write(fd, s, s_len);
	ft[1] = errno;
	printf("\ndiff ori: %d (___errno : %d), ft: %d (___errno : %d)\n", \
		ori[0], ori[1], ft[0], ft[1]);
	if ((ori[0] != ft[0]) || (ori[1] != ft[1]))
		exit(1);
}

void	ft_write_test(void)
{
	int	i;

	printf("===================================================\n");
	printf("testing ft_write();\n");
	i = 0;
	while (i < 10)
		do_test(i, g_string[i++]);
	printf("SUCCESS!\n");
}
