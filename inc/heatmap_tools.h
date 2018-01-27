/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap_tools.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 15:33:57 by upopee            #+#    #+#             */
/*   Updated: 2018/01/26 17:31:47 by Bilou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEATMAP_TOOLS_H
# define HEATMAP_TOOLS_H

int		is_free(char **c, int x, int y);
void	update_heatvalues(t_hmap *hmap, char opponent);

#endif
