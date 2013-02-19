#include "AppDelegate.h"
#include "MainScene.h"
#include "AppMacros.h"

USING_NS_CC;

AppDelegate::AppDelegate() {}

AppDelegate::~AppDelegate() {}

bool AppDelegate::applicationDidFinishLaunching() {
	// initialize director
	CCDirector* pDirector = CCDirector::sharedDirector();
	CCEGLView* pEGLView = CCEGLView::sharedOpenGLView();

	pDirector->setOpenGLView(pEGLView);

	pEGLView->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, kResolutionNoBorder);

	CCSize frameSize = pEGLView->getFrameSize();
	Resource selectedResource;
	if (frameSize.width>=largeResource.screenWidth) {
		selectedResource=largeResource;
	}
	else if (frameSize.width>=normalResource.screenWidth) {
		selectedResource=normalResource;
	}
	else {
		selectedResource=smallResource;
	}
	CCFileUtils::sharedFileUtils()->setResourceDirectory(selectedResource.directory);
	pDirector->setContentScaleFactor(selectedResource.scale);

	pDirector->setDisplayStats(false);
	pDirector->setAnimationInterval(1.0 / 60);

	// create a scene. it's an autorelease object
	CCScene *pScene = MainScene::scene();
	pDirector->runWithScene(pScene);

	return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
	CCDirector::sharedDirector()->stopAnimation();

	// if you use SimpleAudioEngine, it must be pause
	// SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
	CCDirector::sharedDirector()->startAnimation();

	// if you use SimpleAudioEngine, it must resume here
	// SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}
