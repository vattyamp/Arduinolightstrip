/*
 * IRremote: IRreceiveDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Initially coded 2009 Ken Shirriff http://www.righto.com/
 */

#include <IRremote.h>

#define REDPIN 5
#define GREENPIN 6
#define BLUEPIN 3

int IR_RECEIVE_PIN = 11;

int r,g,b;

IRrecv IrReceiver(IR_RECEIVE_PIN);

// On the Zero and others we switch explicitly to SerialUSB
decode_results results;

void setup() {
    //pinMode(LED_BUILTIN, OUTPUT);
    IrReceiver.enableIRIn();  // Start the receiver
    pinMode(REDPIN, OUTPUT);
    pinMode(GREENPIN, OUTPUT);
    pinMode(BLUEPIN, OUTPUT);


    r=0;
    g=0;
    b=0;
    delay(200);
    // IrReceiver.blink13(true); // Enable feedback LED

}

void loop() {
    if (IrReceiver.decode(&results)) {
        if (results.decode_type == NEC){
          if (results.value == 0xFFA25D){
            Red();
            delay(10);
          } else if (results.value == 0xFF629D){
            Green();
            delay(10);
          } else if (results.value == 0xFFE21D){
            Blue();
            delay(10);
          }
        }
        IrReceiver.resume(); // Receive the next value
    }
    delay(100);
}


void Red() {
  while (g > 0) {
    analogWrite(GREENPIN, g); 
    g--;
    delay(15);
  }
  while (b > 0) {
    analogWrite(BLUEPIN, b); 
    b--;
    delay(15);
  }
  for (r = 0; r < 256; r++) { 
    analogWrite(REDPIN, r);
    delay(15);
  } 
  
}
void Green() {
  while (r > 0) {
    analogWrite(REDPIN, r); 
    r--;
    delay(15);
  }
  while (b > 0) {
    analogWrite(BLUEPIN, b); 
    b--;
    delay(15);
  }
  for (g = 0; g < 256; g++) { 
    analogWrite(GREENPIN, g);
    delay(15);
  } 
}
void Blue() {
  while (g > 0) {
    analogWrite(GREENPIN, g); 
    g--;
    delay(15);
  }
  while (r > 0) {
    analogWrite(REDPIN, r); 
    r--;
    delay(15);
  }
  for (b = 0; b < 256; b++) { 
    analogWrite(BLUEPIN, b);
    delay(15);
  } 
}
