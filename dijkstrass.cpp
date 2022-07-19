#include<stdio.h>
void dijkstras(int v,int cost[10][10],int dist[10],int n)
{
   int i,u,min,w,s[10];
   for(i=1;i<=n;i++)
   	{
   	s[i]=0;
   	dist[i]=cost[v][i];
   }	
   dist[v]=0;
   s[v]=1;
   for(min=2;min<=n-1;min++)
   	{
   	for(i=1;i<=n;i++)
   	{
	   	if(s[i]!=1)
	   	{
	   		min=dist[i];
	   		u=i;
	   		break;
	   	}
    }
   for(i=1;i<=n;i++)
  {
   if(dist[i]!=0)
  {
   if(dist[i]<min&&s[i]!=1)
  {
  min=dist[i];
  u=i;
   }
  }
  }
  printf("u=%d ",u);
  s[u]=1;
  for(w=1;w<=n;w++)
  {
  	s[u]=1;
  }
  for(w=1;w<=n;w++)
  {
  	if(cost[u][w]!=0&&cost[u][w]!=9999&&s[w]==0)
  	{
	  	if(dist[w]>dist[u]+cost[u][w])
	  	{
	  		dist[w]=dist[u]+cost[u][w];
	  	}
	  }
  }
}
  for(i=1;i<=n;i++)
  	printf("Distance from source vertex %d to vertex %d is: %d\n5",v,i,dist[i]);
  
}

int main()
{
	int i,j,cost[10][10],sv,n,dist[10];
	printf("Enter no.of vertices: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
        		printf("enter cost[%d][%d]: ",i,j);
        		scanf("%d",&cost[i][j]);
		}
	}
	printf("Enter source vertex from 1 to %d: ",n);
	scanf("%d",&sv);
	dijkstras(sv,cost,dist,n);
	return 0;
}
