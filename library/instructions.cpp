#include <Arduino.h>
#include "instructions.h"
#include "pinmap.h"
void (*command_table[])(void) = {
    [ADD] = do_add,
    [SUB] = do_sub,
    [AND] = do_and,
    [OR] = do_or,
    [XOR] = do_xor,
    [SRA] = do_sra,
    [SLA] = do_sla,
    [ROR] = do_ror,
    [ROL] = do_rol,
    [NOT] = do_not,
    [STOLO] = do_stolo,
    [STOHI] = do_stohi,
    [SWAP] = do_swap,
    [CLEAR] = do_clear,
    [MUL] = do_mul,
    [DIV] = do_div
};

void do_command(int registers[]){
   int command_to_do = digiread4(registers);
   command_table[command_to_do]();
}
