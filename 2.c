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

typedef struct names
{
  char *name,gender,*offnum;
  double lat,lon;  
}NAMES;


