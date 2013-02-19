#include "MainScene.h"
#include "AppMacros.h"
#include "AppModel.h"
#include <cstdlib>
#include <ctime>
#include "Utils.h"

USING_NS_CC;

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

	for (int i = 0; i < 9; ++i) {
		CCSprite* sprite = CCSprite::create("circle.png");
		sprite->setPosition(Utils::alignTo((ScreenAlign) i));
		this->addChild(sprite);
	}

	//CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	//CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

	///////////////////////////////
	//// 2. add a menu item with "X" image, which is clicked to quit the program
	////    you may modify it.

	//// add a "close" icon to exit the progress. it's an autorelease object
	//CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
	//	"CloseNormal.png",
	//	"CloseSelected.png",
	//	this,
	//	menu_selector(MainScene::menuCloseCallback));

	//pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
	//	origin.y + pCloseItem->getContentSize().height/2));

	//// create menu, it's an autorelease object
	//CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
	//pMenu->setPosition(CCPointZero);
	//this->addChild(pMenu, 1);

	//schedule(schedule_selector(MainScene::update));

	//refreshDiamonds();

	return true;
}
void MainScene::menuCloseCallback(CCObject* pSender)
{
	CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}

void MainScene::refreshDiamonds() {
	cleanUpSprites();

	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("atlases/animation1.plist", "atlases/animation1.png");
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("atlases/animation2.plist", "atlases/animation2.png");

	CCSprite* earth = CCSprite::create();//CCSprite::createWithSpriteFrameName("1.png");
	this->addChild(earth);
	earth->setPosition(ccp(600, 400));
	earth->setScale(globalScale);

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
	for (int i = 0; i < _sprites.size(); i++)
	{
		delete _sprites[i];
	}

	_sprites.clear();
}


unsigned int _frames=0;
float _time=0;
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
