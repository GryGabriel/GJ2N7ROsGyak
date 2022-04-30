#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
	int semid, getvalue;
	key_t key = 12345L;
	semid = semget(key, 1, 0);
	if(semid < 0){
		perror("Szemafor azonosítása során hiba lépett fel!\n");
		exit(0);
	}
	int fd = open("GJ2N7R.txt", O_RDONLY);
	if(fd == -1){
		printf("Nem sikerult megnyitni a fajlt!\n");
		exit(0);
	}
	do{
		getvalue = semctl(semid, 0, GETVAL, NULL);
		printf("Olvasásra várakozom...\n");
		sleep(3);
	}while(!getvalue);
	printf("File sikeresen megnyitva!\n");
	char beolvas[100];
	lseek(fd, 0, SEEK_SET);
	read(fd, beolvas, sizeof(beolvas));
	printf("Szoveg sikeresen beolvasva: %s\n", beolvas);

	semctl(semid, 0, IPC_RMID, 0); 
	
	close(fd);
	return 0;
}