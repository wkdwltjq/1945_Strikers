#pragma once
#include "gameNode.h"
//#define COUNT 3

struct tagEnemy
{
	image* enemyImage;//적이미지
	RECT rc;//충돌감지를 위한 적렉트
	float speed;//적스피드
	float angle;//ufo 적 각도값
	int x, y;//적중점좌표
	int count;//프레임 카운트
	int moveCount;//무브카운트
	bool loop;//일반적이 화면밖을 벗어나면 위치를 초기화 시키기 위한 변수
	bool hit;//벽에 부딪히면 반대방향으로 이동시키기 위해 필요한 변수
};

class enemy : public gameNode
{
private:
	vector<tagEnemy>			_vEnemy;
	vector<tagEnemy>::iterator	_viEnemy;//일반적

	vector<tagEnemy>			_vEnemyUfo;
	vector<tagEnemy>::iterator	_viEnemyUfo;//왼쪽에서 오른쪽으로 나오는 ufo

	vector<tagEnemy>			_vEnemyUfo2;
	vector<tagEnemy>::iterator	_viEnemyUfo2;//오른쪽에서 왼쪽으로 나오는 ufo

	vector<tagEnemy>			_vEnemyHelicopter;
	vector<tagEnemy>::iterator  _viEnemyHelicopter;//헬리콥터 적

	vector<tagEnemy>			_vEnemyHelicopter2;
	vector<tagEnemy>::iterator  _viEnemyHelicopter2;//헬리콥터 적

	//int _count[COUNT];//각기 다른 프레임 재생을 위한 카운트
	int _count;//헬리콥터 프레임에 사용할 카운트
	int _count2;//헬리콥터 프레임에 사용할 카운트
	int _CountFire;//발사 카운트용
	int _rndCountFire;//적이 랜덤으로 공격할 확률

	char str[127];

public:
	enemy();
	~enemy();

	HRESULT init();
	void release();
	void render();
	void update();

	void removeEnemy(int arrNum);//일반적제거
	void removeEnemyUfo(int arrNum);//ufo적제거
	void removeEnemyUfo2(int arrNum);//ufo적제거
	void removeEnemyHelicopter(int arrNum);//헬리콥터 적 제거
	void removeEnemyHelicopter2(int arrNum);//2페이즈 헬리콥터 적 제거
	void move();
	void move2();

	bool bulletCountfire();//적이 일정확률로 플레이어를 공격하게 만들기 위한 함수

	vector<tagEnemy> getvEnemy() { return _vEnemy; }//일반적
	vector<tagEnemy>::iterator getviEnemy() { return _viEnemy; }//일반적

	vector<tagEnemy> getvEnemyUfo() { return _vEnemyUfo; }//ufo
	vector<tagEnemy>::iterator getviEnemyUfo() { return _viEnemyUfo; }//ufo

	vector<tagEnemy> getvEnemyUfo2() { return _vEnemyUfo2; }//ufo
	vector<tagEnemy>::iterator getviEnemyUfo2() { return _viEnemyUfo2; }//ufo

	vector<tagEnemy> getvEnemyHelicopter() { return _vEnemyHelicopter; }//헬리콥터적
	vector<tagEnemy>::iterator getviEnemyHelicopter() { return _viEnemyHelicopter; }//헬리콥터적

	vector<tagEnemy> getvEnemyHelicopter2() { return _vEnemyHelicopter2; }//헬리콥터적
	vector<tagEnemy>::iterator getviEnemyHelicopter2() { return _viEnemyHelicopter2; }//헬리콥터적
};

