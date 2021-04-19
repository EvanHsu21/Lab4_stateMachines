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
	DDRC = 0xFF; PORTC = 0x00;
enum SM_STATES { SM_SMStart, SM_Lock, SM_Hash, SM_Wait, SM_Y, SM_Unlock } SM_STATE;
        void Tick_Toggle() {
                switch(SM_STATE) {
                        case SM_SMStart:
                                SM_STATE = SM_Lock;		
                                break;
                        case SM_Lock:
                                if (PINA == 0x04) {
					SM_STATE = SM_Hash;
				}
				else {
					SM_STATE = SM_Lock;
				}
                        break;
                        case SM_Hash:
				if (PINA == 0x00) {
                                	SM_STATE = SM_Wait;
				}
                        break;
                        case SM_Wait:
                                if (PINA == 0x02) {
					SM_STATE = SM_Y;
				}
				else {
					SM_STATE = SM_Lock;
				}	
                        break;
			case SM_Y:
				if (PINA == 0x00) {
					SM_STATE = SM_Unlock;
				}
			break;
			case SM_Unlock:
				if (PINA == 0x80) {
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
				PORTC = 0x00;
                               PORTB = 0x00;
                        break;
			case SM_Hash:
				PORTC = 0x01;
			break;
                        case SM_Wait:
				PORTC = 0x02;
                        break;
                       	case SM_Y:
				PORTC = 0x03;
			break;
			case SM_Unlock:
				PORTB = 0x01;
				PORTC = 0x04;
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
