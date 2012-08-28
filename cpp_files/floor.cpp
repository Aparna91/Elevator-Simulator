#include "floor.h"

Floor::Floor ()
{
    floor_number = 0;
}

Floor::Floor (const Floor &f)
{
    floor_number = f.get_floor_number();
    list_waiting = f.get_list_waiting();
}

Floor& Floor::operator= (const Floor& rhs)
{
    floor_number = rhs.get_floor_number();
    int n = rhs.list_waiting.size();
    list_waiting.resize (n);
    for (int i=0; i<n; i++)
    {
        list_waiting[i] = rhs.list_waiting[i];
    }
    return *this;
}

/*
 *  * Parameters   : Passenger object
 *   * Return value : None
 *    * The functions adds the given passenger to the waiting list.
 *     */
void Floor::add_waiting_passenger (Passenger p)
{
    cout<<"Adding passenger " <<p.get_id() <<" on floor " <<floor_number <<endl;
    list_waiting.push_back (p);     
}

/*
 *  * Parameters   : Direction of the elevator, the list of passengers to be removed, and the list of passengers who are waiting on the whole. 
 *   * Return       : The removed list and request list are modified. No output variable.
 *    * The function checks if the direction of the elevator is the same as the direction of the passengers in the waiting list and if it is so, remove them from waiting list and add to elevator list. The request list is changed as some requests have been serviced.
 *     */
void Floor::remove_passenger (int direction, vector<Passenger> &removed_list, vector<Passenger> &request_list, int no_can_enter)
{
    int dir_passenger;                                           /* Direction of each passenger  */
    int i=0;                                                     /* Iterator through the list of waiting passengers */
    vector <Passenger>::iterator vItr = list_waiting.begin();    /* Iterator over waiting list  */
    while (vItr != list_waiting.end() )
    {
        dir_passenger = vItr->get_destination_floor() - vItr->get_source_floor();
        if(dir_passenger > 0)
            dir_passenger = 1;
        else
            dir_passenger = -1;

        if (dir_passenger == direction)
        {
            removed_list.push_back (list_waiting[i]);             /* If the direction of passenger is same as that of elevator,add passenger to removed list */
            vector<Passenger>::iterator V = request_list.begin(); /* Modify request list accordingly */
            while(V != request_list.end() )
            {
                if(V->get_id() == list_waiting[i].get_id())
                {
                    V = request_list.erase (V);
                    break;
                }
                else
                    V++;
            }
            vItr = list_waiting.erase (vItr);
        }
        else
        {
            vItr++;
            i++;
        }
        if (removed_list.size() == no_can_enter)
        {
            cout<<"Overcrowding"<<endl;
            break;
        }

    }
}

