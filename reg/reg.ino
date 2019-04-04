#define BOARD_REG
#include<pinmap.h>
#include<regdisplay.h>

int REGISTERS[4] = {2, 3, 0, 0};
void setup(){
  numDisplaySetup();
 pinMode4(REG_A,OUTPUT);
 pinMode4(REG_B,OUTPUT);
 pinMode4(REG_S,INPUT);
 pinMode4(REG_INSTR,INPUT);
 pinMode(REG_CLOCK,INPUT);
 pinMode(REG_SWAP,INPUT);
 Serial.begin(9600);
}

int reg_a_idx(){
    return digiread4(REG_INSTR) & 3;
}
int reg_b_idx(){
    return digiread4(REG_INSTR) >> 2;
}
#define WAIT_CLOCK() while(digitalRead(REG_CLOCK))
#define SWAPPING !digitalRead(REG_SWAP)
#define WRITE_ENABLED true//digitalRead(REG_WRE)

int last_state = LOW;
void wait_clock(){
  //detect a falling edge on the clock pin
  int spin = 1;
  while(spin){
    int state = digitalRead(REG_CLOCK);
    if(state != last_state && state == LOW){
      break;
    }
  }
}
void loop(){
    WAIT_CLOCK();
    delay(1000);
    if(true){
        REGISTERS[3] = digiread4(REG_S);
    }
    int r1 = 0;//reg_a_idx();
    int r2 = 1;//reg_b_idx();
    if(SWAPPING){
        // nothing fancy
        int tmp = REGISTERS[r1];
        REGISTERS[r1] = REGISTERS[r2];
        REGISTERS[r2] = tmp;
    }
    digiwrite4(REG_A,REGISTERS[r1]);
    digiwrite4(REG_B,REGISTERS[r2]);
    Serial.write("r1 = ");
    Serial.println(REGISTERS[0]);
    Serial.write("r2 = ");
    Serial.println(REGISTERS[1]);
    Serial.write("r3 = ");
    Serial.println(REGISTERS[2]);
    Serial.write("rS = ");
    Serial.println(REGISTERS[3]);
    Serial.write("\n");
    provideRegValues(REGISTERS);
    numDisplayLoop();
}
