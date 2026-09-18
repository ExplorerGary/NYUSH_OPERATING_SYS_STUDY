#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>


int main(int argc, char **argv){
    // iteravtive create a main process and a lots of child process of this parent process
    int N_CHILDREN =atoi(argv[1]); // this is a var to determind how mand child process is needed
    int i;
    for (i = 0; i < N_CHILDREN; i++){
        // create a child process'
        pid_t pid = fork();
        if (pid == 0){
            // we are in the child, end it
            exit(EXIT_SUCCESS);
        }
        // we are in the parent, continue to create more child process.
        // nothing to be done here.
    }
}
