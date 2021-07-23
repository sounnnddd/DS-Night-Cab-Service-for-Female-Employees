# Data Structures and Algorithms Project
*Calum pvt ltd is a startup company, which manufactures and sells healthcare products. We now focus on their call centres with 20 people. Among them are many females who need to work late at night.*
**AIM** - Finding out the shortest route for women office-goers availing the organization's night cab service.
**Technical Stack** - Travelling Salesman Algorithm, haversine formula, linked list, file handling.

## Overview of Files
- **Main Code** : pro.c
- **calum.dat** : Stores information of employees of the company
- **latlon.dat** : Stores the lat-long of the address of the employee

Compile pro.c using the command *gcc pro.c -lm* in Ubuntu Terminal. Run the program and give 1 for yes and 0 for no wherever required, however give only 1 for office data alone. The data of the employees availing the night cab service are then stored in the data structure of linked list.
According to whether the user is a female and is willing to take the night cab service, the distance matrix is calculated using the provided lat-longs using the haversine formula.
The shortest path, with the office as the source, to all other destinations is found out using the Travelling Salesman Algorithm. This computed path can then be followed to drop off the female passengers safely and quickly to their residences.

## FYI:
- This was my first ever mini project in college.
- All other code files in this repository can be ignored; uploaded for personal reference.
