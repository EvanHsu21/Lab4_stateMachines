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
        enum SM_STATES { SM_SMStart, SM_PB0, SM_Wait, SM_PB1 } SM_STATE;
        void Tick_Toggle() {
                switch(SM_STATE) {
                        case SM_SMStart:
                                SM_STATE = SM_PB0;
                                break;
                        case SM_PB0:
                                if (PINA & 0x01) {
                                        SM_STATE = SM_PB1;
                                }
                                else {
                                        SM_STATE = SM_PB0;
                                }
                        break;
                        case SM_PB1:
                                SM_STATE = SM_Wait;
                        break;
                        case SM_Wait:
                                if (PINA & 0x01) {
                                        SM_STATE = SM_PB0;
                                }
                                else {
                                        SM_STATE = SM_PB1;
                                }
                        break;
                        default:
                                SM_STATE = SM_PB0;
                        break;
}

                switch(SM_STATE) {
                        case SM_SMStart:
                        break;
                        case SM_PB0:
                                PORTB = 0x01;
                        break;
                        case SM_PB1:
                                PORTB = 0x02;
                        break;
                        case SM_Wait:
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
