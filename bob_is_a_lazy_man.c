/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bob_is_a_lazy_man.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 20:02:28 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/04/04 14:18:15 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

// Inclusión de librerías
#include "BFL.h" // Es como libft, pero con más funciones

/**
 * @brief Cuenta la cantidad de alfanuméricos (a-z, A-Z, 0-9)
 *
 * @param str El string del que se van a contar los alfanuméricos
 *
 * @return El número de alfanuméricos que tiene str
 */
size_t	count_alphanumerics(const char *str)
{
	size_t	counter; // Contador de alfanuméricos
	int		i; // Índice para iterar sobre el array

	if (!str) // Si el string es NULL
		return (0); // Devuelvo 0
	counter = 0;
	i = -1;
	while (str[++i]) // Itero sobre el string mientras str[i] no sea '\0'
		if (ft_isalnum(str[i])) // Compruebo si el carácter es alfanumérico
			++counter; // Aumento el contador si la condición es true
	return (counter); // Devuelvo el contador
}

/**
 * @brief Función principal para probar el programa
 *
 * @param argc Número de argumentos
 * @param argv Argumentos del programa
 *
 * @return 1 - Si no hay parámetros
 * @return 0 - Si se ejecuta sin problemas
 */
int	main(int argc, char **argv)
{
	int	i;

	if (argc < 2) // Si el número de argumentos es 1
		return (1); // Return 1
	i = 0;
	while (++i < argc) // Mientras la i sea menor que el número de argumentos
		ft_printf("\"%s\" -> %u\n", argv[i], count_alphanumerics(argv[i])); // Imprimo el string y el número de alfanuméricos que tiene
	return (0); // Devuelvo 0 y se termina el programa
}
