#include <stdlib.h>
#include <stdio.h>                                                             
#include <string.h>
#include <unistd.h>                                                                               
int main(int argc, char *argv[])                                               
{                                                                              
    char *var, *value;
	char buf[256];	

    var = "PATH";                                               
    value = getenv(var);                                                   

    if (value)                                                              
        printf("Variable %s has value %s\n", var, value);              
    else                                                                   
        printf("Variable %s has no value\n", var);

	printf("Changing current path...");
	getcwd(buf, 50);

	setenv(var, buf, 1);
    value = getenv(var);

    if (value)                                                              
        printf("Variable %s has value %s\n", var, value);              
    else                                                                   
        printf("Variable %s has no value\n", var);
}

