/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_io.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 14:43:53 by upopee            #+#    #+#             */
/*   Updated: 2018/01/29 13:20:59 by Bilou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_IO_H
# define VM_IO_H

void			get_player_data(t_fenv *env);
void			get_piecedata(t_piece *piece);
void			get_mapdata(t_hmap *hmap, t_piece *piece);

#endif
