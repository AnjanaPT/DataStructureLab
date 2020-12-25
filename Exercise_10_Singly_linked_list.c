#include<stdio.h>
#include<stdlib.h>
struct node
{
int num;
struct node*next;
};
int main()
{
struct node*head,*temp,*newnd;
int op,value,p,c=0,i,sr,srl;
head=temp=NULL;
do
  {
  option:
  printf("\n------------------------\n1 : Insert At The Front\n2 : Insert At The End\n3 : Insert At A Specific Position");
  printf("\n4 : Delete From The Front\n5 : Delete From The End\n6 : Delete From A Specific Position\n7 : Traversal");
  printf("\n8 : SEARCH\n9 : EXIT\n\nEnter Your Option : ");
  scanf("%d",&op);
  switch(op)
    {
     case 1:newnd=(struct node*)malloc(sizeof(struct node));
	    printf("\n------------------------\nEnter A Number : ");
	    scanf("%d",&newnd->num);
	    if(head==NULL)
		{
		 newnd->next=NULL;
		 head=newnd;c++;
		}
	    else
		{
		 temp=head;
		 head=newnd;
		 newnd->next=temp;c++;
		}
	    break;
     case 2:newnd=(struct node*)malloc(sizeof(struct node));
	    printf("\n------------------------\nEnter A Number : ");
	    scanf("%d",&newnd->num);
	    if(head==NULL)
		{
		 newnd->next=NULL;
		 temp=head=newnd;c++;
		}
	    else
		{
		 temp=head;
		 while(temp->next!=NULL)
		    temp=temp->next;
		 temp->next=newnd;
		 newnd->next=NULL;c++;
		}
	    break;
     case 3:newnd=(struct node*)malloc(sizeof(struct node));
	    printf("\n------------------------\nEnter A Number : ");
	    scanf("%d",&newnd->num);
	    if(head==NULL)
		{
		 newnd->next=NULL;
		 head=newnd;c++;
		}
	    else
		{
		 position:
		 printf("\n------------------------\nEnter The Position : ");
	    	 scanf("%d",&p);
		 temp=head;
		 if(p>c+1 || p<1){printf("\nEnter A Position In Between 0 and %d",c+2);goto position;}
		 for(i=1;i<p-1;i++)
		 {
		   temp=temp->next;
		 }
		 if(p==1)
		   {newnd->next=head;head=newnd;}
		 else 
		   {newnd->next=temp->next;temp->next=newnd;}
		 c++;
		}
	    break;
     case 4:if(head==NULL)
		{
		 printf("\n------------------------\nNo Number Is Inserted Yet");
		}
	     else if(head->next==NULL)
		{
		  value=head->num;
		  head=NULL;
		  printf("\n%d Is Deleted ",value);c--;
		}	
	     else
		{
		  temp=head;
		  value=head->num;
	 	  head=temp->next;
		  printf("\n%d Is Deleted ",value);c--;
		}
	    break;
      case 5:if(head==NULL)
		{
		 printf("\n------------------------\nNo Number Is Inserted Yet");
		}
	     else if(head->next==NULL)
		{
		  value=head->num;
		  head=NULL;
		  printf("\n%d Is Deleted ",value);c--;
		}	
	     else
		{
		  temp=head;
		  while((temp->next)->next!=NULL)
		    temp=temp->next;
		  value=(temp->next)->num;
	 	  temp->next=NULL;
		  printf("\n%d Is Deleted ",value);c--;
		}
	    break;
    case 6:if(head==NULL)
		{
		 printf("\n------------------------\nNo Number Is Inserted Yet");
		}
	    else
	    	{
		 if(c==1)
		  {
		    value=head->num;head=NULL;
		  }
		 else
		  {
		    position2:
		    printf("\n------------------------\nEnter The Position : ");
	    	    scanf("%d",&p);
		    temp=head;
		    if(p>c || p<1){printf("\nEnter A Position Between 0 and %d",c+1);goto position2;}
		    for(i=1;i<p-1;i++)
		     {
		      temp=temp->next;
		     }
		    if(p==1)
		     {value=head->num;head=head->next;}
		    else 
		     {value=(temp->next)->num;temp->next=(temp->next)->next;}
		   }
		  printf("\n%d Is Deleted ",value);c--;
		 }
	    break;
     case 7:if(head==NULL)
		{
		 printf("\n------------------------\nNo Number Is Inserted Yet");
		}
	     else
		{
		  printf("\n------------------------\nELEMENTS ARE");
		  temp=head;
		  while(temp->next!=NULL)
		    {
			printf("\n%d",temp->num);
			temp=temp->next;
		    }printf("\n%d",temp->num);
		}
	    break;
     case 8:if(head==NULL)
		{
		 printf("\n------------------------\nNo Number Is Inserted Yet");
		}
	     else
		{
		  printf("\n------------------------\nEnter The Element To Be Searched : ");
		  scanf("%d",&srl);
		  temp=head;sr=0;
		  
		  while(temp!=NULL)
		    {
			if(temp->num==srl)sr++;
			temp=temp->next;
		    }
		  if(sr>0)
			printf("\n%d Is Presented %d Times ",srl,sr);
		  else 
			printf("\n%d Isn't Presented ",srl);
		}
	    break;
     case 9:printf("\n------------E X I T-------------");
	    return 0;
     default:printf("------------------------\nInvalid Option..!!");
	     break;
    }
  }while(op!=10);
return 0;
}