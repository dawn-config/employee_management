/* 10/30/2020 JT Handling of choice 3, looking up by last name. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

int name_lookup(struct employee ** all_employees,int count){
  char name_2lookup[MAXNAME];
  printf("Enter Employee's last name (no extra spaces): ");
  scanf("%s",&name_2lookup);
  struct employee * emp;
  int found =0;
  for (int x = 0 ; x < count; x++){
    emp = all_employees[x];
    if (strcmp(name_2lookup,(*emp).last_name) == 0){
      found = 1;
      printf("%s","----------------------------");
	printf("%s\n","---------------------------------------");
      printf("%20s %20s %8s %8s\n","NAME","","SALARY","ID");
      printf("%s","----------------------------");
	printf("%s\n","---------------------------------------");
      printf("%20s %20s %8d %8d\n",(*emp).first_name,
	   (*emp).last_name,(*emp).salary,
	   (*emp).id_number);
      printf("%s","----------------------------");
	printf("%s\n","---------------------------------------");
	break;
    }
  }
  if(found == 0){
    printf("%s","----------------------------");
	printf("%s\n","---------------------------------------");
    printf("Employee \'%s\' not found.\n", name_2lookup);
    printf("%s","----------------------------");
	printf("%s\n","---------------------------------------");
  }
  return 0;
}
