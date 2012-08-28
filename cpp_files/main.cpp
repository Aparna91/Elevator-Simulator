#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include"event.h"

using namespace std;


int main()
{
    Building B;

    vector<Passenger> request_list;               /* To keep track of the pasenger requests */
    read (B);                                     /* Initialize the building */

    int iter = 0,person_count = 0;      
    int time_stamp = 0;
    Request_elevator r;

    while (1)
    {
        if (iter %4 == 0)
        {
            int no_of_persons = rand() %5;          /* No of persons to be added in the iteration */
            for(int i=0; i<no_of_persons; i++)
            {
                Person_enters p;                    /* Create the person and add to respective floor */
                Event *e1 = &p;
                e1->happen(time_stamp, person_count,request_list, B);
                person_count++;
            }
        }
        Event *e2 = &r;
        e2->happen(request_list, time_stamp, B);                     /* Simulate movement of elevator */

        iter++;
        time_stamp++;
        cout<<"Press enter to continue "<<endl;
        getchar();                                  
    }
    return 0;
}
