//
//  Cadillac.h
//  carWork
//
//  Created by Ryan Bartley on 4/17/14.
//  Copyright (c) 2014 Ryan Bartley. All rights reserved.
//

#pragma once

#include "Vehicle.h"

typedef std::shared_ptr<class Cadillac> CadillacRef;

class Cadillac : public Vehicle {
public:
	Cadillac( const WheelRef &bRWheel, const WheelRef &bLWheel, const WheelRef &fRWheel, const WheelRef &fLWheel );
private:
	void changeWheel( WheelRef &baldWheel );
};
