#include "main.h"
#include "../Classes/AppDelegate.h"
#include "CCEGLView.h"
#include "AppMacros.h"

USING_NS_CC;

int APIENTRY _tWinMain(HINSTANCE hInstance,
					   HINSTANCE hPrevInstance,
					   LPTSTR    lpCmdLine,
					   int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// create the application instance
	AppDelegate app;
	CCEGLView* eglView = CCEGLView::sharedOpenGLView();

	CCSize designSize = AppMacros::getDesignResolutionSize();

	const float viewWidth = 1999;
	const float aspectRatio = designSize.height / designSize.width;
	const float windowWidth = 1280;

	eglView->setFrameSize(viewWidth, viewWidth * aspectRatio);
	eglView->setFrameZoomFactor(windowWidth / viewWidth);

	return CCApplication::sharedApplication()->run();
}