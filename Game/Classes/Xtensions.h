#include "cocos2d.h"
USING_NS_CC;

static inline CCSize
	ccsMul(const CCSize& s, const float coef)
{
	return CCSizeMake(s.width * coef, s.height * coef);
}