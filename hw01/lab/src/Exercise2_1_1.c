#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// the parent process wait for any child process to finish.

int main(int argc, char **argv){
    // iteravtive create a main process and a lots of child process of this parent process

    int N_CHILDREN =atoi(argv[1]); // as noted in the office hour, we will consider the N_CHILDREN obtained from the argv
    
    int i;
    for (i = 0; i < N_CHILDREN; i++){
        // create a child process'
        pid_t pid = fork();
        if (pid < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        }
        if (pid == 0){
            // we are in the child, end it
            exit(EXIT_SUCCESS);
        }
        // we are in the parent, continue to create more child process.
        // nothing to be done here.
    }
    wait(NULL); // wait for any child process to finish
}
