/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 11:13:57 by upopee            #+#    #+#             */
/*   Updated: 2018/01/15 17:36:35 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"

# define SUCCESS 0
# define FAILURE 1

typedef struct	s_fenv
{
	char		**hmap;
	int			size_x;
	int			size_y;
}				t_fenv;

#endif
