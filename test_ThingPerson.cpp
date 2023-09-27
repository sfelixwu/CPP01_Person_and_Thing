
// test_ThingPerson.cpp

#include "Person.h"
#include "Thing.h"

int
main(int argc, char *argv[])
{
  GPS_DD gps_Home_Woodland { 38.672215864622636, -121.72280111121437 };
  GPS_DD gps_TLC_UCDavis   { 38.53874868013882,  -121.7542091083306 };

  Person Felix { "987654321", "Felix", gps_Home_Woodland };

  GPS_DD gps_IKEA_Sacramento { 38.58681641563053, -121.55296296578501};

  Thing Swedish_Meatball { Felix };
  
  Swedish_Meatball.model = "HUVUDROLL";
  Swedish_Meatball.sequence_num = "123456-0000";
  Swedish_Meatball.description = "frozen";
  Swedish_Meatball.location = gps_Home_Woodland;

  Felix.setLocation(gps_TLC_UCDavis, (*getNowJvTime()));

  Felix.dump();
  Swedish_Meatball.dump();
  
  // GPS_DD current { atof(argv[1]), atof(argv[2]) };
  // GPS_DD gps_NYC {40.7, -73.95};
  // GPS_DD gps_Sydney {-33.87, 151.213};
  // double distance_calculated;
  // distance_calculated = gps_TLC_UCDavis.distance(current);
  // std::cout << "the distance to Davis is " << distance_calculated << " miles." << std::endl;

  return 0;
}
