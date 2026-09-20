#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    int N = 3;

    for (int i = 0; i < N; i++) {
        pid_t pid = fork();

        if (pid < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (pid > 0) {
            // parent stops creating more children
            break;
        }

        // only child reaches here and continues the loop
    }


    return 0;
}


