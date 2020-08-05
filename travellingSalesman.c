#include <stdio.h>
#include <stdlib.h>
int G[25][25], visited_places[10], limit, cost = 0;
 
int tsp(int p)
{
 int count, nearest_place = 999;
 int minimum = 999, temp;
 for(count = 0; count < limit; count++)
 {
 if((G[p][count] != 0) && (visited_places[count] == 0))
 {
 if(G[p][count] < minimum)
 {
 minimum = G[count][0] + G[p][count];
 }
 temp = G[p][count];
 nearest_place = count;
 }
 }
 if(minimum != 999)
 {
 cost = cost + temp;
 }
 return nearest_place;
}
 
void minimum_cost(int place)
{
 int nearest_place;
 visited_places[place] = 1;
 printf("%d ", place + 1);
 nearest_place = tsp(place);
 if(nearest_place == 999)
 {
 nearest_place = 0;
 printf("%d", nearest_place + 1);
 cost = cost + G[place][nearest_place];
 return;
 }
 minimum_cost(nearest_place);
}
 
int main()
{ 
 int i, j;
 printf("Enter Total Number of Cities:\t");
 scanf("%d", &limit);
  for(i=0;i<limit;i++)
		for(j=0;j<limit;j++)
			{//scanf("%d",&G[i][j]);
			G[i][j]=rand()%20;}
	for(i=0;i<limit;i++)
		G[i][i]=0;
 
 printf("\nEntered Cost Matrix\n");
 for(i = 0; i < limit; i++)
 {
 printf("\n");
 for(j = 0; j < limit; j++)
 {
 printf("%d ", G[i][j]);
 }
 }
 
printf("\n\nPath:\t");
 minimum_cost(0);
 printf("\n\nMinimum Cost: \t");
 printf("%d\n", cost);
 return 0;
}


/*printf("\nEnter Cost Matrix\n");
 for(i = 0; i < limit; i++)
 {
 printf("\nEnter %d Elements in Row[%d]\n", limit, i + 1);
 for(j = 0; j < limit; j++)
 {
 scanf("%d", &matrix[i][j]);
 }
 visited_cities[i] = 0;
 }*/
