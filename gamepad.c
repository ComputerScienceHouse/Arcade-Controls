/* A USB joystick emulator for CSH's arcade controls.
 *
 * Based on some open source code from grunskis for USB joystick stuff on 
 * AVR/Teensy board, which was in turn based off PJRC's USB keyboard HID 
 * device code for Teensy boards. I've adapted it to add a ton of new buttons,
 * new axis, new HID descriptor, new AVR chip type to accomodate expanded pin
 * count need, etc. 
 *
 * Copyright (c) 2010 Chris Lockfort <clockfort@csh.rit.edu>
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <avr/io.h>
#include <util/delay.h>
#include "usb_gamepad.h"

#define CPU_PRESCALE(n)	(CLKPR = 0x80, CLKPR = (n))

#define LED_CONFIG (DDRD |= (1<<6))
#define LED_OFF (PORTD &= ~(1<<6))
#define LED_ON (PORTD |= (1<<6))


#define JOYSTICK_RIGHT (1 << 0)
#define JOYSTICK_LEFT  (1 << 1)
#define JOYSTICK_UP    (1 << 2)
#define JOYSTICK_DOWN  (1 << 3)

int main(void) {
  //Place to store button presses
  uint8_t f, a, x, y, x2, y2;
  uint8_t i;

  // set for 16 MHz clock
  CPU_PRESCALE(0);

  // enable pull-ups on button & joystick pins
  PORTA = PORTB = PORTC = PORTF = 0xFF; 

  //configure LED pin
  LED_CONFIG;

  // Initialize the USB, and then wait for the host to set configuration.
  // If the Teensy is powered without a PC connected to the USB port,
  // this will wait forever.
  usb_init();
  while (!usb_configured()) /* wait */ ;

  // Wait an extra second for the PC's operating system to load drivers
  // and do whatever it does to actually be ready for input
  _delay_ms(1000);

  while (1) {
    f = a = 0; // assume no buttons pressed
    x = y = x2 = y2 = 128; // joysticks in middle position
    
    if ((PINB & JOYSTICK_LEFT) == 0) {
      x = 0;
    } else if ((PINB & JOYSTICK_RIGHT) == 0) {
      x = 255;
    }

    if ((PINB & JOYSTICK_UP) == 0) {
      y = 0;
    } else if ((PINB & JOYSTICK_DOWN) == 0) {
      y = 255;
    }

    if ((PINC & JOYSTICK_LEFT) == 0) {
      x2 = 0;
    } else if ((PINC & JOYSTICK_RIGHT) == 0) {
      x2 = 255;
    }

    if ((PINC & JOYSTICK_UP) == 0) {
      y2 = 0;
    } else if ((PINC & JOYSTICK_DOWN) == 0) {
      y2 = 255;
    }

    //buttons
    for(i=0; i<8; ++i){
	if( (PINA & (1 << i)) == 0 ){
		a |= (1 << i);
        }
    }

    for(i=0; i<8; ++i){
	if( (PINF & (1 << i)) == 0 ){
		f |= (1 << i);
        }
    }

    usb_gamepad_action(x, y, x2, y2, f, a);

    //LED activity light (Lights up when buttons are down)
    if (x != 128 || y != 128 || x2 != 128 || y2 != 128 || f != 0 || a != 0) {
      LED_ON;
    } else {
      LED_OFF;
    }
  }
}
 
