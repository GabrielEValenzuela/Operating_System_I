/**
Guard to prevent multiple include. This task it's make by the
precompyler. CPP optimizes even further. It remembers when a header
file has a wrapper ‘#ifndef’. If a subsequent ‘#include’ specifies
that header, and the macro in the ‘#ifndef’is still defined,
it does not bother to rescan the file at all. 
*/

#ifndef ksmap.h

//Define the header

#define ksmap.h 

char *get_cpu_information(FILE *fp, pthread thread);

char *get_kernel_information(FILE *fp, pthread thread);

char *get_disck_infomration(FILE *fp, pthread thread);

char *get_all_information();

void clear_all();

#endif ksmap.h
