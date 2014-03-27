#pragma once
#include "Hero.h"
class MaoChong :
	public Hero
{
public:
	CREATE_FUNC(MaoChong);
	// ����״̬��������Ϸ�����еĿ������Լ�����֡
	void statusChangeTo(HeroStatus mStatus);

	// ���ý�ɫ״̬
	void setStatus(HeroStatus mStatus);

	bool initWithTileMap(CCTMXTiledMap* map);

	static MaoChong* createWithTiledMap(CCTMXTiledMap* map);
private:
	// ���ö�Ӧ״̬��animation
	void runStatusAnimation();
};

