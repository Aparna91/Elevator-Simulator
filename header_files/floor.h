/*
 * Filename     : floor.h
 * Author       : Aparna K
 * Date         : 16/01/2012
 * Description  : The file contains the Floor class which has all the members associated with floor object.
 *
 */

#ifndef _FLOOR_H
#define _FLOOR_H
#include<iostream>
#include "passenger.h"
#include<vector>

using namespace std;

/*
 * Class to keep track of the floor number and the list of passengers waiting at a floor.
 * Member functions to access the data and to set the data value are present.
 * Member functions to add neww person on the floor and to remove person from floor when elevator arrives is also there.
 * Datainvariant : Floor number should be an integer between 0 and 6 (both included).
 */
class Floor
{
    int floor_number;
    vector <Passenger> list_waiting;


    public:

    /* Constructor */
    Floor ();

    /* Copy constructor */
    Floor (const Floor &f);

    /* Overloaded '=' operator */
    Floor& operator= (const Floor& rhs);

    /* Accessor for floor number */
    int get_floor_number () const
    {
        return floor_number;
    }

    /* Accessor for waiting passenger list */
    vector <Passenger> get_list_waiting () const
    {
        return list_waiting;
    }

    /* Mutator for floor number */
    void set_floor (int f)
    {
        floor_number = f;
    }

    void add_waiting_passenger (Passenger p);
    void remove_passenger (int direction, vector<Passenger> &removed_list, vector<Passenger> &request_list, int no_can_enter);
};



#endif
