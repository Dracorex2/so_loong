/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:21:39 by lucmansa          #+#    #+#             */
/*   Updated: 2025/03/13 17:51:05 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

#include "./utils/utils.h"
#include "./gnl/get_next_line.h"
# include <fcntl.h>

typedef struct s_player
{
	int		x;
	int		y;
	char	dir;
	int		frame_idx;
} t_player;

typedef struct s_map
{
	char	**map;
	int		height;
	int		width;
	int		coin_count;
	int		coin_idx;
} t_map;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_player	p;
	t_map		m;
	void		*p_sprite[5];
	void		*c_sprite[5];
} t_game;


//check map
int	is_rectangle(t_game *game);
int	has_border(t_game *game);
int	has_element(t_game *game);
char **map_cpy(t_game *game);
int	flood_fill(char **map, int y, int x);
int	map_checker(t_game *game);

#endif