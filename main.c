/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:37:19 by lucmansa          #+#    #+#             */
/*   Updated: 2025/03/17 19:11:57 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	free_map(char **map)
{
	int	y;

	y = -1;
	while (map[++y])
		free(map[y]);
	free(map);
}

int	fline_count(char *file)
{
	int		fd;
	char	*line;
	int		nb;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (fd);
	nb = 0;
	line = NULL;
	line = get_next_line(fd);
	while (line)
	{
		(free(line), nb++);
		line = get_next_line(fd);
	}
	close(fd);
	return (nb);
}

void	fline_read(t_game *game, char *file)
{
	int	y;
	int	fd;

	fd = open(file, O_RDONLY);
	y = 0;
	game->m.map[y] = get_next_line(fd);
	game->m.width = ft_strlen(game->m.map[y]);
	if (game->m.width == 0)
		return ;
	while (++y < game->m.height)
		game->m.map[y] = get_next_line(fd);
	game->m.map[y] = NULL;
	free(get_next_line(fd));
	close(fd);
}

void	prnt_map(t_game *game)
{
	int	y;

	y = -1;
	while (++y < game->m.height)
		printf("%s\n", game->m.map[y]);
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
	//prnt_map(&game);
	if (!map_checker(&game))
		return (write(2, "Map Error\n", 10), free_map(game.m.map), 1);
	mlx_i(&game);
	mlx_loop(game.mlx);
}
