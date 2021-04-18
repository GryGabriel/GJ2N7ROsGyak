#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> 
#include <sys/wait.h>

#define MSIZE 128

int main(){
  char inBuffer[MSIZE];
  int p[2], nbytes, pid;
  
  if(pid(p) < 0){
    perror("Error");
    exit(1);
  }
  
  pid = fork();
  if(pid < 0){
    exit(2); 
  }
  
  if(pid == 0){
    write(p[1], "GG GJ2N7R", MSIZE); 
  }
  else if(pid > 0){
    wait(NULL);
    read(p[0], inBuffer, MSIZE);
    printf("%s\n", inBuffer);
  }
  
  return 0;
}
