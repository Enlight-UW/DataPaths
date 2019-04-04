#include <Arduino.h>
#include "pinmap.h"
/* Define arrays of 4 (or 2) pins which comprise the bits 
 * Instruction pins for the instruction board
 */ 
/* Instruction pins for the register board */
int REG_INSTR[4] = {4, 5, 6, 7};

/* Register pins for the register board */
int REG_A[4] = {21, 23, 25, 27};
int REG_B[4] = {29, 31, 33, 35};
int REG_S[4] = {37, 39, 41, 43};

/* Instruction pins for the ALU board */
int ALU_INSTR[4] = {A0, A1, A2, A3};
/* Register pins for the ALU board */
int ALU_A[4] = {2,3,4,5};
int ALU_B[4] = {6, 7, 8, 9};
int ALU_S[4] = {10, 11, 12, 13};


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

/* setup pins based on board */
void pinMode4(int pins[], int mode){
    pinMode(pins[0],mode);
    pinMode(pins[1],mode);
    pinMode(pins[2],mode);
    pinMode(pins[3],mode);
}
void pin_setup(){
#ifdef BOARD_VERIFY
    pinMode4(ALU_INSTR,INPUT);
#endif
#ifdef BOARD_ALU
    pinMode4(ALU_INSTR,INPUT);
    pinMode4(ALU_A,INPUT);
    pinMode4(ALU_B,INPUT);
    pinMode4(ALU_S,OUTPUT);
#endif
    pinMode4(REG_INSTR,INPUT);
    pinMode4(REG_A,OUTPUT);
    pinMode4(REG_B,OUTPUT);
    pinMode4(REG_S,INPUT);
    pinMode(REG_CLOCK,INPUT);
    pinMode(REG_SWAP,INPUT);
}
