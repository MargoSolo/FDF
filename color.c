/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlongfel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 11:49:47 by xlongfel          #+#    #+#             */
/*   Updated: 2019/11/26 15:14:10 by xlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double			percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

int				get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int				get_color(t_fpoint current, t_fpoint start,
t_fpoint end, t_fpoint deltta)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (current.color == end.color)
		return (current.color);
	if (deltta.x > deltta.y)
		percentage = percent(start.x, end.x, current.x);
	else
		percentage = percent(start.y, end.y, current.y);
	red = get_light((start.color >> 16) & 0xFF,
	(end.color >> 16) & 0xFF, percentage);
	green = get_light((start.color >> 8)
	& 0xFF, (end.color >> 8) & 0xFF, percentage);
	blue = get_light(start.color & 0xFF, end.color & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}

double			colorful(t_fdf *data, float z)
{
	double	cooloore;

	data->z_range = (data->z_max - data->z_min) / 2 + data->z_min;
	if (z <= data->z_range)
	{
		cooloore = (double)((z - data->z_min) /
		((double)data->z_range - data->z_min));
		data->minnn = data->min_color;
		data->maxxx = data->med_color;
	}
	if (z > data->z_range)
	{
		cooloore = (double)((z - data->z_range) /
		((double)data->z_max - data->z_range));
		data->minnn = data->med_color;
		data->maxxx = data->max_color;
	}
	return (cooloore);
}

unsigned int	get_height_color(t_fdf *data, float z)
{
	double	cooloore1;
	int		red;
	int		green;
	int		blue;

	cooloore1 = colorful(data, z);
	red = get_light((data->minnn >> 16) & 0xFF,
					(data->maxxx >> 16) & 0xFF,
					cooloore1);
	green = get_light((data->minnn >> 8) & 0xFF,
	(data->maxxx >> 8) & 0xFF, cooloore1);
	blue = get_light(data->minnn & 0xFF, data->maxxx & 0xFF, cooloore1);
	return ((red << 16) | (green << 8) | blue);
}
