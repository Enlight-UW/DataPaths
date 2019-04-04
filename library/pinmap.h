#ifndef PINMAP_H
#define PINMAP_H

/* Instruction pins for the register board */
#define REG_CLOCK 0
#define REG_SWAP 13
#define REG_WRE  12

extern int REG_INSTR[4];
/* Register pins for the register board */
extern int REG_A[4];
extern int REG_B[4];
extern int REG_S[4];

/* Instruction pins for the ALU board */
#define ALU_SWAP A0
#define ALU_WRE  A1
extern int ALU_INSTR[4];
/* Register pins for the ALU board */
extern int ALU_A[4];
extern int ALU_B[4];
extern int ALU_S[4];
extern int ALU_CC[2];

int digiread4(int pins[]);
void digiwrite4(int pins[],int value);
void pinMode4(int pins[], int mode);
void pin_setup();
#endif /*PINMAP_H*/
