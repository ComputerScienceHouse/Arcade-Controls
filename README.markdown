CSH Arcade Controls
==================

Chris Lockfort (devnull@csh.rit.edu)

A USB joystick emulator for CSH's arcade controls.

Based on some open source code from grunskis for USB joystick stuff on AVR/Teensy board, which was in turn based off PJRC's USB keyboard HID device code for Teensy boards.
I've adapted it to add a ton of new buttons, new axis, new HID descriptor, new AVR chip type to accomodate expanded pin count need, etc.

Pin Wiring Diagram
------------------

Function		Pin
JOYSTICK_1_RIGHT_AXIS 	B0
JOYSTICK_1_LEFT_AXIS	B1
JOYSTICK_1_UP_AXIS	B2
JOYSTICK_1_DOWN_AXIS	B3
JOYSTICK_2_RIGHT_AXIS	C0
JOYSTICK_2_LEFT_AXIS	C1
JOYSTICK_2_UP_AXIS	C2
JOYSTICK_2_DOWN_AXIS	C3
BUTTON_0		F0
BUTTON_1		F1
BUTTON_2		F2
BUTTON_3		F3
BUTTON_4		F4
BUTTON_5		F5
BUTTON_6		F6
BUTTON_7		F7
BUTTON_8		A0
BUTTON_9		A1
BUTTON_10		A2
BUTTON_11		A3
BUTTON_12		A4
BUTTON_13		A5
BUTTON_14		A6
BUTTON_15		A7
