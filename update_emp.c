/*11/11/2020 JT: Update an employee's record by searching for the employee via ID#. User should be able to update any or all fields.*/
#include <stdio.h>
#include <stdlib.h>
#include "main.h"


//handling of choice 7, update  an employee

int update_emp(struct employee *** all_employees,int count){
  int id_num_lookup;
  printf("Enter a 6 digit employee id: ");
  scanf("%d",&id_num_lookup);
  struct employee * emp;
  int found =0;
  int l = 0;
  int r = (count-1);
  int mid;
  char * message;
  int choice;
  while(l<r){
    mid = (r+l)/2;

    if ((*all_employees)[mid]->id_number < id_num_lookup){
      if (l == mid){
	l ++;
      }else{
	l = mid;
      }
    }
    else{
      if ((*all_employees)[mid]->id_number > id_num_lookup){
	r = mid;
      }
      else {
	emp = (*all_employees)[mid];
	printf("%s","----------------------------");
	printf("%s\n","---------------------------------------");

	printf("%20s %20s %8s %8s\n","NAME","","SALARY","ID");
	printf("%s","----------------------------");
	printf("%s\n","---------------------------------------");
	
	printf("%20s %20s %8d %8d\n",emp->first_name,
	       emp->last_name,emp->salary,
	       emp->id_number);
	printf("%s","----------------------------");
	printf("%s\n","---------------------------------------");
	found = 1;
	break;
      }
    }
  }
  if (found ==0 & (*all_employees)[r] -> id_number == id_num_lookup){
     emp = (*all_employees)[r];
	printf("%s","----------------------------");
	printf("%s\n","---------------------------------------");
	printf("%20s %20s %8s %8s\n","NAME","","SALARY","ID");
	printf("%s","----------------------------");
	printf("%s\n","---------------------------------------");
	printf("%20s %20s %8d %8d\n",emp->first_name,
	       emp->last_name,emp->salary,
	       emp->id_number);
	printf("%s","----------------------------");
	printf("%s\n","---------------------------------------");
	found=1;
  }

  if(found == 0){
    printf("Employee with id %d not found in DB.\n", id_num_lookup);
    return 0;
  }
  
//update any or all fields
  do {
    printf("Please select which field you want to update\n");
    printf("\t(1) First Name\n");
    printf("\t(2) Last Name\n");
    printf("\t(3) Salary\n");
    printf("\t(4) Exit ");
    message =  (char *)&"\nSelect Option : ";
    choice = read_input(message,1,4);
    switch(choice){
      case 1 :
	printf("\nPlease enter the new first Name : ");
	scanf("%s",&(*emp).first_name); //scan for user input of each type of info (first/last name)
	break;
      case 2 :
       printf("\nPlease enter the new Last Name : ");
       scanf("%s", &(*emp).last_name); //scan for user input of each type of info (first/last name)
	break;
      case 3 :
	message = (char *)&"\nEnter Salary(30000 to 150000) : ";
	emp->salary = read_input(message,30000,150000); //Ensure range salary (see main,c)
	break;
      case 4 :
	break;
      default :
	break;
    }
  }while(choice !=4);
  return 0;
}
