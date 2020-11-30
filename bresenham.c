/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlongfel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 10:41:03 by xlongfel          #+#    #+#             */
/*   Updated: 2019/11/26 13:10:42 by xlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		isometric(t_fpoint *xy, int z, float ugol1)
{
	xy->x = (xy->x - xy->y) * cos(ugol1 * M_PI / 180);
	xy->y = (xy->x + xy->y) * sin(ugol1 * M_PI / 180) - z;
}

void			bresenham(t_fpoint start, t_fpoint end, t_fdf *data)
{
	t_fpoint	step;
	t_fpoint	cur;
	t_fpoint	delta;

	cur = start;
	zoomify_points(&start, &end, data->zoom);
	isometric(&start, start.z, data->ugol);
	isometric(&end, end.z, data->ugol);
	delta.x = end.x - start.x;
	delta.y = end.y - start.y;
	data->maximum = MAX(fmodule(delta.x), fmodule(delta.y));
	step.x = delta.x / data->maximum;
	step.y = delta.y / data->maximum;
	while ((int)(start.x - end.x) || (int)(start.y - end.y))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, start.x + data->shift_x,
		start.y + data->shift_y, get_color(start, cur, end, delta));
		start.x += step.x;
		start.y += step.y;
	}
}

static void		ft_draw_y_border(t_fdf *data)
{
	t_fpoint	p1;
	t_fpoint	p2;

	p1.y = -1;
	while (++p1.y < data->height)
	{
		p1.x = -1;
		while (++p1.x < data->width)
		{
			if (p1.x < data->width - 1)
			{
				p2.x = p1.x + 1;
				p2.y = p1.y;
				p1.z = data->z_matrix[(int)p1.y][(int)p1.x] * data->spike;
				p2.z = data->z_matrix[(int)p2.y][(int)p2.x] * data->spike;
				p1.color = get_height_color(data, p1.z);
				p2.color = get_height_color(data, p2.z);
				bresenham(p1, p2, data);
			}
		}
	}
}

static void		ft_draw_x_border(t_fdf *data)
{
	t_fpoint	p1;
	t_fpoint	p2;

	p1.y = -1;
	while (++p1.y < data->height)
	{
		p1.x = -1;
		while (++p1.x < data->width)
		{
			if (p1.y < data->height - 1)
			{
				p2.x = p1.x;
				p2.y = p1.y + 1;
				p1.z = data->z_matrix[(int)p1.y][(int)p1.x] * data->spike;
				p2.z = data->z_matrix[(int)p2.y][(int)p2.x] * data->spike;
				p1.color = get_height_color(data, p1.z);
				p2.color = get_height_color(data, p2.z);
				bresenham(p1, p2, data);
			}
		}
	}
}

void			draw(t_fdf *data)
{
	ft_draw_y_border(data);
	ft_draw_x_border(data);
}
