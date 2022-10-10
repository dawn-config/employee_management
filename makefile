all: workerDB

workerDB: main.c name_lookup.c add_record.c find_all_lastName.c print_db.c print_M_emp.c update_emp.c remove_emp.c merge_sort.c id_lookup.c
	gcc -o workerDB main.c name_lookup.c add_record.c find_all_lastName.c print_db.c print_M_emp.c update_emp.c remove_emp.c merge_sort.c id_lookup.c

clean: rm main.o workerDB readfile.o
