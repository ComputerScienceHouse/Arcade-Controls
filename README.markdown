 
CSH Arcade Controls
==================

Chris Lockfort (devnull@csh.rit.edu)

A USB joystick emulator for CSH's arcade controls.

Based on some open source code from grunskis for USB joystick stuff on AVR/Teensy board, which was in turn based off PJRC's USB keyboard HID device code for Teensy boards.
I've adapted it to add a ton of new buttons, new axis, new HID descriptor, new AVR chip type to accomodate expanded pin count need, etc.

Pin Wiring Diagram
------------------

    Function                   Pin
    JOYSTICK 1 RIGHT AXIS      B0
    JOYSTICK 1 LEFT AXIS       B1
    JOYSTICK 1 UP AXIS         B2
    JOYSTICK 1 DOWN AXIS       B3
    JOYSTICK 2 RIGHT AXIS      C0
    JOYSTICK 2 LEFT AXIS       C1
    JOYSTICK 2 UP AXIS         C2
    JOYSTICK 2 DOWN AXIS       C3
    BUTTON 0                   F0
    BUTTON 1                   F1
    BUTTON 2                   F2
    BUTTON 3                   F3
    BUTTON 4                   F4
    BUTTON 5                   F5
    BUTTON 6                   F6
    BUTTON 7                   F7
    BUTTON 8                   A0
    BUTTON 9                   A1
    BUTTON 10                  A2
    BUTTON 11                  A3
    BUTTON 12                  A4
    BUTTON 13                  A5
    BUTTON 14                  A6
    BUTTON 15                  A7
