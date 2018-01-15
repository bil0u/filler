/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_filler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 11:07:54 by upopee            #+#    #+#             */
/*   Updated: 2018/01/15 17:39:58 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		init_fenv(t_fenv *env)
{
	env->hmap = NULL;
	env->size_x = 0;
	env->size_y = 0;

	return (SUCCESS);
}

int		init_heatmap(t_fenv *env, int x, int y)
{
	int		i;

	i = 0;
	if ((env->hmap = ft_memalloc(sizeof(*(env->hmap)) * x)) == NULL)
		return (FAILURE);
	while (i < x)
	{
		if ((env->hmap[i] = ft_memalloc(sizeof(**(env->hmap)) * y)) == NULL)
			break;
		i++;
	}
	env->size_x = i;
	env->size_x = y;
	return (i == x ? SUCCESS : FAILURE);
}

int		delete_fenv(t_fenv *env)
{
	char	**curr;

	if (env->hmap)
	{
		curr = env->hmap;
		while (env->size_x--)
		{
			if (*curr)
				free(*curr);
			curr++;
		}
		free(env->hmap);
	}
	return (SUCCESS);
}

int		main(void)
{
	t_fenv	env;

	init_fenv(&env);
	init_heatmap(&env, 5, 5);
	delete_fenv(&env);

	return (SUCCESS);
}
