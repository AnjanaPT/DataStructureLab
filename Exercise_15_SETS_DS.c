#include<stdio.h>
int setA[50],setB[50],setU[50],bitA[50],bitB[50];
int unAB[50],dfAB[50],intrAB[50];
int sizeA=0,sizeB=0,sizeU=0,bA=0,bB=0;
int getUniversalSet(int a[],int size);
int getSet(int a[],int b[],int size);
int printSet(int a[],int size,char);
int duplicate(int s[],int set[],int size);
int search(int);
int getBitString(int a[],int b[],int size,char ch);
void setOperationsAB(int b1[],int b2[],char ch);
void main()
{
	int op,s[50];char ch;
	printf("\n---------------------------------\nEnter The Size Of Universal Set : ");
	scanf("%d",&sizeU);
	sizeU=getUniversalSet(s,sizeU);
	do{
		printf("\n---------------------------------\n 1 : Read Set A\n 2 : Read Set B\n 3 : Print Set");
		printf("\n 4 : Print BitString\n 5 : Union\n 6 : Intersection\n 7 : Difference\n 8 : E X I T\n---------------------------------");
		printf("\nEnter Your Option : ");
		scanf("%d",&op);
		printf("\n---------------------------------\n");
		switch(op){
			case 1: bA=0;
				read_size_A:
				printf("\nEnter The Size Of Set A : ");
				scanf("%d",&sizeA);
				if(sizeA>sizeU){
					printf("\nYou Can Enter A Size Less Than Or Equal To The Size Of Universal Set");
					goto read_size_A;
				}
				sizeA=getSet(setA,bitA,sizeA);
				break;
			case 2: bB=0;
				read_size_B:
				printf("\nEnter The Size Of Set B : ");
				scanf("%d",&sizeB);
				if(sizeB>sizeU){
					printf("\nYou Can Enter A Size Less Than Or Equal To The Size Of Universal Set");
					goto read_size_B;
				}
				sizeB=getSet(setB,bitB,sizeB);
				break;
			case 3: choice:
				printf("Select The Set You Want To Display( U for Universal / A / B ) : ");
				scanf(" %c",&ch);
				if(ch=='U'||ch=='u'){
					printSet(setU,sizeU,ch);	
				}
				else if(ch=='A'||ch=='a'){
					if(printSet(setA,sizeA,ch)==0){
						printf("\nPlease Read The Set Elements First!!");
					}	
				}
				else if(ch=='B'||ch=='b'){
					if(printSet(setB,sizeB,ch)==0){
						printf("\nPlease Read The Set Elements First!!");
					}	
				}
				else{
					printf("\nYou Can Only Choose From The Given Choices\n");
					goto choice;
				}
				break;
			case 4:choice_bit:
				printf("Choose The BitString You Want To Display( A / B ) : ");
				scanf(" %c",&ch);
				if(ch=='A'||ch=='a'){
					if(printSet(setA,sizeA,ch)==0){
						printf("\nPlease Read The Set First!!");
					}
					else{printSet(setU,sizeU,'U');bA=getBitString(setA,bitA,sizeA,ch);}	
				}
				else if(ch=='B'||ch=='b'){
					if(printSet(setB,sizeB,ch)==0){
						printf("\nPlease Read The Set First!!");
					}
					else{printSet(setU,sizeU,'U');bB=getBitString(setB,bitB,sizeB,ch);}	
				}
				else{
					printf("\nYou Can Only Choose From The Given Choices\n");
					goto choice_bit;
				}
				break;
			case 5: if(printSet(setA,sizeA,'A')==0||printSet(setB,sizeB,'B')==0){
					printf("\nPlease Read 2 Sets First!!");
				}
				else if(bA==0||bB==0){
					printf("\nPlease Generate BitString First!!");
				}
				else{
					printSet(setU,sizeU,'U');setOperationsAB(bitA,bitB,'U');
				}
				break;
			case 6: if(printSet(setA,sizeA,'A')==0||printSet(setB,sizeB,'B')==0){
					printf("\nPlease Read 2 Sets First!!");
				}
				else if(bA==0||bB==0){
					printf("\nPlease Generate BitString First!!");
				}
				else{
					printSet(setU,sizeU,'U');setOperationsAB(bitA,bitB,'I');
				}
				break;
			case 7: if(printSet(setA,sizeA,'A')==0||printSet(setB,sizeB,'B')==0){
					printf("\nPlease Read 2 Sets First!!");
				}
				else if(bA==0||bB==0){
					printf("\nPlease Generate BitString First!!");
				}
				else{
					printSet(setU,sizeU,'U');setOperationsAB(bitA,bitB,'D');
				}
				break;
			case 8: printf("\n-------------E X I T-------------\n");
				break;
			default:printf("Enter A Valid Option !!");
		}
	}while(op!=8);
}
int duplicate(int s[],int set[],int size){
	int j,i,c=0,f;
	for(i=0;i<size;i++){
		f=0;
		for(j=0;j<c;j++){
			if(s[i]==set[j]){f=1;break;}	
		}
		if(f==0)set[c++]=s[i];
	}return(c);
}
int getUniversalSet(int s[],int sizeU){
	int i;
	for(i=0;i<sizeU;i++){
		printf("\nEnter Element %d   : ",i+1);
		scanf("%d",&s[i]);
	}
	sizeU=duplicate(s,setU,sizeU);
	return(sizeU);	
}
int getSet(int set[],int bit[],int size){
	int i,s[50];char U;
	for(i=0;i<size;i++){
		read_element:
		printf("\nEnter Element %d   : ",i+1);
		scanf("%d",&s[i]);
		if(search(s[i])==0){
			printf("\nYou Must Enter An Element That Can Be Found In The Universal Set!!");
			printSet(setU,sizeU,'U');
			goto read_element;
		}
	}size=duplicate(s,set,size);
	for(i=0;i<sizeU;i++)
	{bit[i]=0;}
	return(size);
}
int search(int v){
	int i;
	for(i=0;i<sizeU;i++){
		if(setU[i]==v)return 1;	
	}
	return 0;
}
int printSet(int set[],int size,char ch){
	int i;
	if(size>0){
		if(ch=='U'||ch=='u')printf("\nUNIVERSAL SET  	   : ");
		else if(ch=='A'||ch=='a')printf("\nSET A 		   : ");
		else if(ch=='B'||ch=='b')printf("\nSET B  		   : ");
		printf("{ %d ",set[0]);
		for(i=1;i<size;i++)
		{
			printf(",%d ",set[i]);		
		}
		printf("}");
		return 1;		
	}
	return 0;
}
int getBitString(int set[],int bit[],int size,char ch){
	int i,j,k;
	for(i=0;i<sizeU;i++){
		for(j=0;j<size;j++){
			if(setU[i]==set[j]){bit[i]=1;break;}
		}
	}
	if(ch=='A'||ch=='a'){printf("\nBitString Of Set A ");}
	if(ch=='B'||ch=='b'){printf("\nBitString Of Set B ");}
	printf(": { %d ",bit[0]);
	for(i=1;i<sizeU;i++)
	{
		printf(",%d ",bit[i]);		
	}
	printf("}");	
	return 1;
}
void setOperationsAB(int bitA[],int bitB[],char op){
	int un=0,in=0,df=0,j=0,h=0,k=0;char cu,ci,cd;
	if(op=='U')
		printf("\nUnion A U B	   : { ");
	if(op=='I')
		printf("\nIntersection A n B : { ");
	if(op=='D')
		printf("\nDifference A - B   : { ");
	for(int i=0;i<sizeU;i++){
		cu=ci=cd='n';
		un=bitA[i]|bitB[i];
		in=bitA[i]&bitB[i];
		df=bitA[i]&(!bitB[i]);
		if(un==1){
			unAB[h++]=setU[i];cu='U';}
		if(in==1){
			intrAB[j++]=setU[i];ci='I';}
		if(df==1){
			dfAB[k++]=setU[i];cd='D';}
		if(cu==op||ci==op||cd==op)
			printf("%d  ",setU[i]);
	}
	printf("}");	
}