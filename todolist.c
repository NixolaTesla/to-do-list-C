#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int usrchoice;
char buffer[256];
char task[1024];
char answer[5];

int main(int argc, char *argv[]){

	printf("Choose the mode of operation:\n\n");
	printf("1. Add Task\n");
	printf("2. Read Tasks\n");
	printf("3. Clear Tasks\n\n");

	scanf("%d", &usrchoice);
	getchar();

	if(usrchoice == 1){
		FILE *fptr = fopen("todolist.txt", "a");
		printf("Name of the task you would like to add: ");
		fgets(task, sizeof(task), stdin);
		fprintf(fptr, "%s", task);
		fclose(fptr);
	}

	else if(usrchoice == 2){
		FILE *fp = fopen("todolist.txt", "r");

		if(fp != NULL){
			while(fgets(buffer, sizeof(buffer), fp)){
				printf("%s", buffer);
			}
		}

		fclose(fp);
	}

	else if(usrchoice == 3){
		printf("Are you sure you would like to clear your to-do-list? (y/n): ");
		fgets(answer, sizeof(answer), stdin);
		if(strcmp(answer, "y")){
		   FILE *fpt = fopen("todolist.txt", "w");
		   fclose(fpt);
		 }	  

		else if(strcmp(answer, "n")){
			printf("okay :3\n");
			exit(0);
		}	
	}

	else{
		printf("Invalid choice.");
		exit(1);
	}	

	return 0;
}
