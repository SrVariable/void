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

## Contribuidores

- sejimene https://github.com/RybenShot
- ribana-b https://github.com/SrVariable

Si has contribuido y no apareces en la lista, por favor házmelo saber.
