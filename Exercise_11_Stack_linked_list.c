#include<stdio.h>
#include<stdlib.h>
struct node
{
   int num;
   struct node*next;
};
int main()
{
    int i,m,op;
    struct node*top,*temp,*newnd;
    top=NULL;
    do
    {
        printf("\n-----------------------\n1 : Push\n2 : Pop\n3 : Traverse\n4 : EXIT\n------------------------\nEnter your option : ");
        scanf("%d",&op);
        switch(op)
        {
            case 1:newnd=(struct node*)malloc(sizeof(struct node));
		   printf("Enter the element to be inserted : ");
            	   scanf("%d",&newnd->num); 
            	   newnd->next=top;
		   top=newnd;
	   	   printf("\n-----------------------\n%d is inserted",newnd->num);
            break;
	    case 2:if(top==NULL)
	    	   printf("\n-----------------------\nStack Is In Underflow");
	    	   else
	    	    {
            	       m=top->num;
	    	       top=top->next;
	    	       printf("\n-----------------------\n%d is deleted from the stack",m);
            	    }
	    break;
            case 3:if(top==NULL)
	    	   printf("\n-----------------------\nStack Is In Underflow");
	    	   else
	    	    {
            	       printf("\nSTACK ELEMENTS ARE\n----------------------------------------\n");
            	       temp=top;
		       while(temp->next!=NULL)
			{
            	          printf("%d\n",temp->num);
			  temp=temp->next;
			}
			printf("%d\n",temp->num);
           	    }
	    break;
	    case 4:printf("\n------------EXIT------------");
	    	   return 0;
	    break;
            default:printf("\n-----------------------\nEnter a valid option");
            break;
	}
    }while(op!=4);
    return 0;
}