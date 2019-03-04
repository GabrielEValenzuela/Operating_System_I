//#include "ksmap.h"
#include <stdio.h>
#include <string.h>
//#include <ctime.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc,char *argv[]){
	int flags = 0, opt=0;
	int nsecs = 0, tfnd = 0;
	//Options a-all, c-cpu, k-kernel, l [int] [int]-disck
	while((opt = getopt(argc,argv,"ackhl:")) != -1){
	switch(opt){
	case 'n':
		flags = 1;
		break;
	case 't':
		tfnd = 1;
		nsecs = atoi(optarg);
		break;
	default: /* '?' */
		fprintf(stderr, "Error");
	exit(1);
	 }
	}
	printf("flags = %d; tfnd = %d; optind=%d\n",flags,tfnd,optind);
	printf("argc = %d",argc);	
	if((optind-1) >= argc){
	fprintf(stderr, "Expected argumente after options\n");
	exit(1);
	}

	printf("Name argument = %s\n", argv[optind-1]);
	return 0;
}

