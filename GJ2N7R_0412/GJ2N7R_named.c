#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main()
{

    char inBuffer[128];
    int pid, fd;
    char input[] = "Garay Gabriel";
    char * fifo = "/tmp/gj2n7r";

    mkfifo(fifo, 0666);

    pid = fork();

    if (pid < 0)
    {
        exit(2);
    }

    if (pid == 0)
    {
        printf("Child most fog beirni a fifo pipe-ba!\n");

        fd = open(fifo, O_WRONLY);

        write(fd, input, strlen(input)+1);

        printf("Child sikeresen irt a pipe-ba!\n");
    }

    else if (pid > 0 )
    {
        fd = open(fifo, O_RDONLY);

        read(fd, inBuffer, strlen(input)+1);

        printf("Parent ezt kaptam: %s\n", inBuffer);

        close(fd);
    }

    return 0;
}