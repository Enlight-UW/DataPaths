



volatile byte state = HIGH;

int count = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(5, OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(4, OUTPUT);



}

void loop() {
  // put your main code here, to run repeatedly:

   digitalWrite(5,LOW);

   digitalWrite(6,count & 1);
   digitalWrite(7,count & 2);
   digitalWrite(8, count & 4);
   digitalWrite(9, count & 8);
   digitalWrite(10,count & 16);
   digitalWrite(11,count & 32);
   digitalWrite(12, count & 64);
   digitalWrite(13, count & 128);
   digitalWrite(4, state);
   state = !state;
   delay(800);

   count++;
  
}
