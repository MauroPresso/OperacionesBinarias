/** @file binary_operations_functions_library.c
*  @brief Implementaciones de funciones para manipular datos a nivel de bits (de 32 y 64 bits).
*/

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "binary_operations_functions_library.h"


// SHOW_BIN

/**
* @brief Muestra la representación binaria de un valor de 32 bits.
* 
* Formatea la salida con espacios cada 4 bits y un separador adicional cada 8 bits.
* 
* @param value Valor de 32 bits a mostrar.
*/
void show_bin32(uint32_t value)
{
    uint32_t aux;
    uint32_t mask = 1; // 0000 0000 - 0000 0000 - 0000 0000 - 0000 0001
    mask = mask << 31; // 1000 0000 - 0000 0000 - 0000 0000 - 0000 0000
    for(uint8_t i = 1 ; i <= 32 ; i++)
    {
        aux = value & mask; // Extrae el bit que necesitas.
        if(aux != 0)
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
        mask = mask >> 1; // 0100 0000 - 0000 0000 - 0000 0000 - 0000 0000 // mask es un 'desplazador'
        if(i%4==0)
        {
            printf(" ");
            if(i%8==0 && i!=32)
            {
                printf("- ");
            }
        }
    }
    
}

/**
* @brief Muestra la representación binaria de un valor de 64 bits.
* 
* Formatea la salida con espacios cada 4 bits y un separador adicional cada 8 bits.
* 
* @param value Valor de 64 bits a mostrar.
*/
void show_bin64(uint64_t value)
{
    uint64_t aux;
    uint64_t mask = 1; // 0000 0000 - 0000 0000 - 0000 0000 - 0000 0001
    mask = mask << 63; // 1000 0000 - 0000 0000 - 0000 0000 - 0000 0000
    for(uint8_t i = 1 ; i <= 64 ; i++)
    {
        aux = value & mask; // Extrae el bit que necesitas.
        if(aux != 0)
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
        mask = mask >> 1; // 0100 0000 - 0000 0000 - 0000 0000 - 0000 0000 // mask es un 'desplazador'
        if(i%4==0)
        {
            printf(" ");
            if(i%8==0 && i!=64)
            {
                printf("- ");
            }
        }
    }
    
}


// SET_BIT

/**
* @brief Modifica un bit específico de un valor de 32 bits.
* 
* Establece el bit en la posición indicada como 1 o 0 dependiendo de bit_value.
* 
* @param data Valor original.
* @param bit_pos Posición del bit a modificar (0-31).
* @param bit_value Valor booleano que indica el nuevo estado del bit (true: 1, false: 0).
* @return Valor modificado con el bit ajustado.
*/
uint32_t set_bit32(uint32_t data, uint8_t bit_pos, bool bit_value)
{
    if(bit_pos > 31)
    {
        printf("\nLa posicion del bit a SETear debe valer entre 0 y 31 (ambos incluidos).\n");
        return data; // Retorna el dato sin tocarlo.
    }
    uint32_t aux;
    uint32_t mask = 1; // 0000 0000 - 0000 0000 - 0000 0000 - 0000 0001 // ~mask == 1111 1111 - 1111 1111 - 1111 1111 - 1111 1110
    mask = mask << bit_pos; // Me lleva el 1 de la variable mask hasta la posicion del bit que quiero setear.
    // bit_value es un dato booleano (o es 'true' o es 'false'). 
    if (bit_value == true) // El bit de bit_pos te lo hace '1' sea lo que sea.
    {
        aux = data | mask; // '|' == 'Alt + 124'. // Esta linea hace un OR bit a bit entre los bits de la variable data y la variable mask.
        data = aux; // Reemplazo el dato original por el dato modificado.
    }
    else // El bit de bit_pos te lo hace '0' sea lo que sea. 
    {
        aux = data & (~mask); // '~' == 'Alt + 126'
        data = aux; // Reemplazo el dato original por el dato modificado.
    }
    return data;
}

/**
* @brief Modifica un bit específico de un valor de 64 bits.
* 
* Establece el bit en la posición indicada como 1 o 0 dependiendo de bit_value.
* 
* @param data Valor original.
* @param bit_pos Posición del bit a modificar (0-63).
* @param bit_value Valor booleano que indica el nuevo estado del bit (true: 1, false: 0).
* @return Valor modificado con el bit ajustado.
*/
uint64_t set_bit64(uint64_t data, uint8_t bit_pos, bool bit_value)
{
    if(bit_pos > 63)
    {
        printf("\nLa posicion del bit a SETear debe valer entre 0 y 63 (ambos incluidos).\n");
        return data; // Retorna el dato sin tocarlo.
    }
    uint64_t aux;
    uint64_t mask = 1; // 0000 0000 - 0000 0000 - 0000 0000 - 0000 0001 // ~mask == 1111 1111 - 1111 1111 - 1111 1111 - 1111 1110
    mask = mask << bit_pos; // Me lleva el 1 de la variable mask hasta la posicion del bit que quiero setear.
    // bit_value es un dato booleano (o es 'true' o es 'false'). 
    if (bit_value == true) // El bit de bit_pos te lo hace '1' sea lo que sea. 
    {
        aux = data | mask; // '|' == 'Alt + 124'. // Esta linea hace un OR bit a bit entre los bits de la variable data y la variable mask.
        data = aux; // Reemplazo el dato original por el dato modificado.
    }
    else // El bit de bit_pos te lo hace '0' sea lo que sea.
    {
        aux = data & (~mask); // '~' == 'Alt + 126'
        data = aux; // Reemplazo el dato original por el dato modificado.
    }
    return data;
}


// TOGGLE_BIT

/**
* @brief Invierte el estado de un bit específico de un valor de 32 bits.
* 
* Cambia un bit de 0 a 1 o de 1 a 0 en la posición indicada.
* 
* @param data Valor original.
* @param bit_pos Posición del bit a invertir (0-31).
* @return Valor modificado con el bit invertido.
*/
uint32_t toggle_bit32(uint32_t data, uint8_t bit_pos)
{
    if(bit_pos > 31)
    {
        printf("\nLa posicion del bit a invertir debe valer entre 0 y 31 (ambos incluidos).\n");
        return data; // Retorna el dato sin tocarlo.
    }
    uint32_t aux;
    uint32_t mask = 1; // 0000 0000 - 0000 0000 - 0000 0000 - 0000 0001
    mask = mask << bit_pos; // Me lleva el 1 de la variable mask hasta la posicion del bit que quiero togglear.
    aux = data ^ mask; // '^' == 'Alt + 94'.
    // Si data tiene un 0 en bit_pos, en aux me queda un 1. Si data tiene un 1 en bit_pos, en aux me queda un 0.
    data = aux;
    return data;
}

/**
* @brief Invierte el estado de un bit específico de un valor de 64 bits.
* 
* Cambia un bit de 0 a 1 o de 1 a 0 en la posición indicada.
* 
* @param data Valor original.
* @param bit_pos Posición del bit a invertir (0-63).
* @return Valor modificado con el bit invertido.
*/
uint64_t toggle_bit64(uint64_t data, uint8_t bit_pos)
{
    if(bit_pos > 63)
    {
        printf("\nLa posicion del bit a invertir debe valer entre 0 y 63 (ambos incluidos).\n");
        return data; // Retorna el dato sin tocarlo.
    }
    uint64_t aux;
    uint64_t mask = 1; // 0000 0000 - 0000 0000 - 0000 0000 - 0000 0001
    mask = mask << bit_pos; // Me lleva el 1 de la variable mask hasta la posicion del bit que quiero togglear.
    aux = data ^ mask; // '^' == 'Alt + 94'.
    // Si data tiene un 0 en bit_pos, en aux me queda un 1. Si data tiene un 1 en bit_pos, en aux me queda un 0.
    data = aux;
    return data;
}


// CARRY_ROTATE

/**
* @brief Realiza una rotación con acarreo en un valor de 32 bits.
* 
* La función rota los bits hacia la izquierda o derecha, dependiendo del signo de N.
* - N positivo: Rotación a la izquierda.
* - N negativo: Rotación a la derecha.
* 
* @param data Valor original.
* @param N Cantidad de posiciones para rotar (-31 a 31).
* @return Valor rotado. Si N está fuera del rango, retorna 0.
*/
uint32_t carry_rotate32(uint32_t data, int N)
{
    uint32_t auxA;
    uint32_t auxB;
    uint32_t maskA;
    uint32_t maskB;
    if(N < (-31) && N > 31)
    {
        printf("\nError: El valor de rotacion ingresado debe valer entre -31 y 31 (ambos incluidos).\n");
        return data; // Retorna el dato sin tocarlo.
    }
    if(N == 0)
    {
        printf("No hay rotación necesaria.\n");
        return data; // Retorna el dato sin tocarlo.
    }
    if(N > (-31) && N < 0) // Rotacion a la DERECHA.
    {
        N = -N; // Hacer N positivo.
        maskA = 1; // maskA = 0000 0000 - 0000 0000 - 0000 0000 - 0000 0001.    
        for(uint8_t i = 0 ; i < N ; i++)
        {
            auxA = data & maskA ; // Rescato el bit que quiero.
            auxA = auxA << 31 ; // Corro el bit rescatado en aux hasta el final.
            data = data >> 1 ; // Corro data un lugar, para poner luego el bit que quiero.
            data = data | auxA ; // El bit que rescate antes, lo pongo al final.
        }    
        return data;
    }
    else 
    {
        if(N > 0 && N < 31) // Rotacion a la IZQUIERDA.
        {
            maskB = 1; // mask = 0000 0000 - 0000 0000 - 0000 0000 - 0000 0001.
            maskB = maskB << 31; // maskB = 1000 0000 - 0000 0000 - 0000 0000 - 0000 0000.
            for(uint8_t i = 0 ; i < N ; i++)
            {
                auxB = data & maskB ; // Rescato el bit que quiero.
                auxB = auxB >> 31 ; // Corro el bit rescatado en aux hasta el final.
                data = data << 1 ; // Corro data un lugar, para poner luego el bit que quiero.
                data = data | auxB ; // El bit que rescate antes, lo pongo al final.
            }
            return data;
        }
    }
}

/**
* @brief Realiza una rotación con acarreo en un valor de 64 bits.
* 
* La función rota los bits hacia la izquierda o derecha, dependiendo del signo de N.
* - N positivo: Rotación a la izquierda.
* - N negativo: Rotación a la derecha.
* 
* @param data Valor original.
* @param N Cantidad de posiciones para rotar (-63 a 63).
* @return Valor rotado. Si N está fuera del rango, retorna 0.
*/
uint64_t carry_rotate64(uint64_t data, int N)
{
    uint64_t auxA;
    uint64_t auxB;
    uint64_t maskA;
    uint64_t maskB;
    if(N < (-63) && N > 63)
    {
        printf("\nError: El valor de rotacion ingresado debe valer entre -63 y 63 (ambos incluidos).\n");
        return data; // Retorna el dato sin tocarlo.
    }
    if(N == 0)
    {
        printf("No hay rotación necesaria.\n");
        return data; // Retorna el dato sin tocarlo.
    }
    if(N > (-63) && N < 0) // Rotacion a la DERECHA.
    {
        N = -N; // Hacer N positivo.
        maskA = 1; // maskA = 0000 0000 - 0000 0000 - 0000 0000 - 0000 0001.    
        for(uint8_t i = 0 ; i < N ; i++)
        {
            auxA = data & maskA ; // Rescato el bit que quiero.
            auxA = auxA << 63 ; // Corro el bit rescatado en aux hasta el final.
            data = data >> 1 ; // Corro data un lugar, para poner luego el bit que quiero.
            data = data | auxA ; // El bit que rescate antes, lo pongo al final.
        }    
        return data;
    }
    else 
    {
        if(N > 0 && N < 63) // Rotacion a la IZQUIERDA.
        {
            maskB = 1; // mask = 0000 0000 - 0000 0000 - 0000 0000 - 0000 0001.
            maskB = maskB << 63; // maskB = 1000 0000 - 0000 0000 - 0000 0000 - 0000 0000.
            for(uint8_t i = 0 ; i < N ; i++)
            {
                auxB = data & maskB ; // Rescato el bit que quiero.
                auxB = auxB >> 63 ; // Corro el bit rescatado en aux hasta el final.
                data = data << 1 ; // Corro data un lugar, para poner luego el bit que quiero.
                data = data | auxB ; // El bit que rescate antes, lo pongo al final.
            }
            return data;
        }
    }
}

// EXTRACT_BIT_SEGMENT

/**
* @brief Extrae un segmento de bits de un valor de 32 bits.
* 
* Devuelve un segmento de bits definido por las posiciones startBit y endBit.
* 
* @param value Valor original.
* @param startBit Posición inicial (0-31).
* @param endBit Posición final (0-31).
* @return Segmento de bits extraído. Si las posiciones son inválidas, retorna el valor original.
*/
uint32_t extract_bits_segment32(uint32_t value, uint8_t startBit, uint8_t endBit) 
{
    if(endBit > 31 || startBit > endBit)
    {
        printf("\nError: La posicion del bit del final no puede ser mayor a 31 \ny la posicion del bit del inicio no puede ser mayor a la posicion del bit del final.\n");
        return value; // Retorna el valor original.
    }
    else
    {
        if(startBit <= endBit) // Si startBit = endBit, solo me extrae 1 bit.
        {
            uint32_t left;
            left = ((sizeof(uint32_t)*8) - 1) - endBit;
            uint32_t segment;
            segment = value << left;
            uint32_t aux;
            aux = segment >> (left + startBit);
            segment = aux;
            return segment;
        }
    }

}

/**
* @brief Extrae un segmento de bits de un valor de 64 bits.
* 
* Devuelve un segmento de bits definido por las posiciones startBit y endBit.
* 
* @param value Valor original.
* @param startBit Posición inicial (0-63).
* @param endBit Posición final (0-63).
* @return Segmento de bits extraído. Si las posiciones son inválidas, retorna el valor original.
*/
uint64_t extract_bits_segment64(uint64_t value, uint8_t startBit, uint8_t endBit) 
{
    if(endBit > 63 || startBit > endBit)
    {
        printf("\nError: La posicion del bit del final no puede ser mayor a 63 \ny la posicion del bit del inicio no puede ser mayor a la posicion del bit del final.\n");
        return value; // Retorna el valor original.
    }
    else
    {
        if(startBit <= endBit) // Si startBit = endBit, solo me extrae 1 bit.
        {
            uint64_t left;
            left = ((sizeof(uint64_t)*8) - 1) - endBit;
            uint64_t segment;
            segment = value << left;
            uint64_t aux;
            aux = segment >> (left + startBit);
            segment = aux;
            return segment;
        }
    }
}