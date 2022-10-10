/*11/10/2020 JT Handling of choice 9: Find all employees with matching last name.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"


int find_all_lastname_lookup(struct employee ** all_employees,int count){
  char name_lookup[MAXNAME];
  printf("Enter Employee's last name (case sensitive and no extra spaces): ");
  scanf("%s",&name_lookup);
  struct employee * emp;
  int found =0;
  printf("%s","----------------------------");
      printf("%s\n","---------------------------------------");
      printf("%20s %20s %8s %8s\n","NAME","","SALARY","ID");
      printf("%s","----------------------------");
      printf("%s\n","---------------------------------------");
  for (int x = 0 ; x < count; x++){
    emp = all_employees[x];
    if (strcmp(name_lookup,(*emp).last_name) == 0){
      printf("%20s %20s %8d %8d\n",(*emp).first_name,
	   (*emp).last_name,(*emp).salary,
	   (*emp).id_number);
      found = 1;
    }
  }
      printf("%s","----------------------------");
      printf("%s\n","---------------------------------------");


  if(found == 0){
    printf("%s","----------------------------");
	printf("%s\n","---------------------------------------");
    printf("Employee \'%s\' not found.\n", name_lookup);
    printf("%s","----------------------------");
	printf("%s\n","---------------------------------------");
  }
  return 0;
}
