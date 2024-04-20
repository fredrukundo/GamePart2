/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 03:32:56 by frukundo          #+#    #+#             */
/*   Updated: 2024/04/20 03:32:57 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

t_img	*mlx_load_img(void *ptr, char *path)
{
	int		fd;
	t_img	*i;

	i = malloc(sizeof(t_img));
	i->i = NULL;
	if (!path || ft_strrncmp(path, ".xpm", 4))
		return (i);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (i);
	close(fd);
	i->i = mlx_xpm_file_to_image(ptr, path, &i->width, &i->height);
	i->addr = mlx_get_data_addr(i->i, &i->bpp, &i->line_len, &i->endian);
	return (i);
}

int	cub_atoi(const char *nptr, long *nbr)
{
	*nbr = 0;
	if (!nptr || !ft_isdigit(*nptr))
		return (-1);
	while (ft_isdigit(*nptr))
	{
		*nbr = 10 * (*nbr) + (*nptr - '0');
		if (*nbr < 0 || *nbr > 255)
			return (-1);
		nptr++;
	}
	if (*nptr)
		return (-1);
	return (0);
}

float	degree_to_radians(float degree)
{
	return (degree * M_PI / 180);
}

int	checkcn(char *m, char c, int n0, int n1)
{
	int	i;

	i = n0;
	while (i >= 0 && i < n1 && i < (int) ft_strlen(m))
	{
		if (m[i] != c)
			return (1);
		i++;
	}
	return (0);
}
