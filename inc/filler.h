/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 11:13:57 by upopee            #+#    #+#             */
/*   Updated: 2018/01/17 19:27:47 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"

# define SUCCESS 0
# define FAILURE 1
# define UNSET 0
# define EMPTY_CELL '.'
# define BORDER_CELL '#'
# define HOT_CELL '%'
# define P1_CHAR 'o'
# define P2_CHAR 'x'
# define PIECE_CHAR '*'

typedef struct	s_hmap
{
	char		**cells;
	int			size_x;
	int			size_y;
}				t_hmap;

typedef struct	s_piece
{
	char		**cells;
	int			size_x;
	int			size_y;
	int			offset_x;
	int			offset_y;
}				t_piece;

typedef struct	s_fenv
{
	int			player;
	int			opponent;
	char		char_used;
	char		char_opp;
	int			next_x;
	int			next_y;
	t_hmap		heat_map;
	t_piece		piece_buffer;
}				t_fenv;

#endif
