/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Bilou <Bilou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 15:49:22 by Bilou             #+#    #+#             */
/*   Updated: 2018/01/26 16:09:38 by Bilou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#define EMPTY_CELL '.'

typedef struct	s_piece
{
	char		cells[4][4];
	int			size_x;
	int			size_y;
	int			offset_x;
	int			offset_y;
}				t_piece;

static void		get_offset(t_piece *p)
{
	int		i;

	while (p->offset_x < p->size_x)
	{
		i = 0;
		while (i < p->size_y && p->cells[p->offset_x][i] == EMPTY_CELL)
			i++;
		if (i == p->size_y)
			p->offset_x++;
		else
			break ;
	}
	while (p->offset_y < p->size_y)
	{
		i = 0;
		while (i < p->size_x && p->cells[i][p->offset_y] == EMPTY_CELL)
			i++;
		if (i == p->size_x)
			p->offset_y++;
		else
			break ;
	}
	printf("Off X : %d // Off Y : %d \n", p->offset_x, p->offset_y);
}

void	print_piece(t_piece p)
{
	int		i;
	int		j;

	i = 0;
	while (i < p.size_x)
	{
		j = 0;
		while (j < p.size_y)
		{
			printf("%c", p.cells[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int		main(void)
{
	t_piece p;

	p.cells[0][0] = '.';
	p.cells[0][1] = '.';
	p.cells[0][2] = '.';
	p.cells[0][3] = '.';
	p.cells[1][0] = '.';
	p.cells[1][1] = '.';
	p.cells[1][2] = '.';
	p.cells[1][3] = '.';
	p.cells[2][0] = '.';
	p.cells[2][1] = '.';
	p.cells[2][2] = '.';
	p.cells[2][3] = '*';
	p.cells[3][0] = '.';
	p.cells[3][1] = '.';
	p.cells[3][2] = '*';
	p.cells[3][3] = '*';
	p.size_x = 4;
	p.size_y = 4;
	p.offset_x = 0;
	p.offset_y = 0;
	print_piece(p);
	get_offset(&p);
	return 0;
}
