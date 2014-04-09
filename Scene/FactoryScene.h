#pragma once
#include "cocos2d.h"
#include "BaseScene.h"
#include "Rope.h"

class FactoryScene :
	public BaseScene
{
public:
	CREATE_FUNC(FactoryScene);

	virtual bool init();
	static CCScene* scene();

	//���õ�ͼ�ϵ���Ϣ������ ��
	void setMapThings();

	// �ѽ�ɫ������������,�ȷ��ã������Ƿ���������
	bool bindHeroToRope(Rope* rope);
	// ��ʼ��hero
	void initHero();

	void findRope();

	/* ����˿����*/
	void doSiPa();
	/* ���ë����˿�󣬿ɷ��ص����ӣ�����NULL�������޷��ҵ����ʵġ�*/
	Rope* getSiTouchRope();
	/* �ص����� */
	void backToRope(float dt);

	void setPa();
	~FactoryScene();

private:
	Rope* targetRope;
};

