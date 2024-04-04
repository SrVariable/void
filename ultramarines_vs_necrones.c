/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ultramarines_vs_necrones.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 22:24:09 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/04/04 15:49:29 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#define SOLDIER_AMOUNT 5 // Cantidad de soldados que tiene el ejército
#define NAME_LENGTH 40 // Longitud máxima del nombre de los soldados
#define HEALTH_POINTS 100 // Puntos de vida base de los soldados
#define ATTACK_DAMAGE 20 // Puntos de ataque base de los soldados
#define ULTRAMARINE_AMPLIFIER 25 // Amplificador de los soldados Ultramarine
#define NECRONE_AMPLIFIER 5 // Amplificador de los soldados Necrone

#include "BFL.h" // Como libft, pero con más funciones
#include <time.h> // Para poder utilizar la función time()
#include <stdlib.h> // Para poder utilizar la función rand() y srand()

/**
 * @brief Defino un tipo de dato t_class que es un enum que tiene las clases
 * existentes
 */
typedef enum e_class
{
	ULTRAMARINE = 0, // Clase Ultramarine con un valor de 0
	NECRONE // Clase Necrone con un valor de 1
}	t_class;

/**
 * @brief Defino un tipo de dato t_soldier que es una estructura que contiene
 * el nombre del soldado, sus puntos de vida y su puntos de ataque
 */
typedef struct s_soldier
{
	char	name[NAME_LENGTH]; // Nombre del soldado
	int		health_points; // Puntos de vida del soldado
	int		attack_damage; // Puntos de ataque del soldado
}	t_soldier;

/**
 * @brief Defino un tipo de dato t_army que es una estructura que contiene
 * el número de soldados restantes del ejército, el daño total realizado,
 * y los soldados
 */
typedef struct s_army
{
	int			soldiers_left; // Soldados restantes del ejército
	int			total_damage; // Daño total del ejército
	t_soldier	soldier[SOLDIER_AMOUNT]; // Soldados del ejército
}	t_army;

/**
 * @brief Genera un nombre para cada soldado
 *
 * @param final_name Donde se va a almacenar el nombre del soldado
 * @param class La clase del soldado
 * @param random_number Un número aleatorio
 */
void	generate_name(char *final_name, t_class class, int random_number)
{
	static const char	*name[] = {"Lorem", "Ipsum", "Dolor", "Sit", "Amet", // Nombres para el soldado
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
	static const char	*class_name[] = {"[Ultramarine] ", "[Necrone] "}; // Nombre de la clase del soldado
	size_t				length; // Tamaño del nombre de la clase
	size_t				length2; // Tamaño del nombre del soldado

	length = ft_strlen(class_name[class]); // Longitud de clase
	length2 = ft_strlen(name[random_number % (sizeof(name) / sizeof(name[0]))]); // Longitud de un nombre aleatorio
	ft_memcpy(final_name, class_name[class], length); // Copia el nombre de la clase al nombre del soldado
	ft_memcpy(final_name + length, // Copia el nombre aleatorio al nombre del soldado
		name[random_number % (sizeof(name) / sizeof(name[0]))], length);
	final_name[length + length2] = '\0'; // Final del string del nombre del soldado
	// En este punto el soldado ya tiene un nombre, por ejemplo:
	// [Necrone] Yow
}

/**
 * @brief Inicializa la estructura del ejército
 * 
 * @param army Estructura del ejército
 * @param class Clase del ejército
 */
void	initialise_info(t_army *army, t_class class)
{
	int	i; // Contador de soldados

	army->soldiers_left = SOLDIER_AMOUNT; // Inicializo los soldados restantes del ejército con la cantidad total de soldados
	army->total_damage = 0; // Inicializo el daño total a 0
	i = -1; // Inicializo el contador
	while (++i < SOLDIER_AMOUNT) // Mientras el contador sea menor que la cantidad total de soldados
	{
		generate_name(army->soldier[i].name, class, rand()); // Genera un nombre para el soldado
		army->soldier[i].health_points = rand() % HEALTH_POINTS + 1 // Le asigna unos puntos de vida aleatorios
			+ ((class == ULTRAMARINE) * ULTRAMARINE_AMPLIFIER); // Si la clase es Ultramarine se le aplica el amplificador, por lo que tienen más vida
		army->soldier[i].attack_damage = rand() % ATTACK_DAMAGE + 1 // Le asigna unos puntos de ataque aleatorios
			+ ((class == NECRONE) * NECRONE_AMPLIFIER); // Si la clase es Necrone se le aplica el amplificador, por lo que tienen más daño
	}
}

/**
 * @brief Mensaje que anuncia el ganador
 *
 * @param ultramarine El ejército Ultramarine
 * @param necrone El ejército Necrone
 */
void	announce_winner(t_army *ultramarine, t_army *necrone)
{
	if (!ultramarine->soldiers_left && !ultramarine->soldiers_left) // Si no quedan soldados Ultramarine ni soldados Necrone
	{
		if (ultramarine->total_damage > necrone->total_damage) // Si el daño total del ejército Ultramarine es mayor que el daño total del ejército Necrone
			ft_printf("Ultramarine wins!\n"); // Gana el ejército Ultramarine
		else // Sino
			ft_printf("Necrone wins!\n"); // Gana el ejército Necrone
	}
	else if (!ultramarine->soldiers_left) // Sino si no quedan soldados Ultramarine
		ft_printf("Necrone wins!\n"); // Gana el ejército Necrone
	else // Sino
		ft_printf("Ultramarine wins!\n"); // Gana el ejército Ultramarine
}

/**
 * @brief Mensaje que anuncia los resultados de la batalla
 *
 * @param ultramarine El ejército Ultramarine
 * @param necrone El ejército Necrone
 */
void	show_results(t_army *ultramarine, t_army *necrone)
{
	ft_printf("\n\n\t\tUltramarine\t|\tNecrone\n"); // Imprime un par de saltos de línea y tabulaciones necesarias para un espaciado entre Ultramarine y Necrone
	ft_printf("Total damage\t%d\t\t|\t%d\n", // Imprimo el daño total de cada ejército
		ultramarine->total_damage, necrone->total_damage);
	ft_printf("Soldiers left\t%d\t\t|\t%d\n\n", // Imprimo los soldados restantes de cada ejército
		ultramarine->soldiers_left, necrone->soldiers_left);
}

/**
 * @brief Muestra las estadísticas de los soldados
 *
 * @param soldier Estructura del soldado
 */
void	show_soldier_status(t_soldier *soldier)
{
	ft_printf("%s %dHP %dAD ",
		soldier->name, soldier->health_points, soldier->attack_damage);
}

/**
 * @brief Muestra el enfretamiento de los soldados y se atacan
 *
 * @param ultramarine El ejército Ultramarine
 * @param necrone El ejército Necrone
 * @param i Número del soldado Ultramarine actual
 * @param j Número del soldado Necrone actual
 */
void	attack(t_army *ultramarine, t_army *necrone, size_t i, size_t j)
{
	show_soldier_status(&ultramarine->soldier[i]); // Imprimo las estadísticas del soldado Ultramarine
	ft_printf("vs "); // Imprimo un vs
	show_soldier_status(&necrone->soldier[j]); // Imprimo las estadísticas del soldado Necrone
	ft_printf("\n"); // Imprimo un salto de línea
	ultramarine->soldier[i].health_points -= necrone->soldier[j].attack_damage; // Resto los puntos de ataque del soldado Necrone a los puntos de vida del soldado Ultramarine
	necrone->soldier[j].health_points -= ultramarine->soldier[i].attack_damage; // Resto los puntos de ataque del soldado Ultramarine a los puntos de vida del soldado Necrone
	ultramarine->total_damage += ultramarine->soldier[i].attack_damage; // Añado los puntos de daño del soldado Ultramarine a los puntos de daño totales del ejército Ultramarine
	necrone->total_damage += necrone->soldier[j].attack_damage; // Añado los puntos de daño del soldado Necrone a los puntos de daño totales del ejército Ultramarine
}

/**
 * @brief Simula la batalla entre los ejércitos Ultramarine y Necrone
 *
 * @param ultramarine El ejército Ultramarine
 * @param necrone El ejército Necrone
 */
void	fight(t_army *ultramarine, t_army *necrone)
{
	size_t	i; // Contador para identificar al soldado Ultramarine
	size_t	j; // Contador para identificar al soldado Necrone

	i = 0; // Inicializo el contador Ultramarine a 0
	j = 0; // Inicializo el contador Necrone a 0
	while (ultramarine->soldiers_left && necrone->soldiers_left) // Mientras haya soldados en ambos bandos
	{
		while (ultramarine->soldier[i].health_points <= 0 && i < SOLDIER_AMOUNT) // Mientras los puntos de vida del soldado Ultramarine i sean menores o iguales que 0 y el contador Ultramarine no sea mayor o igual la cantidad máxima de soldados
			++i; // Incremento el contador Ultramarine
		while (necrone->soldier[j].health_points <= 0 && j < SOLDIER_AMOUNT) // Mientra los puntos de vida del soldado Necrone j sean menores o iguales que 0 y el contador Necrone no sea mayor o igual la cantidad máxima de soldados
			++j; // Incremento el contador Necrone
		attack(ultramarine, necrone, i, j); // Se producen los ataques entre cada bando
		if (ultramarine->soldier[i].health_points <= 0) // Si los puntos de vida del soldado Ultramarine actual son menores o iguales que 0
		{
			i = (i + 1) * (i < SOLDIER_AMOUNT); // Incremento el contador Ultramarine o lo reinicio si el contador Ultramarine es mayor o igual que la cantidad máxima de soldados
			--ultramarine->soldiers_left; // Reduzco los soldados restantes del ejército Ultramarine
		}
		if (necrone->soldier[j].health_points <= 0) // Si los puntos de vida del soldado Necrone actual son menores o iguales que 0
		{
			j = (j + 1) * (j < SOLDIER_AMOUNT); // Incremento el contador Necrone o lo reinicio si el contador Ultramarine es mayor o igual que la cantidad máxima de soldados
			--necrone->soldiers_left; // Reduzco los soldados restantes del ejército Necrone
		}
	}
	show_results(ultramarine, necrone); // Muestro los resultados de la batalla
	announce_winner(ultramarine, necrone); // Anuncio el ganador de la batalla
}

/**
 * @brief Función principal para probar el programa
 *
 * @return - 0 Siempre devuelve 0 porque el programa no puede fallar
 */
int	main(void)
{
	t_army	ultramarine; // Estructura del ejército Ultramarine
	t_army	necrone; // Estructura del ejército Necrone

	srand(time(NULL)); // Genero una semilla random para poder simular diferentes batallas en cada ejecución del programa
	initialise_info(&ultramarine, ULTRAMARINE); // Inicializo la estructura del ejército Ultramarine
	initialise_info(&necrone, NECRONE); // Inicializo la estructura del ejército Necrone
	fight(&ultramarine, &necrone); // Comienzo de la simulación de una batalla entre el ejército Ultramarine y el ejército Necrone
	return (0);
}
