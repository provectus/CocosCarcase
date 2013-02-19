#include "Utils.h"
#include <cstdlib>
#include <ctime>
#include "cocos2d.h"

USING_NS_CC;

bool Utils::_isRandomInited = false;

void Utils::initRandom() {
	if (_isRandomInited) {
		return;
	}
	_isRandomInited =true;

	srand((unsigned)time(0));
}

int Utils::randomRange(int max) {
	initRandom();

	return rand() % max;
}
int Utils::randomRange(int min, int max) {
	initRandom();

	return (rand() + min) % max;
}
float Utils::randomValue(){
	initRandom();

	float result = (rand() % 1000000) / (float)1000000;
	return result;
}

CCPoint Utils::alignTo(ScreenAlign screenAlign, CCPoint offset) {
	CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
	CCSize screen = CCDirector::sharedDirector()->getVisibleSize();
	
	switch ((int) screenAlign) {
		case Middle :	
			return ccpAdd(ccpAdd(origin, offset), ccp(screen.width/2, screen.height/2));
		case Left :
			return ccpAdd(ccpAdd(origin, offset), ccp(0, screen.height/2));
		case Right :
			return ccpAdd(ccpAdd(origin, offset), ccp(screen.width, screen.height/2));
		case TopLeft :
			return ccpAdd(ccpAdd(origin, offset), ccp(0, screen.height));
		case TopMiddle :
			return ccpAdd(ccpAdd(origin, offset), ccp(screen.width/2, screen.height));
		case TopRight :
			return ccpAdd(ccpAdd(origin, offset), ccp(screen.width, screen.height));
		case BottomLeft :
			return ccpAdd(origin, offset);
		case BottomMiddle :
			return ccpAdd(ccpAdd(origin, offset), ccp(screen.width/2, 0));
		case BottomRight :
			return ccpAdd(ccpAdd(origin, offset), ccp(screen.width, 0));
		default :
			CCLOG("Invalid screen align: %d", screenAlign);
			return CCPointZero;
	}
}

CCPoint Utils::alignTo(ScreenAlign screenAlign) {
	return alignTo(screenAlign, CCPointZero);
}