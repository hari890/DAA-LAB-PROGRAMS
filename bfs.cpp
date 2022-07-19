#include<stdio.h>
#define size 10
int G[10][10],queue[size];
int visited[10];
int front=-1,rear=-1;
int isEmpty()
{
	if(front==-1||front>rear)
	  return 1;
    else
       return 0;
}
void enqueue(int x)
{
	if(rear==size-1)  
       printf("\nQueue is Full!!");  
   else {  
    if(front==-1){
       front=0;  	
    }  
    rear++;  
    queue[rear]=x;
   }
}
int deque()
{
	if(front==-1||front>rear){
		printf("Queue is empty \n");
	}
	else{
		int x=queue[front];
		front++;
		//if(front>rear)
		  //front=rear=-1;
	return x;
	}
	
}
void bfs(int v)
{
	int u,i,j,n,w;
	u=v;
	visited[u]=1;
	do{
	printf("%d\n",u);
	for(i=1;i<=n;i++)
	{
		if(G[u][i]==1 && visited[i]!=1)
		{
			enqueue(u);
			visited[u]=1;
		}
	}
		if(isEmpty())
		   return;
        u=deque();
	}while(1);
}
void bft(int G[10][10],int n)
{   int i,visited[10];
	for(i=1;i<=n;i++){
		visited[i]=0;
	}
	for(i=1;i<=n;i++){
		if(visited[i]!=0)
		   bfs(i);
	}
}

int main()
{
	int n,i,j;
	printf("Enter no.of vertices: ");
	scanf("%d",&n);
	printf("Enter adjacency matrix:");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
				printf("G[%d][%d]: ",i,j);
		        scanf("%d",&G[i][j]);
		}
	}
	printf("Breadth first search\n");
	bft(G,n);
}

