/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:14:27 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/05/13 09:31:41 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "cli.h"

void	command_help(void)
{
	display_message("Estos son los comandos disponibles:\n"\
"\thelp - Muestra información sobre los comandos\n"\
"\tchallenge - Muestra el enunciado del reto\n"\
"\tsubmit - Entrega el reto y ejecuta los tests\n"\
"\thint - Muestra una pista para el reto actual\n"\
"\texit - Salir de la CLI\n");
}

void	command_exit(void)
{
	display_message("Bye bye\n");
	exit(0);
}

void	command_submit(int *challenge)
{
	switch (*challenge)
	{
		case BOB_IS_A_LAZY_MAN:
			if (system("cc ../bob_is_a_lazy_man/bob_is_a_lazy_man.c \
./test/test_bob_is_a_lazy_man.c -I../lib/BFL/include -I../bob_is_a_lazy_man \
../lib/BFL/libBFL.a") != 0)
				return ;
			if (system("./a.out") != 0)
				return ;
			remove("./a.out");
			break ;
		case TROLLING_THE_TROLL:
			if (system("cc ../trolling_the_troll/trolling_the_troll.c \
./test/test_trolling_the_troll.c -I../lib/BFL/include -I../trolling_the_troll \
../lib/BFL/libBFL.a") != 0)
				return ;
			if (system("./a.out") != 0)
				return ;
			remove("./a.out");
			break ;
		case ULTRAMARINES_VS_NECRONES:
			if (system("cc ../ultramarines_vs_necrones/ultramarines_vs_necrones.c \
./test/test_ultramarines_vs_necrones.c -D SOLDIER_AMOUNT=1 -I../lib/BFL/include \
-I../ultramarines_vs_necrones ../lib/BFL/libBFL.a") != 0)
				return ;
			if (system("./a.out") != 0)
				return ;
			remove("./a.out");
			break ;
		default:
			break ;
	}
	++(*challenge);
	return ;
}

void	command_hint(int challenge)
{
	static const char	*hint[CHALLENGE_AMOUNT][HINT_LIMIT] = { {},
		// Bob is a lazy man
		{ "Iterar sobre el string puede ser un buen comienzo\n",
			"Tener un contador podría ayudar\n",
			"¿Estás contando minúsculas, mayúsculas y números?\n",
			"Prueba a escribir \"man isalnum\"\n"
		},
		// Trolling the troll
		{ "Iterar sobre el string puede ser buen comienzo\n",
			"Tener un contador podría ayudar\n",
			"¿Estás modificando solamente las mayúsculas y minúsculas?\n",
			"Prueba a escribir \"man strchr\"\n",
			"¿Sabías que if(NULL) es lo mismo que if(0) y que a su vez es lo mismo que if(false)?\n"
		},
		// Ultramarines vs Necrones
		{ "Para acceder a un elemento de la estructura puedes usar -> si la estructura es un puntero\n"\
"o utilizar . si no lo es. Por ejemplo: ultramarine->soldiers_left, ultramarine->soldier[0].name\n",
			"¿Y si restamos los puntos de vida de un soldado dependiendo del daño del otro soldado?\n",
			"Recuerda devolver el ganador (ULTRAMARINE/NECRONE)\n",
		},
	};
	static int counter[CHALLENGE_AMOUNT];

	if (counter[challenge] == HINT_LIMIT || !hint[challenge][counter[challenge]])
	{
		display_message_with_delay("Ya no hay más pistas :c\n");
		return ;
	}
	switch (challenge)
	{
		case BOB_IS_A_LAZY_MAN:
			display_message(hint[challenge][counter[challenge]]);
			break ;
		case TROLLING_THE_TROLL:
			display_message(hint[challenge][counter[challenge]]);
			break ;
		case ULTRAMARINES_VS_NECRONES:
			display_message(hint[challenge][counter[challenge]]);
			break ;
	}
	++counter[challenge];
}

void	command_man(const char *str)
{
	if (!str)
		handle_error(INVALID_STRING);
	if (strncmp(str, "isalnum", 7) == 0)
		display_message("#include <ctype.h>\n\n"\
"int isalnum(int c)\n\n"\
"Función que te dice si un carácter es alfanumérico o no\n\n"\
"- c es el carácter\n\n"\
"- Devuelve 1 si es alfanumérico\n"\
"- Devuelve 0 si no es alfanumérico\n");
	else if (strncmp(str, "strchr", 6) == 0)
		display_message("#include <string.h>\n\n"\
"char *strchr(const char *s, int c)\n\n"\
"Función que te dice si un carácter está dentro de un string o no\n\n"\
"- s es el string\n"\
"- c es el carácter\n\n"\
"- Devuelve un puntero a la posición de la primera ocurrencia del carácter\n"\
"- Devuelve NULL si no encuentra el carácter\n");
	else
		display_message_with_delay("A saber qué funciones tiene este manual...\n");
}
