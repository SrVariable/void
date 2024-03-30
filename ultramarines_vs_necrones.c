/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ultramarines_vs_necrones.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 22:24:09 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/03/30 02:22:10 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#define SOLDIER_AMOUNT 5
#define NAME_LENGTH 40
#define HEALTH_POINTS 100
#define ATTACK_DAMAGE 20
#define ULTRAMARINE_AMPLIFIER 25
#define NECRONE_AMPLIFIER 5

#include "BFL.h"
#include <time.h>
#include <stdlib.h>

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

void	generate_name(char *final_name, t_class class, int random_number)
{
	static const char	*name[] = {"Lorem", "Ipsum", "Dolor", "Sit", "Amet",
		"Consectetur", "Adipiscing", "Elit", "Sed", "Do", "Eiusmod", "Tempor",
		"Incididunt", "Ut", "Labore", "Et", "Dolore", "Magna", "Aliqua", "Enim",
		"Ad", "Minim", "Veniam", "Quis", "Nostrud", "Exercitation", "Ullamco",
		"Laboris", "Nisi", "Aliquip", "Ex", "Ea", "Commodo", "Consequat",
		"Duis", "Aute", "Irure", "In", "Reprehenderit", "Voluptate", "Velit",
		"Esse", "Cillum", "Eu", "Fugiat", "Nulla", "Pariatur", "Excepteur",
		"Sint", "Occaecat", "Cupidadat", "Non", "Proident", "Sunt", "Culpa",
		"Qui", "Officia", "Deserunt", "Mollit", "Anim", "Id", "Est", "Laborum",
		"Yow", "Thresh", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday",
		"Saturday", "Sunday"
	};
	static const char	*class_name[] = {"[Ultramarine] ", "[Necrone] "};
	size_t				length;
	size_t				length2;

	length = ft_strlen(class_name[class]);
	length2 = ft_strlen(name[random_number % (sizeof(name) / sizeof(name[0]))]);
	ft_memcpy(final_name, class_name[class], length);
	ft_memcpy(final_name + length,
		name[random_number % (sizeof(name) / sizeof(name[0]))], length);
	final_name[length + length2] = '\0';
}

void	initialise_info(t_army *army, t_class class)
{
	int	i;

	army->soldiers_left = SOLDIER_AMOUNT;
	army->total_damage = 0;
	i = -1;
	while (++i < SOLDIER_AMOUNT)
	{
		generate_name(army->soldier[i].name, class, rand());
		army->soldier[i].health_points = rand() % HEALTH_POINTS + 1
			+ ((class == ULTRAMARINE) * ULTRAMARINE_AMPLIFIER);
		army->soldier[i].attack_damage = rand() % ATTACK_DAMAGE + 1
			+ ((class == NECRONE) * NECRONE_AMPLIFIER);
	}
}

void	announce_winner(t_army *ultramarine, t_army *necrone)
{
	ft_printf("\n");
	if (!ultramarine->soldiers_left && !ultramarine->soldiers_left)
	{
		if (ultramarine->total_damage > necrone->total_damage)
			ft_printf("Ultramarine wins!\n");
		else
			ft_printf("Necrone wins!\n");
	}
	else if (!ultramarine->soldiers_left)
		ft_printf("Necrone wins!\n");
	else
		ft_printf("Ultramarine wins!\n");
}

void	show_results(t_army *ultramarine, t_army *necrone)
{
	ft_printf("\n\n\t\tUltramarine\t|\tNecrone\n");
	ft_printf("Total damage\t%d\t\t|\t%d\n",
		ultramarine->total_damage, necrone->total_damage);
	ft_printf("Soldiers left\t%d\t\t|\t%d\n",
		ultramarine->soldiers_left, necrone->soldiers_left);
}

void	show_soldier_status(t_soldier *soldier)
{
	ft_printf("%s %dHP %dAD ",
		soldier->name, soldier->health_points, soldier->attack_damage);
}

void	attack(t_army *ultramarine, t_army *necrone, size_t i, size_t j)
{
	show_soldier_status(&ultramarine->soldier[i]);
	ft_printf("vs ");
	show_soldier_status(&necrone->soldier[j]);
	ft_printf("\n");
	ultramarine->soldier[i].health_points -= necrone->soldier[j].attack_damage;
	necrone->soldier[j].health_points -= ultramarine->soldier[i].attack_damage;
	ultramarine->total_damage += ultramarine->soldier[i].attack_damage;
	necrone->total_damage += necrone->soldier[j].attack_damage;
}

t_bool	limit(size_t j)
{
	return (j < SOLDIER_AMOUNT);
}

void	fight(t_army *ultramarine, t_army *necrone)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (ultramarine->soldiers_left && necrone->soldiers_left)
	{
		while (ultramarine->soldier[i].health_points <= 0 && i < SOLDIER_AMOUNT)
			++i;
		while (necrone->soldier[j].health_points <= 0 && j < SOLDIER_AMOUNT)
			++j;
		attack(ultramarine, necrone, i, j);
		if (ultramarine->soldier[i].health_points <= 0)
		{
			i = (i + 1) * (i < SOLDIER_AMOUNT);
			--ultramarine->soldiers_left;
		}
		if (necrone->soldier[j].health_points <= 0)
		{
			j = (j + 1) * (j < SOLDIER_AMOUNT);
			--necrone->soldiers_left;
		}
	}
	show_results(ultramarine, necrone);
	announce_winner(ultramarine, necrone);
}

int	main(void)
{
	t_army	ultramarine;
	t_army	necrone;

	srand(time(NULL));
	initialise_info(&ultramarine, ULTRAMARINE);
	initialise_info(&necrone, NECRONE);
	fight(&ultramarine, &necrone);
	return (0);
}
