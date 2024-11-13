/**
 * File: signal_sigaction.c
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
    int pid = info->si_pid;
    printf("Signal origin pid: %d\n", pid);
}
int main() {
    int pid = fork();
    if(pid == 0) {
        //Child
        kill(getppid(), SIGUSR1);
        printf("Child Done\n");

    } else {
        struct sigaction new_action;
        new_action.sa_sigaction = handler;
        new_action.sa_flags = SA_SIGINFO;
        sigaction(SIGUSR1, &new_action, NULL);
        wait(NULL);
        printf("Parent Done\n");
        
    }
    return 0;
}


