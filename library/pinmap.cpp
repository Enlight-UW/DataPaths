#include <Arduino.h>
/* Define arrays of 4 (or 2) pins which comprise the bits 
 * Instruction pins for the instruction board
 */ 
int INST_INSTR_LOW[4] = {2, 3, 4, 5};
int INST_INSTR_HI[4] = {6, 7, 8, 9};

/* Condition codes for the instruction board */
int INST_CC[2] = {12, 13};

/* Instruction pins for the register board */
int REG_INSTR_LOW[4] = {2, 3, 4, 5};
int REG_INSTR_HI[4] = {6, 7, 8, 9};

/* Register pins for the register board */
int REG_A[4] = {21, 23, 25, 27};
int REG_B[4] = {29, 31, 33, 35};
int REG_S[4] = {37, 39, 41, 43};

/* Instruction pins for the ALU board */
int ALU_INSTR_LOW[4] = {A0, A1, A2, A3};
/* Register pins for the ALU board */
int ALU_A[4] = {0,1,2,3};
int ALU_B[4] = {29, 31, 33, 35};
int ALU_S[4] = {37, 39, 41, 43};
int ALU_CC[2] = {12, 13};


/* convert digitalread of 4 pins into int */
int digiread4(int pins[]){
    return digitalRead(pins[0])+digitalRead(pins[1])*2 + 
           digitalRead(pins[2])*4 + digitalRead(pins[3])*8;
}

/* write a value across 4 digital pins */
void digiwrite4(int pins[],int value){
    digitalWrite(pins[0],value & 1);
    digitalWrite(pins[1],value & 2);
    digitalWrite(pins[2],value & 4);
    digitalWrite(pins[3],value & 8);
}
