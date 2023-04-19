#define right A2              // Right IR sensor connected to analog pin A3 of Arduino Uno:
#define left A1              // Left IR sensor connected to analog pin A2 of Arduino Uno:
#define forward A0              // forward IR sensor connected to analog pin A0 of Arduino Uno:
// Motor A connections
int en1 = 5; //to enable motor A
int in1 = 7; 
int in2 = 8;
// Motor B connections 
int en2 = 6; //to enable motor B
int in3 = 9;
int in4 = 10;
unsigned int right_Value = 0; //Variable to store Right IR sensor value:
unsigned int left_Value = 0;  //Variable to store Left IR sensor value:
unsigned int forward_Value = 0;  //Variable to store forward IR sensor value:
unsigned int Speed = 0; 
void setup() {
    // Set all the motor control pins to outputs
  pinMode(en1, OUTPUT);
  pinMode(en2, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

Serial.begin(9600); //initailize serial communication at 9600 bits per second:
delay(200);

   pinMode(right, INPUT); //set analog pin RIGHT as an input:
   pinMode(left, INPUT);  //set analog pin LEFT as an input:
   pinMode(forward, INPUT);  //set analog pin FORWARD as an input:
}
// the lope function runs forever
void loop() {
    right_Value = digitalRead(right);             // read the value from Right IR sensor:
    left_Value = digitalRead(left);               // read the value from Left IR sensor:
    forward_Value = digitalRead(forward);         // read the value from front IR sensor:
 
Serial.print("RIGHT");                      
Serial.println(right_Value);                      // print the right IR sensor value in serial monitor:
Serial.print("LEFT");                       
Serial.println(left_Value);                       //print the left IR sensor value in serial monitor:
Serial.print("FORWARD");                       
Serial.println(forward_Value);                    //print the forward IR sensor value in serial monitor:

if((right_Value==1) && (left_Value==1) && (forward_Value==0)){
  //Move Forward:
  analogWrite(enA, 255);
  analogWrite(enB, 255);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(100);
  
}else if((right_Value==1) && (left_Value==0) && (forward_Value==1)){ //If the condition is 'true' then the statement below will execute:
  
  //Turn Left 
  analogWrite(en1, 255);
  analogWrite(en2, 255);                                               
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(100);
  
  }else if((right_Value==1) && (left_Value==0) && (forward_Value==0)){ //If the condition is 'true' then the statement below will execute:
  //Turn curved Left
  analogWrite(en2, 150);
  analogWrite(en1, 255);                                                
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
   
  delay(100);

}else if((right_Value==0) && (left_Value==1) && (forward_Value==1)){  //If the condition is 'true' then the statement below will execute:
  
  //Turn right 
  analogWrite(en1, 255);
  analogWrite(en2, 255);                                               
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay(100);

  }else if((right_Value==0) && (left_Value==1) && (forward_Value==0)){  //If the condition is 'true' then the statement below will execute:
  //Turn curved right
  analogWrite(en2, 255);
  analogWrite(en1, 150);                                             
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(100);
  
}else if((right_Value==0) && (left_Value==0) && (forward_Value==0)){     //If the condition is 'true' then the statement below will execute:
  
  // stop
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  delay(100);
  
}else if((right_Value==1) && (left_Value==1) && (forward_Value==1)){     //If the condition is 'true' then the statement below will execute:
  
  // stop
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  delay(100);
}
}
