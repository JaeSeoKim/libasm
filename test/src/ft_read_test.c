/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 18:59:45 by jaeskim           #+#    #+#             */
/*   Updated: 2021/03/14 19:28:34 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_test.h"

static void	do_test(char *path)
{
	char	buf[2][100];
	int		ori[2];
	int		ft[2];
	int		fd;

	printf("try... ft_read(fd, \"%s\", 50);\n", path);
	memset(&buf, 0, sizeof(char [2][100]));
	fd = open(path, O_RDONLY);
	ori[0] = read(fd, buf[0], 50);
	ori[1] = errno;
	close(fd);
	fd = open(path, O_RDONLY);
	ft[0] = ft_read(fd, buf[1], 50);
	ft[1] = errno;
	close(fd);
	if ((strcmp(buf[1], buf[0]) != 0) || (ori[0] != ft[0]) || (ori[1] != ft[1]))
	{
		printf("KO: diff \n");
		printf("ori char: %s, ret: %d, errno: %d\n", buf[0], ori[0], ori[1]);
		printf("ft char: %s, ret: %d, errno: %d\n", buf[1], ft[0], ft[1]);
		exit(1);
	}
}

void	ft_read_test(void)
{
	printf("===================================================\n");
	printf("ft_read_test();\n");
	do_test("./Makefile");
	do_test("./readme.md");
	do_test("not exist file");
	do_test("42424242");
	printf("SUCCESS!\n");
}
