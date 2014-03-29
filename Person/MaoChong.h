#pragma once
#include "Hero.h"
#include "Controller/DirectController.h"
#include "Scene/Rope.h"
class FactoryScene;

class MaoChong :
	public Hero
{
public:
	// ����״̬��������Ϸ�����еĿ������Լ�����֡
	virtual void statusChangeTo(int mStatus);

	// ���ý�ɫ״̬
	void setStatus(int mStatus);
	bool initWithTileMap(CCTMXTiledMap* map);

	virtual void setSimplePosition(CCPoint c);
	static MaoChong* createWithTiledMap(CCTMXTiledMap* map);
	int getCurLine();
	void setCurLine(int c);
	void moveFinishedCallFunc();
private:
	// ���ö�Ӧ״̬��animation
	void runStatusAnimation();
	// ��ǰ������ ��0������1���м䣬2������
	int curLine;
};

