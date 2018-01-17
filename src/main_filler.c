/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_filler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 11:07:54 by upopee            #+#    #+#             */
/*   Updated: 2018/01/17 19:33:42 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "buffer_tools.h"
#include "heatmap_tools.h"
#include "vm_io.h"

void	print_board(t_hmap *hmap)
{
	int		i;
	int		j;

	ft_printf("---\n");
	i = 0;
	while (i < hmap->size_x)
	{
		j = 0;
		while (j < hmap->size_y)
		{
			ft_putchar(hmap->cells[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
	ft_printf("---\n");
}

void	init_fenv(t_fenv *env)
{
	env->player = UNSET;
	env->char_used = UNSET;
	env->opponent = UNSET;
	env->char_opp = UNSET;
	env->next_x = UNSET;
	env->next_y = UNSET;
	env->heat_map.cells = NULL;
	env->heat_map.size_x = UNSET;
	env->heat_map.size_y = UNSET;
	env->piece_buffer.cells = NULL;
	env->piece_buffer.size_x = UNSET;
	env->piece_buffer.size_y = UNSET;
	env->piece_buffer.offset_x = UNSET;
	env->piece_buffer.offset_y = UNSET;
}

int		main(void)
{
	t_fenv	env;

	init_fenv(&env);
	get_vm_output(&env);
	update_heatvalues(&(env.heat_map), env.char_opp);

	print_board(&(env.heat_map));
	delete_doublearray(env.heat_map.cells, env.heat_map.size_x);
	delete_doublearray(env.piece_buffer.cells, env.heat_map.size_x);
	return (SUCCESS);
}
