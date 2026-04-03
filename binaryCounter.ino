/*
    This is a simple program on a SparkFun Tinker Kit-14556
    With Port COMM 5 and Arduino Uno Board type

    In this file, I have used 4 LEDS to make a incrementing counter
    in binary, which would correspond with the LED bulb lighting up. 

    On = 1
    Off = 0
*/


int interval = 750;                 //pause for 750 ms or 7.5 s
int ledPins[] = {13,12,11,10};      //make a set where it holds all inputs
int count = 0; 


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);                           //connect to Serial Monitor

  for (int i = 0; i < 4; i++) {
    pinMode(ledPins[i], OUTPUT); // Set pins as output
  }


}

void loop() {
  // put your main code here, to run repeatedly:
  
  for (int i = 0; i < 4; i++) {
    // Read each bit of the counter and set the corresponding LED
    digitalWrite(ledPins[i], bitRead(count, i));
  }
  
  Serial.println(count);                                //reveal current number
  delay(750);
  count++;
  
  if (count > 15) { // Reset after 1111 (15 in decimal)
    count = 0;
  }
}