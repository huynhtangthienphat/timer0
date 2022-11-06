#include "Arduino.h"
/*
 * Demo program to show Timer Interrupts using 8-bit Timer 2
 *
 * See www.youtube.com/ralphbacon video #209
 */

void setup()
{
  Serial.begin(9600);
 

  // Initialise timer/counter to known value
  TCCR2A = 0;

  // Enable interrupts on overflow by adjusting pins 2:0
  // Set the Timer 2 Interrupt Mask Register so that
  // we enable to overflow interrupt TOIE2 (Timer 2 Overflow Interrupt Enable)
  // AND when the values match two values (comparators OCIE2A & OCIE2B) we
  // trigger two further, independent interrupts.
  TIMSK2 = ((1 << TOIE2) | (1 << OCIE2A) | (1 << OCIE2B));

  // What values do want to compare against?
  OCR2A = 42;
  OCR2B = 99;

  // Set prescaler (divide by) on the clock ticks for 16MHz clock
  /* For Timer 2 the options for are:
   *  111 divide by 1024  = 15.625kHz = 64uS
   *  110 divide by 256   = 62.5kHz   = 16uS
   *  101 divide by 126   = 125kHz    = 8
   *  100 divide by 64    = 250kHZ    = 4
   *  011 divide by 32    = 500kHz    = 2
   *  010 divide by 8     = 2MHz      = 0.5
   *  001 divide by 1     = 16MHz     = 0.0625 uS
   *  000 timer disabled
   *
   *  the CSnn are the Clock Source prescaler TTCRnB bits we are setting
   */
  //TCCR2B = ((1 << CS22) | (1 << CS21) | (1 << CS20));
  // or
  //TCCR2B |= 0b00000111;
  // or
  TCCR2B = _BV(CS22) | _BV(CS21) | _BV(CS20);

  // Datasheet says to set pin mode AFTER timer registers set
  //pinMode(13, OUTPUT);
  //pinMode(10, OUTPUT);
  //pinMode(8, OUTPUT);
  // or
  DDRB |= 0b00100101;

  // All done here
  Serial.println("Set up completed");
}

// Loop does nothing to affect the timers but not so the reverse
void loop()
{
  // Some nonsense counter here just to prove it runs

  
}

// Overflow interrupt handler
ISR(TIMER2_OVF_vect) {
  
}

// Comparator A for Timer 2
ISR(TIMER2_COMPA_vect) {
 
}
// Comparator B for Timer 2
ISR(TIMER2_COMPB_vect) {
 Serial.println("phatcuto");
 
}
