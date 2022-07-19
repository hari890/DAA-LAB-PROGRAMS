#include<stdio.h>
int knapsack(int *p,int *w,int n,int M)
{   float x[n],profit;
	int i,cu;
	for(i=0;i<n;i++){
		x[i]=0;
	}
	cu=M;
	for(i=0;i<n;i++)
	{
		if(w[i]>cu)
		     break;
        else{
        	x[i]=1;
        	cu=cu-w[i];
        }
	}
	if(i<n){
		x[i]=(float)cu/w[i];
 	}
	printf("Optimized solution is: \n");
    for(i=0;i<n;i++){
  	  printf("%f ",x[i]);
    }
    profit=0;
    for(i=0;i<n;i++){
    	profit+=p[i]*x[i];
    }
  return profit;
}
int main()
{
	int p[10];
	int w[10];
	int n,m;
	int i;
	printf("Enter number of objects:\n");
	scanf("%d",&n);
	printf("Enter capacity of knapsack:\n");
	scanf("%d",&m);
	printf("Enter profit values of objects:\n");
	for(i=0;i<n;i++){
		scanf("%d",&p[i]);
	}
	printf("Enter weight values of objects:\n");
	for(i=0;i<n;i++){
		scanf("%d",&w[i]);
	}
    printf("\nmaximized profit is:%d\n",knapsack(p,w,n,m));
}
