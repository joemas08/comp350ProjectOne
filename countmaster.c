/*
 Joseph Masone
 COMP350-001
 October 4, 2023
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {

    char* arguments[4];
    arguments[0]="./countprimes";
    arguments[1]="10";
    arguments[2]="30";
    arguments[3]= "4";

	int NUMBER_OF_CALLS = atoi(arguments[3]);
    arguments[3]= NULL;

	int processids[NUMBER_OF_CALLS];

	int exitStatusTotal = 0;


	for (int i = 0; i < NUMBER_OF_CALLS; i++) {
		processids[i] = fork();

		if (processids[i] == 0) {

			execvp("./countprimes", arguments);

		}


	}

	for (int i = 0; i < NUMBER_OF_CALLS;i++){
		int status;
		waitpid(processids[i], &status, 0);
		exitStatusTotal += WEXITSTATUS(status);
		printf("\n\nRunning Total: %d\n", exitStatusTotal);
		
	}

}

