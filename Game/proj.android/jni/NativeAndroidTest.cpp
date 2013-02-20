#include "NativeTest.h"
#include "cocos2d.h"
#include "platform\android\jni\JniHelper.h"

using namespace cocos2d;

void NativeTest::test()
{
	CCLog("hello android world");
	JniMethodInfo methodInfo;
	JniHelper::getStaticMethodInfo(methodInfo, "org/cocos2dx/game/Game", "test", "()V");
	methodInfo.env->CallStaticObjectMethod(methodInfo.classID, methodInfo.methodID);
}
