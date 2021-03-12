/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 01:17:49 by jaeskim           #+#    #+#             */
/*   Updated: 2021/03/13 03:42:17 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_test.h"

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
	test_strlen();
	test_strcpy();
	return (0);
}
