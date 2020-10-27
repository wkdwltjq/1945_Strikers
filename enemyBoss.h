#pragma once
#include "gameNode.h"
#include <iostream>
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
using namespace std;
struct tagBoss
{
	image* imageName;
	RECT rc;
	float speed;
	float angle;
};

class enemyBoss : public gameNode
{
private:
	vector<tagBoss>			  _vEnemyBoss;
	vector<tagBoss>::iterator _viEnemyBoss;
	float _x, _y;
	int _hp;
	int _count;
	int _frameNum;
	bool _bossAppear;

public:
	enemyBoss();
	~enemyBoss();

	HRESULT init();
	void update();
	void release();
	void render();
	void move();
	void fristMove();
	void removeBoss(int arrNum);

	float getBossX() { return _x; }
	float getBossY() { return _y; }
	int getHP() { return _hp; }
	void setHP(int hp) { _hp -= hp; }
	bool getBossAppear() { return _bossAppear; }

	vector<tagBoss> getvEnemyBoss() { return _vEnemyBoss; }
	vector<tagBoss>::iterator getviEnemyBoss() { return _viEnemyBoss; }
};

