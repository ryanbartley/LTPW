//
//  Particle.h
//  ParticleSystem
//
//  Created by Ryan Bartley on 3/6/14.
//
//

#pragma once

class Particle {
public:
	
	Particle() {}
	Particle( ci::Vec3f position );
	~Particle();
	
	bool isDead();
	void addForce( ci::Vec3f force );
	void update();
	void draw();
	
	const ci::Vec3f & getPosition();
	
private:
	ci::Vec3f	mPosition;
	ci::Vec3f	mVelocity;
	ci::Vec3f	mAcceleration;
	
	float		mMass;
	int			mLife;
	bool		mDead;
};