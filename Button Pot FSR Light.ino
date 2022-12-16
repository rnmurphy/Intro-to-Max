/*Button, potentiometer, FSR, and phototransistor on Arduino Uno, receiving information from IDE via serial communication and interacting with Max.
This code sends four values separated by spaces.

The first value relates to the button, and is coded as buttonPress:
  If the button is pressed, Arduino sends 1. If it is not pressed, Arduino sends 0. The digital reading comes from pin 2 (buttonPin)

The second value is the potentiometer:
  This is an analog pin (potPin = A1) which can send values between 0 and 1023. This is scaled down to a more useful range for Max of 25 to 500 (potVal).

The third value is the FSR:
  This analog reading comes from pin A0 (fsrPin). The value range is scaled to between 10 and 200 (fsrVal).

The fourth value is the phototransistor:
  This corresponds to pin A2 (lightPin), with a scaled range of 0 to 255 (lightVal).
*/

const int buttonPin = 2;  // digital pin
int buttonPress = 0;      // digital value
const int potPin = A1;    // first analog pin
int potVal = 0;           // first analog value
const int fsrPin = A0;    // second analog pin
int fsrVal = 0;           // second analog value
const int lightPin = A2;  // third analog pin
int lightVal = 0;         // third analog value

void setup(){
  pinMode(buttonPin, INPUT); // digital pin 2 is identified as an INPUT
  Serial.begin(9600);        // Begin serial communciation at the baud rate of 9600 bits per second maximum
}

void loop(){
  buttonPress = digitalRead(buttonPin);      // reading pin 2 value
  potVal = analogRead(potPin);               // reading A1 value
  potVal = map(potVal, 0, 1023, 25, 500);    // Scaling to a more useful range for Max
  fsrVal = analogRead(fsrPin);               // reading A0 value
  fsrVal = map(fsrVal, 0, 1023, 10, 200);    // Scaling range
  lightVal = analogRead(lightPin);           // reading A2 value
  lightVal = map(lightVal, 0, 1023, 0, 255); // Scaling range

  if (buttonPress == HIGH){
    Serial.print(1); // if button is pressed, send value of 1
  } else {
    Serial.print(0); // if not pressed, send 0
  }
  Serial.print(" ");      // values separated by spaces to allow interpretation by Max
  Serial.print(potVal);   // send A1 value  
  Serial.print(" ");    
  Serial.print(fsrVal);   // send A0  value
  Serial.print(" ");
  Serial.print(lightVal); // send A2 value

  Serial.println();

  delay(500); // 500 millisecond delay
}

