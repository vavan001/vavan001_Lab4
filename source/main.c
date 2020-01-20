/*	Author: vavan001
 *  Partner(s) Name: 
 *	Lab Section:23
 *	Assignment: Lab #4  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum States { start, s0, s0_b, s1, s1_b} state;

int main(void) {
DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x01;
	state = start;
	while(1) {
		tick();
	};	
    return 1;
}
void tick() {
	switch(state) {
case start:
	state = s0;
	break;
case s0:
  if((PINA & 0x01) == 0x01) {
     state = s0_b;
	} 
          else {
            state = s0;
		}
	break;
case s0_b:
	if((PINA & 0x01) == 0x01) {
		state = s0_b;
			}
         else {
	  state = s1;
		}
	break;
case s1:
	if((PINA & 0x01) == 0x01) {
	     state = s1_b;
			}
        else {
	 state = s1;	
		}
	break;
case s1_b:
			
      if((PINA & 0x01) == 0x01) {
		state = s1_b;
			} 
      else {
	state = s0;
	     }
      break;
	}
switch(state) {

case start:
case s0: break;
case s1_b:
	PORTB = 0x01;
		break;
case s0_b: PORTB = 0x02;
case s1: break;
default:
			break;
	}
}

