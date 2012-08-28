/*
 * Filename     : elevator.h
 * Author       : Aparna K
 * Date         : 16/01/2012
 * Description  : The file contains the Elevators class with methods corresponding to the elevator.
 */

#ifndef _ELEVATOR_H
#define _ELEVATOR_H
#include<iostream>
#include "floor.h"
#define CAPACITY 10

using namespace std;

/*
 * Class to keep track of capacity,the current floor at which the elevator is in,the direction of travel and a list of current passengers in the elevator
 * Member functions for accessing and setting the private elements are present.
 * Member functions to add a passenger into the elevator and to remove passengers from the elevator are maintained.
 * Datainvariant : The assumptions are that the capacity is less than 10 and the direction is specified by integers. 0->stationary ; 1->moving up ; -1-> moving down. Each elevator has a unique id.
 */
class Elevator
{
    int id;
    int capacity;
    Floor current_floor;
    int direction;
    vector <Passenger> current_passenger_list;

    public:

    /* Constructor */ 
    Elevator ();

    /* Copy constructor */ 
    Elevator (const Elevator &e);

    /* Overloaded operator '=' */
    Elevator& operator= (const Elevator& rhs);

    /* Accessor for capacity */
    int get_capacity () const
    {
        return capacity;
    }

    /* Accessor for current floor */
    Floor get_current_floor () const 
    {
        return current_floor;
    }

    /* Accessor for direction */ 
    int get_direction () const
    {
        return direction;
    }

    /* Accessor for current passenger list */
    vector <Passenger> get_passenger_list () const
    {
        return current_passenger_list;
    }

    /* Mutator for direction */
    void set_direction (int dir)
    {
        direction = dir;
    }

    /* Mutator for capacity */
    void set_capacity (int n)
    {
        capacity = n;
    }

    /* Mutator for current floor */
    void set_current_floor (Floor f)
    {
        current_floor = f;
    }

    /* Accessor for id */
    int get_id () const
    {
        return id;
    }

    /* Mutator for id */
    void set_id (int given_id) 
    {
        id = given_id;
    }

    /* Remove passenger from elevator */
    void remove_passenger ();

    /* Add passenger to the elevator */
    void add_passenger (Passenger p, int time_stamp);

    /* Check if the elevator is at top floor and trying to go up */
    bool check_top_floor();

    /* Check if elevator is at ground floor and trying to go down */
    bool check_ground_floor();

};




#endif
