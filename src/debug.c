/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Bilou <Bilou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 15:12:07 by Bilou             #+#    #+#             */
/*   Updated: 2018/01/29 14:20:45 by Bilou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		print_board(char **cells, int x, int y, int fd)
{
	int		i;
	int		j;

	i = 0;
	while (i < x)
	{
		j = 0;
		while (j < y)
		{
			ft_dprintf(fd, "{yellow}%c{eoc}", cells[i][j]);
			j++;
		}
		i++;
		ft_dprintf(fd, "\n");
	}
}

void			print_heatmap(t_hmap *hmap, int print, int fd)
{
	ft_dprintf(fd, "{red}- Board -{eoc}\n");
	if (print == 1)
		print_board(hmap->cells, hmap->size_x, hmap->size_y, fd);
	ft_dprintf(fd, "Board @: %p\n", hmap);
	ft_dprintf(fd, "Cells @: %p\n", hmap->cells);
	ft_dprintf(fd, "Size x: %d\n", hmap->size_x);
	ft_dprintf(fd, "Size y: %d\n", hmap->size_y);
	ft_dprintf(fd, "{red}---{eoc}\n");
}

void			print_piece(t_piece *piece, int print, int fd)
{
	ft_dprintf(fd, "{red}- Piece -{eoc}\n");
	if (print == 1)
		print_board(piece->cells, piece->size_x, piece->size_y, fd);
	ft_dprintf(fd, "Piece @: %p\n", piece);
	ft_dprintf(fd, "Cells @: %p\n", piece->cells);
	ft_dprintf(fd, "Size x: %d\n", piece->size_x);
	ft_dprintf(fd, "Size y: %d\n", piece->size_y);
	ft_dprintf(fd, "Offset x: %d\n", piece->offset_x);
	ft_dprintf(fd, "Offset y: %d\n", piece->offset_y);
	ft_dprintf(fd, "{red}---{eoc}\n");
}

void			print_env(t_fenv *env, int fd)
{
	ft_dprintf(fd, "{red}- Env -{eoc}\n");
	ft_dprintf(fd, "Player No: %d\n", env->player);
	ft_dprintf(fd, "Oppon. No: %d\n", env->opponent);
	ft_dprintf(fd, "Char used: %c\n", env->char_used);
	ft_dprintf(fd, "Char opp.: %c\n", env->char_opp);
	ft_dprintf(fd, "Current move score: %d\n", env->score);
	ft_dprintf(fd, "Playing ? %d\n", env->playing);
	ft_dprintf(fd, "Hmap  @: %p\n", &(env->heat_map));
	ft_dprintf(fd, "Piece @: %p\n", &(env->piece_buffer));
	ft_dprintf(fd, "{red}---{eoc}\n");
}
