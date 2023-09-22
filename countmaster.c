#include <stdio.h>
#include <stdlib.h>
int main()
{
    
    char* arguments[4];
    arguments[0]="./countprimes";
    arguments[1]="10";
    arguments[2]="30";
    arguments[3]=NULL;


    execvp("./countprimes", arguments);

}














