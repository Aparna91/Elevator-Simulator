/*
 * Filename     : building.h
 * Author       : Aparna K
 * Date         : 16/01/2012
 * Description  : This file contains a structure building which has 2 elevators and 6 floors. The read function initializes the building.
 */

#ifndef _BUILDING_H
#define _BUILFING_H

#include<iostream>
#include"elevator.h"
#define NO_OF_FLOORS 6
#define NO_OF_ELEVATORS 2
#define CAPACITY 10

/* Structure building has a vector of elevators and floors as members. */
struct Building
{
    vector <Elevator> elevators;
    vector <Floor> floors;
};   

void read(Building &B);

#endif
