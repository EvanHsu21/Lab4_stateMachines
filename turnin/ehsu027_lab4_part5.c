/*	Author: ehsu027
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0x00;
	DDRB = 0xFF; PORTB = 0x00;
	DDRC = 0x0F; PORTC = 0x00;
	unsigned char i = 0;
	char combination[4];
	combination[0] = 0x04;
	combination[1] = 0x01;
	combination[2] = 0x02;
	combination[3] = 0x01;
enum SM_STATES { SM_SMStart, SM_Lock, SM_Reset, SM_Continue, SM_Unlock } SM_STATE;
        void Tick_Toggle() {
                switch(SM_STATE) {
                        case SM_SMStart:
                                SM_STATE = SM_Lock;		
                                break;
                        case SM_Lock:
				if (PINA == sequence[i]) {
					PORTC = i;
					if (i < 3) {
						SM_STATE = SM_Continue;
					}
					else if (i == 3) {
						SM_STATE = SM_Unlock;
					}
				}
				else if (PINA) {
					SM_State = SM_Reset;
					i = 0;
				}
                        break;
			case SM_Continue:
				if (PINA == 0x00) {
					i++;
					SM_STATE = SM_Lock;
				}
			break;
			
			case SM_Reset:
				if (PINA == 0x00) {
					SM_STATE = SM_Lock;
				}
			break;
				
			case SM_Unlock:
				if (PINA == 0x80) {
					PORTB = 0x00;
					SM_STATE = SM_Lock;
				}
				else if (PINA == sequence[0]) {
					SM_STATE = SM_Lock;
				}
			break;
				
                        default:
                                SM_STATE = SM_SMStart;
                        break;
}

                switch(SM_STATE) {
                        case SM_SMStart:
                        break;
                        case SM_Lock:
			break;
			case SM_Continue:
			break;
			case SM_Reset:
				PORTB = 0x00;
			break;
			case SM_Unlock:
				if (PORTB == 0x00) {
					PORTB = 0x01;
				}
				else if (PORTB == 0x01) {
					PORTB = 0x00;
				}
			break;
			
}
}
SM_STATE = SM_SMStart;

    /* Insert your solution below */
    while (1) {
	Tick_Toggle();			
    }
    return 1;
}
