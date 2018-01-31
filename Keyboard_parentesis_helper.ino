// Davide Caminati 2017
// simple keyboard for Openscad
// MIT licence

#include <Bounce2.h>
#include "Keyboard.h"
#define NUM_BUTTONS 6
const uint8_t BUTTON_PINS[NUM_BUTTONS] = {2, 3, 4, 5, 6, 7};
const char BTN_CHAR[NUM_BUTTONS] = {']',40,'[',42,'{','}'};
const char BTN_ALT_CHAR[NUM_BUTTONS] = {KEY_RIGHT_ALT,NULL,KEY_RIGHT_ALT,NULL,KEY_RIGHT_ALT,KEY_RIGHT_ALT};
Bounce * buttons = new Bounce[NUM_BUTTONS];

void setup() {

  for (int i = 0; i < NUM_BUTTONS; i++) {
    buttons[i].attach( BUTTON_PINS[i] , INPUT_PULLUP  );
    buttons[i].interval(25);             
  }
  Keyboard.begin();
  
}

void loop() {

  for (int i = 0; i < NUM_BUTTONS; i++)  {
    buttons[i].update();
    if ( buttons[i].fell() ) {
      if (BTN_ALT_CHAR[i] != NULL){
        Keyboard.press(BTN_ALT_CHAR[i]);
        Keyboard.print(BTN_CHAR[i]);
        Keyboard.release(BTN_ALT_CHAR[i]);
      }
      else
      {
        Keyboard.print(BTN_CHAR[i]);
      }
      delay(1000);
    }
  }
}
