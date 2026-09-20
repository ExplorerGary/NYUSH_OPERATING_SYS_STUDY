#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

// init process wait until the end of all process in the chain

int main() {
    int N = 3;

    for (int i = 0; i < N; i++) {
        pid_t pid = fork();

        if (pid < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (pid > 0) {
            waitpid(pid, NULL, 0); // wait for the child process to finish        
            exit(EXIT_SUCCESS);
        }

        // only child reaches here and continues the loop
    }

    return 0;
}