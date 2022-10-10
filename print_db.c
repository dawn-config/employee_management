/* print_db.c (10/29/2020) by JT: This code handles the printing of the database. When asked by the user to print the database, it will be printed in a tabular format followed by printing out the total number of employees in the database*/

//Handling of choice 1 to print the DB and total number of employees.
#include <stdio.h>
#include <stdlib.h>
#include "main.h"


int print_db(struct employee ** all_employees,int count){
  struct employee * emp;
  printf("%s","----------------------------");
	printf("%s\n","---------------------------------------");
  printf("%20s %20s %8s %8s\n","NAME","","SALARY","ID");
  printf("%s","----------------------------");
	printf("%s\n","---------------------------------------");
  for (int x = 0 ; x < count; x ++){
    emp = all_employees[x];
    printf("%20s %20s %8d %8d\n",(*emp).first_name,
	   (*emp).last_name,(*emp).salary,
	   (*emp).id_number);
  }
  printf("%s","----------------------------");
	printf("%s\n","---------------------------------------");
  printf("Number of employees (%d)\n",count);
  return 0;
}
