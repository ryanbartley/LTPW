#ifndef Sensors_h
#define Sensors_h

#include "Sensor.h"
#include <math.h>

const uint8_t indexNum = 48;

class Sensors{
public:
        Sensors() : mSensors( new Sensor[indexNum] ), currentIndex(0) {}
        ~Sensors() { delete [] mSensors; }
  
	inline void setCurIndexVal( uint16_t curVal )
	{
//		if( mSensors[currentIndex].getRising() || abs(mSensors[currentIndex].getCurVal() - curVal) > 5 )
		mSensors[currentIndex].setVal( curVal );
		
		currentIndex++;
		
		if( currentIndex >= indexNum )
			currentIndex = 0;
	}
	
	inline void sendSensorVals( UARTClass * serial )
	{
		if( serial->available() > 0 ) {
			serial->read();
			uint8_t howMany = 0;
			uint8_t holdOver = 0;
			for( int i = 0; i < indexNum; i++ ) {
				serial->write( mSensors[i].getByte() );
				holdOver |= mSensors[i].getCarryOver();
				if( howMany == 3 ) {
					serial->write( holdOver );
					howMany = 0;
				}
				else {
					holdOver <<= 2;
					howMany++;
				}
			}
		}
	}

        inline void sendDummyVals( UARTClass * serial )
        {
                for( int i = 45; i < 46; i++ ) {
                        serial->print( i );
                        serial->print( ": " );
                        serial->println( mSensors[i].getCurVal() ); 
                }
        } 
        
        
  
private:
	uint8_t currentIndex;
	Sensor * mSensors;
};


#endif
