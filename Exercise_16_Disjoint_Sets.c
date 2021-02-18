#include<stdio.h>
int setU[50],parent[50];
int sizeU=0;
void makeSet();
int findSet(int a);
int search(int a);
void printSet(char u,int a);
void unionDS(int a,int b);
void main()
{
	int op,a,n1,n2;char ch;
	do{
		printf("\n---------------------------------\n");
		printf(" 1 : Make Set\n 2 : Find Set\n 3 : Union\n 4 : Print Set\n 5 : E X I T\n---------------------------------");
		printf("\nEnter Your Option : ");
		scanf("%d",&op);
		printf("\n---------------------------------\n");
		switch(op){
			case 1: makeSet();
				break;
			case 2: if(sizeU<=0)printf("\nRead Elements First");
				else{
					element:
					printf("\nEnter The Element : ");
					scanf("%d",&a);
					if(search(a)==0){goto element;}
					printf("\nRepresentative Of %d Is %d",a,findSet(a));
				}
				break;
			case 3: if(sizeU<=1)printf("\nRead Elements First");
				else{
					union1:
					printf("\nEnter The Element 1: ");
					scanf("%d",&n1);
					if(search(n1)==0){goto union1;}
					union2:
					printf("\nEnter The Element 2: ");
					scanf("%d",&n2);
					if(search(n2)==0){goto union2;}
					if(findSet(n1)==findSet(n2))
					{
						printf("\nBoth %d And %d Are Already Belongs To The Same Set",n1,n2);
					}
					else {
						unionDS(n1,n2);
					}
				}
				break;
			case 4: if(sizeU<=0)printf("\nRead Elements First");
				else{
					print:
					printf("\nEnter The Element : ");
					scanf("%d",&a);
					if(search(a)==0){goto print;}
					printSet('S',a);
				}
				break;
			case 5: printf("\n-------------E X I T-------------\n");
				break;
			default:printf("Enter A Valid Option !!");
		}
	}while(op!=5);
}
void makeSet(){
	int a,i,f;
	duplicate:
	f=0;
	printf("\nEnter The Element : ");
	scanf("%d",&a);
	for(i=0;i<sizeU;i++){
		if(a==setU[i]){f=1;break;}
	}
	if(f==1)
	{
		printf("\n%d Is Already Inserted.You Can't Enter Duplicate Elements!!",a);
		printSet('U',0);goto duplicate;
	}
	parent[a]=setU[sizeU++]=a;
	return;
}
int findSet(int a){
	if(a==parent[a])
		return a;
	else
		return findSet(parent[a]);
}
int search(int a){
	int i;
	for(i=0;i<sizeU;i++){
		if(a==setU[i])return 1;
	}
	printf("\nYou Must Enter An Element That Can Be Found In The Universal Set!!");
	printSet('U',0);
	return 0;	
}
void printSet(char ch,int a){
	int i,fa;
	if(ch=='U'){
		printf("\nUniversal Set : { %d",setU[0]);
		for(i=1;i<sizeU;i++){
			printf(", %d",setU[i]);
		}printf("}");	
	}
	if(ch=='S'){
		fa=findSet(a);
		printf("\nThe Element %d Belongs To : { %d",a,fa);
		for(i=0;i<sizeU;i++){
			if((findSet(setU[i])==fa) && (fa!=setU[i]))
				printf(", %d",setU[i]);
		}printf("}");	
	}
	return;	
}
void unionDS(int a,int b){
	parent[findSet(b)]=findSet(a);
	printSet('S',b);printSet('S',a);
	return;
}