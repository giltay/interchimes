/* Primes
 * For Arduino Uno.
 * Written by Geoffrey Gilmour-Taylor, 2016.
 * This work is in the public domain.
 * 
 * Circuit diagram for this project at
 * http://www.sunfounder.com/index.php?c=case_incs&a=detail_&id=163&name=Starter%20Kit%20For%20Arduino&zsid=91
 * but it's basically just 8 LEDs connected to D2 through D9.
 */

/**************************************/
const int lowestPin = 2; // The lowest bit
const int highestPin = 9; // The highest bit
/**************************************/

void setup()
{
    for(int thisPin = lowestPin; thisPin <= highestPin; thisPin++)
        pinMode(thisPin, OUTPUT); // Initialize thisPin as an output
}
/****************************************/

/* Display an integer from 0 to 255 as binary */
void bin_display(int n)
{
    int b, c, thisPin;
    for (c = 0; c < 8; c++)
    {
        b = n >> c;
        thisPin = c + lowestPin;
        if (b & 1)
            digitalWrite(thisPin, HIGH);
        else
            digitalWrite(thisPin, LOW);
    }
}

/* Main loop:
 * Display all prime numbers < 256
 * then clear the LEDs and pause.
 */
void loop()
{
    // Calculate primes less than 256
    int n, i, c;
    for (i = 2; i < 256 ; i++)
    {
        // Stop if there are any divisors
        for (c = 2; c < i; c++)
            if (i%c == 0)
                break;
        // If we go through the loop without stopping,
        // then c == i and we have a prime. Display it.
        if (c == i)
        {
            bin_display(i);
            delay(500);
        }
    }
    // Clear all LEDs
    for (int thisPin = lowestPin; thisPin <= highestPin; thisPin++)
        digitalWrite(thisPin, LOW);
    // Wait
    delay(1000);
}
