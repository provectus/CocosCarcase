#include "AppMacros.h"
#include "PlatformSpecific.h"

USING_NS_CC;

/*static*/ CCSize AppMacros::_designResolutionSize = cocos2d::CCSizeMake(1280, 800);

/*static*/ Resource AppMacros::_smallResource	=	{0,		1,	"small"		};
/*static*/ Resource AppMacros::_normalResource	=	{1000,	2,	"normal"	};
/*static*/ Resource AppMacros::_largeResource	=	{2000,	4,	"large"		};

/*static*/ float AppMacros::_globalScale = 1;
/*static*/ float AppMacros::_targetFps = 45;

/*static*/ float AppMacros::getGlobalScale() {
	return _globalScale;
}
/*static*/ CCSize AppMacros::getDesignResolutionSize()
{
	return _designResolutionSize;
}
/*static*/ CCSize AppMacros::getVisibleSize()
{
	return CCDirector::sharedDirector()->getVisibleSize();
}
/*static*/ CCPoint AppMacros::getVisibleOrigin()
{
	return CCDirector::sharedDirector()->getVisibleOrigin();
}

/*static*/ void AppMacros::initView() {
	CCDirector* pDirector = CCDirector::sharedDirector();
	CCEGLView* pEGLView = CCEGLView::sharedOpenGLView();

	pDirector->setOpenGLView(pEGLView);

	pEGLView->setDesignResolutionSize(_designResolutionSize.width, _designResolutionSize.height, kResolutionNoBorder);

	CCSize frameSize = pEGLView->getFrameSize();
	Resource selectedResource;
	if (frameSize.width >= AppMacros::_largeResource.screenWidth) {
		selectedResource = AppMacros::_largeResource;
	}
	else if (frameSize.width >= AppMacros::_normalResource.screenWidth) {
		selectedResource = AppMacros::_normalResource;
	}
	else {
		selectedResource = AppMacros::_smallResource;
	}
	CCFileUtils::sharedFileUtils()->setResourceDirectory(selectedResource.directory);
	pDirector->setContentScaleFactor(selectedResource.scale);
	_globalScale = selectedResource.scale;

	pDirector->setDisplayStats(PlatformSpecific::getShowDisplayStats());
	pDirector->setAnimationInterval(1.0 / _targetFps);
}