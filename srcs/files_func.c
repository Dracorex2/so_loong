/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 07:55:06 by lucmansa          #+#    #+#             */
/*   Updated: 2025/03/21 17:47:17 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*remove_newline(char *line)
{
	int	i;

	if (!line)
		return (NULL);
	i = 0;
	while (line[i])
		i++;
	if (i > 1 && line[i - 1] == '\n')
		line[i - 1] = '\0';
	return (line);
}

int	ext_check(char *file, char *ext)
{
	int	i;
	int	y;

	i = 0;
	while (file[i])
		i++;
	i -= ft_strlen(ext);
	y = 0;
	while (file[i + y])
	{
		if (file[i + y] != ext[y])
			return (0);
		y++;
	}
	return (1);
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
	game->m.map[y] = remove_newline(get_next_line(fd));
	game->m.width = ft_strlen(game->m.map[y]);
	if (game->m.width == 0)
		return (close(fd), free(get_next_line(fd)));
	while (++y < game->m.height)
		game->m.map[y] = remove_newline(get_next_line(fd));
	game->m.map[y] = NULL;
	close(fd);
	free(get_next_line(fd));
}
