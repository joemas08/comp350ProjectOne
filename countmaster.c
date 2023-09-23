#include <stdio.h>
#include <stdlib.h>
int main()
{
    
    char* arguments[4];
    arguments[0]="./countprimes";
    arguments[1]="10";
    arguments[2]="30";
    arguments[3]=NULL;


	int processID = fork();
	if (processID == 0)
		execvp("./countprimes", arguments);
	int status;
	waitpid(processID, &status, 0);
	printf("\n\tTest Print\n");
	printf("Exit status: %d\n",WEXITSTATUS(status));
}














