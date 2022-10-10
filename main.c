/* menu.c (10/29/2020) by JT: Here is the function that initiates the call to print as well as the function to read in the user input and main function.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "merge_sort.h"
#include "readfile.h"
#include "print_db.h"
#include "id_lookup.h"
#include "name_lookup.h"
#include "add_record.h"
#include "remove_emp.h"
#include "find_all_lastName.h"
#include "print_M_emp.h"
#include "update_emp.h"


//Function to print the menu options
int print_menu()
{
  printf("\n%s\n","***************************************");
  printf("\n%s\n","***************************************");
  printf("Employee DB menu:\n");
  printf("%s\n","---------------------------------------");
  printf("\t(1) Print the Database\n");
  printf("\t(2) Lookup employee by ID\n");
  printf("\t(3) Lookup employee by last name\n");
  printf("\t(4) Add an employee\n");
  printf("\t(5) Quit\n");
  printf("\t(6) Remove an employee\n");
  printf("\t(7) Update an employee's information\n");
  printf("\t(8) Print the M employees with the highest salaries\n");
  printf("\t(9) Find all employees with matching last names\n");
  printf("%s\n","---------------------------------------");
  
  return 0;
}

int clean_stdin()
{
    while (getchar()!='\n');
    return 1;
}
//Function reads user input and make sure is within int range.    
int read_input(char *message,int from, int to)
{
  int choice =0;  
  char c;
  do
    {
      printf("%s",message);//"Enter your choice: ");
    } while (((scanf("%d%c", &choice, &c)!=2 || c!='\n') && clean_stdin()) || choice<from || choice>to);
  return choice;
}

// function to load data and build the array
int load_data(char filename[],struct employee *** all_employees){
  
  *all_employees =(struct employee **)malloc(sizeof(struct employee *)*1024);
  struct employee_node sortEmployees[1024];

  FILE *fp;

  fp = fopen(filename, "r");
  if (fp == NULL){
    return -1;
  }
  char * line;   size_t len = 0;
  ssize_t read;   char delim[] = " ";
  int e = 0;   char *ptr;
  int i;   int ret;
  struct employee * newEmployee;
   while ((read = getline(&line, &len, fp)) != -1) {
	char * end;
	newEmployee = (struct employee *)malloc(sizeof(struct employee) );
	(*newEmployee).id_number = strtol(line,&end,10);
	sortEmployees[e].id_number = newEmployee->id_number;

	line = end;
	line++;
	ptr= strtok(line, delim);
	i=0;
	while(*ptr){
	  (*newEmployee).first_name[i] = *ptr;
	  i++;ptr++;
	}
	ptr= strtok(NULL, delim);
	i=0;
	while(*ptr){
	  (*newEmployee).last_name[i] = *ptr;
	  i++;ptr++;
	}
	ptr= strtok(NULL, delim);
	(*newEmployee).salary =strtol(ptr,&end,10); 
	(*all_employees)[e] = newEmployee;
	sortEmployees[e].emp_ptr = newEmployee;
	e++;	
    }
   mergeSort(sortEmployees,0,e-1);
   for (int i = 0; i<e;i++){
     (*all_employees)[i] = sortEmployees[i].emp_ptr;
   }
  return e;
}

/*Main function, which calls the initial print of the menu (via print_menu())
 and reading of user input. It also handles the user choice with switches that
 call each selection function. */

int main(int argc, char *argv[])
{

  // Handling of initial program call to ensure correct number of arguments.
  if (argc !=2){
    printf("Error! This program must take only one argument:\n\t a file name containing employee data\n");
    exit(0);
  }
  // call to load data and pass by value of all_employees.
  int choice;
  struct employee ** all_employees;
  int  employee_count = load_data(argv[1],&all_employees);
  if (employee_count < 0){
    printf("Error reading the data from :%s\n",argv[1]);
    exit(0);
  }

  //switch cases and handling of user inputs 1-9.
  char * message = "Enter your choice : ";
  while (1){
    print_menu();
    choice = read_input(message,1,9);
   switch(choice) {
      case 1 :
	print_db(all_employees,employee_count);
	break;
      case 2 :
	id_lookup(all_employees,employee_count);
	break;
      case 3 :
        name_lookup(all_employees,employee_count);
        break;
      case 4 :
	add_record(&all_employees,&employee_count);
        break;
      case 5 :
	exit(0);
        break;
      case 6 :
	remove_employee(&all_employees,&employee_count);
        break;
      case 7 :
	update_emp(&all_employees,employee_count);
        break;
      case 8 :
	print_M_emp(all_employees,employee_count);
        break;
      case 9 :
	find_all_lastname_lookup(all_employees,employee_count);
        break;
      default :
         printf("Invalid selction, please try again.\n" );
	 break;
   }
  }
  return 0;
}
