/**
 * File: recv_signal
 * Modified by: Vincent Vassallo
 * 
 * Brief summary of program:
 */
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

void handler(int signo, siginfo_t *info, void *context) {
    //Get sival
    
    printf("Signal value: %d\n", info->si_value.sival_int);
    //"Return"
    exit(1);
}

int main() {
    
    //Create struct to hold data
    struct sigaction new_action;
    //Set the struct to the handler
    new_action.sa_sigaction = handler;
    //Set the flag to save the data
    new_action.sa_flags = SA_SIGINFO;
    //Register for signal
    sigaction(SIGUSR1, &new_action, NULL);
    //wait for the child to send signal
    while(1);
    return 0;
}