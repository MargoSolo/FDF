/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlongfel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 10:11:26 by xlongfel          #+#    #+#             */
/*   Updated: 2019/11/26 14:33:27 by xlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_height(char *file_name)
{
	char	*line;
	int		fd;
	int		height;

	fd = open(file_name, O_RDONLY, 0);
	height = 0;
	while (get_next_line(fd, &line))
	{
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

int		ft_wdcounter(char *str, char c)
{
	int		i;
	int		words;

	words = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		if (str[i])
			words++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (words);
}

int		get_width(char *file_name)
{
	char	*line;
	int		fd;
	int		width;
	int		i;

	i = 0;
	fd = open(file_name, O_RDONLY, 0);
	while (get_next_line(fd, &line))
	{
		if (i == 1)
			width = ft_wdcounter(line, ' ');
		i++;
		free(line);
	}
	close(fd);
	return (width);
}

void	fill_matrix(int *z_line, t_fdf *data, char *line)
{
	char	**nums;
	int		i;

	i = 0;
	nums = ft_strsplit(line, ' ');
	while (nums[i])
	{
		z_line[i] = ft_atoi(nums[i]);
		if (data->z_min > z_line[i])
			data->z_min = z_line[i];
		if (data->z_max < z_line[i])
			data->z_max = z_line[i];
		free(nums[i]);
		i++;
	}
	free(nums);
}

void	read_file(char *file_name, t_fdf *data)
{
	int		fd;
	char	*line;
	int		i;

	data->height = get_height(file_name);
	data->width = get_width(file_name);
	data->z_matrix = (int **)malloc(sizeof(int*) * (data->height));
	i = 0;
	while (i < data->height)
	{
		data->z_matrix[i] = (int*)malloc(sizeof(int) * (data->width));
		i++;
	}
	fd = open(file_name, O_RDONLY, 0);
	i = 0;
	while (get_next_line(fd, &line))
	{
		fill_matrix(data->z_matrix[i], data, line);
		free(line);
		i++;
	}
	close(fd);
}
