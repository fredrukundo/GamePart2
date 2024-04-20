/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 03:31:53 by frukundo          #+#    #+#             */
/*   Updated: 2024/04/20 03:31:54 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	check_walls(t_game *g, char **map, int i, int j)
{
	if (j - 1 >= 0 && j - 1 < g->height)
	{
		if (i - 1 >= 0 && i - 1 < (int)ft_strlen(map[j - 1]))
			cub_perror(inv_wall, g, NULL, map[j - 1][i - 1] == '0');
		if (i + 1 >= 0 && i + 1 < (int)ft_strlen(map[j - 1]))
			cub_perror(inv_wall, g, NULL, map[j - 1][i + 1] == '0');
		if (i >= 0 && i < (int)ft_strlen(map[j - 1]))
			cub_perror(inv_wall, g, NULL, map[j - 1][i] == '0');
	}
	if (i - 1 >= 0 && i - 1 < (int)ft_strlen(map[j]))
		cub_perror(inv_wall, g, NULL, map[j][i - 1] == '0');
	if (i + 1 >= 0 && i + 1 < (int)ft_strlen(map[j]))
		cub_perror(inv_wall, g, NULL, map[j][i + 1] == '0');
	if (j + 1 >= 0 && j + 1 < g->height)
	{
		if (i - 1 >= 0 && i - 1 < (int)ft_strlen(map[j + 1]))
			cub_perror(inv_wall, g, NULL, map[j + 1][i - 1] == '0');
		if (i + 1 >= 0 && i + 1 < (int)ft_strlen(map[j + 1]))
			cub_perror(inv_wall, g, NULL, map[j + 1][i + 1] == '0');
		if (i >= 0 && i < (int)ft_strlen(map[j + 1]))
			cub_perror(inv_wall, g, NULL, map[j + 1][i] == '0');
	}
}

void	check_characters(t_game *g, char **map, int i, int j)
{
	if (!g->pl.dir && ft_strchr("NSWE", map[j][i]))
	{
		g->pl.dir = map[j][i];
		g->pl.x = (float)i;
		g->pl.y = (float)j;
	}
	else if (g->pl.dir && ft_strchr("NSWE", map[j][i]))
		cub_perror(inv_player, g, NULL, 1);
	else if (!ft_strchr("01oc", map[j][i]))
		cub_perror(inv_charac, g, NULL, 1);
	if (j == g->height - 1 && !g->pl.dir)
		cub_perror(inv_player, g, NULL, 1);
}

char	**square_map(t_game *g)
{
	char	**aux;
	int		i;
	int		j;

	aux = malloc(sizeof(char *) * (g->height + 1));
	j = -1;
	while (++j < g->height)
	{
		aux[j] = malloc(sizeof(char) * (g->width + 1));
		i = -1;
		while (++i < g->width)
		{
			if (i >= (int)ft_strlen(g->map[j]))
				aux[j][i] = ' ';
			else
				aux[j][i] = g->map[j][i];
		}
		aux[j][i] = '\0';
	}
	aux[j] = NULL;
	return (aux);
}

void	check_elements(t_game *g)
{
	int		i;
	int		j;

	j = -1;
	while (++j < g->height)
	{
		i = -1;
		while (++i < g->width)
		{
			if (g->map[j][i] == ' ')
				check_walls(g, g->map, i, j);
			else
				check_characters(g, g->map, i, j);
		}
	}
}
