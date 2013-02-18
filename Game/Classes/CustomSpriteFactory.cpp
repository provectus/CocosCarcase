#include "CustomSpriteFactory.h"

using namespace cocos2d;

CustomSpriteFactory* CustomSpriteFactory::_pInstance = NULL;

CustomSpriteFactory::CustomSpriteFactory(void)
{
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("atlases/atlas_1.plist", "atlases/atlas_1.png");
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("atlases/atlas_2.plist", "atlases/atlas_2.png");
}
CustomSpriteFactory::~CustomSpriteFactory(void)
{
}

CustomSpriteFactory* CustomSpriteFactory::getInstance()
{
	if (_pInstance== NULL)
	{
		_pInstance = new CustomSpriteFactory();
	}

	return _pInstance;
}

CustomSprite* CustomSpriteFactory::createSprite(const char* spriteName, cocos2d::CCNode* node)
{
	cocos2d::CCSprite* pSprite = cocos2d::CCSprite::createWithSpriteFrameName(spriteName);
	node->addChild(pSprite);
	return new CustomSprite(pSprite);
}
