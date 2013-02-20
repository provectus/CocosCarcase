#include "cocos2d.h"

class MainMenu : public cocos2d::CCLayer
{
public:	
	virtual bool init();

	CREATE_FUNC(MainMenu);
private:
	void menuCloseCallback(CCObject* pSender);
};
