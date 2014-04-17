//
//  BridgStoneWheel.h
//  CarWorkCINDER
//
//  Created by Ryan Bartley on 4/17/14.
//
//

#pragma once

#include "Wheel.h"

typedef std::shared_ptr<class BridgeStoneWheel> BridgeStoneWheelRef;

class BridgeStoneWheel : public Wheel {
public:
	
	static BridgeStoneWheelRef create(){
		return BridgeStoneWheelRef( new BridgeStoneWheel );
	}
	
private:
	BridgeStoneWheel();
};
