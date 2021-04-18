#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#inclide <signal.h>

void AlarmHandler();

int main(){
  if(signal(SIGALRM, AlarmHandler == SIG_ERR){
    printf("Error!");
    return 1;
  }
  
  return 0;
}

void AlarmHandler(int sig){
  printf("GJ2N7R\nMostantol nem blokkolodok!\n");
  exit(1);
}
