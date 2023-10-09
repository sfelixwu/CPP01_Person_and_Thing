
#ifndef _THING_H_
#define _THING_H_

// Thing.h
#include "Person.h"
#include "GPS.h"
#include "JvTime.h"

class Thing
{
 private:
 protected:
 public:
  // member attribute for the object of this class
  // std::string class_name;

  // member attribute for the class shared among all the objects
  static std::string class_name;
  
  std::string model;
  std::string sequence_num;
  std::string description;
  Person      owner;
  JvTime      purchased;
  JvTime      sold;

  GPS_DD      location;
  
  Thing(void);
  Thing(Person arg_owner);
  virtual void dump(); // print the content of the object
};

#endif /* _THING_H_ */
