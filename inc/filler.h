/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 11:13:57 by upopee            #+#    #+#             */
/*   Updated: 2018/01/29 14:52:55 by Bilou            ###   ########.fr       */
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
# define P1_CHAR 'O'
# define P2_CHAR 'X'
# define PIECE_CHAR '*'

# define HOT_SCORE 10
# define WALL_SCORE 50

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
	int			score;
	int			tmp_score;
	int			playing;
	t_hmap		heat_map;
	t_piece		piece_buffer;
}				t_fenv;

#endif
