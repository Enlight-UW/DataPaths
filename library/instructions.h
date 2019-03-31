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
#define IMMLO 10
#define IMMHI 11
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
extern void do_immlo();
extern void do_immhi();
extern void do_swap();
extern void do_clear();
extern void do_mul();
extern void do_div();

extern void (*command_table[])(void);
void do_command(int registers[]);
#endif

