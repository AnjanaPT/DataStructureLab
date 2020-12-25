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
    struct node*front,*temp,*newnd;
    front=NULL;
    do
    {
        printf("\n-----------------------\n1 : Enqueue\n2 : Dequeue\n3 : Traverse\n4 : EXIT\n----------------------\nEnter your option : ");
        scanf("%d",&op);
        switch(op)
        {
            case 1:newnd=(struct node*)malloc(sizeof(struct node));
		   printf("Enter the element to be inserted : ");
            	   scanf("%d",&newnd->num); 
		   if(front==NULL)
		     {
			front=newnd;
			front->next=NULL;
		     }
		   else
		     {
			temp=front;
            	   	while(temp->next!=NULL)
		   	  {
			    temp=temp->next;
			  }
			temp->next=newnd;
			newnd->next=NULL;
		     }
	   	   printf("\n-----------------------\n%d is inserted",newnd->num);
            break;
	    case 2:if(front==NULL)
	    	     {
			printf("\n-----------------------\nQueue Is In Underflow");
		     }
	    	   else
	    	     {
            		m=front->num;
	    		front=front->next;
	    		printf("\n-----------------------\n%d is deleted from the queue",m);
		     }
	    break;
            case 3:if(front==NULL)
	    	     {
			printf("\n-----------------------\nQueue Is In Underflow");
		     }
	    	   else
	    	     {
            		temp=front;
			while(temp->next!=NULL) 
			  {
			      printf("%d\n",temp->num);
			      temp=temp->next;
			  }
			printf("%d\n",temp->num);
		     }
	    break;
            case 4:printf("\n-----------EXIT-----------");
	    	   return 0;
	    break;
            default:printf("\n-----------------------\nEnter a valid option");
            break;
	    }
    }while(op!=4);
    return 0;
}