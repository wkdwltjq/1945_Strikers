#pragma once
#include "gameNode.h"

enum PLAYERDIRECTION
{
	IDLE,
	LEFT_MOVE,
	RIGHT_MOVE
};

class player : public gameNode
{
private:
	PLAYERDIRECTION _direction;//플레이어 이동 프레임 처리를 위한 변수
	image* _player;//플레이어 이미지
	RECT _rc;//플레이어 충돌용 렉트
	float _speed;//플레이어 스피드
	float _currentHP, _maxHP;//플레이어 HP
	int _x, _y;//플레이어 중점좌표
	int _count, _index;//프레임 처리를 위한 카운트

	char str[127];//디버깅용

public:
	player();
	~player();

	HRESULT init();
	void release();
	void render();
	void update();

	void move();
	RECT getPlayerRC() { return _rc; }//플레이어의 렉트를 플레이 그라운드에서 가져다 충돌처리 감지용으로 쓰기위한 함수
	int getPlayerX() { return _x; }//플레이어 x좌표를 플레이 그라운드에서 가져다가 적들이 공격할 위치를 지정하기 위한 함수
	int getPlayerY() { return _y; }//플레이어 y좌표를 플레이 그라운드에서 가져다가 적들이 공격할 위치를 지정하기 위한 함수
	void setPlayerX(int x) { _x = x; }
	void setPlayerY(int y) { _y = y; }

	float getCurrentHP() { return _currentHP; }//플레이어 HP를 플레이 그라운드에서 참조하기 위한 함수
	float getMaxHP() { return _maxHP; }//플레이어 maxHP를 플레이 그라운드에서 참조하기 위한 함수
	void setCurrentHP(float currentHP) { _currentHP -= currentHP; }//플레이어 현재 HP를 플레이 그라운드에서 변경하기 위한 함수
	void setCurrentPlusHP(float currentHP) { _currentHP = currentHP; }//플레이어 현재 HP를 플레이 그라운드에서 변경하기 위한 함수
};

