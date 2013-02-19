#ifndef __APPMACROS_H__
#define __APPMACROS_H__

#include "cocos2d.h"

static cocos2d::CCSize designResolutionSize = cocos2d::CCSizeMake(1280, 800);

typedef struct tagResource
{
	float screenWidth;
	float scale;
	char directory[100];
}Resource;

static Resource smallResource	=	{0,		0.25f,	"small"};
static Resource normalResource	=	{1000,	0.5f,	"normal"};
static Resource largeResource	=	{2000,	1,		"large"};

static float globalScale = 1;

// The font size 24 is designed for small resolution, so we should change it to fit for current design resolution
#define TITLE_FONT_SIZE  (cocos2d::CCEGLView::sharedOpenGLView()->getDesignResolutionSize().width / smallResource.size.width * 24)

#endif /* __APPMACROS_H__ */
