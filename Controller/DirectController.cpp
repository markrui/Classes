#include "DirectController.h"


bool DirectController::init(){
	this->iXSpeed = 0;
	this->iYSpeed = 0;

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

	CCPoint curPos = mControllerListener->getCurPosition();
	curPos.x += iXSpeed;
	curPos.y += iYSpeed;

	mControllerListener->setSimplePosition(curPos.x, curPos.y);
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
	return true;
}

void DirectController::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
	/* ��ȡ��������� */
	CCPoint touchLocation = pTouch->getLocationInView();
	touchLocation = CCDirector::sharedDirector()->convertToGL(touchLocation);

	/* �����ƶ�������� */
	CCPoint pos = mControllerListener->getCurPosition();

	/* �ж��������ƶ����������ƶ� */
	int iSpeed = 0;
	if (touchLocation.x > pos.x) {
		iSpeed = 1;
	}
	else {
		iSpeed = -1;
	}

	setiXSpeed(iSpeed);
}

void DirectController::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{
	/* ֹͣX�����ϵ��ƶ� */
	setiXSpeed(0);
}

void DirectController::registerWithTouchDispatcher()
{
	/* ע�ᴥ���¼� */
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}