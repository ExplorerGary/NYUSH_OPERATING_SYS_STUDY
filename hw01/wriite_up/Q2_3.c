#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
    int a = 10;
    int e;

    if (fork() == 0) {
        a *= 2;
        if (fork() == 0) {
            a += 1;
            exit(2);
        }
        printf("%d\n", a);
        exit(a);
    }

    sleep(30);
    wait(&e);
    printf("a:%d; e:%d\n", a, WEXITSTATUS(e));
    return 0;
}