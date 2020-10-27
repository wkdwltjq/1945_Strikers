#pragma once
#include "gameNode.h"
#include <vector>

//총알에 사용할 구조체
struct tagBullet
{
	image* bulletImage;		//총알에 쓸 이미지
	RECT rc;				//총알에 쓸 렉트
	float x, y;				//중점 x, y
	float angle;			//총알 각도
	float radius;			//총알 반지름
	float speed;			//스피드
	float fireX, fireY;		//총알 발사된 위치 XY
	bool isFire;			//발사했나?
	int count;				//프레임 이미지에 쓸 카운트
};

//플레이어 폭탄
class bomb : public gameNode
{
private:
	vector<tagBullet>			_vBomb;
	vector<tagBullet>::iterator	_viBomb;

	const char* _imageName;//폭탄 이미지
	float _range;//사거리
	int _bombMax;//폭탄개수

	char _str[127];

public:
	bomb() {};
	~bomb() {};

	HRESULT init(const char* imageName, float range, int bombMax);
	void release();
	void render();
	void update();

	void move();
	void bombFire(float x, float y, float speed);
	void removeBomb(int arrNum);

	vector<tagBullet> getvBomb() { return _vBomb; }
	vector<tagBullet>::iterator getviBomb() { return _viBomb; }

	void setBombMax(int bombMax) { _bombMax = bombMax; }//폭탄개수 조절
};

//일반적총알
class enemyBullet : public gameNode
{
private:
	vector<tagBullet>			_vEnemyBullet;
	vector<tagBullet>::iterator _viEnemyBullet;

	const char* _imageName;
	float _range;
	int _bulletMax;
public:
	enemyBullet() {};
	~enemyBullet() {};

	HRESULT init(const char* imageName, int bulletMax, float range);
	void release();
	void update();
	void render();

	void fire(float x, float y, float angle, float speed);

	void move();
	
	void removeEnemyBullet(int arrNum);

	vector<tagBullet> getvEnemyBullet() { return _vEnemyBullet; }
	vector<tagBullet>::iterator getviEnemyBullet() { return _viEnemyBullet; }
};

//ufo적총알
class enemyBullet2 : public gameNode
{
private:
	vector<tagBullet>			_vEnemyBullet2;
	vector<tagBullet>::iterator	_viEnemyBullet2;

	const char* _imageName;
	float _range;
	int _bulletMax;

	char str[127];

public:
	enemyBullet2() {};
	~enemyBullet2() {};

	HRESULT init(const char* imageName, int bulletMax, float range);
	void render();
	void release();
	void update();

	void fire(float x, float y, float angle, float speed);

	void move();

	void removeEnemyBullet2(int arrNum);

	vector<tagBullet> getvEnemyBullet2() { return _vEnemyBullet2; }
	vector<tagBullet>::iterator	getviEnemyBullet2() { return _viEnemyBullet2; }
};

//헬리콥터 적총알
class enemyBullet3 : public gameNode
{
private:
	vector<tagBullet>			_vEnemyBullet3;
	vector<tagBullet>::iterator	_viEnemyBullet3;

	const char* _imageName;
	float _range;
	int _bulletMax;

	char str[127];

public:
	enemyBullet3() {};
	~enemyBullet3() {};

	HRESULT init(const char* imageName, int bulletMax, float range);
	void render();
	void release();
	void update();

	void fire(float x, float y, float speed);

	void move();

	void removeEnemyBullet3(int arrNum);

	vector<tagBullet> getvEnemyBullet3() { return _vEnemyBullet3; }
	vector<tagBullet>::iterator	getviEnemyBullet3() { return _viEnemyBullet3; }
};

//준보스 적총알
class enemyJuneBullet : public gameNode
{
private:
	vector<tagBullet>			_vEnemyJuneBullet;
	vector<tagBullet>::iterator	_viEnemyJuneBullet;

	const char* _imageName;
	float _range;
	int _bulletMax;

public:
	enemyJuneBullet() {};
	~enemyJuneBullet() {};

	HRESULT init(const char* imageName, int bulletMax, float range);
	void render();
	void release();
	void update();

	void fire(float x, float y, float angle, float speed);

	void move();

	void removeEnemyJuneBullet(int arrNum);

	vector<tagBullet> getvEnemyJuneBullet() { return _vEnemyJuneBullet; }
	vector<tagBullet>::iterator	getviEnemyJuneBullet() { return _viEnemyJuneBullet; }
};

//보스 적총알
class enemyBossBullet : public gameNode
{
private:
	vector<tagBullet>			_vEnemyBossBullet;
	vector<tagBullet>::iterator	_viEnemyBossBullet;

	const char* _imageName;
	float _range;
	int _bulletMax;

public:
	enemyBossBullet() {};
	~enemyBossBullet() {};

	HRESULT init(const char* imageName, int bulletMax, float range);
	void render();
	void release();
	void update();

	void fire(float x, float y, float angle, float speed);

	void move();

	void removeEnemyBossBullet(int arrNum);

	vector<tagBullet> getvEnemyBossBullet() { return _vEnemyBossBullet; }
	vector<tagBullet>::iterator	getviEnemyBossBullet() { return _viEnemyBossBullet; }
};

//보스 적총알2페이즈
class enemyBossBullet2 : public gameNode
{
private:
	vector<tagBullet>			_vEnemyBossBullet2;
	vector<tagBullet>::iterator	_viEnemyBossBullet2;

	const char* _imageName;
	float _range;
	int _bulletMax;

public:
	enemyBossBullet2() {};
	~enemyBossBullet2() {};

	HRESULT init(const char* imageName, int bulletMax, float range);
	void render();
	void release();
	void update();

	void fire(float x, float y, float angle, float speed);

	void move();

	void removeEnemyBossBullet2(int arrNum);

	vector<tagBullet> getvEnemyBossBullet2() { return _vEnemyBossBullet2; }
	vector<tagBullet>::iterator	getviEnemyBossBullet2() { return _viEnemyBossBullet2; }
};

//플레이어총알
class playerBullet : public gameNode
{
private:
	vector<tagBullet>			_vPlayerBullet;
	vector<tagBullet>::iterator _viPlayerBullet;

	int _bulletMax;
	float _range;
public:
	playerBullet() {};
	~playerBullet() {};

	virtual HRESULT init(int bulletMax, float range);
	virtual void release();
	virtual void update();
	virtual void render();

	void fire(float x, float y);

	void move();

	void removePlayerBullet(int arrNum);

	vector<tagBullet> getvPlayerBullet() { return _vPlayerBullet; }
	vector<tagBullet>::iterator getviPlayerBullet() { return _viPlayerBullet; }
};

//플레이어총알 2단계
class playerBullet2 : public gameNode
{
private:
	vector<tagBullet>			_vPlayerBullet2;
	vector<tagBullet>::iterator _viPlayerBullet2;

	int _bulletMax;
	float _range;

public:
	playerBullet2() {};
	~playerBullet2() {};

	HRESULT init(int bulletMax, float range);
	void release();
	void update();
	void render();

	void fire(float x, float y);
	void move();
	void removePlayerBullet2(int arrNum);

	vector<tagBullet> getvPlayerBullet2() { return _vPlayerBullet2; }
	vector<tagBullet>::iterator getviPlayerBullet2() { return _viPlayerBullet2; }
};

//플레이어 총알 3단계
class playerBullet3 : public gameNode
{
private:
	vector<tagBullet>			_vPlayerBullet3;
	vector<tagBullet>::iterator _viPlayerBullet3;

	float _range;
	int _bulletMax;

public:
	playerBullet3() {};
	~playerBullet3() {};

	HRESULT init(int bulletMax, float range);
	void update();
	void render();
	void release();

	void move();
	void fire(float x, float y);
	void removePlayerBullet3(int arrNum);

	vector<tagBullet> getvPlayerBullet3() { return _vPlayerBullet3; }
	vector<tagBullet>::iterator getviPlayerBullet3() { return _viPlayerBullet3; }
};

//1. 생성해두고 발사하는 
class missile : public gameNode
{
private:
	vector<tagBullet>			_vBullet;
	vector<tagBullet>::iterator _viBullet;

	float _range;	//사거리
public:
	missile() {};
	~missile() {};

	//초기화 함수 (최대 몇발, 사거리는 얼마)
	HRESULT init(int bulletMax, float range);
	void release();
	void update();
	void render();

	void fire(float x, float y);

	void move();
	void removeBullet(int arrNum);

	vector<tagBullet> getvBullet() { return _vBullet; }
	vector<tagBullet>::iterator getviBullet() { return _viBullet; }
};