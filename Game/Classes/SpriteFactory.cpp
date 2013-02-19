#include "SpriteFactory.h"

void SpriteFactory::init()
{
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("atlases/atlas_1.plist", "atlases/atlas_1.png");
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("atlases/atlas_2.plist", "atlases/atlas_2.png");
}

CCSprite* SpriteFactory::createSprite(const char* spriteName, cocos2d::CCNode* node)
{
	cocos2d::CCSprite* pSprite = cocos2d::CCSprite::createWithSpriteFrameName(spriteName);
	node->addChild(pSprite);
	return pSprite;
}
