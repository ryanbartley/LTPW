//
//  ParticleSystem.cpp
//  ParticleSystem
//
//  Created by Ryan Bartley on 3/6/14.
//
//

#include "ParticleSystem.h"
#include "cinder/Rand.h"

using namespace ci;

ParticleSystem::ParticleSystem( size_t numParticles )
{
	mParticles.resize( numParticles );
	
	for ( std::list<Particle>::iterator partIt = mParticles.begin(); partIt != mParticles.end(); ++partIt ) {
		Vec3f randomPosition = Vec3f( randFloat( -app::getWindowWidth() / 2, app::getWindowWidth() / 2 ), randFloat( -app::getWindowHeight() / 2, app::getWindowHeight() / 2 ), randFloat( -100, 100 ) );
		(*partIt) = Particle( randomPosition );
	}
}

ParticleSystem::~ParticleSystem()
{
	
}

void ParticleSystem::update()
{
	for ( std::list<Particle>::iterator partIt = mParticles.begin(); partIt != mParticles.end(); ) {
		if( partIt->isDead() ) {
			partIt = mParticles.erase( partIt );
		}
		else {
			partIt->addForce( Vec3f( 0, -1, 0 ) );
			partIt->addForce( 3.0f *  mWind.dnoise( partIt->getPosition().x, partIt->getPosition().y, partIt->getPosition().z ) );
			partIt->update();
			++partIt;
		}
	}
}

void ParticleSystem::addParticle()
{
	Vec3f randomPosition = Vec3f( randFloat( -app::getWindowWidth() / 2, app::getWindowWidth() / 2 ), randFloat( -app::getWindowHeight() / 2, app::getWindowHeight() / 2 ), randFloat( -100, 100 ) );
	
	mParticles.push_back( Particle( randomPosition ) );
}

void ParticleSystem::draw()
{
	for ( std::list<Particle>::iterator partIt = mParticles.begin(); partIt != mParticles.end(); ++partIt ) {
		partIt->draw();
	}
}