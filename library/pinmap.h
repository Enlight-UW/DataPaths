#ifndef PINMAP_H
#define PINMAP_H
extern int INST_INSTR_LOW[4];
extern int INST_INSTR_HI[4];

/* Condition codes for the instruction board */
extern int INST_CC[2];

/* Instruction pins for the register board */
extern int REG_INSTR_LOW[4];
extern int REG_INSTR_HI[4];

/* Register pins for the register board */
extern int REG_A[4];
extern int REG_B[4];
extern int REG_S[4];

/* Instruction pins for the ALU board */
extern int ALU_INSTR_LOW[4];
/* Register pins for the ALU board */
extern int ALU_A[4];
extern int ALU_B[4];
extern int ALU_S[4];
extern int ALU_CC[2];

int digiread4(int pins[]);
void digiread4(int pins[],int value);
#endif /*PINMAP_H*/
