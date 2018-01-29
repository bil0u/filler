/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 11:13:57 by upopee            #+#    #+#             */
/*   Updated: 2018/01/29 21:06:41 by Bilou            ###   ########.fr       */
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
# define WALL_SCORE 20

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

typedef struct	s_analytics
{
	int			playing;
	int			score;
	int			tmp_score;
	int			direction;
	int			opp_x;
	int			opp_y;
	int			player_x;
	int			player_y;
	int			x_direction;
	int			y_direction;
	int			x_best;
	int			y_best;
}				t_analytics;

typedef struct	s_fenv
{
	int			player;
	int			opponent;
	char		char_used;
	char		char_opp;
	t_hmap		heat_map;
	t_piece		piece_buffer;
	t_analytics	round;
}				t_fenv;

#endif
