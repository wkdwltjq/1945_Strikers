#pragma once
#include "gameNode.h"
#include "player.h"
#include "enemy.h"
#include "bullets.h"
#include "progressBar.h"
#include "effect.h"
#include "item.h"
#include "enemyJuneBoss.h"
#include "enemyBoss.h"
#include <iostream>
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
using namespace std;
#define COUNT 4//화면밖의 렉트에 쓸 배열방번호

class mainGameScene : public gameNode
{
private:
	effect* _deathExplosions;//플레이어나 적이 죽으면 폭발 이펙트
	effect* _playerHit;//적총알에 플레이어가 공격당할때 이펙트
	effect* _bossExplosions;//보스가 죽었을때 나올 이펙트

	image* _background;//배경이미지
	image* _gameOver;//게임오버 이미지
	image* _blackScrren;//죽었을때 검은화면 출력을 위한 이미지
	image* _playerBombMove;//플레이어가 폭탄을 발사할때 플레이어의 프레임 이미지 출력용
	image* _bombExplosionImage;//폭탄 폭발 프레임
	image* _missionComplete;//게임클리어

	player* _player;//플레이어 상속할당
	enemy* _enemy;//적 상속할당
	enemyJuneBoss* _enemyJuneBoss;//준보스 상속할당
	enemyBoss* _enemyBoss;//보스 상속할당
	enemyBullet* _enemyBullet;//적총알 상속할당
	enemyBullet2* _enemyBullet2;//ufo적 총알 상속할당
	enemyBullet3* _enemyBullet3;//헬리콥터 적 총알 상속할당
	enemyJuneBullet* _enemyJuneBullet;//준보스 총알 상속할당
	enemyBossBullet* _enemyBossBullet;//보스 총알 상속할당
	enemyBossBullet2* _enemyBossBullet2;//보스 총알 2페이지 상속할당
	playerBullet* _playerBullet;//플레이어 총알 상속할당
	playerBullet2* _playerBullet2;//플레이어 총알 2단계 상속할당
	playerBullet3* _playerBullet3;//플레이어 총알 3단계 상속할당
	progressBar* _progressBar;//프로그래스바 상속할당
	item* _item;//아이템 상속할당
	bomb* _bomb;//폭탄 상속할당

	string _token;
	vector<string>			_vSoundList;
	vector<string>::iterator	_viSoundList;
	//사운드

	RECT _rc[COUNT];//플레이어가 맵밖으로 나가지 못하게 막기위한 렉트

	RECT _bombExplosionRc;//폭탄 폭발 렉트
	float _rotation;//보스공격각도
	int _loopX, _loopY;//배경이미지 무한루프
	int _alpha;//검은화면 연출을 위한 알파값 
	int _missionCompleteAlpha;//게임클리어 이미지에 사용할 알파값
	int _missionCompleteAlphaCount;//게임클리어 이미지에 사용할 알파값의 카운트값
	int _count;//프레임 카운트
	int _bobmExplosionCount;//폭탄 폭발 프레임에 사용할 카운트
	int _rndItem;//공격력강화 아이템, 폭탄아이템 둘중 랜덤으로 나올 아이템 정할 변수
	int _juneBossBulletCount;//보스 총알 발사 카운트
	int _bossBulletCount;//보스 총알 발사 카운트
	int _bossBulletCount2;//보스 총알 2페이즈 발사 카운트

	bool _death;//플레이어가 죽으면
	bool _playerBomb;//플레이어가 폭탄 발사할때 플레이어의 프레임 이미지 작동여부 확인
	bool _bombExplosion;//폭탄폭발이 트루인지 확인
	bool _juneBossAttack;//준보스 공격시작
	bool _juneBossAppear;//준보스 등장
	bool _bossAttack;//보스공격시작
	bool _bossAppear;//보스 등장
	bool _oneSoundPlay;//사운드를 한번만 재생시키기 위해 사용할 변수

public:
	mainGameScene();
	~mainGameScene();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void collision();//충돌처리를 위한 함수
};

