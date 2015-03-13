/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hsvtorgb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroche <vroche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 01:26:26 by vroche            #+#    #+#             */
/*   Updated: 2015/02/08 22:59:03 by vroche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** HSV Color to RGB color
** thanks wiki
*/

#include "fract_ol.h"

int	ft_hsvtorgb(int h, int s, int v)
{
	int	region;
	int	fpart;
	int	p;
	int	q;
	int	t;

	if (s == 0)
		return ((v << 16) + (v << 8) + v);
	region = h / 42.5;
	fpart = (h - (region * 42.5)) * 6;
	p = (v * (255 - s)) >> 8;
	q = (v * (255 - ((s * fpart) >> 8))) >> 8;
	t = (v * (255 - ((s * (255 - fpart)) >> 8))) >> 8;
	if (region == 0)
		return ((v << 16) + (t << 8) + p);
	else if (region == 1)
		return ((q << 16) + (v << 8) + p);
	else if (region == 2)
		return ((p << 16) + (v << 8) + t);
	else if (region == 3)
		return ((p << 16) + (q << 8) + v);
	else if (region == 4)
		return ((t << 16) + (p << 8) + v);
	return ((v << 16) + (p << 8) + q);
}
