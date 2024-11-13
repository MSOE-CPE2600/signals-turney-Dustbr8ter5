/**
 * File: signal_alarm.c
 * Modified by: Vincent Vassallo
 * 
 * Brief summary of program: The program waits for a 5 second alarm in
 * an infinite loop, it then catches the alarm signal and exits
 */
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
void handle() {
    printf("Alarm received...\n");
    exit(1);
}

int main() {
    //Register for the signal
    signal(SIGALRM, handle);
    //Start timer for alarm
    alarm(5);
    //Hold the program while the alarm counts down
    int i = 0;
    while(1) {
        i++; //i is there so the loop is not empty
    }
    return i;
}