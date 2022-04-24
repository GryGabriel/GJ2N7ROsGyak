#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
	sem_t *x;
	x = sem_open("/x", O_CREAT);
	int fd = open("GJ2N7R.txt", O_CREAT, S_IRWXU);
	close(fd);
	fd = open("GJ2N7R.txt", O_WRONLY);
	char szoveg[] = "Lorem ipsum";
	
	write(fd, szoveg, sizeof(szoveg));	
	printf("A szoveg a fileba kerult..kerem varjon 7 mp-et!\n");
	close(fd);
	
	sleep(7);
	sem_post(x);
	sem_close(x);
	return 0;
}