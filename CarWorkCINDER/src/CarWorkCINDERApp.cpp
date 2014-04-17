#include "cinder/app/AppNative.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include "Cadillac.h"
#include "BridgStoneWheel.h"
#include "MexicanTires.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class CarWorkCINDERApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
	
	CadillacRef mCadillac;
};

void CarWorkCINDERApp::setup()
{
	mCadillac = CadillacRef( new Cadillac( BridgeStoneWheel::create(),  MexicanWheel::create(), BridgeStoneWheel::create(), BridgeStoneWheel::create() ) );
}

void CarWorkCINDERApp::mouseDown( MouseEvent event )
{
}

void CarWorkCINDERApp::update()
{
}

void CarWorkCINDERApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) );
	
	mCadillac->drive();
}

CINDER_APP_NATIVE( CarWorkCINDERApp, RendererGl )
