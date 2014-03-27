#pragma once

#include "cocos2d.h"

using namespace cocos2d;

class Rope : public CCNode
{
public:
	Rope();
	// ���������
	static const float MAXLINE;

	// ������̳���
	static const float MINLINE;
	// ��ʼ��
	virtual bool init();
	// ������ӵ���ײ����
	CCRect getCollideRect();
	// ���Ӿ�Ч��ʵ��
	void rollAction();
	// ��������Ч��
	void update(float delta);
protected:
	CCSprite* mSprite;
	// ��ǰ�˶������Ƿ�����
	bool isDown;
	// ��ǰ����
	float curLength;
};