#include<stdio.h>
int prims(int cost[10][10],int n,int t[10][10])
{
	int i,j,y,z,m,p;
	int k=0,l=0;
	int min,mincost,near[10];
	min=999;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(cost[i][j]<min &&i!=j){
				min=cost[i][j];
				k=i;
				l=j;
			}
		}
	}
	t[1][1]=k;
	t[1][2]=l;
	printf("%d %d", t[1][1], t[1][2]);
	mincost=cost[k][l];
	for(i=0;i<n;i++){
		if(cost[i][l]<cost[i][k]){
			near[i]=l;
		}
		else{
			near[i]=k;
		}
	}
	near[k]=0;
    near[l]=0;
	for(i=2;i<n;i++){
		min=999;
		for(j=0;j<n;j++){
		z=near[j];
			if(near[j]!=0 && cost[j][z]<min){
			  	min=cost[j][z];
			  	p=j;
			}
	 		}
			 	t[i][1]=p;
				t[i][2]=near[p];
				printf("t=%d %d\n",t[i][1],t[i][2]);
				mincost=mincost+cost[p][near[p]];
				near[p]=0;
			
			for(m=0;m<n;m++){
				y=near[m];
				if(near[m]!=0 && (cost[m][near[m]]>cost[m][p])){
					near[m]=p;
				}
			}
		}
	
	return mincost;
}

int main()
{
	int n,i,j,cost[10][10],t[10][10];
	int res;
	printf("Enter no.of vertices: ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){  
		    //printf("Enter distance between %d and %d : ",i+1,j+1);
		    scanf("%d",&cost[i][j]);	
 
		}
	}
	res=prims(cost,n,t);
	printf("%d\n",res);
}


/*
7
0 28 999 999 999 10 999
28 0 16 999 999 999 14
999 16 0 12 999 999 999
999 999 12 0 22 999 18
999 999 999 22 0 25 24
10 999 999 999 25 0 999
999 14 999 18 24 999 0 */
