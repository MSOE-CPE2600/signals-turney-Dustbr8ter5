/**
 * @file signal_segfault.c
 * @brief Program that dereferences a null pointer causing a segmentation fault
 */

/**
 * Modified by: Vincent Vassallo
 * 
 * Brief summary of modifications: Installed a handler function and signal() in main
 */


#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void handler() {
    printf("Received segmentation fault...");
}
int main (int argc, char* argv[]) {
    //Resister for signal
    signal(SIGSEGV, handler);
    // Declare a null pointer
    int* i = NULL;

    // Dereference the null pointer
    printf("The value of i is: %d\n", *i);

    // Return to exit the program
    return 0;
}