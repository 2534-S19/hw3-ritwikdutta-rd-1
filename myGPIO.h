/*
 * myGPIO.h
 *
 *  Created on:
 *      Author:
 *
 */

#ifndef MYGPIO_H_
#define MYGPIO_H_

// This function initializes the peripherals used in the program.
void initGPIO();
// This function returns the value of Launchpad S1.
unsigned char checkStatus_LaunchpadS1();
// This function returns the value of Launchpad S2.
unsigned char checkStatus_LaunchpadS2();
// This function returns the value of Boosterpack S1.
unsigned char checkStatus_BoosterpackS1();
// This function returns the value of Boosterpack S2.
unsigned char checkStatus_BoosterpackS2();
// This function turns on Launchpad LED1.
void turnOn_LaunchpadLED1();
// This function turns off Launchpad LED1.
void turnOff_LaunchpadLED1();
// This function turns on Launchpad Red LED2.
void turnOn_LaunchpadLED2Red();
// This function turns off Launchpad Red LED2.
void turnOff_LaunchpadLED2Red();
// This function turns on Launchpad Blue LED2.
void turnOn_LaunchpadLED2Blue();
// This function turns off Launchpad Blue LED2.
void turnOff_LaunchpadLED2Blue();
// This function turns on Launchpad Green LED2.
void turnOn_LaunchpadLED2Green();
// This function turns off Launchpad Green LED2.
void turnOff_LaunchpadLED2Green();
// This function turns on Boosterpack Red LED.
void turnOn_BoosterpackLEDRed();
// This function turns off Boosterpack Red LED.
void turnOff_BoosterpackLEDRed();
// This function turns on Boosterpack Green LED.
void turnOn_BoosterpackLEDGreen();
// This function turns off Boosterpack Green LED.
void turnOff_BoosterpackLEDGreen();
// This function turns on Boosterpack Blue LED.
void turnOn_BoosterpackLEDBlue();
// This function turns off Boosterpack Blue LED.
void turnOff_BoosterpackLEDBlue();

// TODO: Define any constants that are local to myGPIO.c using #define

#define LAUNCHPAD_LED1 BIT0 // Assigning LED1 Pin to BIT 0 from P1.0
#define LAUNCHPAD_RLED2 BIT0 // Assigning RED_LED2 Pin to BIT 0 from P2.0
#define LAUNCHPAD_GLED2 BIT1 // Assigning GREEN_LED2 Pin to BIT 1 from P2.1
#define LAUNCHPAD_BLED2 BIT2 // Assigning BLUE_LED2 Pin to BIT 2 from P2.2
#define BOOSTER_RLED BIT6 // Assigning RED_BOOSTER_LED Pin to BIT 6 from P2.6
#define BOOSTER_BLED BIT6 // Assigning BLUE_BOOSTER_LED Pin to BIT 6 from P5.6
#define BOOSTER_GLED BIT4 // Assigning GREEN_BOOSTER_LED Pin to BIT 4 from P2.4
#define LAUNCHPAD_S1 BIT1 // Assigning LAUNCHPAD_S1 Pin to BIT 1 from P1.1
#define LAUNCHPAD_S2 BIT4 // Assigning LAUNCHPAD_S2 Pin to BIT 4 from P1.4
#define BOOSTER_S1 BIT1 // Assigning BOOSTER_S1 Pin to BIT 1 from P5.1
#define BOOSTER_S2 BIT5 // Assigning BOOSTER_S2 Pin to BIT 5 from P3.5

#endif /* MYGPIO_H_ */
