#include <dht.h>
#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
#define DHT_PIN 3
dht DHT;
int SmokeSensor = A0;
int SMOKERED = 2;
//int GREEN = 4;
int BUZZER = 5;
int RED = 9;
int GREEN = 8;
int BLUE = 11;
int FAN = 7;
int REDNH4 = 4;
int GREENNH4 = 13;
int Ammonia = A2;

void setup() {
  pinMode(SmokeSensor, INPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(FAN , OUTPUT);
  pinMode(SMOKERED, OUTPUT);
  pinMode(REDNH4, OUTPUT);
  pinMode(GREENNH4, OUTPUT);
  pinMode(Ammonia, INPUT);
  lcd.backlight();
  lcd.init();
  lcd.begin(16,2);
  lcd.setCursor(0, 0);
  lcd.print("Initializing....");
  delay(2000);
  lcd.clear();

  Serial.begin(9600);
}

void loop() {
 int sensorValue = analogRead(A0);
 //Serial.println(sensorValue);
 int Ammonia = analogRead(A2);
 Serial.println("AMMONIA=");
 Serial.println(Ammonia);
 
 
  int chk = DHT.read11(DHT_PIN);
  lcd.setCursor(0,0);
  //lcd.print("Temp="DHT.temperature);
  lcd.print("Temp: ");
  lcd.print(DHT.temperature);
  lcd.print((char)223);
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print("Humi: ");
  lcd.print(DHT.humidity);
  delay(5000);
  //lcd.clear();

   if(DHT.temperature > 20 and DHT.temperature<30 ){
       digitalWrite( FAN , LOW);
       digitalWrite(GREEN, HIGH);
       //delay(1000);
       //digitalWrite(GREEN, LOW);
       //delay(1000);
       digitalWrite(RED, LOW);
       digitalWrite(BUZZER, LOW);
      
        
  } 
  else {
       digitalWrite(GREEN, LOW);
       digitalWrite(RED, HIGH);
       digitalWrite(BUZZER, HIGH ); 
       digitalWrite(FAN, HIGH);
       

    
    }
    if(DHT.humidity > 50 and DHT.humidity<100  ){
       //digitalWrite(RED, LOW);
       //delay(1000);
       //digitalWrite(RED, LOW);
      // delay(1000);
       digitalWrite(BLUE,HIGH );
       digitalWrite(BUZZER, LOW);
        
  } 
  else {
    digitalWrite(GREEN, LOW);
       digitalWrite(RED, LOW);
       digitalWrite(BUZZER,LOW ); 
       delay(1000);
    
    }
   if ( sensorValue > 1000 ){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("SMOKE ");
      digitalWrite(SMOKERED , HIGH);
      digitalWrite(BUZZER , HIGH);
      digitalWrite(FAN , HIGH);
      delay(2000);
    }
    else {
      digitalWrite( SMOKERED, LOW);
     digitalWrite(BUZZER , LOW);
      digitalWrite(FAN , LOW);
      
      
    }
    if (Ammonia > 400)
  {
    digitalWrite(REDNH4, HIGH);
  }
  else
    digitalWrite(REDNH4, LOW);
    }
