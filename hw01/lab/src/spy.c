/**** spy.c ****/

#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>


#define _XOPEN_SOURCE 700

#define BUFSZ 1024 // buffer size for reading input
#define WDSZ 24 


int cut_down(char *buf, char **cmd) {
	char* s = strtok(buf, " \n");
	int i = 0;
	while (s != NULL) {
		cmd[i] = (char*) malloc(sizeof(char) * WDSZ);
		strcpy(cmd[i], s);
		s = strtok(NULL, " \n");
		i++;
	}
	cmd[i] = NULL;
	return i;
}


int main(int argc, char **argv)
{

    int or = 1, pid, command_size, i;
	char buf[BUFSZ]; // init the buffer
	char *command[WDSZ]; // init the command array, this is the thing to execute

    while (or > 0) 
    {
		for (i = 0; i < BUFSZ ; i++)
			buf[i] = '\0';
        if ((or = read(STDIN_FILENO, buf, BUFSZ)) == -1)
			perror("read");
		else if (or > 0) {
			command_size = cut_down(buf, (char**)command);
			/* TO DO :
					-> EXECUTION OF THE COMMAND BY A CHILD
					-> PARENT WAITS UNTIL COMPLETION AND RELEASES MEMORY */

					// create a child process
					pid = fork();
					if (pid == -1) {
						perror("fork");
						exit(EXIT_FAILURE); // you failed to create a child process, exit the program
					} else if (pid == 0) {
						// this is the child process, execute the command
						// first, detect if the comand is ls -l
						if (strcmp(command[0], "ls") == 0 && strcmp(command[1], "-l") == 0) {
							// execute ls -l
							execlp("ls", "ls", "-l", NULL);
						} else {
							// execute the other command
							execvp(command[0], command);
						}
					} else {
						// this is the parent process, wait for the child to complete
						wait(NULL);
					}

		}
    }
	
	return 0;
}
