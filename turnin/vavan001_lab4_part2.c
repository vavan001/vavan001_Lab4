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

enum States { start, s0, inc, dec} state;

void tick() {
	switch(state) {
case start:
state = s0;
PORTC = 0x07;
break;

case s0: 
	if((PINA & 0x0F) == 0x01) {
		state = inc;
	if(PORTC < 9) PORTC++;
			} 
        else if((PINA & 0x0F) == 0x02){
		state = dec;
	if(PORTC != 0) PORTC--;
			}
        else if((PINA & 0x0F) == 0x03){
		state = s0;
		PORTC = 0;
			} 
        else {
		state = s0;
			}
		break;
case inc:
       if((PINA & 0x0F) == 0x01) {
		state = inc;
			} 
      else if((PINA & 0x0F) == 0x00){
		state = s0;
			} 
      else if((PINA & 0x0F) == 0x03) {
		state = s0;
		PORTC = 0;
			}
			break;
case dec:
	if((PINA & 0x0F) == 0x02) {
		state = dec;
			} 
        else if((PINA & 0x00F) == 0x00){
		state = s0;	
			} 
        else if((PINA & 0x0F) == 0x03){
		state = s0;
		PORTC = 0;
			}
			break;
		break;
	}
switch(state) {
case start:
case s0:
case dec:
case inc:
default:
break;
	}
}


int main(void) {
DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0x07;
	state = start;
	while(1) {
		tick();
	};	
    return 1;
}
