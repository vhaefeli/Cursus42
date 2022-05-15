/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:45:17 by lgenevey          #+#    #+#             */
/*   Updated: 2022/05/15 14:06:46 by nakawashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	Creates a new image in memory.
	Returns the id of the img we want to manipulate
	void *img is the image initialized in init_img (init_game.c)
	x and y define where the img should be placed in the window
*/
void	img_draw(t_game *game, void *img, int img_pos_x, int img_pos_y)
{
	mlx_put_image_to_window
		(game->mlx_id, game->win_id, img,
			img_pos_x * IMG_SIZE, img_pos_y * IMG_SIZE);
}

static void	draw_and_init_e(t_game *game, int i, int j)
{
	img_draw(game, game->img_ground, j, i);
	game->exit_index_i = i;
	game->exit_index_j = j;
}

/*
	Extract index of P (gonna be the start position)
*/
static void	draw_and_init_p(t_game *game, int j, int i)
{
	img_draw(game, game->img_player_s, j, i);
	game->player.index_i = i;
	game->player.index_j = j;
	game->player.nb_movements = 0;
}

/*
	Run through the map and
	display *img according to the char in the map (01PEC)
	display exit only if we get all collectibles
*/
void	map_init(t_game *game)
{
	int		i;
	int		j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == WALL)
				img_draw(game, game->img_wall, j, i);
			else if (game->map[i][j] == COLLECTIBLE)
				img_draw(game, game->img_collectible, j, i);
			else if (game->map[i][j] == EXIT)
				draw_and_init_e(game, i, j);
			else if (game->map[i][j] == PLAYER)
				draw_and_init_p(game, j, i);
			else
				img_draw(game, game->img_ground, j, i);
		}
	}
}
