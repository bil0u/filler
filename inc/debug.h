/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Bilou <Bilou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 15:13:09 by Bilou             #+#    #+#             */
/*   Updated: 2018/01/27 17:12:20 by Bilou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

void	print_heatmap(t_hmap *hmap, int print, int fd);
void	print_piece(t_piece *piece, int print, int fd);
void	print_env(t_fenv *env, int fd);

#endif
