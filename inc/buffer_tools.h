/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_tools.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 15:19:00 by upopee            #+#    #+#             */
/*   Updated: 2018/01/26 18:29:39 by Bilou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_TOOLS_H
# define BUFFER_TOOLS_H

int		init_heatmap(t_hmap *map, int x, int y);
int		init_piecebuffer(t_piece *p, int xmax, int ymax);
void	clean_buffer(char **buffer, int x, int y);
int		delete_doublearray(char **cells, int nb_lines);

#endif
