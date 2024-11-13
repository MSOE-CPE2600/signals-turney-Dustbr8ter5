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
    printf("Alarm recieved...\n");
    exit(1);
}

int main() {
    signal(SIGALRM, handle);
    alarm(5);
        int i = 0;
    while(1) {
        i++;
    }
    return i;
}