#pragma once

namespace cocos2d {
	class CCPoint;
}

enum ScreenAlign {
	Middle = 0,
	Left = 1,
	Right = 2,
	TopLeft = 3,
	TopMiddle = 4,
	TopRight = 5,
	BottomLeft = 6,
	BottomMiddle = 7,
	BottomRight = 8,
};

class Utils
{
public:
	static int randomRange(int max);
	static int randomRange(int min, int max);
	static float randomValue();
	static cocos2d::CCPoint alignTo(ScreenAlign screenAlign, cocos2d::CCPoint offset);
	static cocos2d::CCPoint alignTo(ScreenAlign screenAlign);

private:
	static bool _isRandomInited;

	static void initRandom();
};