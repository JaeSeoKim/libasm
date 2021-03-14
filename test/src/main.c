/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 01:17:49 by jaeskim           #+#    #+#             */
/*   Updated: 2021/03/14 19:54:32 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_test.h"

char	*g_string[10] = {
	"hello world!",
	"string test",
	"abcdefg",
	"42seoul",
	"jaeskim",
	"badge42",
	"a b c d e f g",
	"123456789",
	"42NetWork",
	"test program!"
};

void	putstr_slow(char *s)
{
	while (*s)
	{
		usleep(50000);
		write(1, s++, 1);
	}
}

int	main(void)
{
	system("clear");
	putstr_slow("🤩 TEST Libasm!!!! 🚀\n");
	ft_strlen_test();
	ft_strcpy_test();
	ft_strcmp_test();
	ft_write_test();
	ft_read_test();
	ft_strdup_test();
	return (0);
}
