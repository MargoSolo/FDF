/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlongfel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 10:12:26 by xlongfel          #+#    #+#             */
/*   Updated: 2019/11/26 14:40:55 by xlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include <math.h>
# include "minilibx_macos/mlx.h"
# include "get_next_line.h"
# include <stdio.h>

typedef struct			s_fpoint
{
	float			x;
	float			y;
	int				z;
	unsigned int	color;
}						t_fpoint;

typedef struct			s_fdf
{
	int			width;
	int			height;
	int			**z_matrix;
	int			zoom;
	unsigned int max_color;
	unsigned int min_color;
	unsigned int med_color;
	int			shift_x;
	int			shift_y;
	float		ugol;
	int			z_min;
	int			z_max;
	int			z_range;
	void		*mlx_ptr;
	void		*win_ptr;
	int			maximum;
	void		*window;
	double		spike;
	unsigned int    minnn;
	unsigned int    maxxx;
}						t_fdf;

void					read_file(char *file_name, t_fdf *data);
void					bresenham(t_fpoint start, t_fpoint end, t_fdf *data);
void					draw(t_fdf *data);
float					fmodule(float i);
int						create_color(int i);
void					ft_free_struct(t_fdf *param);
void					ft_init(t_fdf *temp);
int						get_color(t_fpoint current, t_fpoint start, t_fpoint end, t_fpoint deltta);
unsigned int			get_height_color(t_fdf *data, float z);
void					print_menu(t_fdf *data);
void					zoomify_points(t_fpoint *start, t_fpoint *end, int zoom);
int						cl(void *c);

#endif
