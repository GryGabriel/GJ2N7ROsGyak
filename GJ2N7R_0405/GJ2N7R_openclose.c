#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd = open("GJ2N7R.txt", O_RDWR);
    if(fd == -1)
    {
        printf("Nem sikerult megnyitni a fajlt!\n");
        return 1;
    } else printf("A fajl sikeresen megnyitva!");

    char beolvas[64];
    int buffer = read(fd, beolvas, sizeof(beolvas));

    beolvas[buffer] = '\0';
    printf("Beolvasott tartalom: %s Ami %i byte.\n", beolvas, buffer);

    lseek(fd, 0, SEEK_SET);
    printf("A mutato a fajl elejere lett allitva\n");

    char szoveg[] = "Rendszerhivassal iras fajlba\n";
    int irt = write(fd, szoveg, sizeof(szoveg));
    printf("A fajlba irodott a(z) %s Ami %i byte.\n", szoveg, irt);

    close(fd);

    return 0;
}