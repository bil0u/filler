/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_io.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 15:25:50 by upopee            #+#    #+#             */
/*   Updated: 2018/02/01 13:07:23 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "filler.h"
#include "buffer_tools.h"

static char		*next_word(char *str, char separator)
{
	while (*str && *str != separator)
		str++;
	while (*str && *str == separator)
		str++;
	return (str);
}

static void		get_linedata(t_hmap *hmap, char *buff, int curr_line)
{
	int		i;

	i = 0;
	while (i < hmap->size_y)
	{
		hmap->cells[curr_line][i] = buff[i];
		i++;
	}
}

void			get_player_data(t_fenv *env)
{
	char	*buff;

	buff = NULL;
	get_next_line(STDIN_FILENO, &buff);
	env->player = ft_strstr(buff, "p1") ? 1 : 2;
	env->opponent = env->player == 1 ? 2 : 1;
	env->char_used = env->player == 1 ? P1_CHAR : P2_CHAR;
	env->char_opp = env->player == 1 ? P2_CHAR : P1_CHAR;
	ft_strdel(&buff);
}

void			get_mapdata(t_hmap *hmap, t_piece *piece)
{
	char	*buff;
	char	*tmp;
	int		i;

	buff = NULL;
	get_next_line(STDIN_FILENO, &buff);
	if (hmap->size_x == UNSET && hmap->size_y == UNSET)
	{
		tmp = next_word(buff, ' ');
		hmap->size_x = ft_atoi(tmp);
		tmp = next_word(tmp, ' ');
		hmap->size_y = ft_atoi(tmp);
		init_heatmap(hmap, hmap->size_x, hmap->size_y);
		init_piecebuffer(piece, hmap->size_x, hmap->size_y);
	}
	ft_strdel(&buff);
	get_next_line(STDIN_FILENO, &buff);
	ft_strdel(&buff);
	i = 0;
	while (i++ < hmap->size_x)
	{
		get_next_line(STDIN_FILENO, &buff);
		get_linedata(hmap, next_word(buff, ' '), i - 1);
		ft_strdel(&buff);
	}
}

void			get_piecedata(t_piece *piece)
{
	char	*buff;
	char	*tmp;
	int		i;
	int		j;

	buff = NULL;
	get_next_line(STDIN_FILENO, &buff);
	tmp = next_word(buff, ' ');
	piece->size_x = ft_atoi(tmp);
	tmp = next_word(tmp, ' ');
	piece->size_y = ft_atoi(tmp);
	ft_strdel(&buff);
	i = 0;
	while (i < piece->size_x)
	{
		get_next_line(STDIN_FILENO, &buff);
		j = 0;
		while (j < piece->size_y)
		{
			piece->cells[i][j] = buff[j];
			j++;
		}
		ft_strdel(&buff);
		i++;
	}
}
