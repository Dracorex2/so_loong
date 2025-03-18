/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:37:19 by lucmansa          #+#    #+#             */
/*   Updated: 2025/03/18 19:54:42 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	prnt_map(t_game game)
{
	int y;

	y = -1;
	while (++y < game.m.height)
		printf("%s\n", game.m.map[y]);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (1);
	game = (t_game){0};
	game.m.height = fline_count(argv[1]);
	if (game.m.height == -1)
		return (write(2, "Wrong file name\n", 16), 1);
	game.m.map = ft_calloc((game.m.height + 1), sizeof(char *));
	fline_read(&game, argv[1]);
	prnt_map(game);
	if (!map_checker(&game))
		return (write(2, "Map Error\n", 10), free_map(game.m.map), 1);
	mlx_i(&game);
	mlx_loop(game.mlx);
}
