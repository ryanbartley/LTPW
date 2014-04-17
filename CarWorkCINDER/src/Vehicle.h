//
//  Car.h
//  carWork
//
//  Created by Ryan Bartley on 4/17/14.
//  Copyright (c) 2014 Ryan Bartley. All rights reserved.
//

#pragma once

#include <vector>
#include "Wheel.h"

class Vehicle {
public:
	
	Vehicle( int topSpeed );
	virtual ~Vehicle();
	
	virtual void drive();
	
	const uint8_t getTopSpeed() const { return mTopSpeed; }
	
protected:
	
	virtual void changeWheel( WheelRef &baldWheel ) = 0;
	
	std::vector<WheelRef>	mWheels;
	const uint8_t			mTopSpeed;
};
