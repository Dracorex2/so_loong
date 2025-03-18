/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:37:19 by lucmansa          #+#    #+#             */
/*   Updated: 2025/03/18 22:05:22 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game			game;
	struct timeval	t;

	gettimeofday(&t, NULL);
	srand(t.tv_sec + t.tv_usec);
	if (argc != 2)
		return (1);
	game = (t_game){0};
	game.m.height = fline_count(argv[1]);
	if (game.m.height == -1)
		return (write(2, "Wrong file name\n", 16), 1);
	game.m.map = ft_calloc((game.m.height + 1), sizeof(char *));
	fline_read(&game, argv[1]);
	if (!map_checker(&game))
		return (write(2, "Map Error\n", 10), free_map(game.m.map), 1);
	mlx_i(&game);
	mlx_loop(game.mlx);
}
