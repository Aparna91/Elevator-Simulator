#include "event.h"

/*
 *  * Parameters : Elevator, Current floor, Request list of passengers and current time.
 *   * Return value : Modifies the request list.
 *    * The function removes passengers from the elevator whose destination is the current floor and add passengers from the current floor who are to travel in same direction as the elevator. Modify the request list by deleting passengers who left the elevator.
 *     */
void Check::happen (Elevator &e, Floor &f, vector <Passenger> &request_list, int time_stamp, Building &B)
{
    vector <Passenger> removed_list;
    e.remove_passenger ();
    int number_can_enter = 10 - e.get_passenger_list().size();
    f.remove_passenger (e.get_direction(), removed_list,request_list, number_can_enter);   
    int n = removed_list.size();
    for (int i =0; i<n; i++)
    { 
        e.add_passenger (removed_list[i], time_stamp);
        removed_list[i].print ();
    }
    e.set_current_floor (f);
}

/*
 *  * Parameters : Elevator, Elevator id, Request list, current time.
 *   * Return value : Modifies the request list.
 *    * The function moves the elevator by 1 floor in the elevator direction and performs check on the floor reached.
 *     */
void Move_elevator::happen (Elevator &e, int id, vector<Passenger> &request_list, int time_stamp, Building &B)
{
    int direction = e.get_direction();
    Check c;
    e.set_current_floor (B.floors[ e.get_current_floor().get_floor_number() + direction]);
    cout<<"Elevator " <<id <<" in floor " <<e.get_current_floor().get_floor_number() <<endl;
    c.happen (e, B.floors[e.get_current_floor().get_floor_number()], request_list, time_stamp, B);

}

/*
 *  * Parameters : Request list, current time.
 *   * Return value : Modifies request list
 *    * The function sets the direction of the elevator and calls move. If elevator reaches top floor or ground floor, its direction is reversed.
 *     */
void Request_elevator::happen (vector<Passenger> &request_list, int time_stamp, Building &B)
{

    Move_elevator m;

    for (int i=0; i<NO_OF_ELEVATORS; i++)
    {
        if (B.elevators[i].check_top_floor())
            B.elevators[i].set_direction(-1);
        if (B.elevators[i].check_ground_floor())
            B.elevators[i].set_direction(1);
        m.happen(B.elevators[i], i, request_list, time_stamp, B);
    }

}

/*
 *  * Parametes : current time, passenger id, request list.
 *   * Return value : Modifies the request list.
 *    * The function creates a new passenger with random source and destination floors and adds the passenger to its source floor waiting list.
 *     */
void Person_enters::happen(int time_stamp, int id, vector<Passenger> &request_list, Building &B)
{
    int source_floor = rand() % (NO_OF_FLOORS +1);
    int destination_floor = rand() % (NO_OF_FLOORS +1);
    if (source_floor == destination_floor)
    {
        return;
    }
    else
    {
        Passenger p (id, time_stamp, source_floor, destination_floor);
        request_list.push_back (p);
        B.floors[source_floor].add_waiting_passenger(p);
    }
}


