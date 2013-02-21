#include "MainScene.h"
#include "AppMacros.h"
#include "AppModel.h"
#include <cstdlib>
#include <ctime>
#include "NativeTest.h"
#include "Utils.h"
#include "MainMenu.h"
#include "MainBackground.h"
#include "SpriteFactory.h"

USING_NS_CC;

CCScene* MainScene::scene() {
	SpriteFactory::initSpriteFactory();

	CCScene *scene = CCScene::create();

	scene->addChild(MainBackground::create());
	scene->addChild(MainScene::create());
	scene->addChild(MainMenu::create());

	return scene;
}

bool MainScene::init() {
	if (!CCLayer::init()) {
		return false;
	}

	_frames = 0;
	_time = 0;

	CCLabelTTF* pLabel = CCLabelTTF::create("hello from cocos world", "Fonts/Century Gothic.TTF", 40);
	pLabel->setColor(ccc3(200, 200, 200));
	pLabel->setPosition(ccp(0, 0));
	pLabel->setAnchorPoint(ccp(0, 0));
	this->addChild(pLabel);

	_pBunny = new Bunny(this);
	_pBunny->setPosition(ccp(150, 250));

	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
	this->setTouchEnabled(true);

	scheduleUpdate();

	return true;
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
bool MainScene::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent) {
	_pBunny->walkTo(pTouch->getLocation());
	return true;
}