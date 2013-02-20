#ifndef __APPMACROS_H__
#define __APPMACROS_H__

#include "cocos2d.h"

typedef struct tagResource
{
	float screenWidth;
	float scale;
	char directory[100];
}Resource;

class AppMacros
{
public:
	static void initView();

	static float getGlobalScale();	
	static cocos2d::CCSize getDesignResolutionSize();
private:
	static float _globalScale;
	static float _targetFps;

	static Resource _smallResource;
	static Resource _normalResource;
	static Resource _largeResource;

	static cocos2d::CCSize _designResolutionSize;
};

// The font size 24 is designed for small resolution, so we should change it to fit for current design resolution
#define TITLE_FONT_SIZE  (cocos2d::CCEGLView::sharedOpenGLView()->getDesignResolutionSize().width / _smallResource.size.width * 24)

#endif /* __APPMACROS_H__ */