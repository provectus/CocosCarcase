LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := game_shared

LOCAL_MODULE_FILENAME := libgame

LOCAL_SRC_FILES := main.cpp \
					NativeAndroidTest.cpp \
					PlatformSpecificAndroid.cpp \
                   ../../Classes/AppDelegate.cpp \
                   ../../Classes/MainScene.cpp \
                   ../../Classes/AppModel.cpp \
                   ../../Classes/DiamondItem.cpp \
                   ../../Classes/Utils.cpp \
                   ../../Classes/SpriteFactory.cpp \
                   ../../Classes/AppMacros.cpp \
                   ../../Classes/NativeTest.cpp	\
                   ../../Classes/MainMenu.cpp \
                   ../../Classes/MainBackground.cpp \
                   ../../Classes/Bunny.cpp

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes

LOCAL_WHOLE_STATIC_LIBRARIES := cocos2dx_static

include $(BUILD_SHARED_LIBRARY)

$(call import-module,cocos2dx)