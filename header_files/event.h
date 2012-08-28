#ifndef _EVENT_H
#define _EVENT_H
#include<iostream>
#include<stdlib.h>
#include"building.h"
#define NO_OF_FLOORS 6
#define NO_OF_ELEVATORS 2
using namespace std;

/* Global variable of type building */

class Event
{

    public:

        virtual void happen (int time_stamp, int id, vector <Passenger> &p, Building &B){}
        virtual void happen (vector <Passenger> p, Building &B){}
        virtual void happen (vector <Passenger> &request_list, int time_stamp, Building &B){}
        virtual void happen (Elevator &e, int id, vector <Passenger> &request_list, int time_stamp, Building &B){}
        virtual void happen (Elevator &e, Floor &f, vector <Passenger> &request_list, int time_stamp, Building &B){}

};


/*
 * Class to implement the event of a Person entering the building.
 */
class Person_enters : public Event
{

    public:

        void happen (int time_stamp, int id, vector <Passenger> &p, Building &B);
        void happen (vector <Passenger> p, Building &B){;}
        void happen (vector <Passenger> &request_list, int time_stamp, Building &B){;}
        void happen (Elevator &e, int id, vector <Passenger> &request_list, int time_stamp, Building &B){;}
        void happen (Elevator &e, Floor &f, vector <Passenger> &request_list, int time_stamp, Building &B){;}


};

/*
 * Class to implement the event of a Person leaving the building.
 */
class Person_leaves : public Event
{

    public:

        void happen (vector <Passenger> p, Building &B);
        void happen (vector <Passenger> &request_list, int time_stamp, Building &B){;}
        void happen (Elevator &e, int id, vector <Passenger> &request_list, int time_stamp, Building &B){;}
        void happen (Elevator &e, Floor &f, vector <Passenger> &request_list, int time_stamp, Building &B){;}
        void happen (int time_stamp, int id, vector <Passenger> &p, Building &B){;}


};

/*
 * Class to implement the event of requesting the elevator.
 */
class Request_elevator : public Event
{

    public:

        void happen (vector <Passenger> &request_list, int time_stamp, Building &B);
        void happen (int time_stamp, int id, vector <Passenger> &p, Building &B){;}
        void happen (vector <Passenger> p, Building &B){;}
        void happen (Elevator &e, int id, vector <Passenger> &request_list, int time_stamp, Building &B){;}
        void happen (Elevator &e, Floor &f, vector <Passenger> &request_list, int time_stamp, Building &B){;}


};

/*
 * Class to implement the event of moving the elevator by 1 floor.
 */
class Move_elevator : public Event
{

    public:

        void happen (Elevator &e, int id, vector <Passenger> &request_list, int time_stamp, Building &B);
        void happen (int time_stamp, int id, vector <Passenger> &p, Building &B){;}
        void happen (vector <Passenger> p, Building &B){;}
        void happen (vector <Passenger> &request_list, int time_stamp, Building &B){;}
        void happen (Elevator &e, Floor &f, vector <Passenger> &request_list, int time_stamp, Building &B){;}

};

/*
 * Class to implement the event of passengers leaving the elevator at the destination floor and new passengers alighting the elevator at their source floor.
 */
class Check : public Event 
{

    public:

        void happen (Elevator &e, Floor &f, vector <Passenger> &request_list, int time_stamp, Building &B);
        void happen (int time_stamp, int id, vector <Passenger> &p, Building &B){;}
        void happen (vector <Passenger> p, Building &B){;}
        void happen (vector <Passenger> &request_list, int time_stamp, Building &B){;}
        void happen (Elevator &e, int id, vector <Passenger> &request_list, int time_stamp, Building &B){;}

};



#endif
