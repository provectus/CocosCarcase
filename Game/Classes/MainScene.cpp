#include "MainScene.h"
#include "AppMacros.h"
#include "AppModel.h"
#include <cstdlib>
#include <ctime>
#include "CustomSpriteFactory.h"

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
		menu_selector(MainScene::menuCloseCallback));

	pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
		origin.y + pCloseItem->getContentSize().height/2));

	// create menu, it's an autorelease object
	CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
	pMenu->setPosition(CCPointZero);
	this->addChild(pMenu, 1);

	scheduleUpdate();

	refreshDiamonds();

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

	CustomSprite* pCSprite = CustomSpriteFactory::getInstance()->createSprite("Star.png", this);
	pCSprite->getCCSprite()->setPosition(ccp(250,250));

	CustomSprite* pCSprite1 = CustomSpriteFactory::getInstance()->createSprite("1361223273_keditbookmarks.png", this);
	pCSprite1->getCCSprite()->setPosition(ccp(500,500));

	CustomSprite* pCSprite2 = CustomSpriteFactory::getInstance()->createSprite("1361223276_star.png", this);
	pCSprite2->getCCSprite()->setPosition(ccp(700,500));

	/*CCSize winSize = CCDirector::sharedDirector()->getWinSize();

	AppModel* model = AppModel::getInstance();
	for (int i = 1; i < model->getTableSize() + 1; i++)
	{
		for (int j = 1; j < model->getTableSize() + 1; j++)
		{
			CCSprite* pSprite = NULL;
			DiamondItem* pDiamond = model->getDiamondItemAtCell(i - 1, j - 1);

			if (pDiamond->getType() == Star) {
				pSprite = CCSprite::create("Star.png");
			} else if (model->getDiamondItemAtCell(i - 1,j -1 )->getType() == Ruby) {
				pSprite = CCSprite::create("Ruby.png");
			} else {
				pSprite = CCSprite::create("ghost.png");
			}

			pSprite->setPosition(ccp(i * 150, j * 150));
			this->addChild(pSprite);

			_sprites.push_back(pSprite);
		}
	}*/
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
void MainScene::update( float dt )
{
	_time+=dt;
	_frames++;

	if (_time>1)
	{
		CCLog("fps: %f", _frames/_time);
		_frames=0;
		_time-=1;
	}	
}
