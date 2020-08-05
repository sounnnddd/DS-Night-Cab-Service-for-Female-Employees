#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct names
{
  char *name,gender,*offnum;
}NAMES;
void main()
{
  FILE *f1;
  f1=fopen("calum.dat","w");
  NAMES n[21]={{"Sujatha",'f',"20176789"},{"Thomas",'m',"20186909"},{"Velan",'m',"20179989"},{"Anupama",'f',"20190871"},{"Ritika",'f',"20189009"},{"Murugan",'t',"20184510"},{"Raziel",'f',"20171234"},{"Fathima",'f',"20190906"},{"Murthi",'t',"20173416"},{"Bindu",'f',"20195206"},{"Shobana",'f',"20183445"},{"Sindhu",'f',"20190657"},{"Rahjaan",'t',"20177989"},{"Elosan",'m',"20188100"},{"Vani",'f',"20196712"},{"Xinthia",'f',"20194554"},{"Raja",'t',"20187889"},{"Siva",'m',"20170001"},{"Haran",'m',"20180019"},{"William",'m',"20188095"},{"Tessa",'f',"20188096"}},m;  
  
  fwrite(n,sizeof(NAMES),21,f1);
  fclose(f1);

  f1=fopen("calum.dat","r");
  fread(&m,sizeof(NAMES),1,f1);
  printf("%s-%c-%s\n",m.name,m.gender,m.offnum);
  fread(&m,sizeof(NAMES),1,f1);
  printf("%s-%c-%s\n",m.name,m.gender,m.offnum);
  
  
  
  fclose(f1);    
}

/*FILE *f1;
  f1=fopen("calum.dat","w");
  NAMES n[21]={{"Sujatha",'f',"20176789"},{"Thomas",'m',"20186909"},{"Velan",'m',"20179989"},{"Anupama",'f',"20190871"},{"Ritika",'f',"20189009"},{"Murugan",'t',"20184510"},{"Raziel",'f',"20171234"},{"Fathima",'f',"20190906"},{"Murthi",'t',"20173416"},{"Bindu",'f',"20195206"},{"Shobana",'f',"20183445"},{"Sindhu",'f',"20190657"},{"Rahjaan",'t',"20177989"},{"Elosan",'m',"20188100"},{"Vani",'f',"20196712"},{"Xinthia",'f',"20194554"},{"Raja",'t',"20187889"},{"Siva",'m',"20170001"},{"Haran",'m',"20180019"},{"William",'m',"20188095"},{"Tessa",'f',"20188096"}};  
  
  fwrite(n,sizeof(NAMES),21,f1);
  /*NAMES n={"Sujatha",'f',"20176789"};
  fwrite(&n,sizeof(NAMES),1,f1);*/

  
