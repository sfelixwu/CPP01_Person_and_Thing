
#ifndef _GPS_H_
#define _GPS_H_

// GPS.h

#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <cstdlib>

using namespace std;

// class <name> { public private variables functions }
// struct <name> { ... }

class GPS_DD
{
  
  // the difference between private and public --
  // please try to move one of the private line to the public
  // and then, in test_ThingPerson.cpp, please try to direct access --
  // [with the original position, you should receive a compiler error]
  // ==> printf("the latitude is [%f]\n", gps_Home_Woodland.latitude);
  
 private:
  // the following are all private "members" or and "member functions"  
  double longitude;
  double latitude;
  
 public:
  // the following are all public "members" or and "member functions"

  // the following two are "constructors" or "constructor functions"
  // in Python --
  // > def __init__(self, ...):
  // >   # body of the constructor
  // FYI, self in python is like "this" in C++ (but "this" doesn't show
  // as an explicit argument of a constructor.

  explicit GPS_DD();
  explicit GPS_DD(double, double);
  
  // member functions -- it is a function associated with a particular class (not object)
  // e.g., it is associated with class GPS (not the object, gps_Home_Woodland)
  // Therefore, the identifier of a member function is
  // ==> <class_name>::<member_function_name>
  // e.g., GPS_DD::GPS_DD, GPS_DD::getLatitude
  
  double getLatitude();
  double getLongitude();
  double distance(GPS_DD);
  void dump();
};

#endif /* _GPS_H_ */
