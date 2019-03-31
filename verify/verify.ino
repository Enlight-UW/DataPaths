#define BOARD_VERIFY
#include<pinmap.h>
#include<instructions.h>

void do_add(){
    Serial.write("add\n");
}
void do_sub(){
    Serial.write("sub\n");
}
void do_and(){
    Serial.write("and\n");
}
void do_or(){
    Serial.write("or\n");
}
void do_xor(){
    Serial.write("xor\n");
}
void do_sra(){
    Serial.write("sra\n");
}
void do_sla(){
    Serial.write("sla\n");
}
void do_ror(){
    Serial.write("ror\n");
}
void do_rol(){
    Serial.write("rol\n");
}
void do_not(){
    Serial.write("not\n");
}
void do_immlo(){
    Serial.write("immlo\n");
}
void do_immhi(){
    Serial.write("immhi\n");
}
void do_swap(){
    Serial.write("swap\n");
}
void do_clear(){
    Serial.write("clear\n");
}
void do_mul(){
    Serial.write("mul\n");
}
void do_div(){
    Serial.write("div\n");
}
void setup(){
    pin_setup();
    Serial.begin(9600);
}

void loop(){
    do_command(ALU_INSTR);
    delay(1000);
}
