#include "elevator.h"

Elevator::Elevator ()
{
    capacity = CAPACITY;
    direction = 0;
}

Elevator::Elevator (const Elevator &e)
{
    capacity = e.get_capacity ();
    current_floor = e.get_current_floor ();
    direction = e.get_direction ();
    current_passenger_list = e.get_passenger_list ();
    id = e.get_id ();
} 

Elevator& Elevator::operator= (const Elevator& rhs)
{
    capacity = rhs.capacity;
    current_floor = rhs.current_floor;
    direction = rhs.direction;
    id = rhs.id;
    int n = rhs.current_passenger_list.size ();
    current_passenger_list.resize (n);
    for (int i=0; i<n; i++)
    {
        current_passenger_list[i] = rhs.current_passenger_list[i];
    }
    return *this;
}

bool Elevator::check_top_floor()
{
    if (direction == 1 && current_floor.get_floor_number()==6)
        return 1;
    else
        return 0;
}

bool Elevator::check_ground_floor()
{
    if (direction == -1 && current_floor.get_floor_number()==0)
        return 1;
    else
        return 0;
}

/*
 *  * Parameters   : None
 *   * Return value : None
 *    * The function checks its current passenger list to check if any passenger's destination is the current floor. If it is so, the passenger gets out of the elevator and is removed from the current passenger list.
 *     */
void Elevator::remove_passenger ()
{
    vector <Passenger>::iterator vItr = current_passenger_list.begin ();            /* vItr is the iterator over current passenger list */

    while( vItr != current_passenger_list.end () )
    {
        if (vItr->get_destination_floor () == current_floor.get_floor_number ())
        {
            cout<<"Passenger " <<vItr->get_id() <<" leaving from floor " <<vItr->get_destination_floor ()<<endl;
            vItr = current_passenger_list.erase (vItr);
        }
        else
            vItr++;
    }
}

/*
 *  * Parameters   : Passenger object and timestamp
 *   * Return value : None
 *    * The function adds the given passenger to the current passenger list when the passenger enters the elevator.
 *     */
void Elevator::add_passenger (Passenger p, int time_stamp)
{
    cout<<"Passenger " <<p.get_id() <<" enters elevator " <<id <<" at floor " <<p.get_source_floor () <<" and waiting time was " <<time_stamp-p.get_time_of_arrival() <<endl;
    current_passenger_list.push_back (p);  
}

