//
//  Cadillac.cpp
//  carWork
//
//  Created by Ryan Bartley on 4/17/14.
//  Copyright (c) 2014 Ryan Bartley. All rights reserved.
//

#include "Cadillac.h"
#include "MexicanTires.h"

#include <iostream>

using namespace std;

Cadillac::Cadillac( const WheelRef &bRWheel, const WheelRef &bLWheel, const WheelRef &fRWheel, const WheelRef &fLWheel )
: Vehicle( 145 )
{
	mWheels.resize( 4 );
	mWheels[0] = bRWheel;
	mWheels[1] = bLWheel;
	mWheels[2] = fRWheel;
	mWheels[3] = fLWheel;
}

void Cadillac::changeWheel( WheelRef &baldWheel )
{
	cout << "I'm changing this wheel and my Id is " << baldWheel->getPersonalId()  << endl;
	baldWheel.reset( MexicanWheel::create().get() );
}