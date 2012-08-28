#include "passenger.h"

Passenger::Passenger ()
{
    id = 0;
    time_of_arrival = 0;
    source_floor = 0;
    destination_floor = 0;
}

Passenger::Passenger (int id1, int t, int s, int d)
{
    id = id1;
    time_of_arrival = t;
    source_floor = s;
    destination_floor = d;
}

Passenger::Passenger (const Passenger &p)
{
    id = p.get_id();
    time_of_arrival = p.get_time_of_arrival();
    source_floor = p.get_source_floor();
    destination_floor = p.get_destination_floor();
}

Passenger& Passenger::operator= (const Passenger &rhs)
{
    time_of_arrival = rhs.time_of_arrival;
    source_floor = rhs.source_floor;
    destination_floor = rhs.destination_floor;
    id = rhs.id;
    return *this;
}

void Passenger::print () const
{
    cout<<"-----------------"<<endl;
    cout<<"Id is "<<id<<endl;
    cout<<"Source is "<<source_floor<<endl;
    cout<<"Destination is "<<destination_floor<<endl;
    cout<<"-----------------"<<endl;
}

class Vip : public Passenger
{
    int priority;

    public:

    void set_priority (int p)
    {
        priority = p;
    }

    int get_priority ()
    {
        return priority;
    }
};

class Physically_challenged : public Passenger
{
    int capacity;

    public:

    void set_capacity (int c)
    {
        capacity = c;
    }

    int get_capacity ()
    {
        return capacity;
    }
};

