/* Buttons to USB Keyboard Example

   You must select Keyboard from the "Tools > USB Type" menu

   This example code is in the public domain.
*/

#include <Bounce.h>

// Create Bounce objects for each button.  The Bounce object
// automatically deals with contact chatter or "bounce", and
// it makes detecting changes very simple.
Bounce button0 = Bounce(0, 10);
Bounce button1 = Bounce(1, 10);  // 10 = 10 ms debounce time
Bounce button2 = Bounce(2, 10);  // which is appropriate for
Bounce button3 = Bounce(3, 10);  // most mechanical pushbuttons
Bounce button4 = Bounce(4, 10);
Bounce button5 = Bounce(5, 10);  // if a button is too "sensitive"
Bounce button6 = Bounce(6, 10);  // to rapid touch, you can
Bounce button7 = Bounce(7, 10);  // increase this time.
Bounce button8 = Bounce(8, 10);
Bounce button9 = Bounce(9, 10);

void setup() {
  // Configure the pins for input mode with pullup resistors.
  // The pushbuttons connect from each pin to ground.  When
  // the button is pressed, the pin reads LOW because the button
  // shorts it to ground.  When released, the pin reads HIGH
  // because the pullup resistor connects to +5 volts inside
  // the chip.  LOW for "on", and HIGH for "off" may seem
  // backwards, but using the on-chip pullup resistors is very
  // convenient.  The scheme is called "active low", and it's
  // very commonly used in electronics... so much that the chip
  // has built-in pullup resistors!
  pinMode(0, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);  // Teensy++ LED, may need 1k resistor pullup
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);

  // INITIATE LED PINS
  pinMode(23, OUTPUT);
  pinMode(22, OUTPUT);
  pinMode(21, OUTPUT);
  pinMode(20, OUTPUT);
  pinMode(19, OUTPUT);
  pinMode(18, OUTPUT);
  pinMode(17, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(14, OUTPUT);
}

void loop() {
  // Update all the buttons.  There should not be any long
  // delays in loop(), so this runs repetitively at a rate
  // faster than the buttons could be pressed and released.
  button0.update();
  button1.update();
  button2.update();
  button3.update();
  button4.update();
  button5.update();
  button6.update();
  button7.update();
  button8.update();
  button9.update();

  // Check each B0 press
  if (button0.fallingEdge()) {
    Keyboard.press(KEY_ESC);
    digitalWrite(14, HIGH);
  }
  if (button1.fallingEdge()) {
    Keyboard.press(KEY_ENTER);
    digitalWrite(15, HIGH);
  }
  if (button2.fallingEdge()) {
    Keyboard.press(KEY_ENTER);
    digitalWrite(16, HIGH);
  }
  if (button3.fallingEdge()) {
    Keyboard.press(KEY_G);
    digitalWrite(17, HIGH);
  }
  if (button4.fallingEdge()) {
    Keyboard.press(KEY_Y);
    digitalWrite(18, HIGH);
  }
  if (button5.fallingEdge()) {
    Keyboard.press(KEY_H);
    digitalWrite(19, HIGH);
  }
  if (button6.fallingEdge()) {
    Keyboard.press(KEY_D);
    digitalWrite(20, HIGH);
  }
  if (button7.fallingEdge()) {
    Keyboard.press(KEY_F);
    digitalWrite(21, HIGH);
  }
  if (button8.fallingEdge()) {
    Keyboard.press(KEY_J);
    digitalWrite(22, HIGH);
  }
  if (button9.fallingEdge()) {
    Keyboard.press(KEY_K);
    digitalWrite(23, HIGH);
  }

  // Check each button for "rising" edge
  // Type a message on the Keyboard when each button releases.
  // For many types of projects, you only care when the button
  // is pressed and the release isn't needed.
  // rising = low (pressed - button connects pin to ground)
  //          to high (not pressed - voltage from pullup resistor)
  if (button0.risingEdge()) {
    Keyboard.release(KEY_ESC);
    digitalWrite(14, LOW);
  }
  if (button1.risingEdge()) {
    Keyboard.release(KEY_ENTER);
    digitalWrite(15, LOW);
  }
  if (button2.risingEdge()) {
    Keyboard.release(KEY_ENTER);
    digitalWrite(16, LOW);
  }
  if (button3.risingEdge()) {
    Keyboard.release(KEY_G);
    digitalWrite(17, LOW);
  }
  if (button4.risingEdge()) {
    Keyboard.release(KEY_Y);
    digitalWrite(18, LOW);
  }
  if (button5.risingEdge()) {
    Keyboard.release(KEY_H);
    digitalWrite(19, LOW);
  }
  if (button6.risingEdge()) {
    Keyboard.release(KEY_D);
    digitalWrite(20, LOW);
  }
  if (button7.risingEdge()) {
    Keyboard.release(KEY_F);
    digitalWrite(21, LOW);
  }
  if (button8.risingEdge()) {
    Keyboard.release(KEY_J);
    digitalWrite(22, LOW);
  }
  if (button9.risingEdge()) {
    Keyboard.release(KEY_K);
    digitalWrite(23, LOW);
  }
}
