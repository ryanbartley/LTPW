//
//  Particle.cpp
//  ParticleSystem
//
//  Created by Ryan Bartley on 3/6/14.
//
//

#include "Particle.h"
#include "cinder/Rand.h"

using namespace ci;

Particle::Particle( Vec3f position )
: mPosition(position), mVelocity( Vec3f::zero() ), mAcceleration( Vec3f::zero() ), mMass( randFloat( 1.0f, 5.0f ) ), mLife( randInt( 100, 200 ) ), mDead( false )
{
}

Particle::~Particle()
{
}

bool Particle::isDead()
{
	return mDead;
}

void Particle::addForce( Vec3f force )
{
	mAcceleration += force / mMass;
}

void Particle::update()
{
	mVelocity += mAcceleration;
	mPosition += mVelocity;
	mAcceleration *= 0.0;
	
	if ( mLife > 0 ) {
		mLife--;
	}
	else {
		mLife = 0;
		mDead = true;
	}
}

void Particle::draw()
{
	gl::pushMatrices();
	gl::translate(mPosition);
	gl::drawSolidCircle( Vec2f( 0, 0 ), mMass );
	gl::popMatrices();
}

const Vec3f & Particle::getPosition()
{
	return mPosition;
}