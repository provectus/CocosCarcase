#include "MainMenu.h"
#include "AppMacros.h"
#include "NativeTest.h"

USING_NS_CC;

bool MainMenu::init() {
	if (!CCLayer::init()) {
		return false;
	}

	CCMenuItemImage* pCloseItem = CCMenuItemImage::create();
	pCloseItem->setNormalSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("exit"));
	pCloseItem->setSelectedSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("exit_hover"));
	pCloseItem->setTarget(this, menu_selector(MainMenu::menuCloseCallback));			
	pCloseItem->setAnchorPoint(ccp(1, 0));
	pCloseItem->setScale(AppMacros::getGlobalScale());

	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();	
	pCloseItem->setPosition(ccp(origin.x + visibleSize.width, origin.y));

	CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
	pMenu->setPosition(CCPointZero);
	this->addChild(pMenu, 1);	

	return true;
}

void MainMenu::menuCloseCallback(CCObject* pSender) {
	NativeTest::getInstance()->test();

	CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}