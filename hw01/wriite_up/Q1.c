#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main () {
	pid_t pid;
	printf ( "Begin\n" );
	pid = fork ();
	if (pid == -1) {
		perror("fork"); exit(1);
	}
	if (pid == 0) {
	printf ( "execution 1 \n"); 
	} else {
	printf ( "execution 2 \n"); 
	}
	printf ( "End \n");
	return EXIT_SUCCESS;
}
