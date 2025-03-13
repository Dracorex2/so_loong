/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:37:19 by lucmansa          #+#    #+#             */
/*   Updated: 2025/03/13 20:01:58 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
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
	while (++y < game->m.height)
		free(game->m.map[y]);
	free(game->m.map);
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
	while (++y < game->m.height)
		game->m.map[y] = get_next_line(fd);
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
	t_game game;

	if (argc != 2)
		return (1);
	game.m.height = fline_count(argv[1]);
	game.m.map = calloc(game.m.height, sizeof(char *));
	fline_read(&game, argv[1]);
	prnt_map(&game);
	if (!map_checker(&game))
		return (write(2, "Map Error", 9), 1);
	mlx(&game);
	mlx_loop_hook(game.mlx, &do_draw, &game);
	mlx_loop(game.mlx);
}