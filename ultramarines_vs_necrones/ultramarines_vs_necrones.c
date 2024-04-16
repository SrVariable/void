/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ultramarines_vs_necrones.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 22:24:09 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/04/16 06:31:51 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "ultramarines_vs_necrones.h"

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

void	select_alive_soldier(t_army *army, size_t *index)
{
	while (army->soldier[*index].health_points <= 0
			&& *index< SOLDIER_AMOUNT)
		++(*index);
}

void	move_to_the_next_soldier(t_army *army, size_t *index)
{
	*index = (*index + 1) * (*index < SOLDIER_AMOUNT);
	--army->soldiers_left;
}

void	simulate_fight(t_army *ultramarine, t_army *necrone)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (ultramarine->soldiers_left && necrone->soldiers_left)
	{
		select_alive_soldier(ultramarine, &i);
		select_alive_soldier(necrone, &j);
		attack(ultramarine, necrone, i, j);
		if (ultramarine->soldier[i].health_points <= 0)
			move_to_the_next_soldier(ultramarine, &i);
		if (necrone->soldier[j].health_points <= 0)
			move_to_the_next_soldier(necrone, &j);
	}
}

void	ultramarines_vs_necrones(t_army *ultramarine, t_army *necrone)
{
	simulate_fight(ultramarine, necrone);
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
	ultramarines_vs_necrones(&ultramarine, &necrone);
	return (0);
}
