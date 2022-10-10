/*11/10/2020 JT header to Remove an employee*/
/* Remove an employee: looks up employee by ID number, confirms deletion, deletes employee, adjusts array to remove gaps.*/


#include "main.h"
#include <stdlib.h>
#include <stdio.h>

//handling of choice 6, remove an employee

int remove_employee(struct employee *** all_employees,int *count){
  int id_num_lookup;
  printf("Enter a 6 digit employee id: ");
  scanf("%d",&id_num_lookup);
  struct employee * emp;
  int found =0;
  int l = 0;
  int r = (*count-1);
  int mid;
  int idx;
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
	
	struct employee * emp = (*all_employees)[mid];
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
	idx = mid;
	break;
      }
    }
  }
  if (found ==0 & (*all_employees)[r] -> id_number == id_num_lookup){
    struct employee * emp = (*all_employees)[r];
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
	idx = r;
	found=1;
  }
  if(found == 0){
    printf("Employee with id %d not found in DB.\n", id_num_lookup);
    return 0;
  }
  
  //Confirm deletion
  
  printf("\n Do you want to delete this employee?");
  int valid=0;
  int choice;
  while(valid ==0){
    printf("Enter 1 for yes, 0 for no: ");
    scanf("%d",&choice);
    
    if( choice == 0 || choice == 1 ){
      valid=1;
    }
    else{
      printf("\nPlease provide a valid choice (0 or 1).\n");
    }
  }
  // If choice == 1, user wants to delete the employee
  if (choice == 1){
    free((*all_employees)[idx]);
    for(int i = idx; i+1<*count;i++){
      (*all_employees)[i] = (*all_employees)[i+1];
    }
    *count = (*count)-1;
  }
  return 0;
}



