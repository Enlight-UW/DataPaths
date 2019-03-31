#include<pinmap.h>
#include<instructions.h>

void do_add(){
    Serial.write("add");
}
void do_sub(){
    Serial.write("sub");
}
void do_and(){
    Serial.write("and");
}
void do_or(){
    Serial.write("or");
}
void do_xor(){
    Serial.write("xor");
}
void do_sra(){
    Serial.write("sra");
}
void do_sla(){
    Serial.write("sla");
}
void do_ror(){
    Serial.write("ror");
}
void do_rol(){
    Serial.write("rol");
}
void do_not(){
    Serial.write("not");
}
void do_stolo(){
    Serial.write("stolo");
}
void do_stohi(){
    Serial.write("stohi");
}
void do_swap(){
    Serial.write("swap");
}
void do_clear(){
    Serial.write("clear");
}
void do_mul(){
    Serial.write("mul");
}
void do_div(){
    Serial.write("div");
}
void setup(){
    Serial.begin(9600);
}

void loop(){
    do_command(ALU_INSTR_LOW);
}
