/*
2018503561
K.Soundarya
Data Structures Mini Project

Calum pvt ltd is a startup company, which manufactures and sells healthcare products. We now focus on their call centres with 21 people. Among them are many females who need to work late at night.

*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
#include<time.h>
#define radius 6371000
#define MAX 12

/*
Linked list will be used as and when the user registers their entry
struct: name,gender.
A person is credited with extra bonus only when they attend more than a specific number of calls per day, this bonus will be give bades on day to day basis.
There will be two seperate linked lists: one for women, and another for men and transgenders.This will be helpful in plotting the graph and implementing the dijkstra's algorithm later in the code.
*/

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
  //NAMES n;
  //double lat,lon;
  LLD available;
  struct node *next;
}NODE;
typedef NODE * LIST;
LIST makeNode(NAMES);
LIST insertEnd(LIST,NAMES);
LIST deleteName(LIST,char[]);
void displayNames(LIST);

//distance functions
double deg2rad(double);
double rad2deg(double);
double distance(double,double,double,double);

void main()
{
  //everyone registers in the register so that the total count is calculated for the day
  //enter name..if found in file..enter it inside the linked list.
  char a[20],b,c[20]; 
  double t; 
  int i=0,p,j=0,n,u,count=0;//i,j,n,u,G[MAX][MAX] graph
  double G[MAX][MAX];
  LIST today=NULL,female=NULL,temp1=female,temp2=female;
  //LIST today=NULL,female=NULL,temp=female,temp1=female;
  FILE *f1,*f2;
  NAMES m;
  LLD l1;
  //la=(LLD *)malloc(sizeof(LLD)*12);
  
  //file functions don't work when given in a seperate program...
  f1=fopen("calum.dat","w");
  NAMES name[22]={{"Office",'f',"NILL"},{"Sujatha",'f',"20176789"},{"Thomas",'m',"20186909"},{"Velan",'m',"20179989"},{"Anupama",'f',"20190871"},{"Ritika",'f',"20189009"},{"Murugan",'t',"20184510"},{"Raziel",'f',"20171234"},{"Fathima",'f',"20190906"},{"Murthi",'t',"20173416"},{"Bindu",'f',"20195206"},{"Shobana",'f',"20183445"},{"Sindhu",'f',"20190657"},{"Rahjaan",'t',"20177989"},{"Elosan",'m',"20188100"},{"Vani",'f',"20196712"},{"Xinthia",'f',"20194554"},{"Raja",'t',"20187889"},{"Siva",'m',"20170001"},{"Haran",'m',"20180019"},{"William",'m',"20188095"},{"Tessa",'f',"20188096"}};  
  LLD lld[12]={{"Office",12.9010,80.2279},{"Sujatha",12.9249,80.1000},{"Anupama",13.0500,80.2121},{"Ritika",13.0521,80.2255},{"Raziel",13.0732,80.2609},{"Fathima",13.0850,80.2101},{"Bindu",13.0715, 80.2415},{"Shobana",13.0569, 80.2425},{"Sindhu",13.0368, 80.2676},{"Vani",12.9675, 80.1491},{"Xinthia",12.9516, 80.1462},{"Tessa",13.0532, 80.1922}};
  fwrite(name,sizeof(NAMES),22,f1);
  fclose(f1);
  
//  female=insertEnd(female,name[0],knt);
  f1=fopen("calum.dat","r");
  
  if(f1==NULL)
  {
    printf("Error in opening the file\n");
    exit(1);
  }
  printf("\n---------Calum Private Limited---------\n");
  while(!feof(f1))
  {      
    fread(&m,sizeof(NAMES),1,f1);
    if(!feof(f1))
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
	  female=insertEnd(female,m);
	  count++;	  
        }
	//else	count++;
      }
    } 
    }
  }
  
  fclose(f1);
  displayNames(female);
  //graph
  i=0;j=0;
  n=count;
  printf("\n");
  while(temp1)
  {
    while(temp2)
    {
      G[i][j]=distance(temp1->available.lat,temp1->available.lon,temp2->available.lat,temp2->available.lon);
      j++;
      temp2=temp2->next; 
    }
    if(!temp2)	temp2=female;
    i++;
    temp1=temp1->next;
  }
  //printing g
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      printf("%5f",G[i][j]);
    }
    printf("\n");
  }
  
  printf("\n\n");
}


//list functs
LIST makeNode(LLD n)//name,lat,lon
{
  LIST l=(LIST)malloc(sizeof(NODE));
  l->n.name=(char *)malloc(sizeof(char)*20);
  strcpy(l->n.name,n.name);
  l->n.lat=n.lat;
  l->n.lon=n.lon;  
  l->next=NULL;
  return l;  
}
LIST insertEnd(LIST l,LLD n)
{
  LIST newNode=makeNode(n),t=l;
  //newNode->index=knt;
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
  while(l)
  {
    printf("%s\t",l->n.name);
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


