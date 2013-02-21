#include "MainBackground.h"
#include "AppMacros.h"

bool MainBackground::init() {
	if (!CCLayer::init()) {
		return false;
	}
	
	CCSprite* pAnimatedSprite = CCSprite::createWithSpriteFrameName("_ (1)");
	this->addChild(pAnimatedSprite);
	pAnimatedSprite->setAnchorPoint(ccp(0,0));

	CCSize size = pAnimatedSprite->getContentSize();
	pAnimatedSprite->setScale(AppMacros::getVisibleSize().width / size.width);

	CCArray* pSpriteFramesArray= new CCArray(9);
	char buffer [50];

	for (int i = 1; i < 9; i++) {
		sprintf(buffer,"_ (%d)", i);
		pSpriteFramesArray->addObject(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(buffer));
	}	

	pAnimatedSprite->runAction(CCRepeatForever::create(CCAnimate::create(CCAnimation::createWithSpriteFrames(pSpriteFramesArray, 0.15f))));

	return true;
}