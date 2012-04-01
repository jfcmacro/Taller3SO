/* mayusculas.c */

/* $Id: mayusculas.c,v 1.1.1.1 2003/06/19 19:00:15 fcardona Exp $ */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 40


int main (int argc , char *argv[]){
char buff [SIZE];
int i=1;


while (i<argc){
    strupr(argv[i]);
    fputs(argv[i],stdout);
    printf("\n");
    i++;
}

while ( fgets(buff, 20, stdin) ){
      if (buff[0]=='\n')
        exit(0);
      fputs(strupr(buff),stdout);
}
}





