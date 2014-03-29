#include "DirectController.h"
#include "Data/GlobalVar.h"

bool DirectController::init(){
	this->isStartTouch = false;
	this->startP = CCPointZero;
	this->iYSpeed = SPEED;

	/* ���������� */
	this->setTouchEnabled(true);

	this->scheduleUpdate();
	return true;
}

void DirectController::update(float dt)
{
	if (mControllerListener == NULL) {
		return;
	}

	
	MaoChong* hero = dynamic_cast<MaoChong*>(mControllerListener);
	if (!hero){
		CCLog("wrong 1");
		return;
	}
	CCPoint curPos = hero->getCurPosition();
	curPos.y += iYSpeed;
	hero->setSimplePosition(curPos);
}

void DirectController::setiXSpeed(int iSpeed)
{
	this->iXSpeed = iSpeed;
}

void DirectController::setiYSpeed(int iSpeed)
{
	this->iYSpeed = iSpeed;
}
bool DirectController::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	if (!mControllerListener){
		return false;
	}
	if (isStartTouch){
		return false;
	}
	isStartTouch = true;
	/* ��ȡ��������� */
	CCPoint touchLocation = pTouch->getLocationInView();
	this->startP = CCDirector::sharedDirector()->convertToGL(touchLocation);
	return true;
}

void DirectController::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
	///* ��ȡ��������� */
	//CCPoint touchLocation = pTouch->getLocationInView();
	//touchLocation = CCDirector::sharedDirector()->convertToGL(touchLocation);

	///* �����ƶ�������� */
	//CCPoint pos = mControllerListener->getCurPosition();

	///* �ж��������ƶ����������ƶ� */
	//int iSpeed = 0;
	//if (touchLocation.x > pos.x) {
	//	iSpeed = 1;
	//}
	//else {
	//	iSpeed = -1;
	//}

	//setiXSpeed(iSpeed);
}

void DirectController::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{
	if (!mControllerListener){
		return;
	}
	if (!isStartTouch){
		return;
	}
	isStartTouch = false;
	CCPoint touchLocation = pTouch->getLocationInView();
	CCPoint endP = CCDirector::sharedDirector()->convertToGL(touchLocation);

	MaoChong* hero = dynamic_cast<MaoChong*>(mControllerListener);
	if (!hero){
		return;
	}
	if (startP.x - endP.x < -20){
		hero->statusChangeTo(HeroStatus::RIGHT_FLY);
	}
	else if(startP.x - endP.x > 20){
		hero->statusChangeTo(HeroStatus::LEFT_FLY);
	}
	//float maxLength = MAX(abs(startP.x - endP.x), abs(startP.y - endP.y));
}

void DirectController::registerWithTouchDispatcher()
{
	/* ע�ᴥ���¼� */
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}