#include "MainScene.h"
#include "AppMacros.h"
#include "AppModel.h"
#include <cstdlib>
#include <ctime>
#include "NativeTest.h"
#include "Utils.h"
#include "MainMenu.h"

USING_NS_CC;

CCScene* MainScene::scene() {
	CCScene *scene = CCScene::create();
	MainScene *layer = MainScene::create();
	scene->addChild(layer);

	scene->addChild(MainMenu::create());
	return scene;
}

bool MainScene::init() {
	if (!CCLayer::init()) {
		return false;
	}

	_frames=0;
	_time=0;

	drawSomething();

	scheduleUpdate();

	return true;
}

void MainScene::drawSomething() {
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("atlases/animation1.plist", "atlases/animation1.png");
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("atlases/animation2.plist", "atlases/animation2.png");
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("atlases/gui_atlas.plist", "atlases/gui_atlas.png");

	CCSprite* pAnimatedSprite = CCSprite::create();
	this->addChild(pAnimatedSprite);
	pAnimatedSprite->setPosition(ccp(600, 400));
	pAnimatedSprite->setScale(AppMacros::getGlobalScale());

	CCArray* pSpriteFramesArray= new CCArray(9);
	char buffer [50];

	for (int i = 1; i < 9; i++)
	{
		sprintf(buffer,"_ (%d)", i);
		pSpriteFramesArray->addObject(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(buffer));
	}	

	pAnimatedSprite->runAction(CCRepeatForever::create(CCAnimate::create(CCAnimation::createWithSpriteFrames(pSpriteFramesArray, 0.15f))));
		
	CCLabelTTF* pLabel = CCLabelTTF::create("hello from cocos world", "Fonts/Century Gothic.TTF", 40);
	pLabel->setPosition(ccp(0, 350));
	pLabel->setAnchorPoint(ccp(0, 0));
	this->addChild(pLabel);
}

void MainScene::update( float dt ) {
	const float updateInterval = 5;

	_time += dt;
	_frames++;

	if (_time > updateInterval) {
		CCLog("fps: %f", _frames / _time);
		_frames = 0;
		_time -= updateInterval;
	}	
}