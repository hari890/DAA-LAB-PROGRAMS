#include<stdio.h>
int G[10][10];
int visited[10],n;
void dfs(int v)
{   int i;
	visited[v]=1;
	printf("%d\n",v);
	for(i=1;i<=n;i++){
		if(G[v][i]==1 && visited[i]==0)
	          dfs(i);
	}
}
int main()
{
	int i,j;
	printf("Enter no.of vertices: ");
	scanf("%d",&n);
	printf("Enter adjacency matrix\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			//printf("G[%d][%d]: ",i,j);
            scanf("%d",&G[i][j]);
		}
	}
	printf("DFS\n");
	dfs(1);
}
