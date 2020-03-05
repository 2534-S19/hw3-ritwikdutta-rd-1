/*
 * GPIO.c
 *
 *  Created on:
 *      Author:
 */

// For the code you place here, you may use your code that uses register references.
// However, I encourage you to start using the Driver Library as soon as possible.

#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "myGPIO.h"

// TODO: Create a function to initialize the GPIO.
// Even though this assignment does not use all of the pushbuttons, you should write one function that does a complete GPIO init.
void initGPIO()
{
    // Launchpad S1
    P1DIR = P1DIR & ~LAUNCHPAD_S1; // Setting Launchpad Button S1 to an input
    P1REN = P1REN | LAUNCHPAD_S1;
    P1OUT = P1OUT | LAUNCHPAD_S1;

    // Launchpad S2
    P1DIR = P1DIR & ~LAUNCHPAD_S2; // Setting Launchpad Button S2 to an input
    P1REN = P1REN | LAUNCHPAD_S2;
    P1OUT = P1OUT | LAUNCHPAD_S2;

    // Boosterpack S1
    P5DIR = P5DIR & ~BOOSTER_S1; // Setting Booster Button S1 to an input
    P5REN = P5REN | BOOSTER_S1;
    P5OUT = P5OUT | BOOSTER_S1;

    // Boosterpack S2
    P3DIR = P3DIR & ~BOOSTER_S2; // Setting Booster Button S2 to an input
    P3REN = P3REN | BOOSTER_S2;
    P3OUT = P3OUT | BOOSTER_S2;

    // Launchpad LED1
    P1DIR = P1DIR | LAUNCHPAD_LED1; // Setting Launchpad LED1 to an output

    // Launchpad LED2 Red
    P2DIR = P2DIR | LAUNCHPAD_RLED2; // Setting Launchpad RED_LED1 to an output

    // Launchpad LED2 Green
    P2DIR = P2DIR | LAUNCHPAD_GLED2; // Setting Launchpad GREEN_LED1 to an output

    // Launchpad LED2 Blue
    P2DIR = P2DIR | LAUNCHPAD_BLED2; // Setting Launchpad BLUE_LED1 to an output

    // Boosterpack LED Red
    P2DIR = P2DIR | BOOSTER_RLED; // Setting Booster RED_LED to an output

    // Boosterpack LED Green
    P2DIR = P2DIR | BOOSTER_GLED; // Setting Booster GREEN_LED to an output

    // Boosterpack LED Blue
    P5DIR = P5DIR | BOOSTER_BLED; // Setting Booster BLUE_LED to an output


    // Turn off all LEDs at the start.
    P1OUT = P1OUT & ~ LAUNCHPAD_LED1; // Turn OFF LED1
    P2OUT = P2OUT & ~ BOOSTER_RLED; // Turn OFF BLED’s red LED
    P2OUT = P2OUT & ~ BOOSTER_GLED; // Turn OFF BLED’s green LED
    P5OUT = P5OUT & ~ BOOSTER_BLED; // Turn OFF BLED’s blue LED
    P2OUT = P2OUT & ~ LAUNCHPAD_RLED2; // Turn OFF LED2’s red LED
    P2OUT = P2OUT & ~ LAUNCHPAD_GLED2; // Turn OFF LED2’s green LED
    P2OUT = P2OUT & ~ LAUNCHPAD_BLED2; // Turn OFF LED2’s blue LED

}

// TODO: Create a function to return the status of Launchpad Pushbutton S1
unsigned char checkStatus_LaunchpadS1()
{
    return (P1IN & LAUNCHPAD_S1);
}

// TODO: Create a function to return the status of Launchpad Pushbutton S2
unsigned char checkStatus_LaunchpadS2()
{
    return (P1IN & LAUNCHPAD_S2);
}

// TODO: Create a function to return the status of Boosterpack Pushbutton S1
unsigned char checkStatus_BoosterpackS1()
{
    return (P5IN & BOOSTER_S1);
}

// TODO: Create a function to return the status of Boosterpack Pushbutton S2
unsigned char checkStatus_BoosterpackS2()
{
    return (P3IN & BOOSTER_S2 );
}

// TODO: Create a function to turn on Launchpad LED1.
void turnOn_LaunchpadLED1()
{
    P1OUT = P1OUT | LAUNCHPAD_LED1; // Turn ON LED1

}

// TODO: Create a function to turn off Launchpad LED1.
void turnOff_LaunchpadLED1()
{
    P1OUT = P1OUT & ~ LAUNCHPAD_LED1; // Turn OFF LED1

}

// TODO: Create a function to turn on the Red Launchpad LED2.
void turnOn_LaunchpadLED2Red()
{
    P2OUT = P2OUT | LAUNCHPAD_RLED2; // Turn ON LED2’s red LED

}

// TODO: Create a function to turn off the Red Launchpad LED2.
void turnOff_LaunchpadLED2Red()
{
    P2OUT = P2OUT & ~ LAUNCHPAD_RLED2; // Turn OFF LED2’s red LED

}

// TODO: Create a function to turn on the Green Launchpad LED2.
void turnOn_LaunchpadLED2Green()
{
    P2OUT = P2OUT | LAUNCHPAD_GLED2; // Turn ON LED2’s green LED

}

// TODO: Create a function to turn off the Green Launchpad LED2.
void turnOff_LaunchpadLED2Green()
{
    P2OUT = P2OUT & ~ LAUNCHPAD_GLED2; // Turn OFF LED2’s green LED

}

// TODO: Create a function to turn on the Blue Launchpad LED2.
void turnOn_LaunchpadLED2Blue()
{
    P2OUT = P2OUT | LAUNCHPAD_BLED2; // Turn ON LED2’s blue LED

}

// TODO: Create a function to turn off the Blue Launchpad LED2.
void turnOff_LaunchpadLED2Blue()
{
    P2OUT = P2OUT & ~ LAUNCHPAD_BLED2; // Turn OFF LED2’s blue LED

}

// TODO: Create a function to turn on the Red Boosterpack LED2.
void turnOn_BoosterpackLEDRed()
{
    P2OUT = P2OUT | BOOSTER_RLED; // Turn ON BLED’s red LED

}

// TODO: Create a function to turn off the Red Boosterpack LED2.
void turnOff_BoosterpackLEDRed()
{
    P2OUT = P2OUT & ~ BOOSTER_RLED; // Turn OFF BLED’s red LED

}

// TODO: Create a function to turn on the Green Boosterpack LED2.
void turnOn_BoosterpackLEDGreen()
{
    P2OUT = P2OUT | BOOSTER_GLED; // Turn ON BLED’s green LED

}

// TODO: Create a function to turn off the Green Boosterpack LED2.
void turnOff_BoosterpackLEDGreen()
{
    P2OUT = P2OUT & ~ BOOSTER_GLED; // Turn OFF BLED’s green LED

}

// TODO: Create a function to turn on the Blue Boosterpack LED2.
void turnOn_BoosterpackLEDBlue()
{
    P5OUT = P5OUT | BOOSTER_BLED; // Turn ON BLED’s blue LED

}

// TODO: Create a function to turn off the Blue Boosterpack LED2.
void turnOff_BoosterpackLEDBlue()
{
    P5OUT = P5OUT & ~ BOOSTER_BLED; // Turn OFF BLED’s blue LED

}
