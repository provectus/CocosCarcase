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
	static cocos2d::CCSize designResolutionSize;

	static Resource smallResource;
	static Resource normalResource;
	static Resource largeResource;

	static float globalScale;
};


// The font size 24 is designed for small resolution, so we should change it to fit for current design resolution
#define TITLE_FONT_SIZE  (cocos2d::CCEGLView::sharedOpenGLView()->getDesignResolutionSize().width / smallResource.size.width * 24)

#endif /* __APPMACROS_H__ */
