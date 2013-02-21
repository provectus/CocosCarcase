#include "SpriteFactory.h"

void SpriteFactory::initSpriteFactory() {
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("atlases/atlas_1.plist", "atlases/atlas_1.png");
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("atlases/atlas_2.plist", "atlases/atlas_2.png");
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("atlases/gui_atlas.plist", "atlases/gui_atlas.png");
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("atlases/animation2.plist", "atlases/animation2.png");
		CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("atlases/walking_bunny.plist", "atlases/walking_bunny.png");
}