#include "HelloWorldScene.h"
#include "AppMacros.h"
#include <cstdlib>
#include <ctime>

USING_NS_CC;

void HelloWorld::update(float dt) {
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();

	srand((unsigned)time(0));
	float x = rand() % (int) winSize.width/2+1;
	float y = rand() % (int) winSize.height/2+1;
	_ghost->setPosition(ccp(x,y));
}

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if (!CCLayer::init())
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(HelloWorld::menuCloseCallback));
    
	pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
                                origin.y + pCloseItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);

	/////////////////////////// Shit code begin ////////////////////////////
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	_ghost = CCSprite::create("ghost.png");
	_ghost->setScale(5);
    _ghost->setPosition(ccp(winSize.width/2, winSize.height/2));
    this->addChild(_ghost);

	schedule(schedule_selector(HelloWorld::update));

    return true;
}


void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
