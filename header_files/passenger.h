/*
 * Filename     : passenger.h
 * Author       : Aparna K
 * Date         : 16/01/2012
 * Description  : The file contains the Passenger class which has all the members associated with passenger object.
 *
 */

#ifndef _PASSENGER_H
#define _PASSENGER_H
#include<iostream>

using namespace std;

/*
 * Class to keep track of the passenger id, time of arrival, source floor and destination floor of the passenger.
 * Member functions to access the data and to set the data value are present.
 * Member functions to print details of passenger is present.
 * Datainvariant : Passenger id is unique for each passenger's each trip. Source floor and destination floors should be between 0 and 6 (both included).
 */

class Passenger
{
    int id;
    int time_of_arrival;
    int source_floor;
    int destination_floor;

    public:

    /* Constructor */
    Passenger ();

    /* Constructor */
    Passenger (int id, int t, int s, int d);

    /* Copy constructor */ 
    Passenger (const Passenger &p);

    /* Overloaded operator '=' */
    Passenger& operator= (const Passenger &rhs);

    /* Accessor for time */
    int get_time_of_arrival () const
    {
        return time_of_arrival;
    }

    /* Accessor for source */
    int get_source_floor () const
    {
        return source_floor;
    }

    /* Accessor for destination */
    int get_destination_floor () const
    {
        return destination_floor;
    }

    /* Accessor for id */
    int get_id () const
    {
        return id;
    }

    /* Print passenger details */
    void print () const;
};


#endif
