#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

struct sembuf sembuf, *sop;
union semun{
		int val;
    	struct semid_ds *buf;
		unsigned short *array;
}arg;

int main(){
	int semid, setvalue, getvalue;
	key_t key = 12345L;
	semid = semget(key, 1, 0666 | IPC_CREAT);
	if(semid < 0){
		perror("Szemafor kreálás hiba lépett fel!");
		exit(0);
	}

	setvalue = semctl(semid, 0, SETVAL, 0);

	int fd = open("GJ2N7R.txt", O_CREAT, S_IRWXU);
	close(fd);
	fd = open("GJ2N7R.txt", O_WRONLY);
	char szoveg[] = "Lorem ipsum";
	
	write(fd, szoveg, sizeof(szoveg));	
	printf("A szoveg a fileba kerult!\n");
	close(fd);
	
	if(setvalue == 0){
		printf("Olvasás blokkolva! Kérem, várjon 7 mp-et!\n");
	}
	sleep(7);

	sembuf.sem_num = 0;
	sembuf.sem_op = 1;
	sembuf.sem_flg = 0666;
	sop = &sembuf;
	setvalue = semop(semid, sop, 1);
	
	return 0;
}