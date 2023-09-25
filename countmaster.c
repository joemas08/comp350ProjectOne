#include <stdio.h>
#include <stdlib.h>

int main() {

    char* arguments[4];
    arguments[0]="./countprimes";
    arguments[1]="10";
    arguments[2]="30";
    arguments[3]= "4";

	int NUMBER_OF_CALLS = atoi(arguments[3]);

    arguments[3]= NULL;

	for (int i = 0; i < NUMBER_OF_CALLS; i++) {
		int processID = fork();

		if (processID == 0) {

			execvp("./countprimes", arguments);

		}
		int status;
		waitpid(processID, &status, 0);
		printf("\n\tTest Print\n");
		printf("\tExit status: %d\n\n",WEXITSTATUS(status));

	}
	

}

