#include "cocos2d.h"
USING_NS_CC;

class Bunny : public CCObject
{
public:
	Bunny(CCLayer* layer);
	virtual ~Bunny(void);

	void setPosition(CCPoint position);
	void walkTo(CCPoint position);
	void walkFinish();
private:
	bool _isWalking;
	CCSprite* _pSprite;
	CCArray* _pSpriteFramesArray;
};