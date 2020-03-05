#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "homework3.h"
#include "myGPIO.h"
#include "myTimer.h"


typedef enum {Stable_P,  Stable_R} debounce_state_t; //Enum which stores the values of Stable_P and Stable_R

int main(void)
{
    // Count variables to control the LEDs.
    unsigned int count0 = 0;
    unsigned int count1 = 0;

    // TODO: Declare the variables that main uses to interact with your state machine.
    unsigned char buttonhistory;

    // Stops the Watchdog timer.
    initBoard();
    // Initialize the GPIO.
    // YOU MUST WRITE THIS FUNCTION IN myGPIO.c
    initGPIO();
    // Initialize Timer0 to provide a one second count interval for updating LED2.
    // YOU MUST WRITE THIS FUNCTION IN myTimer.c
    initTimer(TIMER32_0_BASE, TIMER0_PRESCALER, TIMER0_COUNT);
    // Initialize Timer1 to provide a one millisecond count interval for updating the button history.
    // YOU MUST WRITE THIS FUNCTION IN myTimer.c
    initTimer(TIMER32_1_BASE, TIMER1_PRESCALER, TIMER1_COUNT);

    while(1)
    {
        // Update the color of LED2 using count0 as the index.
        // YOU MUST WRITE THIS FUNCTION BELOW.
        changeLaunchpadLED2(count0);
        // Update the color of the Boosterpack LED using count1 as the index.
        // YOU MUST WRITE THIS FUNCTION BELOW.
        changeBoosterpackLED(count1);

        // TODO: If Timer0 has expired, increment count0.
        // YOU MUST WRITE timer0expired IN myTimer.c
        if (timer0Expired())
        {
            count0=count0+1;
        }


        // TODO: If Timer1 has expired, update the button history from the pushbutton value.
        // YOU MUST WRITE timer1expired IN myTimer.c
        if(timer1Expired())
        {
           buttonhistory = checkStatus_BoosterpackS1();


        // TODO: Call the button state machine function to check for a completed, debounced button press.
        // YOU MUST WRITE THIS FUNCTION BELOW.
           if(fsmBoosterpackButtonS1(buttonhistory))
           {

        // TODO: If a completed, debounced button press has occurred, increment count1.

            count1=count1+1;
      }
    }
    }
}

void initBoard()
{
    WDT_A_hold(WDT_A_BASE);
}

// TODO: Map the value of a count variable to a color for LED2.
// Since count is an unsigned integer, you can mask the value in some way.
void changeLaunchpadLED2(unsigned int count)
{
    if (count&BIT0) //configuring BIT0 to RED LED, BIT1 to GREEN LED and BIT2 to BLUE LED, so that whenever the counter counts, it can call upon
                    //those LED's to light up whose bit manipulation are TRUE.
    {
        turnOn_LaunchpadLED2Red();

    }
    else if (count&BIT1)
    {

        turnOff_LaunchpadLED2Red();
        turnOn_LaunchpadLED2Green();
    }

    else if (count&BIT2)
    {
        turnOff_LaunchpadLED2Red();
        turnOff_LaunchpadLED2Green();
        turnOn_LaunchpadLED2Blue();
    }
   else
    {
        turnOff_LaunchpadLED2Red();
        turnOff_LaunchpadLED2Green();
        turnOff_LaunchpadLED2Blue();
    }
}

// TODO: Maybe the value of a count variable to a color for the Boosterpack LED
// This is essentially a copy of the previous function, using a different LED
void changeBoosterpackLED(unsigned int count)
{

    if (count&BIT0)//configuring BIT0 to RED LED, BIT1 to GREEN LED and BIT2 to BLUE LED, so that whenever the counter counts, it can call upon
                   //those LED's to light up whose bit manipulation are TRUE.
    {
        turnOn_BoosterpackLEDRed();
    }
    else if (count&BIT1)
    {
        turnOff_BoosterpackLEDRed();
        turnOn_BoosterpackLEDGreen();
    }
    else if (count&BIT2)
    {
        turnOff_BoosterpackLEDRed();
        turnOff_BoosterpackLEDGreen();
        turnOn_BoosterpackLEDBlue();
    }
   else
    {
        turnOff_BoosterpackLEDRed();
        turnOff_BoosterpackLEDGreen();
        turnOff_BoosterpackLEDBlue();
    }
}

// TODO: Create a button state machine.
// The button state machine should return true or false to indicate a completed, debounced button press.
bool fsmBoosterpackButtonS1(unsigned char buttonhistory)
{
    bool pressed = false; // The default value of the returned value

    char current_status;
    static char previous_status = RELEASED;

    static debounce_state_t debounce_state = Stable_R;

    // outputs of the FSM
    bool debouncedButtonStatus;


    switch (debounce_state)
    {
    case Stable_P:
        debouncedButtonStatus = PRESSED; //The current status of the button
        if (buttonhistory != PRESSED) //if button is not pressed, change state to button RELEASED
        {
            // Change state
            debounce_state = Stable_R;

        }

        break;

    case Stable_R:
        debouncedButtonStatus = RELEASED; //The current status of the button
        if (buttonhistory == PRESSED) ////if button is pressed, change state to button PRESSED
        {
            // Change state
            debounce_state = Stable_P;

        }
      break;

    }

    // This state machine will call the push-button machine
    current_status = debouncedButtonStatus;
    if ((current_status == PRESSED) && (previous_status == RELEASED)) //Compares if the button is PRESSED or RELEASED by comparing the previous
                                                                      //and current status
        pressed = true; //Indicates a completed, debounced button press.
    previous_status = current_status; //Changing the current status to the previous status

    return pressed;
}
