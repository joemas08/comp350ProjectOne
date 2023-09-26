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

	int processids[NUMBER_OF_CALLS];

	int exitStatusTotal = 0;


	for (int i = 0; i < NUMBER_OF_CALLS; i++) {
		processids[i] = fork();

		if (processids[i] == 0) {

			int start = atoi(arguments[1]);
			int end = atoi(arguments[2]);

			for (int j = start; j < end; j += 6) {
				char str[10];
				snprintf(str, sizeof(str), "%d", j);
				arguments[1]= str;
				printf("Argument 1: %s\n", arguments[1]);
				char str2[10];
				snprintf(str2, sizeof(str2), "%d", j + 5);
				arguments[2]= str2;
				printf("Argument 2: %s\n", arguments[2]);

				execvp("./countprimes", arguments);

			}


		}


	}

	for (int i = 0; i < NUMBER_OF_CALLS;i++){
		int status;
		waitpid(processids[i], &status, 0);
		exitStatusTotal += WEXITSTATUS(status);
		printf("\n\nRunning Total: %d\n", exitStatusTotal);
		
		//printf("\n\tTest Print\n");
		//printf("\tExit status: %d\n\n",WEXITSTATUS(status));
	}
	

}

