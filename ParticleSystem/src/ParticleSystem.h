//
//  ParticleSystem.h
//  ParticleSystem
//
//  Created by Ryan Bartley on 3/6/14.
//
//

#pragma once

#include "Particle.h"
#include "cinder/Perlin.h"

class ParticleSystem {
public:
	ParticleSystem() {}
	ParticleSystem( size_t numParticles );
	~ParticleSystem();
	
	void update();
	void addParticle();
	void draw();
	
private:
	ci::Perlin			mWind;
	std::list<Particle> mParticles;
};
