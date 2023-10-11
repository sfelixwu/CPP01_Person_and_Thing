
// test_ThingPerson.cpp

#include "Person.h"
#include "Thing.h"

int
main(int argc, char *argv[])
{
  int i = 5;

  // bracket initialization
  GPS_DD gps_Home_Woodland { 38.672215864622636, -121.72280111121437 };
  // GPS_DD gps_Home_Woodland(38.672215864622636, -121.72280111121437);
  
  // [class_name: GPS_DD]
  // [variable/object of GPDS_DD] gps_Home_Woodland
  // [initialization, construction] { }
  // ending ;

  // the following line will cause a compiler error with given GPS.h
  // gps_Home_Woodland is a GPS_DD object (what is the difference between class and object?
  
  // printf("the latitude is [%f]\n", gps_Home_Woodland.latitude);

  // void * gptr = (void *) &gps_Home_Woodland;
  // gptr = gptr + offset_lattidude;
  // printf("the latitude is [%f]\n", *((float *) gptr));
  // *((float *) gptr) = 20.0;
  
  // *** Question: what is the difference between compiler error and run-time error?
  
  GPS_DD gps_TLC_UCDavis   { 38.53874868013882,  -121.7542091083306 };
  double distance_1;

  // line 1
  distance_1 = gps_Home_Woodland.distance(gps_TLC_UCDavis);
  distance_1 = (&gps_Home_Woodland)->distance(gps_TLC_UCDavis);
  printf("distance 1 = %lf miles\n", distance_1);

  // if (Person1 == Person2)
    
  // line 2
  distance_1 = gps_TLC_UCDavis.distance(gps_Home_Woodland);
  printf("distance 1 = %lf miles\n", distance_1);

  // line 3
  // operator overloading
  distance_1 = gps_Home_Woodland - gps_TLC_UCDavis;
  // distance_1 = gps_Home_Woodland.operator-(gps_TLC_UCDavis);
  
  printf("distance 1 = %lf miles (operator overloading)\n", distance_1);

  distance_1 = gps_Home_Woodland - 3;
  // distance_1 = gps_Home_Woodland.operator-(gps_TLC_UCDavis);
  
  printf("distance 1 = %lf miles (operator overloading)\n", distance_1);

  // try a bit more --
  GPS_DD gps_NYC {40.7, -73.95};
  GPS_DD gps_Sydney {-33.87, 151.213};

  printf("distance from NYC to Davis is %lf miles\n", gps_NYC - gps_TLC_UCDavis);
  printf("distance from Sydney to NYC is %lf miles\n", gps_NYC - gps_Sydney);
  
  Person Felix { "987654321", "Felix", gps_Home_Woodland };

  GPS_DD gps_IKEA_Sacramento { 38.58681641563053, -121.55296296578501};

  Thing Swedish_Meatball { Felix };
  
  Swedish_Meatball.model = "HUVUDROLL";
  Swedish_Meatball.sequence_num = "123456-0000";
  Swedish_Meatball.description = "frozen";
  Swedish_Meatball.location = gps_Home_Woodland;

  Felix.setCurrentLocation(gps_TLC_UCDavis, (*getNowJvTime()));
  printf("distance from Felix to NYC = %lf miles (operator overloading)\n", Felix - gps_NYC);

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
