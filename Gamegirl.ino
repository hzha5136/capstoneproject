#include "Joystick.h"

Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,
                   JOYSTICK_TYPE_JOYSTICK, 14, 0,
                   true, true, false, true, true, false,
                   false, false, false, false, false);
const int hatSwitch = 0;
int buttonState = 0;         // variable for reading the pushbutton status
 
int xAxis;
int yAxis;
int rxAxis;
int ryAxis;
int hatRead;
 
void setup() {
  Joystick.setXAxisRange(-254, 254);
  Joystick.setYAxisRange(-254, 254);
  Joystick.setRxAxisRange(-254, 254);
  Joystick.setRyAxisRange(-254, 254);
 
  Joystick.begin();
  pinMode(0, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(14, INPUT_PULLUP);
  pinMode(15, INPUT_PULLUP);
  pinMode(16, INPUT_PULLUP);

  
  
}
int lastButtonState[17] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

void loop() {
  xAxis = (analogRead(A0) - 512)*3/2;
  yAxis = (analogRead(A1) - 512)*3/2;
  rxAxis = (analogRead(A2) - 512)*3/2;
  ryAxis = (analogRead(A3) - 512)*3/2;
          if (xAxis>150|xAxis<-150) {
            Joystick.setXAxis(xAxis);
          } else {
            Joystick.setXAxis(0);
          }
          if (yAxis>150|yAxis<-150) {
            Joystick.setYAxis(yAxis);
          } else {
            Joystick.setYAxis(0);
          }
          if (rxAxis>150|rxAxis<-150) {
            Joystick.setRxAxis(rxAxis);
          } else {
            Joystick.setRxAxis(0);
          }
           if (ryAxis>150|ryAxis<-150) {
            Joystick.setRyAxis(ryAxis);
          } else {
            Joystick.setRyAxis(0);
          }

 

  for (int index = 0; index < 17; index++) 
  {
    int currentButtonState = !digitalRead(index);
    if (currentButtonState != lastButtonState[index])
    {
      switch (index) {
       case 0:
          Joystick.setButton(6, currentButtonState);
          break;
       case 1:
          Joystick.setButton(9, currentButtonState);
          break;
       case 2:
          Joystick.setButton(12, currentButtonState);
          break;
       case 3:
          Joystick.setButton(13, currentButtonState);
          break;
       case 4:
          Joystick.setButton(8, currentButtonState);
          break;
       case 5:
          Joystick.setButton(7, currentButtonState);
          break;
       case 6:
          Joystick.setButton(5, currentButtonState);
          break;
       case 7:
          Joystick.setButton(4, currentButtonState);
          break;
       case 8:
          Joystick.setButton(11, currentButtonState);
          break;
       case 9:
          Joystick.setButton(10, currentButtonState);
          break;
       case 10:
          Joystick.setButton(1, currentButtonState);
          break;
       case 11:
          Joystick.setButton(14, currentButtonState);
          break;
       case 12:
          Joystick.setButton(15, currentButtonState);
          break;
       case 13:
          Joystick.setButton(16, currentButtonState);
          break;
       case 14:
          Joystick.setButton(3, currentButtonState);
          break;
       case 15:
          Joystick.setButton(0, currentButtonState);
          break;
       case 16:
          Joystick.setButton(2, currentButtonState);
          break;
      }
      lastButtonState[index] = currentButtonState;
    }
  }
delay(10); 
}

