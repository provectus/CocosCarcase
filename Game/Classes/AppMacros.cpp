#include "AppMacros.h"

cocos2d::CCSize AppMacros::designResolutionSize = cocos2d::CCSizeMake(1280, 800);

Resource AppMacros::smallResource	=	{0,		0.25f,	"small"		};
Resource AppMacros::normalResource	=	{1000,	0.5f,	"normal"	};
Resource AppMacros::largeResource	=	{2000,	1,		"large"		};

float AppMacros::globalScale = 1;