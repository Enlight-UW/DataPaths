
#define INTERRUPT 2


void setup(){
  Serial.begin(9600);
  pinMode(INTERRUPT, INPUT_PULLUP);
  pinMode(6,INPUT_PULLUP);
  pinMode(7,INPUT_PULLUP);
  pinMode(8,INPUT_PULLUP);
  pinMode(9,INPUT_PULLUP);
  pinMode(10,INPUT_PULLUP);
  pinMode(11,INPUT_PULLUP);
  pinMode(12,INPUT_PULLUP);
  pinMode(13,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(INTERRUPT),recieve_int,RISING);
}


void loop(){
  
}

void recieve_int(){
  int value = 0;
  for(int i = 6; i<14; i++){
    value += digitalRead(i)<<(i-6);
  }
  Serial.println(value);
  
}
