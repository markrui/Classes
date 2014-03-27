#include "MaoChong.h"


//// 有限状态机控制游戏过程中的控制器以及动画帧
//void statucChangeTo(HeroStatus mStatus);
//
//// 设置角色状态
//void setStatus(HeroStatus mStatus);
//
//// 根据传入的参数运行动作
//void doAnimation();

MaoChong* MaoChong::createWithTiledMap(CCTMXTiledMap* map){
	MaoChong* maoChong = new MaoChong();

	if (maoChong && maoChong->initWithTileMap(map)){

	}
	else{
		CC_SAFE_DELETE(maoChong);
	}
	return maoChong;
}

bool MaoChong::initWithTileMap(CCTMXTiledMap* map){
	this->mStatus = HeroStatus::PA;
	this->map = map;
	this->meta = map->layerNamed("meta");
	this->meta->setVisible(false);

	CCTMXObjectGroup* objGroup = map->objectGroupNamed("objects");
	CCDictionary* heroStartPointDic = objGroup->objectNamed("heroStartPoint");
	float heroX = heroStartPointDic->valueForKey("x")->floatValue();
	float heroY = heroStartPointDic->valueForKey("y")->floatValue();

	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("hero/hero.plist", "hero/hero.png");
	CCSprite* heroSprite = CCSprite::createWithSpriteFrameName("chongPaFrame_0.png");

	heroSprite->setPosition(ccp(heroX, heroY));

	map->addChild(heroSprite, 10);

	setSprite(heroSprite);
	return true;
}


void MaoChong::statusChangeTo(HeroStatus mStatus){
	switch (mStatus)
	{
	case PA:
		setStatus(PA);
		break;
	case LEFT_FLY:
		break;
	case RIGHT_FLY:
		break;
	case FALL_DOWN:
		break;
	case BUTTERFLY:
		break;
	default:
		break;
	}
	runStatusAnimation();
}

void MaoChong::setStatus(HeroStatus mStatus){
	this->mStatus = mStatus;
}

void MaoChong::runStatusAnimation(){
	CCArray* animFrames = NULL;
	char str[100] = { 0 };
	CCSpriteFrameCache* cache = CCSpriteFrameCache::sharedSpriteFrameCache();

	switch (mStatus)
	{
	case PA:
		animFrames = CCArray::createWithCapacity(2);
		for (int i = 0; i < 2; i++)
		{
			sprintf(str, "chongPaFrame_%i.png", i);
			CCSpriteFrame* frame = cache->spriteFrameByName(str);
			animFrames->addObject(frame);
		}

		break;
	case LEFT_FLY:
		break;
	case RIGHT_FLY:
		break;
	case FALL_DOWN:
		break;
	case BUTTERFLY:
		break;
	default:
		break;
	}

	CCAnimation* animation = CCAnimation::createWithSpriteFrames(animFrames, 0.5f);
	animation->setLoops(INT32_MAX);
	this->mSprite->runAction(CCAnimate::create(animation));
	/*CCLog("parent: %d",this->mSprite->getParent());*/
}