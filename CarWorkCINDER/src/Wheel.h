//
//  Wheel.h
//  carWork
//
//  Created by Ryan Bartley on 4/17/14.
//  Copyright (c) 2014 Ryan Bartley. All rights reserved.
//

#pragma once

typedef std::shared_ptr<class Wheel> WheelRef;

static int getWheelId() {
	static int newId = 0;
	return newId++;
}

class Wheel {
public:
	
	Wheel( const Wheel &otherWheel );
	~Wheel();
	
	void driveOn();
	
	const int getPersonalId() const { return mId; }
	virtual bool isBald() { return mBald; }
	
protected:
	Wheel( int16_t amountOfTread );
	
	int16_t		mAmountOfTread;
	bool		mBald;
	const int	mId;

};
