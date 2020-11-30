/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlongfel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 10:10:11 by xlongfel          #+#    #+#             */
/*   Updated: 2019/11/26 15:05:22 by xlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		key_move(int key, t_fdf *data)
{
	if (key == 126)
		data->shift_y -= 20;
	if (key == 125)
		data->shift_y += 20;
	if (key == 123)
		data->shift_x -= 20;
	if (key == 124)
		data->shift_x += 20;
}

void		key_zoom_rotate(int key, t_fdf *data)
{
	if (key == 91)
		data->zoom *= 2;
	if (key == 84)
		data->zoom /= 2;
	if (key == 88)
		data->ugol += 2;
	if (key == 86)
		data->ugol -= 2;
}

void		handle_spike(int key, t_fdf *data)
{
	if (key == 67)
	{
		data->spike = data->spike + 0.1;
		if (data->spike >= 10)
			data->spike = 10;
	}
	else if (key == 75)
	{
		data->spike = data->spike - 0.1;
		if (data->spike == 0)
			data->spike = 0.1;
	}
}

int			deal_key(int key, t_fdf *data)
{
	if (key == 53)
		exit(0);
	key_move(key, data);
	key_zoom_rotate(key, data);
	handle_spike(key, data);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	return (0);
}

int			main(int argc, char **argv)
{
	t_fdf *data;

	if (argc != 2)
	{
		ft_putstr("usage: ./fdf map.fdf");
		return (0);
	}
	if (!(data = (t_fdf*)malloc(sizeof(t_fdf))))
		write(1, "ERR_CONV_TO_ARR\n", 17);
	ft_init(data);
	read_file(argv[1], data);
	draw(data);
	print_menu(data);
	mlx_key_hook(data->win_ptr, deal_key, (void *)data);
	mlx_hook(data->win_ptr, 17, 0, cl, NULL);
	mlx_loop(data->mlx_ptr);
	ft_free_struct(data);
	return (0);
}
