/*
CAR PROJECT SOURCE CODE BY INTECBRUSSEL JAVA IoT TEAM
 _____ _   _ _____ _____ _____ ____________ _   _ _____ _____ _____ _     
|_   _| \ | |_   _|  ___/  __ \| ___ \ ___ \ | | /  ___/  ___|  ___| |    
  | | |  \| | | | | |__ | /  \/| |_/ / |_/ / | | \ `--.\ `--.| |__ | |    
  | | | . ` | | | |  __|| |    | ___ \    /| | | |`--. \`--. \  __|| |    
 _| |_| |\  | | | | |___| \__/\| |_/ / |\ \| |_| /\__/ /\__/ / |___| |____
 \___/\_| \_/ \_/ \____/ \____/\____/\_| \_|\___/\____/\____/\____/\_____/
                                                                          
                                                                          
*/
#define trigpin 5//set trigpin
#include <Servo.h>
#define echopin 6//set echopin
int front = 11;
int back = 10;
int left = 9;
int right = 3;
int servoAngle = 0;

int number = 1;


Servo myservo;// declare servo name type servo
  int duration, distance;//declare variable for unltrasonic sensor
  
void setup() {
  Serial.begin(19200);
  pinMode(trigpin, OUTPUT);
  pinMode(front, OUTPUT); // front pin = 11
  pinMode(back, OUTPUT); // back pin = 10
  pinMode(left, OUTPUT); // left pin = 9
  pinMode(right, OUTPUT); // right pin = 3    
  pinMode(echopin, INPUT);
  myservo.attach(2);// attach your servo
  myservo.writeMicroseconds(1500);
  // put your setup code here, to run once:
  
  
  myservo.write(90);
  calibration();
  }


void loop() {  


  digitalWrite(left, HIGH);

  Serial.println("begin new loop"); //print distance unit cm
  
  int directDist = 3;

  int farthest = 0;


  int leftDist =0;
  int rightDist =0;
  int frontDist = 0;
  
   
  leftDist = checkLeft(); 
  rightDist = checkRight();
  frontDist = checkFront(); 

    if (leftDist > farthest) {
      farthest = leftDist;
      directDist = 0;
    }
     if (frontDist >  farthest) {
      farthest = frontDist;
      directDist = 2;
    }
     if (rightDist >  farthest) {
      farthest = rightDist;
      directDist = 1;
    }

   Serial.print("checking distance front less then 40"); //print distance unit cm


    if( farthest > 150) {
      driveFront();
      
    }else {
      if (frontDist < 16 || leftDist <35|| rightDist < 35 ) {
        Serial.print("front cm: "); //print distance unit cm
        Serial.print(farthest);//distance
        directDist = 3;
       }
    }
       

 
  Serial.print("farthes cm: "); //print distance unit cm
  Serial.print(farthest);//distance

  
  Serial.print("farthes cm: "); //print distance unit cm
  Serial.print(farthest);//distance
  Serial.print(", direction: ");//distance
  Serial.print(directDist);


 

 Drive(directDist);

 
}





void calibration() {
    
  Serial.print("calibrating "); //print distance unit cm
 checkDistance();
 delay(200);
  checkDistance();
 delay(200);
  checkDistance();
 delay(200);
}

void Drive(int direction) {

  if (direction == 0) {
    driveLeft();
  }
  if (direction == 1) {
   driveRight();
  }
  if (direction == 2) {
    driveFront();
  }

  if (direction == 3) {
    driveBack();
  }
    
}


int checkDistance(){
  //ultrasonic code 
  digitalWrite(trigpin,HIGH);
  _delay_ms(500);
  digitalWrite(trigpin, LOW);
  duration=pulseIn(echopin,HIGH); 
  distance=(duration/2)/29.1;
  return distance;
  }

void driveFront() { 
    turnFront();
    Serial.println("== > Driving fornt"); 
    digitalWrite(front, HIGH);
      delay(400);
    digitalWrite(front, LOW);
    delay(10);  
  }
void driveBack() {
    Serial.println(" == > Driving Back"); 
   
    digitalWrite(back, HIGH);
       delay(450);
    digitalWrite(back, LOW);
    delay(10);  


 }

void driveLeft() {
    Serial.println("== > Driving Left"); 
    turnRight();
     turnRight();
    digitalWrite(front, HIGH);
    delay(400);
    digitalWrite(front, LOW);
    delay(10);  


 }

 void driveRight() {
    Serial.println("== > Driving Right"); 
    turnLeft();
     turnLeft();
    digitalWrite(front, HIGH);
    delay(400);
    digitalWrite(front, LOW);
    delay(10);
 }

int checkLeft() {
   myservo.write(60);
  int leftDist = checkDistance();
  Serial.print("leftDistance: ");
  Serial.println(leftDist);
  return leftDist;
  
}
int checkRight() {
   myservo.write(120);
  int rightDist = checkDistance();
   Serial.print("RightDistance : ");
    Serial.println(rightDist);
  return rightDist;
  
}
int checkFront() {
  myservo.write(90);
  int frontDist = checkDistance();
  Serial.print("frontDistance: ");
  Serial.println(frontDist);
  return frontDist;
  
}

 void turnRight() {
  myservo.write(120);
  Serial.println("turned right"); 
  digitalWrite(right, HIGH);
  
  
  
  }

   void turnLeft() {
   myservo.write(60);
   Serial.println("turn left"); 
   digitalWrite(left, HIGH);

    }

  
   void turnFront() {
   myservo.write(90);
   Serial.println("turn Front"); 
   digitalWrite(left, LOW);
   digitalWrite(right, LOW);
  
   
    
  
  }
 
