#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "binary_operations_functions_library.h"
#include "binary_operations_test_voids_lib.h"

int main()
{
    // SET_BIT
    printf("\n");
    testing_set_bit32();
    printf("\n");
    testing_set_bit64();
    printf("\n");
    printf("\n");
    // TOGGLE_BIT
    printf("\n");
    testing_toggle_bit32();
    printf("\n");
    testing_toggle_bit64();
    printf("\n");
    printf("\n");
    // CARRY_ROTATE
    printf("\n");
    testing_carry_rotate32();
    printf("\n");
    testing_carry_rotate64();
    printf("\n");
    printf("\n");
    // EXTRACT_BITS_SEGMENT
    printf("\n");
    testing_extract_bits_segment32();
    printf("\n");
    testing_extract_bits_segment64();
    printf("\n");
    printf("\n");
    // FIN DEL PROGRAMA
    printf("FIN DEL PROGRAMA");
    return 0;
}