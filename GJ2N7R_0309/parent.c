#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


pid_t fork();
int main()
{
	pid_t p;
	if ((p = fork()) < 0)
	{
		printf("No output");
		exit(0);
	}
 	else if (p == 0) execl("./child", "child", (char*)NULL);
	waitpid(p, NULL, 0);
}