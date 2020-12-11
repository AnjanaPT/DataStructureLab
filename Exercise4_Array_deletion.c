#include<stdio.h>
#include<conio.h>
int main()
{
    int i,n,m,pos,ar[100],op;
    printf("Enter the number of array elements : ");
    scanf("%d",&n);
    printf("Enter the array elements \n");
    for(i=0;i<n;i++)
     scanf("%d",&ar[i]);
    do
    {
        printf("\n-----------------------\n1 : Deletion\n2 : Display\n3 : EXIT\n-------------------------\nEnter your option : ");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
            position:
	    if(n==0)
	    {
	    printf("\n------Array is empty------");
	    printf("\n-----------EXIT-----------");
	    return 0;
	    }
            printf("Enter the position from which the element to be deleted : ");
            scanf("%d",&pos);
	    m=ar[pos-1];
            if(pos > n || pos <= 0)
            {
                printf("\n-----------------------\nEnter a valid position\n-----------------------\n");
                goto position;
            }
            else
            {
                for(i=pos;i<n;i++)
        	ar[i-1]=ar[i];
    		n--;
                printf("\n-----------------------\n%d is deleted from the position %d",m,pos);
            }
            break;
            case 2:
	    if(n==0)
	    {
	    goto position;
	    }
            printf("\n-----------------------\nARRAY ELEMENTS ARE\n-----------------------\n");
            for(i=0;i<n;i++)
            printf("%d\t",ar[i]);
            break;
            case 3:
	    printf("\n-----------EXIT-----------");
	    return 0;
	    break;
            default :
            printf("\n-----------------------\nEnter a valid option");
            break;
	    }
    }while(op!=3);
    return 0;
}