//
//  OptimizedParticleSystem.cpp
//  ParticleSystem
//
//  Created by Ryan Bartley on 3/6/14.
//
//

#include "OptimizedParticleSystem.h"
#include "cinder/Rand.h"

using namespace ci;

OParticleSystem::OParticleSystem()
{
	
}

OParticleSystem::OParticleSystem( size_t numParticles )
{
	mParticles.resize( numParticles );
	
	for ( std::list<Particle>::iterator partIt = mParticles.begin(); partIt != mParticles.end(); ++partIt ) {
		
		Vec3f randomPosition = Vec3f( randFloat( -app::getWindowWidth() / 2, app::getWindowWidth() / 2 ), randFloat( -app::getWindowHeight() / 2, app::getWindowHeight() / 2 ), randFloat( -100, 100 ) );
		
		partIt->mPosition = randomPosition;
		partIt->mLife = randFloat( 60, 120 );
		partIt->mMass = randFloat( 1.0f, 5.0f );
		partIt->mVelocity = Vec3f::zero();
		partIt->mAcceleration = Vec3f::zero();
		
	}
}

OParticleSystem::~OParticleSystem()
{
	
}

void OParticleSystem::update()
{
	for ( std::list<Particle>::iterator partIt = mParticles.begin(); partIt != mParticles.end(); ++partIt ) {
		
		if( partIt->mLife < 0 ) {
			
			Vec3f randomPosition = Vec3f( randFloat( -app::getWindowWidth() / 2, app::getWindowWidth() / 2 ), randFloat( -app::getWindowHeight() / 2, app::getWindowHeight() / 2 ), randFloat( -100, 100 ) );
			
			partIt->mPosition = randomPosition;
			partIt->mLife = randFloat( 60, 120 );
			partIt->mMass = randFloat( 1.0f, 5.0f );
			partIt->mVelocity = Vec3f::zero();
			partIt->mAcceleration = Vec3f::zero();
			
		}
		else {
			partIt->mAcceleration += ci::Vec3f( 0, -1, 0 ) / partIt->mMass;
			
			partIt->mAcceleration += mWind.dnoise( partIt->mPosition.x, partIt->mPosition.y, partIt->mPosition.z ) / partIt->mMass;
			
			partIt->mVelocity += partIt->mAcceleration;
			partIt->mPosition += partIt->mVelocity;
			partIt->mAcceleration *= 0;
			
			partIt->mLife--;
			
		}
	}
}

void OParticleSystem::draw()
{
	for ( std::list<Particle>::iterator partIt = mParticles.begin(); partIt != mParticles.end(); ++partIt ) {
		gl::pushMatrices();
		gl::translate(partIt->mPosition);
		gl::color(ColorA(1.,0.,0.,1.));
		gl::drawSolidCircle( Vec2f( 0, 0 ), partIt->mMass );
		gl::popMatrices();
	}
}

void OParticleSystem::addParticle()
{
	
}