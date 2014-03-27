#include "Rope.h"

const float Rope::MAXLINE = 400;
const float Rope::MINLINE = 120;
const float RODE_WIDTH = 32;
const float SPEED = 10;

Rope::Rope(){
	init();
}

bool Rope::init()
{
	this->setAnchorPoint(ccp(0.5, 1));
	this->mSprite = CCSprite::create("map/rope.png");
	// �������
	isDown = rand() % 2;

	// �����ʼ����
	curLength = rand() % (int)(Rope::MAXLINE - Rope::MINLINE) + Rope::MINLINE;
	mSprite->setAnchorPoint(ccp(0.5, 1));
	mSprite->setPosition(CCPointZero);
	this->addChild(this->mSprite);

	return true;
}

CCRect Rope::getCollideRect(){
	CCSize size = this->mSprite->getContentSize();
	if (this->getParent()){
		return CCRectMake(this->getPositionX() - size.width / 2, this->getPositionY() - this->curLength, size.width, this->curLength);
	}
	return CCRectZero;
}

void Rope::rollAction(){
	scheduleUpdate();
}

void Rope::update(float delta)
{
	this->removeChild(this->mSprite);
	if (isDown)
	{
		if (this->curLength >= MAXLINE){
			isDown = false;
		}
		else {
			this->curLength += SPEED;
		}
	}
	else
	{
		if (this->curLength <= MINLINE){
			isDown = true;
		}
		else {
			this->curLength -= SPEED;
		}
		
	}
	this->mSprite = CCSprite::create("map/rope.png", CCRectMake(0, 0, 32, this->curLength));
	mSprite->setAnchorPoint(ccp(0.5, 1));
	mSprite->setPosition(CCPointZero);
	this->addChild(this->mSprite);
}




