#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H
#define ADD 0
#define SUB 1
#define AND 2
#define OR 3
#define XOR 4
#define SRA 5
#define SLA 6
#define ROR 7
#define ROL 8
#define NOT 9
#define STOLO 10
#define STOHI 11
#define SWAP 12
#define CLEAR 13
#define MUL 14
#define DIV 15

extern void do_add();
extern void do_sub();
extern void do_and();
extern void do_or();
extern void do_xor();
extern void do_sra();
extern void do_sla();
extern void do_ror();
extern void do_rol();
extern void do_not();
extern void do_stolo();
extern void do_stohi();
extern void do_swap();
extern void do_clear();
extern void do_mul();
extern void do_div();

void (*commands[])(void) = {
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
#endif
