//This code is to control the speed of a DC motor by a potentiometer using l298n driver
//We read the value from the analog input, calibrate it then inject to the module
//Refer to Surtrtech youtube channel for more information


int in1 = 8; //Declaring where our module is wired
int in2 = 9;
int ConA = 10;// Don't forget this is a PWM DI/DO
int speed1; 
#define echoPin 3 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 2 //attach pin D3 Arduino to pin Trig of HC-SR04
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement
int LED = 4;
int Pot = A0;
int Res;
int Pressure;



void setup() {
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);  
  pinMode(10, OUTPUT);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  pinMode(LED, OUTPUT);
  pinMode( Pot , INPUT);
 
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
 // Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
  //Serial.println("with Arduino UNO R3");
  
}

void TurnMotorA(){ //We create a function which control the direction and speed
  digitalWrite(in1, LOW); //Switch between this HIGH and LOW to change direction
  digitalWrite(in2, HIGH);
  
}
void loop() {
   Res = analogRead(Pot);
  //Serial.print(Res);
  Pressure = Res*0.2492668622;
   analogWrite(ConA,Pressure);
TurnMotorA(); //one function that keeps looping you can add another one with different direction or stop
// Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(2);
  //digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = (duration*0.034)/2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  delay(50);
   if (distance > 6 )
  {
    digitalWrite(LED, HIGH);
  }
  else
    digitalWrite(LED, LOW);
}
