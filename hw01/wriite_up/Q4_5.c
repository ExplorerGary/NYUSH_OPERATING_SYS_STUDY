#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// file name : prog
// however, this prog will take one more argument, which is the count of previous launch.
// we will do so by a char of "0" , "1", and "2"
// because the limit is at most 2 B, it is still acceptable
// the initial B_count will be "0"

int main(int argc, char *argv[]) {
    int rcode;
    char B_cont = '0';
    if (argc > 1) {
        B_cont = argv[1][0];
        }

    printf("%s\n", argv[0]);   // A

    if (B_cont != '2') {
        // can do the creation of B, because the limit is not reached yet
        switch (fork()) {

        case -1:
            perror("fork1()");
            exit(EXIT_FAILURE);

        case 0:   // B
            switch (B_cont){
                case '0':
                    B_cont = '1';
                    break;
                case '1':
                    B_cont = '2';
                    break;
            }

            switch (fork()) {

                case -1:
                    perror("fork2()");
                    exit(EXIT_FAILURE);

                case 0:   // C
                    char B_cont_str[2];
                    B_cont_str[0] = B_cont;
                    B_cont_str[1] = '\0';

                    if (execl("./prog", "prog", B_cont_str, (char *)NULL) == -1) {
                        perror("execl");
                        exit(EXIT_FAILURE);
                    }

                default:
                    exit(EXIT_SUCCESS);
            }
        default:
            wait(&rcode);

    }


    }
    else{
        // B_cont == '2', we have reached the limit, so we will not create any more child processes
        exit(EXIT_SUCCESS); // no B branch created.
    }
    

    return EXIT_SUCCESS;
}