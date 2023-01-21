#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

/* Prototypes */
void initializeSM(void);
void runSM(void);
void stateA(void);
void stateB(void);
void stateC(void);
void stateFinish(void);

/* Define an enumerated types for states */
typedef enum {
    STATE_A,
    STATE_B,
    STATE_C,
    STATE_FINISH
    } State_Type; // define a new data type

/* Define a table of pointers to named functions for each state */
static void (*state_table[])(void) = {
    stateA,
    stateB,
    stateC,
    stateFinish
    };

/* Global declarations */
static State_Type curr_state;

enum {
    HALF_STEP_MODE,
    WAVE_DRIVE,
    NORMAL_MODE
    } Operating_Mode;

int main() {
    initializeSM();

    while(1) {
        runSM();
    }
}

void stateA(void) {
    printf("We are at STATE_A (%d).\n", curr_state);
    curr_state = STATE_B;
}

void stateB(void) {
    printf("We are at STATE_B (%d).\n", curr_state);
    curr_state = STATE_C;
}

void stateC(void) {
    printf("We are at STATE_C (%d).\n", curr_state);
    curr_state = STATE_FINISH;
}

void stateFinish(void) {
    printf("We finished at STATE_FINISH. (%d).\n", curr_state);
    exit(0);
}

void initializeSM(void) {
    curr_state = STATE_A;
}

void runSM(void) {
    state_table[curr_state]();
}
