#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>




// OK, this program will do the parallel compiling
int main(int argc, char *argv[]){
    // expected calling: $ ./parallel_compiler main.c titi.c tata.c toto.c
    // so we will start at argv[1] as the first one
    int i; // use a for loop to iterate through the arguments
    pid_t *pids = malloc(sizeof(pid_t) * (argc - 1)); // allocate an array to store the pids of the child processes

    // make a list to hold the expected .o file names
    char **expected_o_files = malloc(sizeof(char*) * (argc - 1));
    // iterate through the arg list and convert the .c file names to .o file names
    for(i = 1; i < argc; i++){
        // allocate memory for the expected .o file name
        expected_o_files[i - 1] = malloc(sizeof(char) * (strlen(argv[i]) + 2)); // +2 for the .o and the null terminator
        // copy the .c file name to the expected .o file name
        strcpy(expected_o_files[i - 1], argv[i]);
        // replace the last two characters with .o
        expected_o_files[i - 1][strlen(argv[i]) - 1] = 'o';
        expected_o_files[i - 1][strlen(argv[i])] = '\0'; // add the null terminator
    }

    // OK, make a valid args list for the final linking gcc command
    char **linking_args = malloc(sizeof(char*) * (argc + 2)); // +2 for the gcc and the null terminator
    linking_args[0] = "gcc"; // first argument is gcc
    linking_args[argc] = NULL; // last argument is NULL
    // populate the linking args with the .o file names
    for(i = 1; i < argc; i++){
        linking_args[i] = expected_o_files[i - 1];
    }


    for(i = 1; i < argc; i++){
        pid_t pid = fork(); // create a child process
        // make sure that our fork was successful
        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        }
        // put the pid in the array
        pids[i - 1] = pid; // will talk about this later
        if(pid == 0){ // this is the child process
            // execute the command
            execlp("gcc", "gcc", "-c", argv[i], NULL); // compile the file
            // if execlp returns, it means there was an error
            perror("execlp");
            exit(EXIT_FAILURE); // exit the child process
        }

    }
    // here is the parent process area.
    // wait for all child process to exit successfully
    for(i = 0; i < argc - 1; i++){
        int status;
        waitpid(pids[i], &status, 0); // wait for the child process to exit
        
        if (!WIFEXITED(status)) {
            fprintf(stderr, "Child process %d did not exit normally\n", pids[i]);
            exit(EXIT_FAILURE);
        }
        
        if (WEXITSTATUS(status) != 0) {
            fprintf(stderr, "Child process %d exited with status %d\n",
                    pids[i], WEXITSTATUS(status));
            exit(EXIT_FAILURE);
        }

    }

    // now we can link the .o files together
    // run the linking command
    execvp("gcc", linking_args); // link the .o files together
    // if execvp returns, it means there was an error
    perror("execvp");
    exit(EXIT_FAILURE); // exit the parent process
}