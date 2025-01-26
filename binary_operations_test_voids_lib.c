/**
 * @file binary_operations_test_voids_lib.c
 * @brief Implementaciones de los procedimientos de pruebas 
 * para las funciones de manipulación de bits de 32 y 64 bits.
 *
 * Este archivo contiene ejemplos de uso y pruebas para las funciones de
 * manipulación de bits específicas para datos de 32 y 64 bits.
 * 
 * Las funciones (para 32 y 64 bits) probadas incluyen:
 * - `set_bit()`
 * - `toggle_bit()`
 * - `carry_rotate()`
 * - `extract_bits_segment()`
 */

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "binary_operations_functions_library.h"
#include "binary_operations_test_voids_lib.h"


// SET_BIT

void testing_set_bit32(void)
{
    printf("\nTESTING SET_BIT32:\n");
    uint8_t p;
    p = 3;
    uint32_t val;
    val = 255;
    printf("\nValor == %u:\n", val);
    show_bin32(val); 
    val = set_bit32(val, p, true);
    printf("\nValor modificado con set_bit32 (true) en la posicion %u:\n", p);
    show_bin32(val);
    printf("\n");
    val = 0;
    printf("\nValor == %u:\n", val);
    show_bin32(val);
    val = set_bit32(val, p, true);
    printf("\nValor modificado con set_bit32 (true) en la posicion %u:\n", p);
    show_bin32(val);
    printf("\n");
    val = 255;
    printf("\nValor == %u:\n", val);
    show_bin32(val); 
    val = set_bit32(val, p, false);
    printf("\nValor modificado con set_bit32 (false) en la posicion %u:\n", p);
    show_bin32(val);
    printf("\n");
    val = 0;
    printf("\nValor == %u:\n", val);
    show_bin32(val);
    val = set_bit32(val, p, false);
    printf("\nValor modificado con set_bit32 (false) en la posicion %u:\n", p);
    show_bin32(val);  
}

void testing_set_bit64(void)
{
    printf("\nTESTING SET_BIT64:\n");
    uint8_t p;
    p = 3;
    uint64_t val;
    val = 255;
    printf("\nValor == %u:\n", val);
    show_bin64(val); 
    val = set_bit64(val, p, true);
    printf("\nValor modificado con set_bit64 (true) en la posicion %u:\n", p);
    show_bin64(val);
    printf("\n");
    val = 0;
    printf("\nValor == %u:\n", val);
    show_bin64(val);
    val = set_bit64(val, p, true);
    printf("\nValor modificado con set_bit64 (true) en la posicion %u:\n", p);
    show_bin64(val);
    printf("\n");
    val = 255;
    printf("\nValor == %u:\n", val);
    show_bin64(val); 
    val = set_bit64(val, p, false);
    printf("\nValor modificado con set_bit64 (false) en la posicion %u:\n", p);
    show_bin64(val);
    printf("\n");
    val = 0;
    printf("\nValor == %u:\n", val);
    show_bin64(val);
    val = set_bit64(val, p, false);
    printf("\nValor modificado con set_bit64 (false) en la posicion %u:\n", p);
    show_bin64(val);
}


// TOGGLE_BIT

void testing_toggle_bit32(void)
{
    printf("\nTESTING TOGGLE_BIT32:\n");
    uint8_t p;
    p = 3;
    uint32_t val;
    val = 255;
    printf("\nValor == %u:\n", val);
    show_bin32(val); 
    val = toggle_bit32(val, p);
    printf("\nValor modificado con toggle_bit32 en la posicion %u:\n", p);
    show_bin32(val);
    printf("\n");
    val = 0;
    printf("\nValor == %u:\n", val);
    show_bin32(val);
    val = toggle_bit32(val, p);
    printf("\nValor modificado con toggle_bit32 en la posicion %u:\n", p);
    show_bin32(val);
}

void testing_toggle_bit64(void)
{
    printf("\nTESTING TOGGLE_BIT64:\n");
    uint8_t p;
    p = 3;
    uint64_t val;
    val = 255;
    printf("\nValor == %u:\n", val);
    show_bin64(val); 
    val = toggle_bit64(val, p);
    printf("\nValor modificado con toggle_bit64 en la posicion %u:\n", p);
    show_bin64(val);
    printf("\n");
    val = 0;
    printf("\nValor == %u:\n", val);
    show_bin64(val);
    val = toggle_bit64(val, p);
    printf("\nValor modificado con toggle_bit64 en la posicion %u:\n", p);
    show_bin64(val);
}


// CARRY_ROTATE

void testing_carry_rotate32(void)
{
    printf("\nTESTING CARRY_ROTATE32:\n");
    uint32_t val;
    val = 4278190080;
    printf("\nValor == %u:\n", val);
    show_bin32(val); 
    int rot;
    rot = 4;
    printf("\nValor rotado %d veces (a la IZQUIERDA):\n", rot);
    val = carry_rotate32(val, rot);
    show_bin32(val);
    printf("\n");
    val = 255;
    rot = (-4);
    printf("\nValor == %u:\n", val);
    show_bin32(val); 
    printf("\nValor rotado %d veces (a la DERECHA):\n", rot);
    val = carry_rotate32(val, rot);
    show_bin32(val);
}

void testing_carry_rotate64(void)
{
    printf("\nTESTING CARRY_ROTATE64:\n");
    uint64_t val;
    val = 9223372036854775807;
    printf("\nValor == %u:\n", val);
    show_bin64(val); 
    int rot;
    rot = 4;
    printf("\nValor rotado %d veces (a la IZQUIERDA):\n", rot);
    val = carry_rotate64(val, rot);
    show_bin64(val);
    printf("\n");
    val = 255;
    rot = (-4);
    printf("\nValor == %u:\n", val);
    show_bin64(val); 
    printf("\nValor rotado %d veces (a la DERECHA):\n", rot);
    val = carry_rotate64(val, rot);
    show_bin64(val);    
}


// EXTRACT_BITS_SEGMENT
void testing_extract_bits_segment32(void)
{
    printf("\nTESTING EXTRACT_BITS_SEGMENT32:\n");
    uint32_t val;
    val = 247;
    printf("\nValor == %u:\n", val);
    show_bin32(val);
    uint8_t inicio, final;
    inicio = 0;
    final = 5;
    printf("\nSegmento extraido (del bit %u al bit %u):\n", inicio, final);
    val = extract_bits_segment32(val, inicio, final);
    show_bin32(val);
}

void testing_extract_bits_segment64(void)
{    
    printf("\nTESTING EXTRACT_BITS_SEGMENT64:\n");
    uint64_t val;
    val = 247;
    printf("\nValor == %u:\n", val);
    show_bin64(val);
    uint8_t inicio, final;
    inicio = 0;
    final = 5;
    printf("\nSegmento extraido (del bit %u al bit %u):\n", inicio, final);
    val = extract_bits_segment64(val, inicio, final);
    show_bin64(val);
}    