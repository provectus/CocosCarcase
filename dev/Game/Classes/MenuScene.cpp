#include "MenuScene.h"
#include "AppMacros.h"
#include "HelloWorldScene.h"

USING_NS_CC;

CCScene* MenuScene::scene()
{
	CCScene *scene = CCScene::create();
	MenuScene *layer = MenuScene::create();
	scene->addChild(layer);
	return scene;
}

// on "init" you need to initialize your instance
bool MenuScene::init()
{
	if (!CCLayer::init()) {
		return false;
	}

	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

	CCTexture2D *texture = CCTextureCache::sharedTextureCache()->addImage("brick_bg.png");
	ccTexParams params = {GL_LINEAR, GL_LINEAR, GL_REPEAT, GL_REPEAT};
	texture->setTexParameters(&params);
	CCSprite *bg = CCSprite::spriteWithTexture(texture, CCRectMake(0, 0, visibleSize.width, visibleSize.height));
	bg->setPosition(ccp(visibleSize.width/2, visibleSize.height/2));
	this->addChild(bg, 0);

	// add a start button
	CCMenuItemFont* pStartButton = CCMenuItemFont::create("START", this, menu_selector(MenuScene::startButtonCallback));
	pStartButton->setFontSizeObj(100);
	pStartButton->setColor(ccBLUE);
	pStartButton->setPosition(ccp(visibleSize.width/2, visibleSize.height/2));

	// create menu, it's an autorelease object
	CCMenu* pMenu = CCMenu::create(pStartButton, NULL);
	pMenu->setPosition(CCPointZero);
	this->addChild(pMenu, 1);
	
	return true;
}


void MenuScene::startButtonCallback(CCObject* pSender)
{
	CCScene *s = HelloWorld::scene();
	CCDirector::sharedDirector()->setDepthTest(true);
	CCTransitionScene *transition = CCTransitionTurnOffTiles::create(0.5f, s);
	CCDirector::sharedDirector()->replaceScene(transition);
}
