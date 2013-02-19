#include "MainScene.h"
#include "AppMacros.h"
#include "AppModel.h"
#include <cstdlib>
#include <ctime>
#include "Utils.h"

USING_NS_CC;

void MainScene::update(float dt) {
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();

	srand((unsigned)time(0));
	float x = rand() % (int) winSize.width/2+1;
	float y = rand() % (int) winSize.height/2+1;
	//_ghost->setPosition(ccp(x,y));
}
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
		CCSprite* sprite = CCSprite::create("Ruby.png");
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

	CCSize winSize = CCDirector::sharedDirector()->getWinSize();

	AppModel* model = AppModel::getInstance();
	for (int i = 1; i < model->getTableSize() + 1; i++)
	{
		for (int j = 1; j < model->getTableSize() + 1; j++)
		{
			CCSprite* pSprite = NULL;
			DiamondItem* pDiamond = model->getDiamondItemAtCell(i - 1, j - 1);

			if (pDiamond->getType() == Star) {
				pSprite = CCSprite::create("Star.png");
			} else if (model->getDiamondItemAtCell(i-1,j-1)->getType() == Ruby) {
				pSprite = CCSprite::create("Ruby.png");
			} else {
				pSprite = CCSprite::create("ghost.png");
			}

			//pSprite->setScale(5);
			pSprite->setPosition(ccp(i * 250, j * 250));
			this->addChild(pSprite);

			_sprites.push_back(pSprite);
		}
	}
}
void MainScene::cleanUpSprites() {
	for (int i = 0; i < _sprites.size(); i++)
	{
		delete _sprites[i];
	}

	_sprites.clear();
}