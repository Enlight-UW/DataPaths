#define BOARD_ALU
#define SWAP_DISABLE() digitalWrite(ALU_SWAP,LOW); 
#define SWAP_ENABLE() digitalWrite(ALU_SWAP,HIGH); 
#include<pinmap.h>
#include<instructions.h>

void do_add(){
    SWAP_DISABLE();
    int a = digiread4(ALU_A);
    int b = digiread4(ALU_B);
    digiwrite4(ALU_S, a + b);
}
void do_sub(){
    SWAP_DISABLE();
    int a = digiread4(ALU_A);
    int b = digiread4(ALU_B);
    digiwrite4(ALU_S, a - b);
}
void do_and(){
    SWAP_DISABLE();
    int a = digiread4(ALU_A);
    int b = digiread4(ALU_B);
    digiwrite4(ALU_S, a & b);
}
void do_or(){
    SWAP_DISABLE();
    int a = digiread4(ALU_A);
    int b = digiread4(ALU_B);
    digiwrite4(ALU_S, a | b);
}
void do_xor(){
    SWAP_DISABLE();
    int a = digiread4(ALU_A);
    int b = digiread4(ALU_B);
    digiwrite4(ALU_S, a ^ b);
}
void do_sra(){
    SWAP_DISABLE();
    int a = digiread4(ALU_A);
    int b = digiread4(ALU_B);
    digiwrite4(ALU_S, a << b);
}
void do_sla(){
    SWAP_DISABLE();
    int a = digiread4(ALU_A);
    int b = digiread4(ALU_B);
    digiwrite4(ALU_S, a >> b);
}
void do_ror(){
    SWAP_DISABLE();
    int a = digiread4(ALU_A);
    int b = digiread4(ALU_B);
    digiwrite4(ALU_S, (a >> b) | (a << (4-b)));
}
void do_rol(){
    SWAP_DISABLE();
    int a = digiread4(ALU_A);
    int b = digiread4(ALU_B);
    digiwrite4(ALU_S, (a << b) | (a >> (4-b)));
}
void do_not(){
    SWAP_DISABLE();
    int a = digiread4(ALU_A);
    digiwrite4(ALU_S, ~a);
}
void do_immlo(){
    SWAP_DISABLE();
    int a = digiread4(ALU_A);
    int b = digiread4(ALU_B);
    int out = (b & 12) + (a & 3);
    digiwrite4(ALU_S, out);
}

void do_immhi(){
    SWAP_DISABLE();
    int a = digiread4(ALU_A);
    int b = digiread4(ALU_B);
    int out = (b & 3) + a<<2;
    digiwrite4(ALU_S, out);
}
void do_swap(){
    SWAP_ENABLE();
}
void do_clear(){
    SWAP_DISABLE();
    digiwrite4(ALU_S, 0);
}
void do_mul(){
    SWAP_DISABLE();
    int a = digiread4(ALU_A);
    int b = digiread4(ALU_B);
    digiwrite4(ALU_S, a * b);
}
void do_div(){
    SWAP_DISABLE();
    int a = digiread4(ALU_A);
    int b = digiread4(ALU_B);
    digiwrite4(ALU_S, a / b);
}
void setup(){
    pin_setup();
    digitalWrite(ALU_WRE,HIGH);
    Serial.begin(9600);
}

#define WAIT_FOR_COMMAND() while(0)
void loop(){
    WAIT_FOR_COMMAND();
    do_command(ALU_INSTR);
}
