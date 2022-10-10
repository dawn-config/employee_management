//define the struct employee

#define MAXNAME 64
int read_input(char *message,int from, int to);

struct employee{
     int id_number;
     char first_name[MAXNAME];
     char last_name[MAXNAME];
     int salary;
}; //Don't forget to include ";" at end of a struct
struct employee_node{
  int id_number;
    struct employee * emp_ptr;
};
