#pragma once
#include "gameNode.h"
#include <gdiplus.h>

#pragma comment(lib,"comctl32")

#pragma comment(lib,"gdiplus")

#pragma warning(disable : 4996)

using namespace Gdiplus;

struct tagJuneBoss
{
	image* juneBossImage;
	RECT rc;
	float speed;
};

class enemyJuneBoss : public gameNode
{
private:
	vector<tagJuneBoss>			  _vJuneBoss;
	vector<tagJuneBoss>::iterator _viJuneBoss;

	image* _juneBossRotation;//�غ��� ȸ���ϴ� ���� �̹���
	float _rotation;//ȸ������
	float _x, _y;
	int _count;
	int _hp;

public:
	enemyJuneBoss() {};
	~enemyJuneBoss() {};

	HRESULT init();
	void release();
	void render();
	void update();
	void move();
	void removeJuneBoss(int arrNum);

	int getHP() { return _hp; }//�غ����� ���� ü�� ��������
	void setHP(int HP) { _hp -= HP; }//�غ��� hp ���̱�

	float getJuneBossX() { return _x; }//�غ��� x��ǥ ������
	float getJuneBossY() { return _y; }//�غ��� y��ǥ ������
	float getJuneBossRotation() { return _rotation; }//�غ��� ���Ű��� ������

	vector<tagJuneBoss> getvJuneBoss() { return _vJuneBoss; }
	vector<tagJuneBoss>::iterator getviJuneBoss() { return _viJuneBoss; }
};

