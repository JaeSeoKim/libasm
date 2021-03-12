/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 03:11:03 by jaeskim           #+#    #+#             */
/*   Updated: 2021/03/13 03:36:19 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TEST_H
# define FT_TEST_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

char	*ft_strcpy(char *dst, const char *src);
void	test_strcpy(void);

# define CASE_1 "test case one!"
# define CASE_2 "test case two!"
# define CASE_3 "Hello WOOOOORLD!"

size_t	ft_strlen(const char *s);
void	test_strlen(void);

#endif
