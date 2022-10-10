/*11/11/2020 JT  Handling of choice 8: print the M employees with the highest salaries*/

#include <stdio.h>
#include "main.h"

int print_M_emp(struct employee ** all_employees,int count){
  int m;
  char  buf[128];
  char * message = &buf[0];
  struct employee * emp;
  snprintf(buf, sizeof(buf), "\nHow many salaries do you want to print? (max=%d)\n", count);
  m = read_input(message,1,count);
  struct employee dummie;
  dummie.salary = 1000;
  struct employee * sortEmployees[m];
  int i;
  
  for ( i = 0; i < m; i++){
    sortEmployees[i] = &dummie;
  }
  // Only go through the employees list ONCE
  for (int x = 0 ; x < count; x++){
    emp = all_employees[x];
    i=0;
    //Only enters while the current employee has higher salary
    while ((i < m) && (emp->salary > sortEmployees[i]->salary) ){
      if (i ==0){
	sortEmployees[i] = emp;
      }else
	{
	  sortEmployees[i-1] = sortEmployees[i];
	  sortEmployees[i] = emp;
	}
      i++;
    }
  }
  printf("%s","----------------------------");
  printf("%s\n","---------------------------------------");
  printf("%20s %20s %8s %8s\n","NAME","","SALARY","ID");
  printf("%s","----------------------------");
  printf("%s\n","---------------------------------------");
  for(int x =0;x < m; x++){
    emp = sortEmployees[m-1-x];
      printf("%20s %20s %8d %8d\n",(*emp).first_name,
	   (*emp).last_name,(*emp).salary,
	   (*emp).id_number);
  }
  printf("%s","----------------------------");
	printf("%s\n","---------------------------------------");
  printf("Number of employees (%d)\n",count);
  return 0;
}
