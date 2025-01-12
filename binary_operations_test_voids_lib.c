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
    uint32_t val;
    val = 255;
    printf("\nValor == 255:\n");
    show_bin32(val); 
    val = set_bit32(val, 3, true);
    printf("\nValor modificado con set_bit32 (true):\n");
    show_bin32(val);

    val = 0;
    printf("\nValor == 0:\n");
    show_bin32(val);
    val = set_bit32(val, 3, true);
    printf("\nValor modificado con set_bit32 (true):\n");
    show_bin32(val);

    val = 255;
    printf("\nValor == 255:\n");
    show_bin32(val); 
    val = set_bit32(val, 3, false);
    printf("\nValor modificado con set_bit32 (false):\n");
    show_bin32(val);

    val = 0;
    printf("\nValor == 0:\n");
    show_bin32(val);
    val = set_bit32(val, 3, false);
    printf("\nValor modificado con set_bit32 (false):\n");
    show_bin32(val);  
}

void testing_set_bit64(void)
{
    printf("\nTESTING SET_BIT64:\n");
    uint64_t val;
    val = 255;
    printf("\nValor == 255:\n");
    show_bin64(val); 
    val = set_bit64(val, 3, true);
    printf("\nValor modificado con set_bit64 (true):\n");
    show_bin64(val);

    val = 0;
    printf("\nValor == 0:\n");
    show_bin64(val);
    val = set_bit64(val, 3, true);
    printf("\nValor modificado con set_bit64 (true):\n");
    show_bin64(val);

    val = 255;
    printf("\nValor == 255:\n");
    show_bin64(val); 
    val = set_bit64(val, 3, false);
    printf("\nValor modificado con set_bit64 (false):\n");
    show_bin64(val);

    val = 0;
    printf("\nValor == 0:\n");
    show_bin64(val);
    val = set_bit64(val, 3, false);
    printf("\nValor modificado con set_bit64 (false):\n");
    show_bin64(val);
}


// TOGGLE_BIT

void testing_toggle_bit32(void)
{
    printf("\nTESTING TOGGLE_BIT32:\n");
    uint32_t val;
    val = 255;
    printf("\nValor == 255:\n");
    show_bin32(val); 
    val = toggle_bit32(val, 3);
    printf("\nValor modificado con toggle_bit32:\n");
    show_bin32(val);

    val = 0;
    printf("\nValor == 0:\n");
    show_bin32(val);
    val = toggle_bit32(val, 3);
    printf("\nValor modificado con toggle_bit32:\n");
    show_bin32(val);
}

void testing_toggle_bit64(void)
{
    printf("\nTESTING TOGGLE_BIT64:\n");
    uint64_t val;
    val = 255;
    printf("\nValor == 255:\n");
    show_bin64(val); 
    val = toggle_bit64(val, 3);
    printf("\nValor modificado con toggle_bit64:\n");
    show_bin64(val);

    val = 0;
    printf("\nValor == 0:\n");
    show_bin64(val);
    val = toggle_bit64(val, 3);
    printf("\nValor modificado con toggle_bit64:\n");
    show_bin64(val);
}


// CARRY_ROTATE

void testing_carry_rotate32(void)
{
    printf("\nTESTING CARRY_ROTATE32:\n");
    uint32_t val;
    val = 4278190080;
    printf("\nValor == 4278190080:\n");
    show_bin32(val); 
    printf("\nValor rotado 4 veces a la IZQUIERDA:\n");
    val = carry_rotate32(val, 4);
    show_bin32(val);
    
    val = 255;
    printf("\nValor == 255:\n");
    show_bin32(val); 
    printf("\nValor rotado 4 veces a la DERECHA:\n");
    val = carry_rotate32(val, -4);
    show_bin32(val);
}

void testing_carry_rotate64(void)
{
    printf("\nTESTING CARRY_ROTATE64:\n");
    uint64_t val;
    val = 9223372036854775807;
    printf("\nValor == 9223372036854775807:\n");
    show_bin64(val); 
    printf("\nValor rotado 4 veces a la IZQUIERDA:\n");
    val = carry_rotate64(val, 4);
    show_bin64(val);
    
    val = 255;
    printf("\nValor == 255:\n");
    show_bin64(val); 
    printf("\nValor rotado 4 veces a la DERECHA:\n");
    val = carry_rotate64(val, -4);
    show_bin64(val);    
}


// EXTRACT_BITS_SEGMENT
void testing_extract_bits_segment32(void)
{
    printf("\nTESTING EXTRACT_BITS_SEGMENT32:\n");
    uint32_t val;
    val = 247;
    printf("\nValor == 247:\n");
    show_bin32(val);
    printf("\nSegmento extraído (bits 0-5):\n");
    val = extract_bits_segment32(val, 0, 5);
    show_bin32(val);
}

void testing_extract_bits_segment64(void)
{    
    uint64_t val;
    val = 247;
    printf("\nValor == 247:\n");
    show_bin64(val);
    printf("\nSegmento extraído (bits 0-5):\n");
    val = extract_bits_segment64(val, 0, 5);
    show_bin64(val);
}    