/**
 * @file binary_operations_test_voids_library.h
 * @brief Declaraciones de procedimientos para testear funciones de manipulación de datos a nivel de bits (de 32 y 64 bits).
 *
 * Este archivo contiene las declaraciones de funciones para manipular datos 
 * a nivel de bits (de 32 y 64 bits).
 */

#pragma once
#include <stdint.h>
#include "binary_operations_functions_library.h"


// SET_BIT

void testing_set_bit32(void);

void testing_set_bit64(void);


// TOGGLE_BIT

void testing_toggle_bit32(void);

void testing_toggle_bit64(void);


// CARRY_ROTATE

void testing_carry_rotate32(void);

void testing_carry_rotate64(void);


// EXTRACT_BITS_SEGMENT

void testing_extract_bits_segment32(void);

void testing_extract_bits_segment64(void);