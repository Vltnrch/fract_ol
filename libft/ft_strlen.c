/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroche <vroche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 11:53:29 by vroche            #+#    #+#             */
/*   Updated: 2015/01/12 16:15:14 by vroche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	a;

	if (s == NULL || *s == 0)
		return (0);
	a = 0;
	while (*s != '\0')
	{
		s++;
		a++;
	}
	return (a);
}
