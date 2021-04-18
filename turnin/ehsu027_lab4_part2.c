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
enum SM_STATES { SM_SMStart, SM_Inc, SM_Wait, SM_Dec, SM_Both } SM_STATE;
        void Tick_Toggle() {
                switch(SM_STATE) {
                        case SM_SMStart:
                                if (PINA == 0x01) {
					SM_STATE = SM_Inc;
				}
				else if (PINA == 0x02) {
					SM_STATE = SM_Dec;
				}
				else if (PINA == 0x03) {
					SM_STATE = SM_Both;
				}
				else {
					SM_STATE = SM_SMStart;
				}		
                                break;
                        case SM_Inc:
                                if (PINA == 0x00) {
					SM_STATE = SM_Wait;
				}
                        break;
                        case SM_Wait:
                                
				if (PINA == 0x01) {
                                        SM_STATE = SM_Inc;
                                }
                                else if (PINA == 0x02) {
                                        SM_STATE = SM_Dec;
                                }
                               	else if (PINA == 0x03) {
                                        SM_STATE = SM_Both;
                                }
				

                        break;
                        case SM_Dec:
                                if (PINA == 0x00) {
					SM_STATE = SM_Wait;
				}
                        break;
			case SM_Both:
				if (PINA == 0x00) {
					SM_STATE = SM_Wait;
				}
			break;
				
                        default:
                                SM_STATE = SM_SMStart;
                        break;
}

                switch(SM_STATE) {
                        case SM_SMStart:
				PORTC = 0x07;
                        break;
                        case SM_Inc:
                                PORTC++;
                        break;
			case SM_Wait:
			break;
                        case SM_Dec:
				if (PORTC != 0x00) {
                                	PORTC--;
				}
                        break;
                       	case SM_Both:
				PORTC = 0x00;
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
