#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

pid_t child_process_creator(int to_create){
    // this is a recursive function to create child processes for the main process
    // returns the pid of the last created child process.
    if (to_create == 1){
        // OK, this is the last one to create
        pid_t pid = fork();
        if (pid < 0){
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (pid == 0){
            // we are in the child, just quit.
            exit(EXIT_SUCCESS);
        }

        // we are in the parent, just return
        return pid;
    }


    // recursion part:
    pid_t pid = fork();
    if (pid < 0) {
    perror("fork");
    exit(EXIT_FAILURE);
    }
    if (pid == 0){
        // we are in the child, just quit.
        exit(EXIT_SUCCESS);
    }
    return child_process_creator(to_create - 1);
}

int main(int argc, char **argv){
    // recursively create a lot of child processes of the main process
    int N_CHILDREN =atoi(argv[1]); // as noted in the office hour, we will consider the N_CHILDREN obtained from the argv
    pid_t pid = child_process_creator(N_CHILDREN); // recursively create a lot of child processes of the main process
}
