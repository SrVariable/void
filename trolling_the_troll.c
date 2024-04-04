/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trolling_the_troll.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 20:57:45 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/04/04 14:18:04 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

// Inclusión de librerías
#include "BFL.h" // Como libft, pero con más funciones

/**
 * @brief Reemplaza las vocales del string dado
 *
 * @param str El string que va a ser modificado
 * @param new_char El carácter que va a reemplazar las vocales
 *
 * @return - str Si se modifican las vocales correctamente
 * @return - NULL si el string es NULL
 */
char	*replace_vowels(char *str, char new_char)
{
	int	i; // Contador para iterar sobre el string

	i = -1; // Inicializo el contador
	if (!str) // Si no hay string
		return (NULL); // Devuelvo NULL
	while (str[++i]) // Mientras existan caracteres (es lo mismo que str[++i] != '\0')
		if (ft_strchr("aeiouAEIOU", str[i])) // Si el carácter actual es una vocal
			str[i] = new_char; // Reemplazo el carácter actual por el nuevo carácter
	return (str); // Devuelvo el string modificado
}

/**
 * @brief Reemplaza las vocales del string dado si coincide con alguna palabra
 * del diccionario
 *
 * @param str El string que va a ser modificado
 * @param new_char El carácter que va a reemplazar las vocales
 *
 * @return - str Si se modifican las vocales correctamente
 * @return - NULL si el string es NULL
 */
char	*replace_vowels_bonus(char *str, char new_char, char **dict)
{
	int	i; // Contador para iterar sobre el string
	int	j; // Contador para iterar sobre el diccionario

	if (!dict || !str) // Si el diccionario o el string son NULL
		return (NULL); // Devuelvo NULL
	i = -1; // Inicializo el contador para recorrer el string
	while (str[++i]) // Mientras existan caracteres
	{
		j = -1; // Inicializo el contador para recorrer el diccionario
		while (dict[++j]) // Mientras existan palabras en el diccionario
		{
			if (ft_strncmp(&str[i], dict[j], ft_strlen(dict[j])) == 0) // Compruebo si el string en la posición i es una palabra del diccionario
			{
				while (str[i + 1] && str[i] != ' ') // Mientras esté en la palabra
				{
					if (ft_strchr("aeiouAEIOU", str[i])) // Compruebo si la posición i del string es una vocal
						str[i] = new_char; // Reemplazo la vocal por el nuevo carácter
					++i; // Incremento el string para iterar sobre toda la palabra
				}
			}
		}
	}
	return (str); // Devuelvo el string modificado
}

/**
 * @brief Función principal para probar el programa
 *
 * @param argc Número de argumentos
 * @param argv Argumentos del programa
 *
 * @return - 1 Si el número de argumentos no es ni 2 ni 3
 * @return - 0 Si se modifica el string correctamente
 */
int	main(int argc, char **argv)
{
	char	*dup; // Duplicado del string
	char	**dict; // Diccionario

	if (argc != 2 && argc != 3) // Si no hay o 2 o 3 argumentos
		return (1); // Devuelvo 1
	else if (argc == 2) // Si hay 2 argumentos
	{
		dup = ft_strdup(argv[1]); // Creo un duplicado de argv[1] para poder modificarlo
		ft_printf("%s\n", replace_vowels(dup, 'i')); // Imprimo el resultado de modificar el string
	}
	else if (argc == 3)
	{
		dup = ft_strdup(argv[1]); // Creo un duplicado de argv[1] para poder modificarlo
		dict = ft_split(argv[2], ' '); // Hago un split de argv[2] que contiene las palabras del diccionario
		ft_printf("%s\n", replace_vowels_bonus(dup, 'i', dict)); // Imprimo el resultado de modificar el string dependiendo del diccionario
	}
	ft_free(&dup, 1); // Libero dup para que no haya leaks
	ft_free(&dict, 2); // Libero dict para que no haya leaks
	return (0); // Devuelvo 0 y termina el programa
}
