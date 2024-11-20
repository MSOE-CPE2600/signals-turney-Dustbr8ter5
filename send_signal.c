/**
 * File: send_signal.c
 * Modified by: Vincent Vassallo
 * 
 * Brief summary of program: Scans in a user inputted PID, sets the value to send
 * to a random integer, and uses sigqueue to send the value to the user inputted pid.
 */
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char* argv[]) {
    union sigval value;
    int pid;
    //Get pid of running process
    printf("Enter pid:\n");
    scanf("%d", &pid);
    //Seed random
    srand(time(NULL));
    //Set sival to a random number
    value.sival_int = rand();
    printf("Value to be sent: %d \n", value.sival_int);
    //Send SIGUSR1 and the random value to pid
    if(sigqueue(pid, SIGUSR1, value) == -1) {
        perror("Sigqueue Failure\n");
        exit(1);
    }
    return 0;
}