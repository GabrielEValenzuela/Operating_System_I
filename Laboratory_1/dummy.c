#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define NUM_THREADS 5

char* print_upper(char *string, size_t lenght){
	char *upper;
	printf("%d\n", sizeof(string)/sizeof(*string));
	printf("Este el tamaño de sting\n");
	printf("%d\n",lenght );
	upper = malloc(lenght);
	for (int i = 0; i < lenght; ++i)
	{
		upper[i] = toupper(string[i]);
	}
	printf("%s\n",upper);
	return upper;
}

int main (int argc, char *argv[]) {
	char test  [] = "los guardianes de la galaxia 2\tHola mundo\tiRoN MaN";
	char **tokens;
	char *result = strtok_r(print_upper(test,sizeof(test)/sizeof(*test)),"\t",&tokens);
	printf("%s\n",result);

}