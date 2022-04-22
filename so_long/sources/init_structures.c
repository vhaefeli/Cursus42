/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 19:27:56 by lgenevey          #+#    #+#             */
/*   Updated: 2022/04/22 11:30:40 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	Parce qu'il faut bien initialiser les variables avant utilisation
*/

void	window_init(t_window *window)
{
	window->win_height = 0;
	window->win_width = 0;
}

void	map_init(t_map *map)
{
	map->map = NULL;
	map->line_lenght = 0;
	map->rows_nb = 0;
	map->count_P = 0;
	map->count_E = 0;
	map->count_C = 0;
}

// void	img_init(t_img *img)
// {

// }