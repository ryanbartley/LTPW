#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

//#include "ParticleSystem.h"
#include "OptimizedParticleSystem.h"

#include "cinder/Camera.h"

using namespace ci;
using namespace gl;
using namespace ci::app;
using namespace std;

class ParticleSystemApp : public AppNative {
  public:
	void setup();
	void keyDown( KeyEvent event );
	void update();
	void draw();
	
	OParticleSystem mParticleSystem;
	CameraPersp mCam;
};

void ParticleSystemApp::setup()
{
	mParticleSystem = OParticleSystem( 10000 );
	
	mCam.setPerspective( 60.0f, getWindowAspectRatio(), 0.1f, 1000.0f );
	mCam.lookAt( Vec3f( 0, 0, 100 ), Vec3f::zero(), Vec3f::yAxis() );
}

void ParticleSystemApp::keyDown( KeyEvent event )
{
	mParticleSystem.addParticle();
}

void ParticleSystemApp::update()
{
	mParticleSystem.update();
}

void ParticleSystemApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) );
	gl::pushMatrices();
	gl::setMatrices(mCam);
	mParticleSystem.draw();
	gl::popMatrices();
}

CINDER_APP_NATIVE( ParticleSystemApp, RendererGl )
