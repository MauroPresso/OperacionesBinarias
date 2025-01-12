/**
 * @file binary_operations_functions_library.h
 * @brief Declaraciones de funciones para manipulación de datos a nivel de bits (de 32 y 64 bits).
 *
 * Este archivo contiene las declaraciones de funciones para manipular datos 
 * a nivel de bits (de 32 y 64 bits).
 */

#pragma once
#include <stdint.h>


// SHOW_BIN

/**
 * @brief Muestra la representación binaria de un valor de 32 bits.
 * 
 * @param value Valor de 32 bits a mostrar.
 */
void show_bin32(uint32_t value);

/**
 * @brief Muestra la representación binaria de un valor de 64 bits.
 * 
 * @param value Valor de 64 bits a mostrar.
 */
void show_bin64(uint64_t value);


// SET_BIT

/**
 * @brief Establece un bit específico en un valor de 32 bits.
 * 
 * @param data Valor original.
 * @param bit_pos Posición del bit (0-31).
 * @param bit_value Valor del bit (true: 1, false: 0).
 * @return Nuevo valor con el bit modificado.
 */
uint32_t set_bit32(uint32_t data, uint8_t bit_pos, bool bit_value);

/**
 * @brief Establece un bit específico en un valor de 64 bits.
 * 
 * @param data Valor original.
 * @param bit_pos Posición del bit (0-63).
 * @param bit_value Valor del bit (true: 1, false: 0).
 * @return Nuevo valor con el bit modificado.
 */
uint64_t set_bit64(uint64_t data, uint8_t bit_pos, bool bit_value);


// TOGGLE_BIT

/**
 * @brief Invierte un bit específico en un valor de 32 bits.
 * 
 * @param data Valor original.
 * @param bit_pos Posición del bit (0-31).
 * @return Nuevo valor con el bit invertido.
 */
uint32_t toggle_bit32(uint32_t data, uint8_t bit_pos);

/**
 * @brief Invierte un bit específico en un valor de 64 bits.
 * 
 * @param data Valor original.
 * @param bit_pos Posición del bit (0-63).
 * @return Nuevo valor con el bit invertido.
 */
uint64_t toggle_bit64(uint64_t data, uint8_t bit_pos);


// CARRY_ROTATE

/**
 * @brief Rota los bits de un valor de 32 bits con acarreo.
 * 
 * @param data Valor original.
 * @param N Número de posiciones a rotar (positivo: derecha, negativo: izquierda).
 * @return Valor rotado.
 */
uint32_t carry_rotate32(uint32_t data, int N);

/**
 * @brief Rota los bits de un valor de 64 bits con acarreo.
 * 
 * @param data Valor original.
 * @param N Número de posiciones a rotar (positivo: derecha, negativo: izquierda).
 * @return Valor rotado.
 */
uint64_t carry_rotate64(uint64_t data, int N);

// EXTRACT_BITS_SEGMENT

/**
 * @brief Extrae un segmento de bits de un valor de 32 bits.
 * 
 * @param value Valor original.
 * @param startBit Bit inicial del segmento (0-31).
 * @param endBit Bit final del segmento (0-31).
 * @return Segmento extraído como un valor de 32 bits.
 */
uint32_t extract_bits_segment32(uint32_t value, uint8_t startBit, uint8_t endBit);

/**
 * @brief Extrae un segmento de bits de un valor de 64 bits.
 * 
 * @param value Valor original.
 * @param startBit Bit inicial del segmento (0-63).
 * @param endBit Bit final del segmento (0-63).
 * @return Segmento extraído como un valor de 64 bits.
 */
uint64_t extract_bits_segment64(uint64_t value, uint8_t startBit, uint8_t endBit);






