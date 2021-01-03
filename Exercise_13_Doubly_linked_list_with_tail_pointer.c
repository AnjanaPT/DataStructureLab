#include<stdio.h>
#include<stdlib.h>
struct node
{
int num;
struct node*next;
struct node*prev;
};
int main()
{
struct node*head,*temp,*newnd,*rear;
int op,value,p,c=0,i,sr,srl;
head=temp=rear=NULL;
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
		 newnd->prev=NULL;
		 head=rear=newnd;c++;
		}
	    else
		{
		 temp=head;
		 head=newnd;
		 newnd->next=temp;
		 temp->prev=head;
		 newnd->prev=NULL;c++;
		}
	    break;
     case 2:newnd=(struct node*)malloc(sizeof(struct node));
	    printf("\n------------------------\nEnter A Number : ");
	    scanf("%d",&newnd->num);
	    if(head==NULL)
		{
		 newnd->next=NULL;
		 newnd->prev=NULL;
		 head=rear=newnd;c++;
		}
	    else
		{
		 temp=rear;
		 temp->next=newnd;
		 newnd->next=NULL;
		 newnd->prev=temp; 
		 rear=newnd;
		 c++;
		}
	    break;
     case 3:newnd=(struct node*)malloc(sizeof(struct node));
	    printf("\n------------------------\nEnter A Number : ");
	    scanf("%d",&newnd->num);
	    if(head==NULL)
		{
		 newnd->next=NULL;
		 newnd->prev=NULL;
		 head=rear=newnd;c++;
		}
	    else
		{
		 position:
		 printf("\n------------------------\nEnter The Position : ");
	    	 scanf("%d",&p);
		 temp=head;
		 if(p>c+1 || p<1){printf("\nEnter A Position In Between 0 and %d..!!",c+2);goto position;}
		 for(i=1;i<p-1;i++)
		 {
		   temp=temp->next;
		 }
		 if(p==1)
		   {newnd->next=head;head->prev=newnd;newnd->prev=NULL;head=newnd;}
		 else 
		   {newnd->next=temp->next;temp->next=newnd;newnd->prev=temp;
		     if((newnd->next)!=NULL)(newnd->next)->prev=newnd;
		     else
			rear=newnd;
		   }
		 c++;
		}
	    break;
     case 4:if(head==NULL)
		{
		 printf("\n------------------------\nNo Number Is Inserted Yet..!!");
		}
	     else if(head->next==NULL)
		{
		  value=head->num;
		  head=rear=NULL;
		  printf("\n%d Is Deleted ",value);c--;
		}	
	     else
		{
		  temp=head;
		  value=head->num;
	 	  head=temp->next;
		  head->prev=NULL;
		  printf("\n%d Is Deleted ",value);c--;
		}
	    break;
      case 5:if(head==NULL)
		{
		 printf("\n------------------------\nNo Number Is Inserted Yet..!!");
		}
	     else if(head->next==NULL)
		{
		  value=head->num;
		  head=rear=NULL;
		  printf("\n%d Is Deleted ",value);c--;
		}	
	     else
		{
		  temp=rear;
		  value=temp->num;
	 	  rear=temp->prev;
		  rear->next=NULL;
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
		    value=head->num;head=rear=NULL;
		  }
		 else
		  {
		    position2:
		    printf("\n------------------------\nEnter The Position : ");
	    	    scanf("%d",&p);
		    temp=head;
		    if(p>c || p<1){printf("\nEnter A Position Between 0 and %d..!!",c+1);goto position2;}
		    for(i=1;i<p;i++)
		     {
		      temp=temp->next;
		     }
		    if(p==1)
		     {value=head->num;head=head->next;head->prev=NULL;}
		    else 
		     {value=temp->num;(temp->prev)->next=temp->next;
		      if(temp->next!=NULL)(temp->next)->prev=temp->prev;
		      else
			rear=temp->prev;
		     }
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
		  while(temp!=rear)
		    {
			printf("\n%d",temp->num);
			temp=temp->next;
		    }printf("\n%d",temp->num);
		}
	    break;
     case 8:if(head==NULL)
		{
		 printf("\n------------------------\nNo Number Is Inserted Yet..!!");
		}
	     else
		{
		  printf("\n------------------------\nEnter The Element To Be Searched : ");
		  scanf("%d",&srl);
		  temp=head;sr=0;
		  while(temp!=rear)
		    {
			if(temp->num==srl)sr++;
			temp=temp->next;
		    }
		  if(sr>0)
			printf("\n%d Is Present %d Times In This List",srl,sr);
		  else 
			printf("\n%d Isn't Present In This List ",srl);
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