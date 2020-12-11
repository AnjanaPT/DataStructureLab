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
        printf("\n-----------------------\n1 : Insertion\n2 : Display\n3 : EXIT\n------------------------\nEnter your option : ");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
            printf("Enter the element to be inserted : ");
            scanf("%d",&m);
            position:
            printf("Enter the position on which the element to be inserted : ");
            scanf("%d",&pos);
            if(pos > n+1 || pos <= 0)
            {
                printf("\n-----------------------\nEnter a valid position\n-----------------------\n");
                goto position;
            }
            else
            {
                for(i=n;i>=pos-1;i--)
                ar[i+1]=ar[i];
                ar[i+1]=m;
                n++;
                printf("\n-----------------------\n%d is inserted at the position %d",m,i+2);
            }
            break;
            case 2:
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