//
//  main.cpp
//  TestProg
//
//  Created by Ryan Bartley on 4/3/14.
//  Copyright (c) 2014 Ryan Bartley. All rights reserved.
//

#include <iostream>
#include <vector>

static int colorId = 0;

enum TastesLike {
	GOOD,
	OK,
	BAD,
	CHICKEN,
	HAVENT_TASTED
};

class Color {
public:
	Color() : mId(colorId++)
	{
		std::cout << "I'm creating a color. My id is " << mId << std::endl;
	}
	Color( const Color &other)
	: mId(colorId++), r(other.r), g(other.g),
		b(other.b), a(other.a)
	{
		std::cout << "I'm in the copy constructor and mId is " << mId << std::endl;
	}
	
	~Color()
	{
		std::cout << "I'm Color and I'm destructing and my Id is "
			<< mId << std::endl;
	}
	
	float r, g, b, a;
	int mId;
};

class Flower {
public:
	Flower( const Color & flowerColor ) : mHeight(0), mIsAlive(true), mColor(flowerColor) {}
	virtual ~Flower() { std::cout << "I'm in base destructor" << std::endl; }
	void grow() { mHeight++; }
	virtual void die()
	{
		std::cout << "I'm in base die" << std::endl;
		mHeight = 0;
		mIsAlive = false;
	}
	void setColor(  Color& color ) { mColor = color; }
	Color& getColor() { return mColor; }
	
protected:
	int mHeight;
	bool mIsAlive;
	Color mColor;
};

class EdibleFlower : public Flower {
public:
	EdibleFlower( const Color &edibleFlowerColor, TastesLike taste ) : Flower(edibleFlowerColor), mTastesLike( taste ) {}
	~EdibleFlower() { std::cout << "I'm in derived destructor" << std::endl; }
	void die()
	{
		std::cout << "I'm in derived die" << std::endl;
		Flower::die();
		mTastesLike = TastesLike::GOOD;
	}

	bool eat()
	{
		if( mHeight > 1 ) {
			die();
			return true;
		}
		else {
			return false;
		}
	}
	
private:
	TastesLike mTastesLike;
};

int main(int argc, const char * argv[])
{
	std::cout << "Creating mFlower" << std::endl;
	Flower* mFlower = new Flower( ( Color() ) );
	std::cout << "mFlower Created, now creating mEdible" << std::endl;
	EdibleFlower* mEdible = new EdibleFlower( Color(), TastesLike::HAVENT_TASTED );
	std::cout << "mEdible created" << std::endl;

	std::vector<Flower*> mFlowerPointers;
	mFlowerPointers.push_back( mEdible );
	mFlowerPointers.push_back( mFlower );
	
	for( auto flowerIt = mFlowerPointers.begin(); flowerIt != mFlowerPointers.end(); ++flowerIt ) {
		(*flowerIt)->die();
		delete (*flowerIt);
	}
	
		
	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

