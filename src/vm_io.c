/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_io.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 15:25:50 by upopee            #+#    #+#             */
/*   Updated: 2018/01/26 18:38:02 by Bilou            ###   ########.fr       */
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
		hmap->cells[curr_line][i] = *buff;
		i++;
		buff++;
	}
}

static void		get_mapdata(t_hmap *hmap, t_piece *piece, char *head)
{
	char	*buff;
	int		i;

	if (hmap->size_x == UNSET && hmap->size_y == UNSET)
	{
		buff = next_word(head, ' ');
		hmap->size_x = ft_atoi(buff);
		buff = next_word(buff, ' ');
		hmap->size_y = ft_atoi(buff);
		init_heatmap(hmap, hmap->size_x, hmap->size_y);
		init_piecebuffer(piece, hmap->size_x, hmap->size_y);
	}
	get_next_line(STDIN_FILENO, &buff);
	free(buff);
	buff = NULL;
	i = 0;
	while (i < hmap->size_x)
	{
		get_next_line(STDIN_FILENO, &buff);
		get_linedata(hmap, next_word(buff, ' '), i);
		free(buff);
		buff = NULL;
		i++;
	}
}

static void		get_piecedata(t_piece *piece, char *head)
{
	char	*buff;
	int		i;
	int		j;

	ft_printf("head %p / text: %s / \n", head, head);
	buff = next_word(head, ' ');
	piece->size_x = ft_atoi(buff);
	ft_printf("%p / %d / \n", buff, piece->size_x);
	buff = next_word(buff, ' ');
	piece->size_y = ft_atoi(buff);
	ft_printf("%p / %d / \n", buff, piece->size_y);
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
		ft_printf("%s\n", piece->cells[i]);
		free(buff);
		buff = NULL;
		i++;
	}
}

void			get_vm_output(t_fenv *env)
{
	char	*buff;

	buff = NULL;
	while (get_next_line(STDIN_FILENO, &buff) > 0)
	{
		if (env->player == UNSET)
		{
			env->player = ft_strstr(buff, "p1") ? 1 : 2;
			env->opponent = env->player == 1 ? 2 : 1;
			env->char_used = env->player == 1 ? P1_CHAR : P2_CHAR;
			env->char_opp = env->player == 1 ? P2_CHAR : P1_CHAR ;
		}
		else if (ft_strstr(buff, "Plateau"))
			get_mapdata(&(env->heat_map), &(env->piece_buffer), buff);
		else if (ft_strstr(buff, "Piece"))
			get_piecedata(&(env->piece_buffer), buff);
		else
			exit(ERROR);
		free(buff);
		buff = NULL;
	}
}
