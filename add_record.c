/* add_record.c (11/1/2020) by JT: This code handles adding a new record to the database. When called, it will prompt the user for the employee's information. It checks to ensure that the user entered valid values for each field, and it will print out an error message and re-prompt the user to try again, repeating until the user enters valid values. It will then print out the field values of the employee to add, and ask the user if (s)he really wants to add the employee. If yes, then it inserts the new employee in the array. It will also make sure that any employee entered by the user is assigned an ID that is numerically larger than any existing employee record in the databse.*/

 //handling of choice 4 to add record to DB, checking that input matches parameters required.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

int add_record(struct employee *** all_employees,int * count){
  int valid = 0;
  struct employee *newEmployee = (struct employee *)malloc(sizeof(struct employee) );
  
  while(valid ==0){
    printf("\nEnter the first name of the employee: ");
    scanf("%s",&(* newEmployee).first_name);
    if (strlen((*newEmployee).first_name)<MAXNAME){
      valid=1;
    }
    else{
      printf("\nProvided first name was too long, please try again\n");
    }
  }
  valid=0;
  while(valid ==0){
    printf("\nEnter the last name of the employee: ");
    scanf("%s",&(* newEmployee).last_name);
    if (strlen((*newEmployee).last_name)<MAXNAME){
      valid=1;
    }
    else{
      printf("\nProvided last name was too long, please try again\n");
    }
  }
  char * message = "\nPlease provide a salary within bounds (30000 to 150000) :";
  (* newEmployee).salary =  read_input(message,30000,150000);
  printf("\nDo you want to add the following employee to the DB?\n");
  printf("\t%s %s, salary: %d\n\t", (*newEmployee).first_name, (*newEmployee).last_name, (*newEmployee).salary);
  valid=0;
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
  if (choice == 1){
    if (*count < 1){
      newEmployee->id_number = 100000;
     }
    else {
      
      int newID =  (*all_employees)[(*count)-1]->id_number;
      newID ++;
      newEmployee->id_number = newID;
     }
     (*all_employees)[(*count)] = newEmployee;
     (*count) =(*count)+1;
  }
  return 0;
}
