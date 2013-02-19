#include <stdlib.h>
#include "cocos2d.h"

using namespace cocos2d;

class SpriteFactory
{
public:
	static void init();	
	static CCSprite* createSprite(const char* spriteName, cocos2d::CCNode* node);
};