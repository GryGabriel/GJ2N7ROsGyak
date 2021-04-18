#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void TerminationHandler();

int main(){
  if(signal(SIGTERM, TerminationHandler) == SIG_ERR){
    printf("Handler allitasa sikertelen \"SIGTERM\" jelre!\n");
    return 0;
  }
  
  while(1){
    printf("Varakozas..\n");
    sleep(3);
  }
  
  return 0;
}

void TerminationHandler(int sig){
  signal(sig, SIG_IGN);
  printf("SIGTERM signal: %d\n", sig);
}
