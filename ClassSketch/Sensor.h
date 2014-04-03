#ifndef Sensor_h
#define Sensor_h

#include "Arduino.h"
#include <inttypes.h>

class Sensor{
public:
	Sensor() : mCurVal(0), mLastVal(0) {}
	~Sensor() {}
  
	inline void setVal( uint16_t curVal ) 
	{
//		mLastVal = mCurVal;
		mCurVal = curVal;
	}
	inline uint16_t getCurVal() { return mCurVal; }
	inline uint16_t getLastVal() { return mLastVal; }
	inline uint8_t  getByte() { return (mCurVal & 0Xff); }
	inline uint8_t  getCarryOver() { return ((mCurVal & 0x300) >> 8); }
private:
	uint16_t mCurVal, mLastVal;
};

#endif
