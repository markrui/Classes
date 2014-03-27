#pragma once
#include "Hero.h"
class MaoChong :
	public Hero
{
public:
	// ����״̬��������Ϸ�����еĿ������Լ�����֡
	virtual void statusChangeTo(HeroStatus mStatus);

	// ���ý�ɫ״̬
	void setStatus(HeroStatus mStatus);
	bool initWithTileMap(CCTMXTiledMap* map);

	virtual void setSimplePosition(CCPoint c);
	static MaoChong* createWithTiledMap(CCTMXTiledMap* map);
private:
	// ���ö�Ӧ״̬��animation
	void runStatusAnimation();
};

