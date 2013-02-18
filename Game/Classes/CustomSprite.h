#include "cocos2d.h"
#include <stdlib.h>

class CustomSprite
{
public:
	CustomSprite(cocos2d::CCSprite* pSprite);
	virtual ~CustomSprite(void);

	cocos2d::CCSprite* getCCSprite();
};

