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
	int value;
	do{
		sem_getvalue(x, &value);
		printf("Várakozás az olvasásra..(szemafor erteke: %d)\n", value);
		sleep(1);
	}while(!value);

	int fd = open("GJ2N7R.txt", O_RDONLY);
	if(fd == -1){
		printf("Nem sikerult megnyitni a fajlt!\n");
	}else{
		printf("File sikeresen megnyitva!\n");
		char beolvas[100];
		lseek(fd, 0, SEEK_SET);
		read(fd, beolvas, sizeof(beolvas));
		printf("Szoveg sikeresen beolvasva: %s\n", beolvas); 
	}
	close(fd);
	sem_wait(x);
	sem_close(x);
	return 0;
}