#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

// init process wait until the end of his child

int main() {
    int N = 3;

    for (int i = 0; i < N; i++) {
        pid_t pid = fork();

        if (pid < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (pid > 0) {
            // we are in the parent process, wait for the child process to finish
            // check if the first child created or in other words, the init processm , if yes, then wait, else, go on
            if (i == 0){
                waitpid(pid, NULL, 0); // wait for the first child process to finish
            }
        
            exit(EXIT_SUCCESS); // exit the parent process after waiting for the first child
        }

        // only child reaches here and continues the loop
    }


    return 0;
}



