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

	image* _juneBossRotation;//준보스 회전하는 포신 이미지
	float _rotation;//회전각도
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

	int getHP() { return _hp; }//준보스의 현재 체력 가져오기
	void setHP(int HP) { _hp -= HP; }//준보스 hp 줄이기

	float getJuneBossX() { return _x; }//준보스 x좌표 얻어오기
	float getJuneBossY() { return _y; }//준보스 y좌표 얻어오기
	float getJuneBossRotation() { return _rotation; }//준보스 포신각도 얻어오기

	vector<tagJuneBoss> getvJuneBoss() { return _vJuneBoss; }
	vector<tagJuneBoss>::iterator getviJuneBoss() { return _viJuneBoss; }
};

