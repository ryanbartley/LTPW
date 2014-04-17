//
//  MexicanTires.h
//  CarWorkCINDER
//
//  Created by Ryan Bartley on 4/17/14.
//
//

#pragma once

#include "Wheel.h"

typedef std::shared_ptr<class MexicanWheel> MexicanWheelRef;

class MexicanWheel : public Wheel {
public:
	
	static MexicanWheelRef create() {
		return MexicanWheelRef( new MexicanWheel );
	}
	
	bool isBald() { return false; }
	
private:
	MexicanWheel();
};
