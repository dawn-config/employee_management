/* readfile.h (11/1/2020) by JT: */
int open_file(char *filename,FILE *fp);
int  read_int(char * line,char *end,int *digit);
int  read_string(char * line,char *end,char *string);
int  read_float(char * line,char *end,float *flt);
int close_file(char *filename,FILE * fp);





