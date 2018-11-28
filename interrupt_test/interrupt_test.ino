
#define INTERRUPT 2

void setup(){
  Serial.begin(9600);
  pinMode(INTERRUPT, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(INTERRUPT),recieve_int,CHANGE);
}


void loop(){
  
}

void recieve_int(){
  Serial.write("Hello, World!");
}
