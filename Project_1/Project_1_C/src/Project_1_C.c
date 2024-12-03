/*
 ============================================================================
 Name        : Student Data Management System
 Author      : Menna Elshahed
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
/* Define structure of data to include it in node of LinkedList
 * also defining typedef to make the syntax of structure easier
 * struct student == student
 */
typedef struct student
{
	int id;              /* student id      */
	char name[50];      /*  student name   */
	int age;           /*   student age   */
	float gpa;        /*    student GPA  */
}student;
/* Define structure of node to represent it in LinkedList
 * also defining typedef to make the syntax of structure easier
 * struct node == node
 */
typedef struct node
{
	student data;       /* struct student variable name data */
	struct node *next; /*  pointer to structure to point to the next node in the LinkedList */
}node;
node *head=NULL;     /*   pointer to node to use it to move throw LinkedList
                       *   making it Global to allow to use it in all functions */

/*  function to add student*/
/* (function which make LinkedList)*/
void addStudent(const struct student *const ptr)  /* function take a constant pointer and the pointer point to structure student his data is also constant */
                                                 /*  the pointer is constant to make sure that it will not move and left the address pass of student data */
{
	node *link=(node*)malloc(sizeof(node));     /* making a node with malloc function and save it in pointer to node */
	node*current=head;                         /*  making another pointer to node to use it to move throw the LIst  */
	while(current!=NULL)                      /*this condition means that List when it is empty or pointer current move to the last node in it */
	{
		if(current->data.id==ptr->id)       /* if statement to check if the id is already in List or not  */
		{
			printf("============================================================================\nThe ID is already exist\n");
			break;   /* to stop the function to continue it's other operation */
		}
		current=current->next;            /* increment current pointer to loop throw List */
	}
	if(link==NULL)                    /*if the heap does not have enough place to allocate new node => malloc function return pointer it's value=NULL */
	{
		printf("============================================================================\nThe Allocation doesn't complete\n");
	}
	/*this code will run if the id is not repeated and the allocation done successfully */
	link->data=*ptr;
	link->next=NULL;   /*Next pointer always =NULL as we insert from the last */
	if(head==NULL)
	{
		head=link;     /* this code will run one time at the fist time of insertion in List  */
		              /*  At this time The head=NULl=> the initial value of the head        */
	}
	else{           /*    this code will run when we add another Node after the first one */
	current=head;  /* make current equal head to make sure that current pointer is point to the first node in List*/
	while(current->next!=NULL)   /* Looping to get to the last */
	{
		current=current->next;
	}
	current->next=link;       /*make the next at the last one point to the address of the new node and the new last one next pointer point to the NULL */
	}
}
void displayStudents(void)     /*function to display students in List*/
{
	node *ptr = head;    /*pointer to move throw the List */
	if(head==NULL)   /*this mean that node is empty */
	{
		printf("============================================================================\nThere are no students are entered\n");
		printf("============================================================================\nThis list is empty\n");
		return;
	}
	else
	{
		printf("============================================================================\n{\n");
		while(ptr!=NULL)  /*this loop will run if there are data in the List */
		{
			printf("{ ID: %d \tName: %s \t age: %d \t GPA: %f\t}\n",ptr->data.id,ptr->data.name,ptr->data.age,ptr->data.gpa);
			ptr=ptr->next;
		}
		printf("}\n");
	}
}
void searchStudentByID(int id)   /*function to search for student data using his ID */
{
	node *ptr=head;
	if(head==NULL)  /* this condition means that List is empty */
	{
		printf("\n============================================================================\nThere are no students are entered here\n");
		return; /*to make sure that the function will not continue other operations */
	}
	else if(head!=NULL)   /*this code run if the List has data  */
	{
		while(ptr!=NULL)  /* loop to search for the ID */
		{
			if(ptr->data.id==id)  /* check in each node that ID in it equal to the serched ID or not */ /* if they are equal this code of if will run */
			{
				printf("============================================================================\nThe student is found\n");
				printf("{ ID: %d \tName: %s \t age: %d \t GPA: %f\t}\n",ptr->data.id,ptr->data.name,ptr->data.age,ptr->data.gpa);
				return;
			}
			ptr=ptr->next;  /* increment the pointer to loop throw List */
		}
		printf("============================================================================\nThe ID is not found\n");
	}
}
/*function to search to student id and update the student data with this ID */
void updateStudent(int id){
	node*ptr=head;
	if(head==NULL)
	{
		printf("============================================================================\nThere are no students are entered here\n");
		return;
	}
	else{
		while(ptr!=NULL)  /*loop to search for ID throw the List */
		{
			if(ptr->data.id==id)  /* this code will run when the ID is found --> asking user to insert the new data  */
			{
				printf("============================================================================\nThe student is found\n");
				printf("============================================================================\nEnter the update of the student data\n");
				printf("============================================================================\nEnter the ID: ");
				fflush(stdout);
			    scanf("%d", &(ptr->data.id));
				printf("============================================================================\nEnter the Name of student: ");
				fflush(stdout);
				scanf(" %49[^\n]", ptr->data.name);
				fflush(stdout);
				printf("============================================================================\nEnter the age: ");
				fflush(stdout);
				scanf("%d", &(ptr->data.age));
				printf("============================================================================\nEnter the GPA: ");
				fflush(stdout);
				scanf("%f", &(ptr->data.gpa));
				return;  /* to make sure to end the function and not to continue the rest of it's code */
			}
			ptr=ptr->next;  /* increment to continue looping */
		}
		printf("============================================================================\nThe ID is not found\n"); /* this code will run if the list is not empty and the ID is not found in List*/
	}

}
/* function to summing all GPA of all students and divide the summing on the total number of students */
float calculateAverageGPA(void)
{
  node*ptr=head;  /* pointer to move throw the list */
  float GPA=0;   /* every summation will be saved in this variable */
  int n=0;      /*  every increment in number of students will be saved here*/
  if(head==NULL)
  {
	  return 0.0;  /* the list is empty */
  }
  else{
	  while(ptr!=NULL) /*loop to sum GPA and total number of students  */
	  {
		  GPA+=ptr->data.gpa;
		  n++;
		  ptr=ptr->next;
	  }

  }
  return GPA/n; /* return the average of GPA */
}
void searchHighestGPA(void)
{
	float High=0,GPA=0;
	node *ptr=head;
	node *PtrHigh=NULL;
	if(head==NULL)
	{
		printf("============================================================================\nThere are no students entered here\n");
		return;
	}
	else{
		while(ptr!=NULL)   /* this code will run if the list is not empty to search for the highest GPA*/
		{
			GPA=ptr->data.gpa;
			if(GPA>High)
			{
				High=GPA;
				PtrHigh=ptr;
			}
			ptr=ptr->next;
		}
	}
	printf("============================================================================\nThe Highest GPA is found which is: %f\n",High);
	printf("============================================================================\nStudent's data whose GPA is the Highest:\n");
	printf("{ ID: %d \tName: %s \t age: %d \t GPA: %f\t}\n",PtrHigh->data.id,PtrHigh->data.name,PtrHigh->data.age,PtrHigh->data.gpa);
	/* or just call search Student by ID function
	 * searchStudentByID(PtrHigh->data.id);
     */
}
void deleteStudent(int id)   /* this function search with ID by looping throw the list and free the node from it */
{
	node *ptr=head,*prev,*deletenode;  /* prev point to the node which is before the deleted node */
	if(head==NULL)
	{
		printf("============================================================================\nThere are no students entered here\n");
		return;
	}
	else if(ptr->data.id==id)
	{
		deletenode=ptr;  /* pointer to use it as pointer to the delete node  */
		head=ptr->next;
		free(deletenode);
		printf("============================================================================\nThe node has been deleted successfully\n");
		return;
	}
	else
	{
		while(ptr->next!=NULL)
		{
			prev=ptr;
			if(ptr->next->data.id==id)
			{
				deletenode=ptr->next;
				prev->next=ptr->next->next;
				free(deletenode);
				printf("============================================================================\nThe node has been deleted successfully\n");
				return;
			}
			ptr=ptr->next;
		}
		printf("============================================================================\nThe id is not found\n");
	}
}
int main(void) {
	printf("Welcome to student program please choose what you want\n");
	int select,running=1;  /* select is int entered by user to use it in switch case to select which function will run  */
	do{
			printf("============================================================================\n1: Add Student\n2: Display Students\n3: Search Student by ID\n4: Update Student Information\n5: Delete Student\n6: Calculate Average GPA\n7: Search for student with Highest GPA\n8: Exit\n============================================================================\n");
			fflush(stdout);
			scanf("%d",&select);
			if(select>=1&&select<8)
					{
				/* use switch case to select which function operate */
				switch(select){
					case 1:
						student* save_student = (student*)malloc(sizeof(student));
						printf("============================================================================\nEnter the ID: ");
						fflush(stdout);
						scanf("%d", &(save_student->id));
						printf("============================================================================\nEnter the Name of student: ");
						fflush(stdout);
						scanf(" %49[^\n]", save_student->name);
						fflush(stdout);
						printf("============================================================================\nEnter the age: ");
						fflush(stdout);
						scanf("%d", &(save_student->age));
						printf("============================================================================\nEnter the GPA: ");
						fflush(stdout);
						scanf("%f", &(save_student->gpa));
						addStudent(save_student);
						break;
					case 2:
					    displayStudents();
						break;
					case 3:
						int id;
						printf("============================================================================\nEnter the ID please ");
						fflush(stdout);
						scanf("%d",&id);
						searchStudentByID(id);
					     break;
					case 4:
						int id_;
						printf("============================================================================\nEnter the ID please ");
						fflush(stdout);
					    scanf("%d",&id_);
					    updateStudent(id_);
					     break;
					case 6:

						if(calculateAverageGPA()==0)
						{
						    printf("============================================================================\nThere are no students Entered Here\n");
						}
						else
						{
							printf("============================================================================\nThe Average of Total GPA is: %f\n",calculateAverageGPA());
						}
						break;
					case 5:
						int id__;
						printf("============================================================================\nEnter the ID please ");
						fflush(stdout);
						scanf("%d",&id__);
						deleteStudent(id__);
					     break;
					case 7:
						 searchHighestGPA();
					     break;
				}


		}
			else if(select==8)
			{
				printf("============================================================================\nEXit...\n============================================================================");
				running=0;
			}
			else
			{
				printf("Wrong input try again\n");  /* this message will run only  in case the user enter wrong input */
			}
	}while(running);

	return 0;
}
