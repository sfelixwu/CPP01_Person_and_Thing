# Makefile for f2023, ecs36b
#

CC = g++ -std=c++14

# CFLAGS = -g -I/usr/include/jsoncpp

CFLAGS = -g

# CFLAGS = -g -D_ECS36B_HW7_ -I/usr/include/jsoncpp
# CFLAGS = -g -DNOT_RIGHT_NOW -I/usr/include/jsoncpp

# CFLAGS = -g -D_ECS36B_DEBUG_ -I/usr/include/jsoncpp
# CFLAGS = -g -Wall -Wstrict-prototypes
# CFLAGS = -O3

# LDFLAGS = 	-ljsoncpp -lmicrohttpd -ljsonrpccpp-common -ljsonrpccpp-server -lcurl -ljsonrpccpp-client


# rules.
all: 	test_ThingPerson

#
#

GPS.o:		GPS.cpp GPS.h
	$(CC) -c $(CFLAGS) GPS.cpp

JvTime.o:	JvTime.cpp JvTime.h
	$(CC) -c $(CFLAGS) JvTime.cpp

Person.o:	Person.cpp Person.h
	$(CC) -c $(CFLAGS) Person.cpp

Thing.o:	Thing.cpp Thing.h
	$(CC) -c $(CFLAGS) Thing.cpp

test_ThingPerson.o:	test_ThingPerson.cpp GPS.h Thing.h Person.h JvTime.h
	$(CC) -c $(CFLAGS) test_ThingPerson.cpp

test_ThingPerson:	GPS.o test_ThingPerson.o Thing.o Person.o JvTime.o
	g++ -std=c++14 test_ThingPerson.o GPS.o Thing.o Person.o JvTime.o -o test_ThingPerson

clean:
	rm -f *.o *~ core test_ThingPerson

