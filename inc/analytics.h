/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analytics.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Bilou <Bilou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 18:21:10 by Bilou             #+#    #+#             */
/*   Updated: 2018/01/29 20:56:05 by Bilou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANALYTICS_H
# define ANALYTICS_H

int		score(t_fenv *e, int x, int y, int wall);
void	init_round(t_analytics *a);
void	first_direction(t_fenv *e, t_hmap *m, t_analytics *a);
void	update_direction(t_fenv *e, t_hmap *m, t_analytics *a);

#endif
