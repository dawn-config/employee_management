/* id_lookup.c (11/1/2020) by JT: This code handles looking up an entry using an ID number. It uses BINARY SEARCH to find a matching employee in the data base. If one is found, it will print out the employee information. If not, it will print out a "not found" message to the user. */

#include <stdio.h>
#include <string.h>
#include "main.h"

//handling of choice 2, look up by ID number.
int id_lookup(struct employee ** all_employees,int count){
  int id_num_lookup;
  printf("Enter a 6 digit employee id: ");
  scanf("%d",&id_num_lookup);
  struct employee * emp;
  int found =0;
  int l = 0;
  int r = (count-1);
  int mid;
  //BEGINS BINARY SEARCH
  while(l<r){
    mid = (r+l)/2;
    if (all_employees[mid]->id_number < id_num_lookup){
      if (l == mid){
	l ++;
      }else{
	l = mid;
      }
    }
    else{
      if (all_employees[mid]->id_number > id_num_lookup){
	r = mid;
      }
      else {
	struct employee * emp = all_employees[mid];
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
	return 0;
      }
    }
  }
  //CORNER CASE (UPPERMOST DUE TO FLOOR)
  if (all_employees[r] -> id_number == id_num_lookup){
    	struct employee * emp = all_employees[r];
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
	return 0;
  }
      
  if(found == 0){
    printf("Employee with id %d not found in DB.\n", id_num_lookup);
  }
  return 0;
}





