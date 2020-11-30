/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlongfel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 14:33:43 by xlongfel          #+#    #+#             */
/*   Updated: 2019/11/26 15:15:14 by xlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			zoomify_points(t_fpoint *start, t_fpoint *end, int zoom)
{
	start->x *= zoom;
	start->y *= zoom;
	end->x *= zoom;
	end->y *= zoom;
}

static void		color_menu(void *win, void *ptr)
{
	int		x;
	int		y;
	int		menu_width;
	int		height;

	menu_width = 250;
	height = 1250;
	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < menu_width)
		{
			mlx_pixel_put(ptr, win, x, y, 0x1E1E1E);
			++x;
		}
		++y;
	}
}

void			print_menu(t_fdf *data)
{
	void	*win;
	void	*ptr;

	win = data->win_ptr;
	ptr = data->mlx_ptr;
	color_menu(win, ptr);
	mlx_string_put(ptr, win, 10, 20, 0xEAEAEA, "FdF");
	mlx_string_put(ptr, win, 10, 60, 0xEAEAEA, "How to use :");
	mlx_string_put(ptr, win, 10, 100, 0xEAEAEA, "Zoom : 8 / 2");
	mlx_string_put(ptr, win, 10, 120, 0xEAEAEA, "Move : Arrows");
	mlx_string_put(ptr, win, 10, 140, 0xEAEAEA, "Rotations : 4 / 6");
	mlx_string_put(ptr, win, 10, 180, 0xEAEAEA, "Change height : * or /");
	mlx_string_put(ptr, win, 10, 300, 0xEAEAEA, "ESC to quit");
	mlx_string_put(ptr, win, 10, 780, 0xEAEAEA, "Created by : XLONGFEL");
}

void			ft_init(t_fdf *temp)
{
	temp->mlx_ptr = mlx_init();
	temp->win_ptr = mlx_new_window(temp->mlx_ptr, 1900, 1250, "FDF");
	temp->zoom = 20;
	temp->shift_x = 700;
	temp->shift_y = 700;
	temp->ugol = 2;
	temp->z_min = 2147483647;
	temp->z_max = -2147483648;
	temp->max_color = 0xFFFFFF;
	temp->min_color = 0x00FF00;
	temp->med_color = 0x0000FF;
	temp->spike = 2;
	temp->minnn = 2147483647;
	temp->maxxx = -2147483647;
}

void			ft_free_struct(t_fdf *param)
{
	int		count;
	int		**z_matrix;

	count = 0;
	z_matrix = param->z_matrix;
	while (count < param->height)
	{
		free(z_matrix[count]);
		count++;
	}
	free(z_matrix);
	free(param);
}
