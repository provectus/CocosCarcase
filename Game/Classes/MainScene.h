#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include <vector>
#include "Bunny.h"

class MainScene : public cocos2d::CCLayer
{
public:
    virtual bool init();  

    static cocos2d::CCScene* scene();
    
    // implement the "static node()" method manually
    CREATE_FUNC(MainScene);

	void update(float dt);
	bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
private:	
	unsigned int _frames;
	float _time;

	Bunny* _pBunny;
};

#endif // __HELLOWORLD_SCENE_H__
