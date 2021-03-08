#include<stdio.h>
int vertex[50],visited[50],graph[50][50];
int nv,f,r;
int search(int a[],int b,int s);
void printVertex(int s);
void dfsT(int);
void main()
{
    int i,j,v,ad,src;
    printf("\nEnter The Number Of Vertices : ");
    scanf("%d",&nv);
    printf("\n-------------------------------------------\nEnter The Vertices\n-------------------------------------------");
    for(i=0;i<nv;i++)
    {
        vertex:
        printf("\nEnter Vertex %d  : ",i+1);
        scanf("%d",&v);
        if(search(vertex,v,i)==1)
        {
            printVertex(i);
            printf("\nVertex %d Already Exists !! \n-------------------------------------------",v);goto vertex;
        }
        vertex[i]=v;//vertex
        visited[v]=0;//to indicate visited or not
    }
    printf("\n-------------------------------------------\nEnter Graph In Matrix Form( %d by %d Matrix, 1 : Presence Of Edge, 0 : Absence Of Edge )\n",nv,nv);
    for(i=0;i<nv;i++)
    {
        for(j=0;j<nv;j++)
        {
            adjacent:
            scanf("%d",&ad);
            if(ad!=0 && ad!=1)
            {
                printf("\nYou Can Only Enter 0 or 1 !!\n");goto adjacent;
            }
            graph[vertex[i]][vertex[j]]=ad;
        }
        printf("\n");
    }
    printf("     ");
    for(j=0;j<nv;j++)
    {
        printf("%d  ",vertex[j]);
    }
    printf("\n    ");
    for(j=0;j<nv;j++)printf("---");
    for(i=0;i<nv;i++)
    {
        printf("\n%d  | ",vertex[i]);
        for(j=0;j<nv;j++)
        {
            printf("%d  ",graph[vertex[i]][vertex[j]]);
        }
    }
    source:
    printf("\n-------------------------------------------\nEnter The Source Vertex : ");
    scanf("%d",&src);
    if(search(vertex,src,nv)==0)
    {
        printVertex(nv);
        printf("\nVertex %d Not Found !! \n-------------------------------------------",src);goto source;
    }
    printVertex(nv);
    visited[src]=1;
    printf("\nDFS TRAVERSAL	  : %d",src);   
    dfsT(src);
    printf("\nRemaining Vertices Are Unreachable,if any !! \n-------------------------------------------");
}
void dfsT(int v)
{
    int i;
    for(i=0;i<nv;i++)
     {
       if(graph[v][vertex[i]]==1 && visited[vertex[i]]==0)
        {
          printf("  %d",vertex[i]);
	  visited[vertex[i]]=1;
	  dfsT(vertex[i]);
        }
     }
    return;
}
int search(int a[],int b,int s)
{
    int i;
    for(i=0;i<s;i++)
    {
        if(b==a[i])return 1;
    }
    return 0;
}
void printVertex(int s)
{
    int i;
    printf("\n-------------------------------------------\nExisting Vertices : ");
    for(i=0;i<s;i++)
    {
        printf("%d  ",vertex[i]);
    }
}