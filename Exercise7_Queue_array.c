#include<stdio.h>
#include<conio.h>
int main()
{
    int i,m,n,qu[100],op,opt,front=-1,rear=-1;
    printf("\nEnter the size of queue : ");
    scanf("%d",&n);
    do
    {
        printf("\n-----------------------\n1 : Enqueue\n2 : Dequeue\n3 : Traverse\n4 : EXIT\n----------------------\nEnter your option : ");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
            if(rear==n-1)
	    printf("\n-----------------------\nQueue is overflow");
	    else
	    {
	    if(front==-1)front=0;
	    printf("Enter the element to be inserted : ");
            scanf("%d",&m);
            rear++;
	    qu[rear]=m;
	    printf("\n-----------------------\n%d is inserted",m);
            }
            break;
	    case 2:
	    if(front==-1 || front>rear)
	    printf("\n-----------------------\nQueue is underflow");
	    else
	    {
            m=qu[front];
	    front++;
	    printf("\n-----------------------\n%d is deleted from the queue",m);
	    if(front>rear)front=rear=-1;
            }
	    break;
            case 3:
	    if(front==-1 || front>rear)
	    printf("\n-----------------------\nQueue is Empty");
	    else
	    {
            printf("\n-----------------------\nQUEUE ELEMENTS ARE\n-----------------------\n");
            for(i=rear;i>=front;i--)
            printf("%d\n",qu[i]);
            }
	    break;
            case 4:
	    printf("\n-----------EXIT-----------");
	    return 0;
	    break;
            default :
            printf("\n-----------------------\nEnter a valid option");
            break;
	    }
    }while(op!=4);
    return 0;
}