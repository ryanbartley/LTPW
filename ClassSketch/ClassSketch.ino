#include "Sensors.h"

Sensors * mSensors;

inline bool incrementChannel()
{
	static uint8_t incr = 0;
	if( incr < 16 ) {
                PIOD->PIO_CODR = 0xf;
	        PIOD->PIO_SODR = incr;
	        incr++;
		return true;
	}
	else {
		incr = 0;
		return false;
	}
}

inline void readSensors()
{
	while( incrementChannel() ) {
		mSensors->setCurIndexVal( analogRead(A0) );
		mSensors->setCurIndexVal( analogRead(A1) );
		mSensors->setCurIndexVal( analogRead(A2) );
		delay(10);
	}
}

// the address pins will go in order from the first one:
const uint8_t myFirstPin = 25;
const uint8_t contact = 255;

void setup() {
	// update this speed
        mSensors = new Sensors();
	Serial.begin(115200);
	for (int pinNumber = myFirstPin; pinNumber < myFirstPin + 4; pinNumber++) {
		pinMode(pinNumber, OUTPUT);
	}
        establishContact();
}

void loop() {
//	readSensors();
        PIOD->PIO_CODR = 0xf;
	PIOD->PIO_SODR = 15;
        Serial.println( analogRead(A0) );
//	mSensors->sendDummyVals( &Serial );
}

void establishContact() {
        while (Serial.available() <= 0) {
              Serial.write(contact); 
              delay(300);
         }
}
