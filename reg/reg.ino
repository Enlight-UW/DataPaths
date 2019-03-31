#define BOARD_REG
#include<pinmap.h>

int REGISTERS[4] = {0, 0, 0, 0};
void setup(){
    pin_setup(); 
    Serial.begin(9600);
}

int reg_a_idx(){
    return digiread4(REG_INSTR) & 3;
}
int reg_b_idx(){
    return digiread4(REG_INSTR) >> 2;
}
#define WAIT_CLOCK() while(!digitalRead(REG_CLOCK))
#define SWAPPING digitalRead(REG_SWAP)
#define WRITE_ENABLED digitalRead(REG_WRE)
void loop(){
    WAIT_CLOCK();
    delay(10);
    if(WRITE_ENABLED){
        REGISTERS[2] = digiread4(REG_S);
    }
    if(SWAPPING){
        // do swap
        int r1 = reg_a_idx();
        int r2 = reg_b_idx();
        // nothing fancy
        int tmp = REGISTERS[r1];
        REGISTERS[r1] = REGISTERS[r2];
        REGISTERS[r2] = tmp;
    }else{
        digiwrite4(REG_A,REGISTERS[reg_a_idx()]);
        digiwrite4(REG_B,REGISTERS[reg_b_idx()]);
    }

}
