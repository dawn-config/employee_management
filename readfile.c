/* readfile.c (11/1/2020) by JT: */

/*Open a file by calling: open_file(), passing in the name of the file to open as a string; open_file() returns 0 if the file is successfully opened, and -1 if the file cannot be opened.
  Functions to read values of different types into program variables: read_int(), read_string(), read_float(). These functions take arguments much like scanf does: they need to know the memory location of where to put the value read in. For example:*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

int open_file(char *filename,FILE * fp)
{
  fp = fopen(filename,"r");
  if (fp == NULL){
    return -1;
  }
   return 0;
}
   
int  read_int(char * line,char *end,int *digit){
  *digit = strtol(line,&end,10);
  if (line ==end){
    return -1;
  }
  return 0 ; 
}

int  read_string(char * line,char *string){
  char delim[] = " ";
  char * end;
  int i;
  char *ptr;
  ptr= strtok(line, delim);
  i=0;
  while(*ptr){
    string[i] = *ptr;
	  i++;ptr++;
  }
  return 0;
}


int read_float(char *line,double*flt){
  (*flt) =  atof(line);
  return 0;
}

  
int close_file(FILE *fp){
  fclose(fp);
  return 0;
}




