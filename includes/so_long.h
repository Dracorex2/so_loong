/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 08:03:16 by lucmansa          #+#    #+#             */
/*   Updated: 2025/03/18 21:34:30 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../srcs/utils/utils.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <sys/time.h>
# include <X11/keysym.h>

typedef struct s_player
{
	int		x;
	int		y;
	int		frame_idx;
	int		frame_p;
	int		move;
}	t_player;

typedef struct s_map
{
	char	**map;
	int		height;
	int		width;
	int		coin_count;
	int		coin_idx;
}	t_map;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	t_player		p;
	t_map			m;
	int				img_s;
	void			*p_sprite[7];
	void			*c_sprite;
	void			*f_sprite;
	void			*w_sprite;
	void			*e_sprite[2];
	unsigned int	tick;
}	t_game;

//check map
int		is_rectangle(t_game *game);
int		has_border(t_game *game);
int		has_element(t_game *game);
int		has_player(t_game *game);
char	**map_cpy(t_game *game);
int		flood_fill(char **map, int y, int x);
int		map_checker(t_game *game);

//mlx
void	draw_player(int x, int y, t_game *game);
void	draw_obj(int x, int y, t_game *game);
int		do_draw(t_game *game);
int		count_frame(t_game *game);

//free
void	free_map(char **map);
void	free_img(t_game *game);
int		destroy(t_game *game);

//init
void	try_init(t_game *game, void **dest, char *path);
int		init_img(t_game *game);

void	mlx_i(t_game *game);
int		key_press(int key, t_game *game);

void	move_player(t_game *game, int x, int y);

//files
int		fline_count(char *file);
void	fline_read(t_game *game, char *file);

void	move_enemies(t_game *game);

#endif