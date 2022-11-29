//****************************************************************************//
//  MSP430 state machine
//  fsm.h
//
//  Describtion:
//    A simple state machine for the MSP430
//
//  Generated with Excel Table
//  Date:  11/21/2022        Time:  16:40:42
//
//****************************************************************************//

#ifndef FSM_H
#define FSM_H

#include <stdint.h>
#include <stdio.h>

//****************************************************************************//
// State table typedef
//****************************************************************************//
typedef struct
{
  void (*ptrFunct) (void);
  uint8_t NextState;
} FSM_STATE_TABLE;

extern uint8_t ActState;


#define NR_EVENTS 2
#define BOTAO  0
#define TIMER  1

#define NR_STATES 6
#define STATE0  0
#define STATE1  1
#define STATE2  2
#define STATE3  3
#define STATE4  4
#define STATE5  5


//****************************************************************************//
// Function prototypes
//****************************************************************************//
// Initialize state machine
void FSM_Init (void);

// Event function "botao"
void FSM_botao (void);

// Event function "timer"
void FSM_timer (void);

// Transition function "state0_botao"
void FSM_state0_botao (void);

// Transition function "state0_timer"
void FSM_state0_timer (void);

// Transition function "state1_botao"
void FSM_state1_botao (void);

// Transition function "state1_timer"
void FSM_state1_timer (void);

// Transition function "state2_botao"
void FSM_state2_botao (void);

// Transition function "state2_timer"
void FSM_state2_timer (void);

// Transition function "state3_botao"
void FSM_state3_botao (void);

// Transition function "state3_timer"
void FSM_state3_timer (void);

// Transition function "state4_timer"
void FSM_state4_timer (void);

// Transition function "state5_timer"
void FSM_state5_timer (void);


//****************************************************************************//

#endif /* FSM_H */

//****************************************************************************//
