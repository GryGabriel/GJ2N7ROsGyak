#include <stdio.h>
#include <stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>


int main()
{
    	if (!system("ls")){
            for (int i = 0; i < 3; i++)
	        printf("%d\n", i);
	}
	system("pajtas");
}