#include<stdio.h>
#include<conio.h>
int main()
{
    int i,m,n,cqu[100],op,opt,front=-1,rear=-1,sr,c,f;
    printf("\nEnter the size of circular queue : ");
    scanf("%d",&n);
    do
    {
        printf("\n-----------------------\n1 : Enqueue\n2 : Dequeue\n3 : Traverse\n4 : SEARCH\n5 : EXIT\n----------------------\nEnter your option : ");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
            if((rear+1)%n==front)
	    printf("\n-----------------------\nQueue is overflow");
	    else
	    {
	    if(front==-1)front=0;
	    printf("Enter the element to be inserted : ");
            scanf("%d",&m);
            rear=(rear+1)%n;
	    cqu[rear]=m;
	    printf("\n-----------------------\n%d is inserted",m);
            }
            break;
	    case 2:
	    if(front==-1 || rear==-1)
	    printf("\n-----------------------\nQueue is underflow");
	    else
	    {
            m=cqu[front];
	    if(front==rear)
		front=rear=-1;
	    else
		front=(front+1)%n;
	    printf("\n-----------------------\n%d is deleted from the queue",m);
            }
	    break;
            case 3:
	    if(front==-1 || rear==-1)
	    printf("\n-----------------------\nQueue is Empty");
	    else
	    {
            printf("\n-----------------------\nQUEUE ELEMENTS ARE\n-----------------------\n");
	    if(front>rear)
	      {
		for(i=rear;i>=0;i--)
		printf("%d\n",cqu[i]);
		for(i=n-1;i>=front;i--)
		printf("%d\n",cqu[i]);
	      }
	    else
	      {
		for(i=rear;i>=front;i--)
            	printf("%d\n",cqu[i]);
	      }
	    }
	    break;
	    case 4:
	    if(front==-1 || rear==-1)
	    printf("\n-----------------------\nQueue is Empty");
	    else
	    {
		printf("\nEnter the number to be searched : ");
	    	scanf("%d",&sr);
		c=0;f=front;
		while(f!=rear)
	    	  {
			if(cqu[f]==sr)c++;
			f=(f+1)%n;
		  }if(cqu[f]==sr)c++;
	    	if(c>0)
			printf("%d is presented %d times in this queue ",sr,c);
	    	else
			printf("%d is not presented in this queue ",sr);
	     }
	    break;
            case 5:
	    printf("\n-----------EXIT-----------");
	    return 0;
	    break;
            default :
            printf("\n-----------------------\nEnter a valid option");
            break;
	    }
    }while(op!=5);
    return 0;
}