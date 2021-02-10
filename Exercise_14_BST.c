#include<stdio.h>
#include<stdlib.h>
struct node
{
int num;
struct node*left;
struct node*right;
};
typedef struct node st;
st*insertNode(st*,int);
st*deleteNode(st*,int);
st*successor(st*);
void searchNode(st*,int);
void inOrder(st*); 
void preOrder(st*); 
void postOrder(st*); 
int main()
{
int op,xi,xd,xs;
st*root,*sn;
root=NULL;
do
{
printf("\n-------------------------------\n1 : Insertion\n2 : Deletion\n3 : Search\n4 : Inorder Traversal\n5 : Preorder Traversal\n6 : Posrorder Traversal\n7 : EXIT");
printf("\n-------------------------------\nEnter Your Option : ");
scanf("%d",&op);
  switch(op)
  {
   case 1:printf("\nEnter The Element To Be Inserted : ");
	  scanf("%d",&xi);
	  root=insertNode(root,xi);
	  printf("\nRoot =%d memory=%d",root->num,root);
	  break;
   case 2:if(root==NULL){
	    	printf("Tree Is Empty !!");
		break;
	  }
	  printf("\nEnter The Element To Be Deleted : ");
	  scanf("%d",&xd);
	  root=deleteNode(root,xd);
	  printf("root memory %d ",root);
	  break;
   case 3:if(root==NULL){
	    	printf("Tree Is Empty !!");break;
	  }
	  printf("\nEnter The Element You Want To Search : ");
	  scanf("%d",&xs);
	  searchNode(root,xs);
	  break;
   case 4:if(root==NULL){
	    	printf("Tree Is Empty !!");break;
	  }
	  inOrder(root);
	  break;
   case 5:if(root==NULL){
	    	printf("Tree Is Empty !!");break;
	  }
	  preOrder(root);
	  break;
   case 6:if(root==NULL){
	    	printf("Tree Is Empty !!");break;
	  }
	  postOrder(root);
	  break;
   case 7:printf("\n------E X I T------");
	  return 0;
   default:printf("Enter A Valid Option !!");
  }
 }while(op!=7);
}
st*insertNode(st*newnd,int xi){
	if(newnd==NULL){
		newnd=(st*)malloc(sizeof(st));
		newnd->num=xi;
		newnd->left=newnd->right=NULL;
	}
	else if(newnd->num == xi){
		printf("\nDuplicate Node");
	}
	else if(xi>newnd->num){
		newnd->right=insertNode(newnd->right,xi);
	}
	else if(xi<newnd->num){
		newnd->left=insertNode(newnd->left,xi);
	}
	return(newnd);
}
st*successor(st*newnd){
	while(newnd->left!=NULL){
		newnd=newnd->left;
	}
	return newnd;		
}
st*deleteNode(st*newnd,int xd){
	st*temp=newnd;
	if(newnd==NULL){
		printf("%d Is Not Found",xd);
	}
	else if(xd>newnd->num){
		newnd->right=deleteNode(newnd->right,xd);
	}
	else if(xd<newnd->num){
		newnd->left=deleteNode(newnd->left,xd);
	}
	else{
		if(newnd->left==NULL && newnd->right==NULL){
			free(newnd);newnd=NULL;
		}
		else if(newnd->left==NULL){
			newnd=newnd->right;free(temp);
		}
		else if(newnd->right==NULL){
			newnd=newnd->left;free(temp);
		}
		else{
			temp=successor(newnd->right);
			newnd->num=temp->num;
			newnd->right=deleteNode(newnd->right,temp->num);			
		}
	}
	return newnd;
}

void inOrder(st*newnd){
	if(newnd==NULL){return;}
	inOrder(newnd->left);
	printf("\n%d",newnd->num);
	inOrder(newnd->right);
}
void preOrder(st*newnd){
	if(newnd==NULL){return;}
	printf("\n%d",newnd->num);
	preOrder(newnd->left);
	preOrder(newnd->right);
}
void postOrder(st*newnd){
	if(newnd==NULL){return;}
	postOrder(newnd->left);
	postOrder(newnd->right);
	printf("\n%d",newnd->num);
}
void searchNode(st*newnd,int xs){
	if(newnd==NULL){
		printf("%d Is Not Found",xs);
		return;
	}
	if(newnd->num==xs){
		printf("%d Is Found",xs);
		return;
	}
	else if(xs>newnd->num){
		searchNode(newnd->right,xs);
	}
	else if(xs<newnd->num){
		searchNode(newnd->left,xs);
	}
}