#define BOARD_ALU
#define SWAP_DISABLE() digitalWrite(ALU_SWAP,LOW); 
#define SWAP_ENABLE() digitalWrite(ALU_SWAP,HIGH); 
#define WRITE_ENABLE() digitalWrite(ALU_WRE,HIGH);
#define WRITE_DISABLE() digitalWrite(ALU_WRE,LOW);
#include<pinmap.h>
#include<instructions.h>

void do_add(){
    WRITE_ENABLE();
    SWAP_DISABLE();
    int a = digiread4(ALU_A);
    int b = digiread4(ALU_B);

    digiwrite4(ALU_S, a + b);
}
void do_sub(){
    WRITE_ENABLE();
    SWAP_DISABLE();
    int a = digiread4(ALU_A);
    int b = digiread4(ALU_B);
    digiwrite4(ALU_S, a - b);
}
void do_and(){
    WRITE_ENABLE();
    SWAP_DISABLE();
    int a = digiread4(ALU_A);
    int b = digiread4(ALU_B);
    digiwrite4(ALU_S, a & b);
}
void do_or(){
    WRITE_ENABLE();
    SWAP_DISABLE();
    int a = digiread4(ALU_A);
    int b = digiread4(ALU_B);
    digiwrite4(ALU_S, a | b);
}
void do_xor(){
    WRITE_ENABLE();
    SWAP_DISABLE();
    int a = digiread4(ALU_A);
    int b = digiread4(ALU_B);
    digiwrite4(ALU_S, a ^ b);
}
void do_sra(){
    WRITE_ENABLE();
    SWAP_DISABLE();
    int a = digiread4(ALU_A);
    int b = digiread4(ALU_B);
    digiwrite4(ALU_S, a >> b);
}
void do_sla(){
    WRITE_ENABLE();
    SWAP_DISABLE();
    int a = digiread4(ALU_A);
    int b = digiread4(ALU_B);
    digiwrite4(ALU_S, a << b);
}
void do_ror(){
    WRITE_ENABLE();
    SWAP_DISABLE();
    int a = digiread4(ALU_A);
    int b = digiread4(ALU_B);
    digiwrite4(ALU_S, (a >> b) | (a << (4-b)));
}
void do_rol(){
    WRITE_ENABLE();
    SWAP_DISABLE();
    int a = digiread4(ALU_A);
    int b = digiread4(ALU_B);
    digiwrite4(ALU_S, (a << b) | (a >> (4-b)));
}
void do_not(){
    WRITE_ENABLE();
    SWAP_DISABLE();
    int a = digiread4(ALU_A);
    digiwrite4(ALU_S, ~a);
}
void do_immlo(){
    WRITE_ENABLE();
    SWAP_DISABLE();
    int a = digiread4(ALU_A);
    int b = digiread4(ALU_B);
    int out = (b & 12) + (a & 3);
    digiwrite4(ALU_S, out);
}

void do_immhi(){
    WRITE_ENABLE();
    SWAP_DISABLE();
    int a = digiread4(ALU_A);
    int b = digiread4(ALU_B);
    int out = (b & 3) + a<<2;
    digiwrite4(ALU_S, out);
}
void do_swap(){
    WRITE_DISABLE();
    SWAP_ENABLE();
}
void do_clear(){
    WRITE_ENABLE();
    SWAP_DISABLE();
    digiwrite4(ALU_S, 0);
}
void do_mul(){
    WRITE_ENABLE();
    SWAP_DISABLE();
    int a = digiread4(ALU_A);
    int b = digiread4(ALU_B);
    digiwrite4(ALU_S, a * b);
}
void do_div(){
    WRITE_ENABLE();
    SWAP_DISABLE();
    int a = digiread4(ALU_A);
    int b = digiread4(ALU_B);
    digiwrite4(ALU_S, a / b);
}
void setup(){
    pinMode4(ALU_A,INPUT);
    pinMode4(ALU_B,INPUT);
    pinMode4(ALU_INSTR,INPUT);
    pinMode4(ALU_S,OUTPUT);
    pinMode(ALU_WRE,OUTPUT);
    pinMode(ALU_SWAP,OUTPUT);
    Serial.begin(9600);
}

#define WAIT_FOR_COMMAND() while(0)
void loop(){
    do_div();
    delay(100);
    //do_command(ALU_INSTR);
}
