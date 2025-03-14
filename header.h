/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:21:39 by lucmansa          #+#    #+#             */
/*   Updated: 2025/03/14 19:27:45 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "./mlx/mlx.h"
# include "./utils/utils.h"
# include "./gnl/get_next_line.h"
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
	void			*mlx;
	void			*win;
	t_player		p;
	t_map			m;
	int				img_s;
	void			*p_sprite[7];
	void			*c_sprite[5];
	void			*f_sprite;
	void			*w_sprite;
	void			*e_sprite[2];
	unsigned int	tick;
} t_game;

//main
void	free_map(char **map);

//check map
int	is_rectangle(t_game *game);
int	has_border(t_game *game);
int	has_element(t_game *game);
char **map_cpy(t_game *game);
int	flood_fill(char **map, int y, int x);
int	map_checker(t_game *game);


//mlx
void	mlx(t_game *game);
int    do_draw(t_game *game);
void    draw_obj(int x, int y, t_game *game);
int	count_frame(t_game *game);
int	destroy(t_game *game);
int	key_press(int key, t_game *game);

#endif