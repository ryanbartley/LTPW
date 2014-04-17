//
//  Wheel.cpp
//  carWork
//
//  Created by Ryan Bartley on 4/17/14.
//  Copyright (c) 2014 Ryan Bartley. All rights reserved.
//

#include "Wheel.h"
#include <iostream>
#include "cinder/Rand.h"

using namespace std;

Wheel::Wheel( int16_t amountOfTread )
: mAmountOfTread( amountOfTread ), mBald( false ), mId( getWheelId() )
{
	cout << "I'm creating a wheel with id " << mId << endl;
}

Wheel::Wheel( const Wheel &otherWheel )
: mAmountOfTread( otherWheel.mAmountOfTread ), mId( getWheelId() ), mBald( false )
{
}

Wheel::~Wheel()
{
	cout << "I'm destructing a wheel with id " << mId << endl;
}

void Wheel::driveOn()
{
	auto rand = ci::randInt() % 8;
	mAmountOfTread -= rand;
	if( mAmountOfTread < 0 ) {
		mBald = true;
	}
}

