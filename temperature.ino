#include <LiquidCrystal.h>
// defines pins numbers
const int trigPin = 6;
const int echoPin = 7;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int red = 13;
int blue = 9;
int green = 8;

// defines variables
long duration;
int distance;
void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(LED_BUILTIN, OUTPUT);
Serial.begin(9600); // Starts the serial communication
lcd.print("Distance= ");
pinMode(red, OUTPUT);
pinMode(blue, OUTPUT);
pinMode(green, OUTPUT);

  // print the number of seconds since reset:

  // Print a message to the LCD.
  
}
void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);

digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
  lcd.begin(16, 2);
      
        
  lcd.print(distance);
if(distance >=25 && distance <=50){
 
  digitalWrite(red, LOW);
   digitalWrite(blue, LOW);
  digitalWrite(green, HIGH);
                       // wait for a second
}else if (distance >50 && distance< 75){
  digitalWrite(red, LOW);
  digitalWrite(green, LOW);
  digitalWrite(blue, HIGH);
  
} else if(distance>= 75){
  digitalWrite(red, HIGH);
  digitalWrite(blue, LOW);
  digitalWrite(green, LOW);
 
} else{

  digitalWrite(green, HIGH);
  delay(50);
  digitalWrite(red, HIGH);
  delay(50);
  digitalWrite(green, LOW);
  digitalWrite(red, LOW);
  delay(50);
  digitalWrite(blue, HIGH);
  delay(50);
  digitalWrite(blue, LOW);
  digitalWrite(red, HIGH);
  delay(50);
  digitalWrite(green, HIGH);
  delay(50);
  digitalWrite(blue, HIGH);
  delay(50);
  digitalWrite(blue, LOW);
  delay(50);

}
}
