#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


// the parent process wait for the last child to finish.

int main(int argc, char **argv){
    // iteravtive create a main process and a lots of child process of this parent process

    int N_CHILDREN =atoi(argv[1]); // as noted in the office hour, we will consider the N_CHILDREN obtained from the argv
    
    int i;
    pid_t last_pid = -1;

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
        last_pid = pid; // update the last_pid to the current child process id
    }

    // after the iteration, the last_pid will be the last child process id, we will wait for it to finish
    waitpid(last_pid, NULL, 0); // wait for the last child process to finish

}
