/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
/*::                                                                         :*/
/*::  This routine calculates the distance between two points (given the     :*/
/*::  latitude/longitude of those points). It is being used to calculate     :*/
/*::  the distance between two locations using GeoDataSource(TM) products.   :*/
/*::                                                                         :*/
/*::  Definitions:                                                           :*/
/*::    South latitudes are negative, east longitudes are positive           :*/
/*::                                                                         :*/
/*::  Passed to function:                                                    :*/
/*::    lat1, lon1 = Latitude and Longitude of point 1 (in decimal degrees)  :*/
/*::    lat2, lon2 = Latitude and Longitude of point 2 (in decimal degrees)  :*/
/*::    unit = the unit you desire for results                               :*/
/*::           where: 'M' is statute miles (default)                         :*/
/*::                  'K' is kilometers                                      :*/
/*::                  'N' is nautical miles                                  :*/
/*::  Worldwide cities and other features databases with latitude longitude  :*/
/*::  are available at https://www.geodatasource.com                         :*/
/*::                                                                         :*/
/*::  For enquiries, please contact sales@geodatasource.com                  :*/
/*::                                                                         :*/
/*::  Official Web site: https://www.geodatasource.com                       :*/
/*::                                                                         :*/
/*::           GeoDataSource.com (C) All Rights Reserved 2018                :*/
/*::                                                                         :*/
/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/

#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#define radius 6371000


/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
/*::  Function prototypes      #define pi 3.14159265358979323846                                       :*/
/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
double deg2rad(double);
double rad2deg(double);

double distance(double lat1, double lon1, double lat2, double lon2) {
  double dlat,dlon,a,c,dist;
  if ((lat1 == lat2) && (lon1 == lon2)) {
    return 0;
  }
  else {
    dlon = lon1 - lon2;
    dlat = lat1 - lat2;
   
    a=sin(deg2rad(dlat/2))*sin(deg2rad(dlat/2)) + cos(deg2rad(lat1))*cos(deg2rad(lat2))*sin(deg2rad(dlon/2))*sin(deg2rad(dlon/2));
    c=2*atan2(sqrt(a),sqrt(1-a));
    dist=radius*c;
    return dist/1000;
  }
}


// This function converts decimal degrees to radians            

double deg2rad(double deg) {
  return (deg * M_PI / 180);
}


//  This function converts radians to decimal degrees             :

double rad2deg(double rad) {
  return (rad * 180 / M_PI);
}


void main()
{
    
    //double ang1=30;
   printf("The distance between Sholinganallur and Vadapalani is %f\n",distance(12.9010, 80.2279, 13.0500,80.2121));
    //printf("Sin of 30 = %f\n",sin(ang1));
    double ang1=30;
    
    printf("Sin of 30 = %f\n",sin(deg2rad(ang1)));

}



/* dist = sin(deg2rad(lat1)) * sin(deg2rad(lat2)) + cos(deg2rad(lat1)) * cos(deg2rad(lat2)) * cos(deg2rad(dlon));
    dist = acos(dist);
    dist = rad2deg(dist);
    dist = dist * 60 * 1.1515;
    switch(unit) {
      case 'M':
        break;
      case 'K':
        dist = dist * 1.609344;
        break;
      case 'N':
        dist = dist * 0.8684;
        break;
    }*/
