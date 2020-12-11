#include<stdio.h>
#include<conio.h>
int main()
{
    int i,m,n,st[100],op,top=-1;
    printf("Enter the size of stack : ");
    scanf("%d",&n);
    do
    {
        printf("\n-----------------------\n1 : Push\n2 : Pop\n3 : Traverse\n4 : EXIT\n------------------------\nEnter your option : ");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
            if(top==n-1)
	    printf("\n-----------------------\nStack is overflow");
	    else
	    {
	    printf("Enter the element to be inserted : ");
            scanf("%d",&m); 
            top++;
	    st[top]=m;
	    printf("\n-----------------------\n%d is inserted",m);
            }
            break;
	    case 2:
	    if(top==-1)
	    printf("\n-----------------------\nStack is underflow");
	    else
	    {
            m=st[top];
	    top--;
	    printf("\n-----------------------\n%d is deleted from the stack",m);
            }
	    break;
            case 3:
	    if(top==-1)
	    printf("\n-----------------------\nStack is underflow");
	    else
	    {
            printf("\nSTACK ELEMENTS ARE\n----------------------------------------\n");
            for(i=top;i>=0;i--)
            printf("%d\n",st[i]);
            }
	    break;
	    case 4:
	    printf("\n------------EXIT------------");
	    return 0;
	    break;
            default :
            printf("\n-----------------------\nEnter a valid option");
            break;
	    }
    }while(op!=4);
    return 0;
}