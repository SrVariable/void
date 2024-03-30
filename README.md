# void

## Descripción

Soluciones a los diferentes retos propuestos en la coalición Void de 42 Málaga.

## Requisitos

- cc
- git
- make

## Dependencias

- [BFL](https://github.com/SrVariable/BFL/)

## Retos

### Bob is a lazy man

- **Dificultad**:  Fácil

- **Descripción**: El único trabajo de Bob es contar cuántas letras y números
existen en una cadena de texto. Como es perezoso, necesita que le creemos un
método que le permita automatizar su trabajo y echar alguna que otra cabezada.

- **Ejemplo**: 

```
Input: "hel2!lo"
Output: 6
```

```
Input: "wicked .. !"
Output: 6
```

```
Input: "!?..A"
Output: 1
```

```
Input: ""
Output: 0
```

```
Input: "@ !."
Output: 0
```

Para probarlo
```shell
make first
```

### Trolling the troll

- **Dificultad**: Fácil

- **Descripción**: Escribir una función que tome una cadena y devolver una nueva
cadena con todas las vocales cambiadas por una única vocal.

- **Ejemplo**

```
Input: "Este sitio web es para perdedores"
Output: "isti sitii wib is piri pirdidiris"
```

- **Bonus**: La función solo actúa cuando se detecta una palabra dentro de un
diccionario de palabras prohibidas.

- **Ejemplo**:

```
Palabras prohibidas: ["idiota", "perdedores", "caca", "culo", "pis"]

Input: "Este sitio web es para perdedores"
Output: "Este sitio web es para pirdidiris"
```

```
Palabras prohibidas: ["idiota", "perdedores", "caca", "culo", "pis"]

Input: "Este sitio web es impresionante"
Output: "Este sitio web es impresionante"
```

Para probarlo
```shell
make second
```

### Ultramarines contra Necrones 

- **Dificultad**: Difícil

- **Descripción**: Desarrolla un programa que simule batallas entre
Ultramarines y Necrones. Cada combatiente, tiene un nombre, unos puntos de
vida y unos puntos de ataque. El programa debe permitir enfrentar a dos
ejércitos entre sí y determinar cuál es el ganador.

- **Ejemplo**

```
[Ultramarine] Irure 28HP 13AD vs [Necrone] Ea 30HP 21AD 
[Ultramarine] Irure 7HP 13AD vs [Necrone] Ea 17HP 21AD 
[Ultramarine] Ex 37HP 15AD vs [Necrone] Ea 4HP 21AD 
[Ultramarine] Ex 16HP 15AD vs [Necrone] Ipsum 35HP 10AD 
[Ultramarine] Ex 6HP 15AD vs [Necrone] Ipsum 20HP 10AD 
[Ultramarine] Thursday 85HP 1AD vs [Necrone] Ipsum 5HP 10AD 
[Ultramarine] Thursday 75HP 1AD vs [Necrone] Ipsum 4HP 10AD 
[Ultramarine] Thursday 65HP 1AD vs [Necrone] Ipsum 3HP 10AD 
[Ultramarine] Thursday 55HP 1AD vs [Necrone] Ipsum 2HP 10AD 
[Ultramarine] Thursday 45HP 1AD vs [Necrone] Ipsum 1HP 10AD 
[Ultramarine] Thursday 35HP 1AD vs [Necrone] Sunday 95HP 16AD 
[Ultramarine] Thursday 19HP 1AD vs [Necrone] Sunday 94HP 16AD 
[Ultramarine] Thursday 3HP 1AD vs [Necrone] Sunday 93HP 16AD 
[Ultramarine] Voluptate 50HP 5AD vs [Necrone] Sunday 92HP 16AD 
[Ultramarine] Voluptate 34HP 5AD vs [Necrone] Sunday 87HP 16AD 
[Ultramarine] Voluptate 18HP 5AD vs [Necrone] Sunday 82HP 16AD 
[Ultramarine] Voluptate 2HP 5AD vs [Necrone] Sunday 77HP 16AD 
[Ultramarine] Ullamco 63HP 9AD vs [Necrone] Sunday 72HP 16AD 
[Ultramarine] Ullamco 47HP 9AD vs [Necrone] Sunday 63HP 16AD 
[Ultramarine] Ullamco 31HP 9AD vs [Necrone] Sunday 54HP 16AD 
[Ultramarine] Ullamco 15HP 9AD vs [Necrone] Sunday 45HP 16AD 


		Ultramarine	|	Necrone
Total damage	135		|	309
Soldiers left	0		|	3

Necrone wins!
```

Para probarlo
```shell
make fourth
```

## Contribuidores

- sejimene https://github.com/RybenShot
- ribana-b https://github.com/SrVariable

Si has contribuido y no apareces en la lista, por favor házmelo saber.
