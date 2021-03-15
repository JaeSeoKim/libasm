/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 01:17:49 by jaeskim           #+#    #+#             */
/*   Updated: 2021/03/16 05:56:49 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_test_bonus.h"

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

t_list	*ft_list_create_elem(void *data);

int	main(void)
{
	system("clear");
	putstr_slow("🤩 TEST Libasm BONUS!!!! 🚀\n");
	ft_atoi_base_test();
	ft_list_push_front_test();
	ft_list_size_test();
	return (0);
}
