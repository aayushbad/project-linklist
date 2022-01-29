#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <ctype.h>
int cnum=0;
struct room {
    int number;        /*unique account number*/
    char name[20];     /*contains name*/
    char aadhar[15];    /*contains aadhar number*/
    char email[20];           /*contains email address*/
    struct room *next; /*next is used to navigate through structures.*/
    int count;   
    } ;
    struct room  *currentc;
    struct room  *addNewroom(struct room  *head)
{ cnum++;
   struct room  *currentc = (struct room  *)malloc(sizeof(struct room ));
    printf("\n","room number ",cnum);/*cnum is used to give unique room numbers*/
     currentc->number = cnum;
    char nam[20];
    printf("\nEnter the name \n");
    scanf("%s", nam);
		fflush(stdin);
      printf("Enter contact aadhar number \n");
    gets(currentc->aadhar);
    	fflush(stdin);
 printf("Enter contact email\n");
    gets(currentc->email);
	fflush(stdin);
     
    strcpy( currentc->name, nam);
     currentc->next = NULL;
     if(head==NULL)
     {
         head=currentc;
    }
    else{
        head->next=currentc;
        head=currentc;
    }
    return head;
}
void listAll(struct room  *firstc) /* list all room details function*/
{
    if(firstc==NULL)
	puts("There are no room details to display!"); 
    else
    {
	    printf("%6s %-20s %-15s %-15s\n","Acct#","Name","aadhar","Email");
	puts("------ -------------------- ------------- -------------------");
	currentc=firstc;
	do
	{
		printf("%6d: %-20s %-15s %-20s\n",
		currentc->number,
		currentc->name,
		currentc->aadhar,
		currentc->email);

		/*prints values of number, name, aadhar and email*/
        currentc=currentc->next;
	}
	while( currentc!= NULL);
    }
}
void deleteroom(struct room  *firstc)     /*delete contact function */
{
    int record;
   
    if(firstc==NULL)
    {
	puts("There are no room details to delete!");
	return;
    }

    listAll(firstc);		/* show all records*/
    printf("Enter room number to delete: ");
    scanf("%d",&record);
    struct room  *currentc = firstc;
    if(currentc->number ==record)
    {
firstc=currentc->next;
free(currentc);
 printf("room deatils %d deleted!\n",record);
	    return;
    }
    currentc=currentc->next;
     struct room *previousa=firstc;
    while(currentc != NULL)
    {
	if(currentc->number == record)
	{
	    previousa->next=currentc->next;
        free(currentc);

	    printf("room deatils %d deleted!\n",record);
	    return;

	}
	else
	{
	    currentc = currentc->next;
        previousa=previousa->next;
	}
    }
    printf("room details %d not found!\n",record);
 }
 int findnum (struct room  *firstc,int recordnum)
{
    int record;
    record = recordnum;
    currentc = firstc;
    while(currentc != NULL)
    {
	if(currentc->number == record)
	     {
	   return 1;
	 }
	else
	{
	    currentc = currentc->next;
	}
    }
    return -1;
}
int prompt(void)
{
	char ch;
    fflush(stdin);
	printf("Update? (Y to update any other key to not)");
	ch = getchar();
	ch = toupper(ch);
	fflush(stdin);
	if(ch == 'Y')
	{
		printf("Enter new value: ");
		return(1);
	}
	else
		return(0);
}
void modifyroom(struct room  *firstc)   /*modify contact function*/
{
    int record, result;
    if(firstc==NULL)
    {
	puts("There are no room details to modify!");
	return;
    }

    listAll(firstc);	
    	/* show all records */
    printf("Enter room account number to modify or change: ");
    scanf("%d",&record);  
    result = findnum(firstc,record);
    if( result >0 ){
	    printf("Contact no %d:\n",currentc->number);
	    printf("Name: %s\n",currentc->name);
	    if(prompt())
		    gets(currentc->name);
	    printf("aadhar: %s\n",currentc->aadhar);
	    if(prompt())
		    gets(currentc->aadhar);
	    printf("Email: %s\n",currentc->email);
	    if(prompt())
		    gets(currentc->email);
	    return;
	}
    printf("room details %d was not found!\n",record);
}
int findroom(struct room  *firstc) /* find contact function*/
{
     char buff[20];
     if(firstc==NULL)
	{
	puts("There are no room details to find!");
	    return 1;
    }
    printf("Enter room name: ");
    fflush(stdin);/*clears any text from the input stream*/
    gets(buff);
    currentc = firstc;
    while(currentc != NULL)
    {
	if( strcmp(currentc->name, buff) == 0 )
	    {
			printf("%6s %-20s %-15s %-15s\n","Acct#","Name","aadhar","Email");
			/*prints table titles*/
	    printf("%6d: %-20s %-15s %-20s\n",\
	    currentc->number,\
	    currentc->name,\
	    currentc->aadhar,\
	    currentc->email);
			return 0;
	   }
		else
		{         currentc = currentc->next;      }
    }
    printf("contact %s was not found!\n",buff);
	  return 1;
}
int main()
{
   struct room  *head; 
  char ch;   
do
    {
	fflush(stdin);
	puts("\nWelcome To The hotel Database");
	puts("-- -----------------------------");
	puts("1 - Add a new room details");
	puts("2 - Delete history of room details");
	puts("3 - List all room and room details");
	puts("4 - Modify room details");
	puts("5 - Find a room detail by name");
	puts("-- -----------------------------");
	puts("Q - Save and quit\n");
	printf("\tYour choice:");
	ch = getchar();
	    ch = toupper(ch);/*changes user input case to upper case*/
	switch(ch)     
	{
	    case '1':
		puts("Add a new room details \n");
		fflush(stdin);
		head=addNewroom(head);
		break;
	    case '2':
		puts("Delete a room details \n");
		deleteroom(head);
		break;
	    case '3':
		puts("List all room details \n");
		listAll(head);
		break;
	    case '4':
		puts("Modify a room details \n");
		modifyroom(head);
		break;
	    case '5':
		puts("Find a room by name\n");
		findroom(head);
		break;
	    case 'Q':
		puts(" quit\n");

		default:
		break;
	}
    }
    while(ch != 'Q');








return 0;

}
