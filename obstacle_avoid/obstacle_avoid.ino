
const int trigPin = 10;  
const int echoPin = 11;  
long duration;                               
int distance;
int mA1=5;
int mA2=6;
int mB1=13;
int mB2=12;

////////////
void find_distance (void)                   
{ 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
 
  distance = 0.034 * duration / 2; 
 } 
///////////
///////////

void forward(){
  digitalWrite(mA1, HIGH);
digitalWrite(mA2, LOW);
digitalWrite(mB1, HIGH);
digitalWrite(mB2, LOW);
}
void back(){
  
digitalWrite(mA1, LOW);
digitalWrite(mA2, HIGH);
digitalWrite(mB1, LOW);
digitalWrite(mB2, HIGH);
}
void stopp(){
  digitalWrite(mA1, LOW);
digitalWrite(mA2, LOW);
digitalWrite(mB1, LOW);
digitalWrite(mB2, LOW);
}

void left(){
 digitalWrite(mA1, HIGH);

//delay(1000);
//digitalWrite(mA1, HIGH);
//
//digitalWrite(mB1, HIGH);

}
void right(){
digitalWrite(mB1, HIGH);


//delay(1000);

//digitalWrite(mA1, HIGH);
//digitalWrite(mB1, HIGH); 

}
//////////
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(trigPin, OUTPUT); 
pinMode(mA1, OUTPUT);
pinMode(mA2, OUTPUT);
pinMode(mB1, OUTPUT);
pinMode(mB2, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
 find_distance();

 if(distance>20){
  forward();
  
  
}
else if(distance<=20) {
  
  stopp();
  delay(100);
  back();
  delay(500);
  stopp();
  delay(200);
  left();
  delay(500);
  
  stopp();

}
}
