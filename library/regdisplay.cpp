#include <SevSeg.h>
#include <Arduino.h>
SevSeg sevseg;

int regValues[];

void numDisplaySetup(){
  byte numDigits = 4;
  byte digitPins[] = {47, 45, 46, 44};
  //byte segmentPins[] = {9, 2, 3, 5, 6, 8, 7, 4}; For test board
  byte segmentPins[] = {48, 42, 53, 51, 50, 49, 40, 52}; //Mega 2560 Board config
  regValues[] = {0, 0, 0, 0};

  bool resistorsOnSegments = true;
  bool updateWithDelaysIn = true;
  byte hardwareConfig = COMMON_CATHODE;
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
  sevseg.setBrightness(90);
}

void numDisplayLoop(){
  sevseg.setNumber(assembleDisplayNumber(), 3, true);
  sevseg.refreshDisplay();
}

int calcRegValueRaw(int regValue){
  return regValue & 0x000F;
}

int calcRegAValue(int regValue){
  return calcRegValueRaw(regValue) << 12;
}

int calcRegBValue(int regValue){
  return calcRegValueRaw(regValue) << 8;
}

int calcRegSValue(int regValue){
  return calcRegValueRaw(regValue) << 4;
}

int calcRegXValue(int regValue){
  return calcRegValueRaw(regValue);
}

void provideRegValues(int values[]){
  for (int i = 0; i < 4; i++){
    regValues[i] = values[i];
  }
}

int assembleDisplayNumber(){
  int regValues[] = {6, 2, 15, 12}; //Replace these array values with the actual values of the registers
  return calcRegAValue(regValues[0]) | calcRegBValue(regValues[1]) | calcRegSValue(regValues[2]) | calcRegXValue(regValues[3]);
}
