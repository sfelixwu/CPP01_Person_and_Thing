
#ifndef _PERSON_H_
#define _PERSON_H_

// Person.h

#include "GPS.h"
#include "JvTime.h"

class Person
{
 private:
  std::string SSN;
  std::string name;
  GPS_DD home;
  GPS_DD location;
  JvTime since_when;
  
public:
  Person(std::string, std::string, GPS_DD);
  Person();
  void setHome(GPS_DD);
  void setLocation(GPS_DD, JvTime);

  bool operator==(Person& aPerson);
  std::string getSSN();
  std::string getName();
  GPS_DD getHome();
  GPS_DD getLocation();
  JvTime getLocationTime();
  void dump();
};

#endif  /* _PERSON_H_ */
