/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:37:19 by lucmansa          #+#    #+#             */
/*   Updated: 2025/03/12 19:34:38 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx/mlx.h"
#include "header.h"
#include <string.h>
//int	main(void)
//{
//	void	*mlx;
//	void	*mlx_win;
//
//	mlx = mlx_init();
//	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
//	mlx_loop(mlx);
//	(void)mlx_win;
//}

void	free_map(t_game *game)
{
	int	y;

	y = -1;
	while (++y < game->nbline)
		free(game->map[y]);
	free(game->map);
}

int	fline_count(char *file)
{
	int		fd;
	char	*line;
	int		nb;
	
	fd = open(file, O_RDONLY);
	nb = 0;
	line = NULL;
	while ((line = get_next_line(fd)))
		(free(line), nb++);
	close(fd);
	printf("%i\n", nb);
	return (nb);
}
void	fline_read(t_game *game, char *file)
{
	int	y;
	int	fd;

	fd = open(file, O_RDONLY);
	y = 0;
	game->map[y] = get_next_line(fd);
	while (++y < game->nbline)
		game->map[y] = get_next_line(fd);
	close(fd);
}

void	prnt_map(t_game game)
{
	int	y;

	y = -1;
	while (++y < game.nbline)
		printf("%s\n", game.map[y]);
}

int	main(int argc, char **argv)
{
	t_game game;

	(void)argc;
	game.nbline = fline_count(argv[1]);
	game.map = calloc(game.nbline, sizeof(char *));
	fline_read(&game, argv[1]);
	prnt_map(game);
}