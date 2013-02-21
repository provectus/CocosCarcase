#include "Bunny.h"
#include "AppMacros.h"

Bunny::Bunny(CCLayer* layer){
	_isWalking = false;

	_pSprite = CCSprite::createWithSpriteFrameName("(8)");
	layer->addChild(_pSprite);
	_pSprite->setScale(AppMacros::getGlobalScale());

	_pSpriteFramesArray= new CCArray(8);
	char buffer [50];

	for (int i = 8; i >= 1; i--) {
		sprintf(buffer,"(%d)", i);
		_pSpriteFramesArray->addObject(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(buffer));
	}
}

Bunny::~Bunny(void) {
	_pSprite->removeFromParentAndCleanup(true);
	delete _pSprite;
}

void Bunny::setPosition(CCPoint position) {
	_pSprite->setPosition(position);
}
void Bunny::walkTo(CCPoint position) {
	if (_isWalking) {
		return;
	}

	_isWalking = true;
	_pSprite->runAction(CCRepeatForever::create(CCAnimate::create(CCAnimation::createWithSpriteFrames(_pSpriteFramesArray, 0.08f))));
	_pSprite->runAction(
		CCSequence::createWithTwoActions(
		CCMoveTo::create(2, position),
		CCCallFunc::create(this,  callfunc_selector(Bunny::walkFinish))
		)
		);
}

void Bunny::walkFinish() {
	_isWalking = false;
	_pSprite->stopAllActions();
}