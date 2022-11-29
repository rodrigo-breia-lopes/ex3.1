//****************************************************************************//
//  MSP430 state machine
//  fsm.c
//
//  Describtion:
//    A simple state machine for the MSP430
//    Do not change code in here!!!
//
//  Generated with Excel Table
//  Date:  11/21/2022        Time:  16:40:41
//
//****************************************************************************//

#include <stdint.h>
#include <stdio.h>
#include "fsm.h"

//****************************************************************************//
// Global variables
//****************************************************************************//
uint8_t  ActState;

const FSM_STATE_TABLE StateTable [NR_STATES][NR_EVENTS] =
{
  FSM_state0_botao, STATE5, FSM_state0_timer, STATE1,
  FSM_state1_botao, STATE5, FSM_state1_timer, STATE2,
  FSM_state2_botao, STATE4, FSM_state2_timer, STATE3,
  FSM_state3_botao, STATE4, FSM_state3_timer, STATE0,
  NULL, STATE4, FSM_state4_timer, STATE3,
  NULL, STATE5, FSM_state5_timer, STATE4
};


//****************************************************************************//
// Initialize state machine
//****************************************************************************//
void FSM_Init (void)
{
  ActState = STATE0;
}


//****************************************************************************//
// Event function "botao"
//****************************************************************************//
void FSM_botao (void)
{
  if (StateTable[ActState][BOTAO].ptrFunct != NULL)
    StateTable[ActState][BOTAO].ptrFunct();

  ActState = StateTable[ActState][BOTAO].NextState;
}


//****************************************************************************//
// Event function "timer"
//****************************************************************************//
void FSM_timer (void)
{
  if (StateTable[ActState][TIMER].ptrFunct != NULL)
    StateTable[ActState][TIMER].ptrFunct();

  ActState = StateTable[ActState][TIMER].NextState;
}


//****************************************************************************//
