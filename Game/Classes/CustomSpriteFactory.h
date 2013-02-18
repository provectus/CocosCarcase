#include <stdlib.h>
#include "cocos2d.h"
#include "CustomSprite.h"

#pragma once
class CustomSpriteFactory
{
public:
	static CustomSpriteFactory* getInstance();
	
	CustomSprite* createSprite(const char* spriteName, cocos2d::CCNode* node);
private:
	static CustomSpriteFactory* _pInstance;

	CustomSpriteFactory(void);
	~CustomSpriteFactory(void);	
};