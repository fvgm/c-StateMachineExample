/*
This implements a simple Finite State Machine originally by
J.L. Garbini (see http://courses.washington.edu/mengr477/resources/StateMachine.pdf)
Actually it represents all the stages of a simple washing machine for educational purposes.

Licensed under the MIT License <http://opensource.org/licenses/MIT>.
SPDX-License-Identifier: MIT
Copyright (c) 2019-2022 Fernando Magro and other contributors.

Permission is hereby  granted, free of charge, to any  person obtaining a copy
of this software and associated  documentation files (the "Software"), to deal
in the Software  without restriction, including without  limitation the rights
to  use, copy,  modify, merge,  publish, distribute,  sublicense, and/or  sell
copies  of  the Software,  and  to  permit persons  to  whom  the Software  is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE  IS PROVIDED "AS  IS", WITHOUT WARRANTY  OF ANY KIND,  EXPRESS OR
IMPLIED,  INCLUDING BUT  NOT  LIMITED TO  THE  WARRANTIES OF  MERCHANTABILITY,
FITNESS FOR  A PARTICULAR PURPOSE AND  NONINFRINGEMENT. IN NO EVENT  SHALL THE
AUTHORS  OR COPYRIGHT  HOLDERS  BE  LIABLE FOR  ANY  CLAIM,  DAMAGES OR  OTHER
LIABILITY, WHETHER IN AN ACTION OF  CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE  OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

/* Prototypes */
void initializeSM(void);
void runSM(void);
void washState(void);
void rinseState(void);
void spinState(void);
void FinishState(void);

/* Define an enumerated types for states */
typedef enum {
    WASH_STATE,
    RINSE_STATE,
    SPIN_STATE,
    FINISH_STATE
} State_Type; // define a new data type

/* Define a table of pointers to named functions for each state */
static void (*state_table[])(void) = {
    washState,
    rinseState,
    spinState,
    FinishState
};

/* Global declarations */
static State_Type curr_state;

int main() {
    initializeSM();

    while(1) {
        runSM();
    }
}

void washState(void) {
    // do some stuff
    printf("\n(%d) - This is the first state - washing.\n", curr_state);
    printf("Fill the machine to certain water level, dispense any chemical from dispenser,\n");
    printf("agitate the load for a certain amount of time and drain the water.\n");

    // go to next state
    curr_state = RINSE_STATE;
}

void rinseState(void) {
    printf("\n(%d) - This is the second state - rinsing.\n", curr_state);
    printf("Fill the machine to certain water level, agitate the load for a certain amount of time\n");
    printf("and drain the water.\n");

    // go to next state
    curr_state = SPIN_STATE;
}

void spinState(void) {
    printf("\n(%d) - This is the third state - spinning.\n", curr_state);
    printf("Spin the basket rapidly for a certain amount of time with the drain open so most\n");
    printf("remaining water is removed by the centrifugal force.\n");

    // go to next state
    curr_state = FINISH_STATE;
}

void FinishState(void) {
    // actions to do at the end of cycle.
    printf("\n(%d) - We finished the entire cycle.\n", curr_state);
    printf("Trigger an audible alarm.\n");
    exit(0);
}

void initializeSM(void) {
    // do some stuff before start the cycle
    // configure I/O, etc.
    printf("\nThis is the initialization state.\n");
    printf("Verifying the pressure of inlet water source.\n");
    printf("Checking if the door is safely closed.\n");
    printf("OK.\n");

    // go to first state
    curr_state = WASH_STATE;
}

void runSM(void) {
    state_table[curr_state]();
}
