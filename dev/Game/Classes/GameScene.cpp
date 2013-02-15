#include "MenuScene.h"
#include "AppMacros.h"
#include "GameScene.h"

USING_NS_CC;

CCScene* GameScene::scene()
{
	CCScene *scene = CCScene::create();
	GameScene *layer = GameScene::create();
	scene->addChild(layer);
	return scene;
}

bool GameScene::init()
{
	if (!CCLayer::init()) {
		return false;
	}

	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();

	_batch = CCSpriteBatchNode::batchNodeWithFile("atlases/gems.png");
	this->addChild(_batch);
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("atlases/gems.plist");
	//CCSpriteFrameCache* spriteFrames = CCSpriteFrameCache::sharedSpriteFrameCache();
	for (int i = 0; i < 3; ++i) {
		CCString name;
		name.initWithFormat("gem%d.png", i+1);
		CCSprite* gem = CCSprite::spriteWithSpriteFrameName(name.getCString());
		gem->setPosition(ccp(visibleSize.width/2 + gem->getContentSize().width * i, visibleSize.height/2));
		_batch->addChild(gem, i);
	}

	return true;
}
