//Program to develop student course registration system

#include<stdio.h>
#include<stdlib.h>         //pre-processor directives
#include<string.h>

//structure definition
struct node{               
	char name[40];
	int rollno;
	char course[20];
	char mobile_no[11];
	char gender[10];
	int age;
	struct node*next;
};
int count=0;    //to find total registered students

//decleration of structure variables
struct node*head=NULL,*temp,*newnode,*prev;   

//function to register a student to a course
int register_std();
    
//function to drop a student from course
int drop_std();

//function to search the details of a particular student
int search_std();

//function to change the details of a student
int changes_in_details();

//function to add student details in .csv file
int add_csv(FILE*);

//function to modify student details in .csv file after dropping a student from course
int modify_csv(FILE*);

//function to display the registered student details
int display();

//funtion to find total number of students registered till now
int no_of_regstd();

int main()
{
	//creating a .csv file to maintaining student details
	FILE*fp=NULL;
    fp=fopen("stdr.csv","w");
    
    //types of columns in .csv file
    fprintf(fp,"Sl.No,Name,Rollno,Course,Mobile_no,Gender,Age\n");
    fclose(fp);
    
    //starting of output screen
    printf("*********************************WELCOME TO STUDENT COURSE REGISTRATION*******************************");
    printf("\n");
    printf("\n");
    
    //menu drive
	while(1)
	{
		int ch;
	    printf("Enter");
		printf("\n");
		
		//displaying option to register a student
		printf("1 to Register a Student:");
		printf("\n");
		
		//displaying option to drop a student
		printf("2 to Drop a Student:");
		printf("\n");
		
		//displaying option to search for student details
		printf("3 to Search for a particular student details:");
		printf("\n");
		
		//displaying option to show all registered students
		printf("4 to Display all registered students:");
		printf("\n");
		
		//displaying option to modify student details
		printf("5 to Modify details of a particular student:");
		printf("\n");
		
		//displaying option to show number of registered students
		printf("6 to Show number of registered students:");
		printf("\n");
		
		//displaying option to exit from program
		printf("7 to Exit:");
		printf("\n");
	    scanf("%d",&ch);
	    switch(ch)
	    {
	    	case 1:
	    		
	    		//case to register a student
		    	register_std();
		    	add_csv(fp);
			    break;
		    case 2:
		    	
		    	//case to drop a student
			    drop_std();
			    modify_csv(fp);
			    break;
		    case 3:
		    	
		    	//case to search for a student details
			    search_std();
			    break;
			case 4:
				
				//case to show all registered students
				display();
				printf("\n");
				break;
			case 5:
				
				//case to modify student details
				changes_in_details();
				modify_csv(fp);
				break;
			case 6:
				
				//case to show no.of registered students
				no_of_regstd();
				break;
		    case 7:
		    	
		    	//case to exit from program
		    	printf("\n");
		    	printf("***************************************THANK YOU HAVE A NICE DAY**************************************");
		    	printf("\n");
			    exit(1);
			    break;
		    default:
		    	
		    	//case to show, select valid choice
			    printf("Enter valid choice.");
			    printf("\n");
			    break;
    	}
	}
}

//function definition to register a student to a course
int register_std()
{
	count++;
	
	//creating a node to register student
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->next=NULL;
	
	//taking details of the student
	printf("Enter student details Name,Rollno,Course,Mobile_no,Gender,Age:");
	printf("\n");
	scanf("%s %d %s %10s %s %d",newnode->name,&newnode->rollno,newnode->course,newnode->mobile_no,newnode->gender,&newnode->age);
	
	//inserting the created node to current list
	if(head==NULL)
	{
		head=temp=newnode;
	}
	else
	{
		temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newnode;
		temp=newnode;
	}
	
	//showing the condition of registration
	printf("Student was registered successfully.");
	printf("\n");
}

//function definition to drop a student from course
int drop_std()
{
	//decleration of variables
	int ch,flag=0;
	char str[40];
	int no;
	
	//To check are there registered students to drop
	if(head==NULL)
	{
		printf("There are no registered students to drop.");
		printf("\n");
	}
	else
	{
		
		//taking student name or rollno who wants to drop
	printf("Enter");
	printf("\n");
	printf("1 to Enter name of student to drop:");
	printf("\n");
	printf("2 to Enter rollno of student to drop:");
	printf("\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			
			//case of taking student name
			printf("Enter name:");
			scanf("%s",str);
			break;
		case 2:
			
			//case of taking student rollno
			printf("Enter rollno:");
			scanf("%d",&no);
			break;
		default:
			
			//case to show, select valid choice
			printf("Enter valid choice.");
			break;
	}
	
	//comparing the student details with registered students, to drop
	temp=head;
	while(temp!=NULL)
	{
		if(!strcmp(temp->name,str) || temp->rollno==no)
		{
			
			if(temp==head)
			{
				
				//condition when the student to drop is first registered student
				head=temp->next;
				
				//dropping student by removing all the details
				free(temp);
				
				//to check whether there is a student to drop or not
				flag=1;
				break;
			}
			else
			{
				
				//condition when the student to drop is other than first registered student
		    	prev->next=temp->next;
		    	
		    	//dropping student by removing all the details
			    free(temp);
			    
			    //to check whether there is a student to drop or not
			    flag=1;
			    break;
			}
		}
		prev=temp;
		
		//moving to next student details while comparing 
		temp=temp->next;
	}
	
	//To show the possibility to drop a student
	if(flag==1)
	{
		count--;
		
		//showing the condition of droping student
		printf("Student was dropped successfully.");
		printf("\n");
	}
	else
	{
		
		//case that there is no student with given name or rollno, to drop
		if(ch==1)
		{
			printf("There is no student named %s to drop.",str);
			printf("\n");
		}
		else if(ch==2)
		{
			printf("There is no student with rollno %d to drop.",no);
			printf("\n");
		}
	}
    }
}

//function definition to display the registered student details
int display()
{
	temp=head;
	
	//To check are there any registered students to display
	if(head==NULL)
	{
		printf("There are no registered students to display.");
	}
	else
	{
		
		//showing the registered students details
	while(temp!=NULL)
	{
		printf("%s %d %s %s %s %d",temp->name,temp->rollno,temp->course,temp->mobile_no,temp->gender,temp->age);
		printf("\n");
		
		//moving to next student
		temp=temp->next;
	}
    }
}

//function definition to search the details of a particular student
int search_std()
{
	//decleration of variables
	int ch,flag=0;
	char str[40];
	int no;
	
	//To check are there registered students, to search for particular student
	if(head==NULL)
	{
		printf("There are no registered students to search details of a student.");
		printf("\n");
	}
	else
	{
		
		//taking student name or rollno, to search
	printf("Enter");
	printf("\n");
	printf("1 to Enter name of student to search:");
	printf("\n");
	printf("2 to Enter rollno of student to search:");
	printf("\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			
			//case of taking student name
			printf("Enter name:");
			scanf("%s",str);
			break;
		case 2:
			
			//case of taking student rollno
			printf("Enter rollno:");
			scanf("%d",&no);
			break;
		default:
			
			//case to show, select valid choice
			printf("Enter valid choice.");
			break;
	}
	
	//comparing the student details with registered students, to show that student details
	temp=head;
	while(temp!=NULL)
	{
		if(!strcmp(temp->name,str) || temp->rollno==no)
		{
			
			//showing the details of searched student
			printf("%s %d %s %s %s %d",temp->name,temp->rollno,temp->course,temp->mobile_no,temp->gender,temp->age);
			printf("\n");
			flag++;
			break;
		}
		
		//moving to next student details while comparing 
		temp=temp->next;
	}
	
	//To show the searching possibility of a student
	if(flag==0)
	{
		if(ch==1)
		{
			printf("No student with name %s is found.",str);
			printf("\n");
		}
		else if(ch==2)
		{
			printf("No student with rollno %d is found.",no);
			printf("\n");
		}
	}
    }
}

//function definition to change the details of a student
int changes_in_details()
{
	//decleration of variables
	int ch,flag=0;
	char str[40];
	int no;
	
	//checking that are there any registered students or not
	if(head==NULL)
	{
		printf("There are no registered students to modify details of a student.");
		printf("\n");
	}
	else
	{
		
	//taking student name or rollno to modify details
	printf("Enter");
	printf("\n");
	printf("1 to Enter name of student to modify details:");
	printf("\n");
	printf("2 to Enter rollno of student to modify details:");
	printf("\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			
			//case of taking student name
			printf("Enter name:");
			scanf("%s",str);
			break;
		case 2:
			
			//case of taking student rollno
			printf("Enter rollno:");
			scanf("%d",&no);
			break;
		default:
			
			//case to show, select valid choice
			printf("Enter valid choice.");
			break;
	}
	
	//comparing the student details with registered students,to modify details
	temp=head;
	while(temp!=NULL)
	{
		if(!strcmp(temp->name,str) || temp->rollno==no)
		{
			
			//taking the modified details of student
			printf("Enetr student details Name,Rollno,Course,Mobile_no,Gender,Age:");
			printf("\n");
			scanf("%s %d %s %10s %s %d",temp->name,&temp->rollno,temp->course,temp->mobile_no,temp->gender,&temp->age);
			flag++;
			break;
		}
		
		//moving to next student details while comparing 
		temp=temp->next;
	}
	
	//To show the non existence of student in registered students, to modify details 
	if(flag==0)
	{
		if(ch==1)
		{
			printf("No student with name %s is found.",str);
			printf("\n");
		}
		else if(ch==2)
		{
			printf("No student with rollno %d is found.",no);
			printf("\n");
		}
	}
	else
	{
		printf("details are modified successfully.");
	}
    }
}

//function definition to add student details in .csv file
int add_csv(FILE*fp)
{
	
	//opening .csv file to add student details
    fp=fopen("stdr.csv","a");
    fprintf(fp,"%d,%s,%d,%s,%10s,%s,%d\n",count,newnode->name,newnode->rollno,newnode->course,newnode->mobile_no,newnode->gender,newnode->age);
    
    //closing of .csv file
	fclose(fp);
}

//function definition to modify student details in .csv file after dropping a student from course
int modify_csv(FILE*fp)
{
	
	//opening .csv file to maintain student details
    fp=fopen("stdr.csv","a");
    fprintf(fp,"Sl.No,Name,Rollno,Course,Mobile_no,Gender,Age\n");
    
    //storing student details in .csv file
    temp=head;
    int i=1;
    while(temp!=NULL)
    {
        fprintf(fp,"%d,%s,%d,%s,%s,%s,%d\n",i,temp->name,temp->rollno,temp->course,temp->mobile_no,temp->gender,temp->age);
        temp=temp->next;
        i++;
    }
    
    //closing of .csv file
    fclose(fp);
}

//function definition to find total number of students registered till now
int no_of_regstd()
{
	
	//showing number of registered students
	printf("Total number of students registered till now is:%d",count);
	printf("\n");
}
