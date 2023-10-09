
#include "Person.h"

Person::Person(std::string arg_SSN, std::string arg_name, GPS_DD arg_home)
{
  this->SSN = arg_SSN;
  this->name = arg_name;
  this->home = arg_home;
}

Person::Person()
{
  this->SSN = "";
  this->name = "";
  this->home = GPS_DD {};
}

void
Person::setHome
(GPS_DD arg_home)
{
  this->home = arg_home;
}

void
Person::setCurrentLocation
(GPS_DD arg_location, JvTime arg_time)
{
  this->location = arg_location;
  this->since_when = arg_time;
}

GPS_DD
Person::getHome
(void)
{
  return this->home;
}

std::string
Person::getSSN()
{
  return this->SSN;
}

std::string
Person::getName()
{
  return this->name;
}

bool
Person::operator==
(Person& aPerson)
{
  // if I change the internal value of aPerson here, then this change will be observed.
  return (this->SSN == aPerson.getSSN());
}

int
Person::operator==
(Person  bPerson)
{
  // if I change the internal value of aPerson here, then this change will be observed.
  return 5;
}

double
Person::operator-
(GPS_DD& aLocation)
{
  return (this->location - aLocation);
}

void Person::dump
(void)
{ 
  std::cout << "dump Person" << std::endl;
  std::cout << "  {" << std::endl;
  std::cout << "    name           = " << this->name << std::endl;
  std::cout << "    SSN            = " << this->SSN << std::endl;
  std::cout << "  }" << std::endl;
  return;
}

