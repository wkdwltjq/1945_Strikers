#pragma once
#include "gameNode.h"

struct tagItem
{
	image* imageName;//아이템 이미지
	RECT rc;//아이템 충돌
	float x, y;//아이템 중점좌표
	float speed;//아이템 스피드
	float angle;//아이템 앵글
	int count;//프레임 카운트
};

class item : public gameNode
{
private:
	vector<tagItem>				_vBombItem;
	vector<tagItem>::iterator	_viBombItem;//폭탄 아이템 벡터

	vector<tagItem>				_vAttackItem;
	vector<tagItem>::iterator	_viAttackItem;//공격력 아이템 벡터

	vector<tagItem>				_vHpItem;
	vector<tagItem>::iterator	_viHpItem;//회복 아이템 벡터

	image* _bombCountImage;//왼쪽하단 폭탄개수 이미지

	int _rndItemFire, _rndItemFireCount;//아이템이 나올확률에 사용할 변수
	int _bombCount;//폭탄개수
	int _attackCount;//플레이어 공격력 단계

	char _str[127];

public:
	item() {};
	~item() {};

	HRESULT init();
	void render();
	void update();
	void release();

	void move();//아이템 무브
	void removeBombItem(int arrNum);//폭탄 아이템이 플레이어랑 충돌시 삭제
	void removeAttackItem(int arrNum);//공격력 강화 아이템이랑 플레이어랑 충돌시 삭제
	void removeHpItem(int arrNum);//회복 아이템 플레이어랑 충돌시 삭제
	void bombItemFire(float x, float y);//폭탄 아이템이 나타날 위치
	void attackItemFire(float x, float y);//플레이어 공격력 단계업 아이템이 나타날 위치
	void hpItemFire(float x, float y);//회복 아이템이 나타날 위치

	int getBobmCount() { return _bombCount; }//현재 가지고 있는 폭탄개수 받아오기
	void setBobmCountPlus(int count) { _bombCount += count; }//현재 가지고 있는 폭탄개수 조절
	void setBobmCountMin(int count) { _bombCount -= count; }//현재 가지고 있는 폭탄개수 조절

	int getAttackCount() { return _attackCount; }//현재 플레이어 공격력 단계 받아오기
	void setAttackCount(int count) { _attackCount += count; }//플레이어 공격력 단계업
	bool itemCountFire();//아이템이 나올확률

	vector<tagItem> getvBombItem() { return _vBombItem; }
	vector<tagItem>::iterator getviBombItem() { return _viBombItem; }//폭탄아이템 벡터 가져오기

	vector<tagItem> getvAttackItem() { return _vAttackItem; }
	vector<tagItem>::iterator getviAttackItem() { return _viAttackItem; }//공격력 강화 아이템 벡터 가져오기

	vector<tagItem> getvHpItem() { return _vHpItem; }
	vector<tagItem>::iterator getviHpItem() { return _viHpItem; }
};

