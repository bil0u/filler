/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap_tools.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 15:33:57 by upopee            #+#    #+#             */
/*   Updated: 2018/01/29 18:06:04 by Bilou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEATMAP_TOOLS_H
# define HEATMAP_TOOLS_H

void	update_heatvalues(t_hmap *hmap, char opponent);
void	get_offset(t_piece *p);
int		can_fit_here(t_fenv *e, int x, int y);

#endif
