/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ultramarines_vs_necrones.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 06:15:20 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/04/16 13:58:56 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#ifndef ULTRAMARINES_VS_NECRONES_H
# define ULTRAMARINES_VS_NECRONES_H

# ifndef SOLDIER_AMOUNT
#  define SOLDIER_AMOUNT 5
# endif // SOLDIER_AMOUNT
# define NAME_LENGTH 40
# define HEALTH_POINTS 100
# define ATTACK_DAMAGE 20
# define ULTRAMARINE_AMPLIFIER 25
# define NECRONE_AMPLIFIER 5

# include "BFL.h"
# include <stdlib.h>

typedef enum e_class
{
	ULTRAMARINE = 0,
	NECRONE
}	t_class;

typedef struct s_soldier
{
	char	name[NAME_LENGTH];
	int		health_points;
	int		attack_damage;
}	t_soldier;

typedef struct s_army
{
	int			soldiers_left;
	int			total_damage;
	t_soldier	soldier[SOLDIER_AMOUNT];
}	t_army;

void	initialise_info(t_army *army, t_class class);
int		ultramarines_vs_necrones(t_army *ultramarine, t_army *necrone);

#endif // ULTRAMARINES_VS_NECRONES_H
