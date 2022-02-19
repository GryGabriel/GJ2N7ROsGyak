#include <stdio.h>

int main(){
	FILE *fp;
	fp = fopen("garay.txt", "w");
	if(fp == NULL){
		perror("Fajl letrehozasa sikertelen");
	}
	fprintf(fp, "Garay Gabriel,\nProgramtervezo informatika,\nGJ2N7R");
	fclose(fp);
	
	fp = fopen("garay.txt", "r");
	if(fp == NULL){
		perror("Sikertelen fajlmegnyitas");
	}
	char string[100];
	while(fgets(string, sizeof(string), fp)){
		printf("%s", string);
	}
	fclose(fp);
	return 0;
}