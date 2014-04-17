//
//  Car.cpp
//  carWork
//
//  Created by Ryan Bartley on 4/17/14.
//  Copyright (c) 2014 Ryan Bartley. All rights reserved.
//

#include "Vehicle.h"

Vehicle::Vehicle( int topSpeed )
: mTopSpeed( topSpeed )
{
}

Vehicle::~Vehicle()
{
	
}

void Vehicle::drive()
{
	for( auto wheelIt = mWheels.begin(); wheelIt != mWheels.end(); ++wheelIt ) {
		auto curWheel = (*wheelIt);
		if( curWheel->isBald() ) {
			changeWheel( curWheel );
		}
		else {
			curWheel->driveOn();
		}
	}
}