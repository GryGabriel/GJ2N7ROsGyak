#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define A 100

int main(){
    int f = open("gj2n7r.txt", O_RDWR);
    if(f == -1){
        printf("Sikertelen fajl megnyitas\n!");
        return -1;
    }
    else{
        printf("Fajl megnyitva!\n");
    }

    char text[] = "Garay Gabriel, Programtervezo informatikus, GJ2N7R";
    int fileba = write(f, text, sizeof(text));
    printf("A fajlba iras sikeres!");
    lseek(f, 0, SEEK_SET);
    printf("A kurzor a fajl elejere kerult!\n");

    char kiolvasas[A];
    int olvas = read(f, kiolvasas, sizeof(kiolvasas));
    kiolvasas[olvas] = '\0';

    printf("A fajlbol olvasott tartalom: %s; %i BYTE\n", kiolvasas, olvas);

    close(f);
}
