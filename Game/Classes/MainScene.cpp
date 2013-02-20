#include "MainScene.h"
#include "AppMacros.h"
#include "AppModel.h"
#include <cstdlib>
#include <ctime>
#include "NativeTest.h"
#include "Utils.h"

USING_NS_CC;

unsigned int _frames=0;
float _time=0;

CCScene* MainScene::scene()
{
	// 'scene' is an autorelease object
	CCScene *scene = CCScene::create();

	// 'layer' is an autorelease object
	MainScene *layer = MainScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool MainScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!CCLayer::init())
	{
		return false;
	}

	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

	CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		this,
		menu_selector(MainScene::menuCloseCallback));
	pCloseItem->setScale(AppMacros::globalScale*0.35f);
	pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 , origin.y + pCloseItem->getContentSize().height / 2));

	CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
	pMenu->setPosition(CCPointZero);
	this->addChild(pMenu, 1);

	//schedule(schedule_selector(MainScene::update));

	//refreshDiamonds();

	return true;
}
void MainScene::menuCloseCallback(CCObject* pSender)
{
	NativeTest::getInstance()->test();

//	CCDirector::sharedDirector()->end();
//
//#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
//	exit(0);
//#endif
}

void MainScene::refreshDiamonds() {
	cleanUpSprites();

	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("atlases/animation1.plist", "atlases/animation1.png");
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("atlases/animation2.plist", "atlases/animation2.png");

	CCSprite* earth = CCSprite::create();
	this->addChild(earth);
	earth->setPosition(ccp(600, 400));
	earth->setScale(AppMacros::globalScale);

	CCArray* arr= new CCArray(9);
	char buffer [50];

	for (int i = 1; i < 9; i++)
	{
		sprintf(buffer,"_ (%d)", i);
		arr->addObject(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(buffer));
	}	

	CCAnimation* animation = CCAnimation::createWithSpriteFrames(arr, 0.15f);
	CCAction* action = CCRepeatForever::create(CCAnimate::create(animation));
	earth->runAction(action);
}
void MainScene::cleanUpSprites() {
	for (int i = 0; i < (int)_sprites.size(); i++)
	{
		delete _sprites[i];
	}

	_sprites.clear();
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
