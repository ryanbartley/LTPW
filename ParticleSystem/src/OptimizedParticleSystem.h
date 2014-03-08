//
//  OptimizedParticleSystem.h
//  ParticleSystem
//
//  Created by Ryan Bartley on 3/6/14.
//
//

#pragma once

#include "cinder/Perlin.h"

struct Particle {
	ci::Vec3f mPosition;
	ci::Vec3f mVelocity;
	ci::Vec3f mAcceleration;
	float mMass;
	int mLife;
};

class OParticleSystem {
public:
	OParticleSystem();
	OParticleSystem( size_t numParticles );
	~OParticleSystem();
	
	void update();
	void draw();
	void addParticle();
	
private:
	ci::Perlin mWind;
	std::list<Particle> mParticles;
};