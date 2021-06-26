//motor left
char enA = A2;
int in1 = 9;
int in2 = 8;
// motor right
char enB = A1;
int in3 = 7;
int in4 = 6;

//ultrasonic 3
// defines pins numbers
const int trigPin_right = 9;
const int echoPin_right = 10;
// defines variables
int duration_right;
int distance_right;
//ultrasonic 2
// defines pins numbers
const int trigPin_center = 9;
const int echoPin_center = 10;
// defines variables
int  duration_center;
int distance_center;
//ultrasonic1
// defines pins numbers
const int trigPin_left = 9;
const int echoPin_left = 10;
// defines variables
int  duration_left;
int distance_left;
void setup() {
pinMode(enA, OUTPUT);
pinMode(enB, OUTPUT);
pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);
pinMode(in3, OUTPUT);
pinMode(in4, OUTPUT);
pinMode(trigPin_center, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin_center, INPUT); // Sets the echoPin as an Input
pinMode(trigPin_right, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin_right, INPUT); // Sets the echoPin as an Input
pinMode(trigPin_left, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin_left, INPUT); // Sets the echoPin as an Input
Serial.begin(9600); // Starts the serial communication
}
void loop() {
  forward();
// Clears the trigPin
digitalWrite(trigPin_left, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin_left, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin_left, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration_left = pulseIn(echoPin_left, HIGH);
distance_left= duration_left*0.034/2;

// Clears the trigPin
digitalWrite(trigPin_center, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin_center, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin_center, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration_center = pulseIn(echoPin_center, HIGH);
// Calculating the distance
distance_center= duration_center*0.034/2;
// Clears the trigPin
digitalWrite(trigPin_right, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin_right, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin_right, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration_right = pulseIn(echoPin_right, HIGH);
// Calculating the distance
distance_right= duration_right*0.034/2;
if(distance_left<=20)
{
   right();
}
if(distance_right<=20)
{
  left();
}
if(distance_center<=20)
{
  if(distance_right<=20 && distance_left<=20)
  {
    backward();
  }
  else if(distance_right<=20)
  {
    left();
  }
  else if(distance_left<=20)
  {
    right();
  }
  
}
}
void forward()
{
  Serial.print("function entered forward");
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 100);
  digitalWrite(in3,  HIGH);
  digitalWrite(in4,LOW);
  analogWrite(enB, 100);
  delay(700);  
}



void left()
{
  Serial.print("function entered left");
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 100);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 100);
  delay(500);
}


void right()
{
  Serial.print("function entered right");
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 100);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 100);
  delay(500);
}

void backward()
{
 
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 100);  
  digitalWrite(in3, LOW);
  digitalWrite(in4,HIGH); 
  analogWrite(enB, 100);
  delay(300);
}

void wait()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW); 
  analogWrite(enB, 0);
  delay(100);
}