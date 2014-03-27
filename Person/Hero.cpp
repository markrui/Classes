#include "Hero.h"


float Max(float a, float b)
{
	if (a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

float Min(float a, float b)
{
	if (a > b){
		return b;
	}
	else
	{
		return a;
	}
}

void Hero::setSprite(CCSprite* mSprite){
	this->mSprite = mSprite;
}

void Hero::setSimplePosition(CCPoint c){

}

void Hero::setStatus(HeroStatus status){
	this->mStatus = status;
}


void Hero::setViewPointByPlayer()
{
	if (mSprite == NULL) {
		return;
	}
	CCLayer* parent = (CCLayer*)mSprite->getParent();

	/* ��ͼ�������� */
	CCSize mapTiledNum = map->getMapSize();

	/* ��ͼ�������Ӵ�С */
	CCSize tiledSize = map->getTileSize();

	/* ��ͼ��С */
	CCSize mapSize = CCSize(
		mapTiledNum.width * tiledSize.width,
		mapTiledNum.height * tiledSize.height);

	/* ��Ļ��С */
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();

	/* ��������� */
	CCPoint spritePos = mSprite->getPosition();

	/* �����������С����Ļ��һ�룬��ȡ��Ļ�е����꣬����ȡ��������� */
	float x = Max(spritePos.x, visibleSize.width / 2);
	float y = Max(spritePos.y, visibleSize.height / 4);

	/* ���x��y������������Ͻǵļ���ֵ����ȡ����ֵ�����꣨����ֵ��ָ���õ�ͼ������Ļ��ɳ��ֺڱߵļ������꣩ */
	x = Min(x, mapSize.width - visibleSize.width / 2);
	y = Min(y, mapSize.height - visibleSize.height / 4 * 3);

	CCPoint destPos = CCPoint(x, y);
	CCPoint fixPos = CCPoint(visibleSize.width / 2, visibleSize.height / 4);

	/* ������Ļ�е����Ҫ�ƶ���Ŀ�ĵ�֮��ľ��� */
	CCPoint viewPos = ccpSub(fixPos, destPos);

	parent->setPosition(viewPos);
}

CCPoint Hero::tileCoordForPosition(CCPoint pos){
	CCSize mapTiledNum = map->getMapSize();
	CCSize tiledSize = map->getTileSize();

	float x = pos.x / tiledSize.width;
	float y = pos.y / tiledSize.height;

	/* Cocos2d-x��Ĭ��Y�������������ϵģ�����Ҫ��һ��������� */
	y = mapTiledNum.height - y;

	/*CCLog("x: %f, y: %f", x, y);
	CCLog("pos.x: %f, pos.y: %f", pos.x, pos.y);*/
	return ccp(x, y);
}

void Hero::setController(Controller* controller){
	this->mController = controller;
	mController->setControllerListener(this);
}

CCPoint Hero::getCurPosition(){
	if (mSprite){
		return this->getPosition();
	}

	return CCPoint(0, 0);
}