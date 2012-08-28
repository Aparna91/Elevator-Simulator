#include "building.h"


/*
 *  * Parameters   : A building object which is to be initialized.
 *   * Return Value : The building object is modified.
 *    * The function initilizes the elevators and floors of the building such that alternate elevators are in ground floor and final floor.
 *     */
void read (Building &B)
{
    int iter=0;

    for (iter=0; iter <= NO_OF_FLOORS; iter++)
    {
        Floor f;
        f.set_floor (iter);
        B.floors.push_back (f);    
    }

    for (iter=0; iter < NO_OF_ELEVATORS; iter++)
    {
        Elevator e;
        e.set_capacity (CAPACITY);
        e.set_id(iter);

        if (iter%2 == 0)
        {
            e.set_direction (1);
            e.set_current_floor (B.floors[0]);
        }
        else
        {
            e.set_direction (-1);
            e.set_current_floor (B.floors[NO_OF_FLOORS]);
        }

        B.elevators.push_back (e);
    }
} 

