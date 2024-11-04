/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <saalarco@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:34:43 by saalarco          #+#    #+#             */
/*   Updated: 2024/09/01 16:47:35 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <string.h>

size_t	ft_strlen(const char *s)
{
	size_t	c;

	c = 0;
	while (*s++ != '\0')
		c++;
	return (c);
}

/*
size_t ft_strlen(const char *str) {
    if (str == NULL) {
        return 0;  // Or handle the error
    }
    size_t length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}
*/
/*
int main (void)
{
	char *s;

	s = NULL;

	ft_putnbr_fd(ft_strlen(s), 1);
}

/// a posteriori: proteger *s
*/
