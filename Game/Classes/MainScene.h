#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include <vector>

class MainScene : public cocos2d::CCLayer
{
public:
    virtual bool init();  

    static cocos2d::CCScene* scene();
    
    // implement the "static node()" method manually
    CREATE_FUNC(MainScene);

	void update(float dt);
private:	
	unsigned int _frames;
	float _time;
	
	void drawSomething();
};

#endif // __HELLOWORLD_SCENE_H__
