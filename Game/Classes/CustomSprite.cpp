#include "CustomSprite.h"

cocos2d::CCSprite* _pSprite=NULL;

CustomSprite::CustomSprite(cocos2d::CCSprite* pSprite )
{
	_pSprite = pSprite;	
}

CustomSprite::~CustomSprite(void)
{
	delete _pSprite;
}

cocos2d::CCSprite* CustomSprite::getCCSprite()
{
	return _pSprite;
}
