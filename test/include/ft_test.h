/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 03:11:03 by jaeskim           #+#    #+#             */
/*   Updated: 2021/03/14 16:38:08 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TEST_H
# define FT_TEST_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

extern char	*g_string[10];

char	*ft_strcpy(char *dst, const char *src);
void	ft_strcpy_test(void);

size_t	ft_strlen(const char *s);
void	ft_strlen_test(void);

int		ft_strcmp(const char *s1, const char *s2);
void	ft_strcmp_test(void);

#endif
