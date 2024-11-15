/**
 * File: send_signal.c
 * Modified by: Vincent Vassallo
 * 
 * Brief summary of program:
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
    //Send SIGUSR1 and the random value to pid
    if(sigqueue(pid, SIGUSR1, value) == -1) {
        perror("Sigqueue Failure\n");
        exit(1);
    }
    return 0;
}