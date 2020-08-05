/*
2018503561
K.Soundarya
Data Structures Mini Project

Calum pvt ltd is a startup company, which manufactures and sells healthcare products. We now focus on their call centres with 20 people. Among them are many females who need to work late at night.

*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>

#define radius 6371000
#define MAX 11

/*
Linked list will be used as and when the user registers their entry
There will a seperate linked list for women which will be helpful in plotting the graph and finding out the route later on in the code.
*/

double G[MAX][MAX],cost=0;
int size,completed[MAX]; 

typedef struct names
{
  char *name,gender,*offnum;
  double lat,lon;  
}NAMES;
typedef struct latlong
{
  char *name;
  double lat,lon;  
}LLD;


//linked list
typedef struct node
{
  NAMES n;
  double lat,lon;
  //LLD available;
  struct node *next;
}NODE;
typedef NODE * LIST;
LIST makeNode(NAMES,double,double);
LIST insertEnd(LIST,NAMES,double,double);
void displayNames(LIST);

//distance functions
double deg2rad(double);
double rad2deg(double);
double distance(double,double,double,double);

//for finding the route
int least(int);
void mincost(int);

//main function
void main()
{
  char a[20],b,c[20]; 
  double t; 
  int i=0,p,j=0,u,count=0,visited_places[10],limit;//i,j,n,u,G[MAX][MAX] graph
  
  LIST female=NULL,temp1,temp2;
  FILE *f1,*f2;
  NAMES m;
  LLD l1;
  //file functions don't work when given in a seperate program...
  f1=fopen("calum.dat","w");
  f2=fopen("latlon.dat","w");
  NAMES name[21]={{"Office",'f',"NILL"},{"Sujatha",'f',"20176789"},{"Thomas",'m',"20186909"},{"Velan",'m',"20179989"},{"Anupama",'f',"20190871"},{"Ritika",'f',"20189009"},{"Murugan",'t',"20184510"},{"Raziel",'f',"20171234"},{"Fathima",'f',"20190906"},{"Murthi",'t',"20173416"},{"Bindu",'f',"20195206"},{"Shobana",'f',"20183445"},{"Rahjaan",'t',"20177989"},{"Elosan",'m',"20188100"},{"Vani",'f',"20196712"},{"Xinthia",'f',"20194554"},{"Raja",'t',"20187889"},{"Siva",'m',"20170001"},{"Haran",'m',"20180019"},{"William",'m',"20188095"},{"Tessa",'f',"20188096"}};  
  LLD lld[11]={{"Office",12.9010,80.2279},{"Sujatha",12.9249,80.1000},{"Anupama",13.0500,80.2121},{"Ritika",13.0521,80.2255},{"Raziel",13.0732,80.2609},{"Fathima",13.0850,80.2101},{"Bindu",13.0715, 80.2415},{"Shobana",13.0569, 80.2425},{"Vani",12.9675, 80.1491},{"Xinthia",12.9516, 80.1462},{"Tessa",13.0532, 80.1922}};
  fwrite(name,sizeof(NAMES),21,f1);
  fclose(f1);
  fwrite(lld,sizeof(LLD),11,f2);
  fclose(f2);  

  f1=fopen("calum.dat","r");
  f2=fopen("latlon.dat","r");
  if(f1==NULL||f2==NULL)
  {
    printf("Error in opening the file\n");
    exit(1);
  }
  printf("\n---------Calum Private Limited---------\n");
  while(fread(&m,sizeof(NAMES),1,f1))
  {    
    printf("%s-%c-%s : Present? ",m.name,m.gender,m.offnum);
    scanf("%d",&p);
    if(p)
    {
      //today=insertEnd(today,m);
      if(m.gender=='f')
      {
	char ch;	
	printf("Will you be opting to go by van today after your night shift? : ");
	scanf("%d",&p);
	if(p)
	{     	      
	  while(fread(&l1,sizeof(LLD),1,f2))
	  {	    
	    if(strcmp(m.name,l1.name)==0)
	      {
		female=insertEnd(female,m,l1.lat,l1.lon);
		count++;
  	      }	    
  	  }
	  fseek(f2,0,SEEK_SET);	  	  
        }	
      }
    } 
    
  }
  fclose(f2);
  fclose(f1);
  printf("\nThe following females will make use of the van after the night shift for travelling back home.");
  displayNames(female);
  //graph
  i=0;j=0;
  size=count;
  temp1=female; temp2=female;
  printf("\n");
  while(temp1)
  {
    while(temp2)
    {
      G[i][j]=distance(temp1->lat,temp1->lon,temp2->lat,temp2->lon);
      j++;
      temp2=temp2->next; 
    }
    temp2=female;
    i++; j=0;
    temp1=temp1->next;
  }
 
  printf("\nThe matrix with the distances calculated between the various places using haversine formula is (cost matrix) :\n");
  for(i=0;i<size;i++)
  {
    for(j=0;j<size;j++)
    {
      printf("%f\t",G[i][j]);
    }
    completed[i]=0;
    printf("\n");
  }

  printf("\n\nThe Path is:\n");
  mincost(0); //passing 0 because starting vertex
  printf("\n\nMinimum distance thus covered is going to be %f km.\n ",cost); 
  
}


//list functs
LIST makeNode(NAMES n,double lat,double lon)
{
  LIST l=(LIST)malloc(sizeof(NODE));
  l->n.name=(char *)malloc(sizeof(char)*20);
  l->n.offnum=(char *)malloc(sizeof(char)*20);
  strcpy(l->n.name,n.name);
  l->n.gender=n.gender;
  strcpy(l->n.offnum,n.offnum);
  l->lat=lat;
  l->lon=lon;
  l->next=NULL;
  return l;  
}
LIST insertEnd(LIST l,NAMES n,double lat,double lon)
{
  LIST newNode=makeNode(n,lat,lon),t=l;  
  if(!l)	
    return newNode;
  while(t->next)
    t=t->next;
  t->next=newNode;
  return l; 
}

void displayNames(LIST l)
{
  if(!l)	
    printf("Noone is present in this list..\n");
  int i=0;
  printf("\n");
  while(l)
  {
    printf("%d : %s-%f-%f\n",++i,l->n.name,l->lat,l->lon);
    l=l->next;
  }
}


//distance functions
double deg2rad(double deg) 
{
  return (deg * M_PI / 180);
}
double rad2deg(double rad) 
{
  return (rad * 180 / M_PI);
}
double distance(double lat1, double lon1, double lat2, double lon2) //using haversine formula
{
  double dlat,dlon,a,c,dist;
  if ((lat1 == lat2) && (lon1 == lon2)) return 0;
  else 
  {
    dlon = lon1 - lon2;
    dlat = lat1 - lat2;   
    a=sin(deg2rad(dlat/2))*sin(deg2rad(dlat/2)) + cos(deg2rad(lat1))*cos(deg2rad(lat2))*sin(deg2rad(dlon/2))*sin(deg2rad(dlon/2));
    c=2*atan2(sqrt(a),sqrt(1-a));
    dist=radius*c;
    return dist/1000;
  }
}

//for finding the route

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
//use gcc pro.c -lm
