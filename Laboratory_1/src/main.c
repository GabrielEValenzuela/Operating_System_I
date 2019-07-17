#include <stdio.h>
#include <string.h>
#include <check.h>
#include <stdlib.h>
#include <unistd.h>

#include "ksmap.h"

int main(int argc, char *argv[])
{
    int a=0, b=0, c=0;
    opterr = 0;
    short int flagC = 0;
    short int flagD = 0;
    short int flagE = 0;

    while ((c=getopt(argc,argv,"slf:"))!=-1) {
        switch (c) {
        case 's':
            if (argc==2) {
                flagC=1;
                break;
            }
            else {
                printf("Las opciones validas son -s , -l a b o -f a b. Siendo a y b numeros enteros.\n");
                return 0;
            }
        case 'l':
            if (argc==4) {
                flagD=1;
                break;
            }

            else {
                printf("Las opciones validas son -s , -l a b o -f a b. Siendo a y b numeros enteros.\n");
                return 0;
            }
        case 'f':
            if (argc==4) {
                flagE=1;
                break;
            }

            else {
               printf("Las opciones validas son -s , -l a b o -f a b. Siendo a y b numeros enteros.\n");
               return 0;
            }
        default:
            printf("Las opciones validas son -s , -l a b o -f a b. Siendo a y b numeros enteros.\n");
            return 0;
        }

        part_a();
        part_b();

        if(flagC){
            part_c();
        }
        if (flagD) {
            part_c();
            sscanf(argv[2],"%u",&a);
            sscanf(argv[3],"%u",&b);
            part_d(a,b);
        }

        if (flagE) {
            part_c();
            sscanf(argv[2],"%u",&a);
            sscanf(argv[3],"%u",&b);
            part_e(a,b);
        }
    }

    return 0;
}

