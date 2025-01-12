#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "binary_operations_functions_library.h"
#include "binary_operations_test_voids_lib.h"

int main()
{
    // SET_BIT
    
    testing_set_bit32();

    testing_set_bit64();

    
    // TOGGLE_BIT

    testing_toggle_bit32();

    testing_toggle_bit64();


    // CARRY_ROTATE

    testing_carry_rotate32();

    testing_carry_rotate64();


    // EXTRACT_BITS_SEGMENT

    testing_extract_bits_segment32();

    testing_extract_bits_segment64();


    // FIN DEL PROGRAMA
    return 0;
}