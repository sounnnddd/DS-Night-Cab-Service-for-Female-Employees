#include<stdio.h>
#include<stdlib.h> 
int G[15][15],completed[15],size,cost=0;
 
void takeInput()
{
	int i,j;
 
	printf("Enter the number of villages: ");
	scanf("%d",&size);
 
	//printf("\nEnter the Cost Matrix\n");
 
	for(i=0;i <size;i++)
	{
		//printf("\nEnter Elements of Row: %d\n",i+1);
 
		for( j=0;j <size;j++)
			G[i][j]=rand()%20;			
//scanf("%d",&ary[i][j]);
 
		completed[i]=0;
	}
    for(i=0;i<size;i++)	G[i][i]=0;
 
	printf("\n\nThe cost list is:");
 
	for( i=0;i <size;i++)
	{
		printf("\n");
 
		for(j=0;j <size;j++)
			printf("\t%d",G[i][j]);
	}
}
 
int least(int c)
{
	int i,nc=999;
	int min=999,kmin;
 
	for(i=0;i <size;i++)
	{
		if((G[c][i]!=0)&&(completed[i]==0))
			if(G[c][i]+G[i][c] < min)
			{
				min=G[i][0]+G[c][i];
				kmin=G[c][i];
				nc=i;
			}
	}
 
	if(min!=999)
		cost+=kmin;
 
	return nc;
}


void mincost(int place)
{
	int i,nplace;
 
	completed[place]=1;
 
	printf("%d--->",place+1);
	nplace=least(place);
 
	if(nplace==999)
	{
		nplace=0;
		printf("%d",nplace+1);
		cost+=G[place][nplace];
 
		return;
	}
 
	mincost(nplace);
}
 
 
int main()
{
	takeInput();
 
	printf("\n\nThe Path is:\n");
	mincost(0); //passing 0 because starting vertex
 
	printf("\n\nMinimum cost is %d\n ",cost);
 
	return 0;
}
