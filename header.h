/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:21:39 by lucmansa          #+#    #+#             */
/*   Updated: 2025/03/12 18:12:21 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

#include "./utils/utils.h"
#include "./gnl/get_next_line.h"
# include <fcntl.h>

typedef struct s_game
{
	char	**map;
	int		c;
	int		nbline;
} t_game;
#endif