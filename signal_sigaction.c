/**
 * File: signal_sigaction.c
 * Modified by: Vincent Vassallo
 * 
 * Brief summary of program: The program forks and uses a child to pass
 * the SIGUSR1 signal to the parent which then is caught by the handler
 */
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

void handler(int signo, siginfo_t *info, void *context) {
    int pid = info->si_pid;
    printf("Signal origin pid: %d\n", pid);
}
int main() {
    int pid = fork();
    if(pid == 0) {
        //Child
        //Send Signal
        kill(getppid(), SIGUSR1);
        printf("Child Done\n");

    } else {
        //Create struct to hold data
        struct sigaction new_action;
        //Set the struct to the handler
        new_action.sa_sigaction = handler;
        //Set the flag to save the data
        new_action.sa_flags = SA_SIGINFO;
        //Register for signal
        sigaction(SIGUSR1, &new_action, NULL);
        //wait for the child to send signal
        wait(NULL);
        printf("Parent Done\n");
        
    }
    return 0;
}


