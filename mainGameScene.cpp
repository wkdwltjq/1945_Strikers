#include "stdafx.h"
#include "mainGameScene.h"


mainGameScene::mainGameScene()
{
}


mainGameScene::~mainGameScene()
{
}

HRESULT mainGameScene::init()
{

	_player = new player;
	_player->init();
	//플레이어 상속할당

	_enemy = new enemy;
	_enemy->init();
	//적 상속할당

	_enemyJuneBoss = new enemyJuneBoss;
	_enemyJuneBoss->init();
	//준보스 상속할당

	_enemyBoss = new enemyBoss;
	_enemyBoss->init();
	//보스 상속할당

	_playerBullet = new playerBullet;
	_playerBullet->init(30, WINSIZEY);
	//플레이어 총알 상속할당

	_playerBullet2 = new playerBullet2;
	_playerBullet2->init(60, WINSIZEY);
	//플레이어 총알 2단계 상속할당

	_playerBullet3 = new playerBullet3;
	_playerBullet3->init(90, WINSIZEY);
	//플레이어 총알 3단계 상속할당

	_progressBar = new progressBar;
	_progressBar->init(_player->getPlayerX(), _player->getPlayerY(), 50, 10);
	//프로그래스바 상속할당

	_missionComplete = IMAGEMANAGER->addImage("missionComplete", "image/missionComplete!.bmp", 600, 800, true, false, RGB(255, 0, 255));//게임클리어

	_enemyBullet = new enemyBullet;
	IMAGEMANAGER->addImage("enemyBullet", "image/enemyBullet.bmp", 12, 10, true, false, RGB(255, 0, 255));
	_enemyBullet->init("enemyBullet", 30, WINSIZEY);
	//일반적 총알 상속할당

	_enemyBullet2 = new enemyBullet2;
	IMAGEMANAGER->addFrameImage("enemyBullet2", "image/enemyBullets.bmp", 72, 20, 6, 1, true, false, RGB(255, 0, 255));
	_enemyBullet2->init("enemyBullet2", 30, WINSIZEY);
	//ufo 총알 상속할당

	_enemyBullet3 = new enemyBullet3;
	IMAGEMANAGER->addFrameImage("enemyBullet3", "image/enemyBullets2.bmp", 120, 20, 9, 1, true, false, RGB(255, 0, 255));
	_enemyBullet3->init("enemyBullet3", 30, WINSIZEY);
	//헬리콥터 총알 상속할당

	_enemyJuneBullet = new enemyJuneBullet;
	IMAGEMANAGER->addImage("enemyJuneBullet", "image/enemyJuneBossBullet.bmp", 18, 16, true, false, RGB(255, 0, 255));
	_enemyJuneBullet->init("enemyJuneBullet", 60, WINSIZEY);
	//준보스 총알 상속할당
	_juneBossBulletCount = 0;//준보스 총알 발사 카운트

	_enemyBossBullet = new enemyBossBullet;
	IMAGEMANAGER->addImage("enemyBossBullet", "image/enemyBossBullet.bmp", 27, 26, true, false, RGB(255, 0, 255));
	_enemyBossBullet->init("enemyBossBullet", 30, WINSIZEY);
	//보스 총알 상속할당
	_bossBulletCount = 0;
	_bossBulletCount2 = 0;

	_enemyBossBullet2 = new enemyBossBullet2;
	IMAGEMANAGER->addImage("enemyBossBullet2", "image/enemyBossBullet2.bmp", 27, 26, true, false, RGB(255, 0, 255));
	_enemyBossBullet2->init("enemyBossBullet2", 15, WINSIZEY);
	//보스 총알 2페이즈 상속할당


	_item = new item;
	_item->init();
	//아이템 상속할당

	_bomb = new bomb;
	IMAGEMANAGER->addFrameImage("bomb", "image/playerFire.bmp", 160, 30, 8, 1, true, false, RGB(255, 0, 255));
	_bomb->init("bomb", 100, _item->getBobmCount());
	//폭탄 상속할당

	_background = IMAGEMANAGER->addImage("backGround", "image/backGround.bmp", 600, 4288, false, false, RGB(255, 0, 255));//배경

	_gameOver = IMAGEMANAGER->addImage("gameOver", "image/gameOver.bmp", 558, 67, true, false, RGB(255, 0, 255));//게임오버

	_blackScrren = IMAGEMANAGER->addImage("blackScreen", "image/blackScrren.bmp", 600, 800, false, false, RGB(255, 0, 255));//검은화면 연출을 위한 이미지

	_playerBombMove = IMAGEMANAGER->addFrameImage("playerBombMove", "image/playerBombMove.bmp", 7050, 200, 47, 1, true, false, RGB(255, 0, 255));//플레이어가 폭탄 발사할때 프레임 이미지
	_playerBomb = false;//플레이어가 폭탄 발사할때 플레이어의 폭탄발사 프레임 이미지의 작동여부
	_playerBombMove->setFrameX(0);
	_playerBombMove->setFrameY(0);
	_count = 0;
	//폭탄

	_bombExplosionImage = IMAGEMANAGER->addFrameImage("bombExplosion", "image/playerBomb.bmp", 3584, 320, 16, 1, true, false, RGB(255, 0, 255));
	_bombExplosionImage->setFrameX(0);
	_bombExplosionImage->setFrameY(0);
	_bobmExplosionCount = 0;
	_bombExplosion = false;
	_bombExplosionRc = RectMake(_player->getPlayerX() - 100, _player->getPlayerY() - 300, _bombExplosionImage->getFrameWidth(), _bombExplosionImage->getFrameHeight());
	//폭탄폭발

	IMAGEMANAGER->addImage("explosion", "image/deathExplosions.bmp", 612, 72, true, false, RGB(255, 0, 255));//적, 플레이어 죽을때 폭발 이미지
	_deathExplosions = new effect;
	_deathExplosions->init(IMAGEMANAGER->findImage("explosion"), 51, 72, 1.0f, 1.0f);
	EFFECTMANAGER->addEffect("explosion", "image/deathExplosions.bmp", 612, 72, 51, 72, 1.0f, 0.5f, 300);
	//적, 플레이어 죽었을때 폭발 이펙트 추가

	IMAGEMANAGER->addImage("bossExplosion", "image/bossExplosions.bmp", 2560, 128, true, false, RGB(255, 0, 255));
	_bossExplosions = new effect;
	_bossExplosions->init(IMAGEMANAGER->findImage("bossExplosion"), 128, 128, 1.0f, 1.0f);
	EFFECTMANAGER->addEffect("bossExplosion", "image/bossExplosions.bmp", 2560, 128, 128, 128, 1.0f, 0.5f, 300);
	//보스가 죽었을때 폭발 이펙트 추가

	IMAGEMANAGER->addImage("playerHit", "image/playerHit.bmp", 200, 20, true, false, RGB(255, 0, 255));
	_playerHit = new effect;
	_playerHit->init(IMAGEMANAGER->findImage("playerHit"), 20, 20, 1.0f, 1.0f);
	EFFECTMANAGER->addEffect("playerHit", "image/playerHit.bmp", 200, 20, 20, 20, 1.0f, 0.5f, 300);
	//플레이어 히트 이펙트 추가

	_alpha = 100;//알파값
	_missionCompleteAlpha = 0;//게임 클리어 이미지에 사용할 알파값
	_missionCompleteAlphaCount = 0;//게임클리어 이미지에 사용할 알파값의 카운트값

	_loopY = 4288 - WINSIZEY;//배경이미지 밑에서부터 재생시키기 위해 초기화

	_rc[0].left = -10;
	_rc[0].right = 0;
	_rc[0].top = 0;
	_rc[0].bottom = WINSIZEY;
	//왼쪽

	_rc[1].left = WINSIZEX;
	_rc[1].right = WINSIZEX + 10;
	_rc[1].top = 0;
	_rc[1].bottom = WINSIZEY;
	//오른쪽

	_rc[2].left = 0;
	_rc[2].right = WINSIZEX;
	_rc[2].top = 90;
	_rc[2].bottom = 100;
	//위

	_rc[3].left = 0;
	_rc[3].right = WINSIZEX;
	_rc[3].top = WINSIZEY;
	_rc[3].bottom = WINSIZEY + 10;
	//아래

	_death = false;//플레이어가 죽었는지 여부 확인
	_juneBossAttack = false;//준보스 공격시작
	_juneBossAppear = false;//준보스 등장
	_bossAppear = false;//보스등장
	_bossAttack = false;//보스공격시작
	_rotation = 1;//보스공격각도
	_oneSoundPlay = false;//사운드를 한번만 재생시키기 위해 사용할 변수

	return S_OK;
}

void mainGameScene::release()
{
}

void mainGameScene::update()
{
	if (!_death)//플레이어가 살아있으면
	{
		if (!_juneBossAppear && _loopY > 0)//배경이미지가 끝날때까지
		{
			_loopY -= 1;//배경이미지 무한재생
		}

		if (_loopY <= 2144)//준보스 등장지점
		{
			_juneBossAppear = true;//준보스 등장
		}
		if(_juneBossAppear && _enemyJuneBoss->getJuneBossY() <= 100)//배경이미지가 일정좌표에 도달하면 준보스 등장
		{
			_enemyJuneBoss->update();//준보스 업데이트
		}
		else if (_enemyJuneBoss->getJuneBossY() >= 100)//준보스의 y좌표가 100에 도달하면
		{
			_juneBossAttack = true;//준보스 공격시작
		}
		if (_enemyJuneBoss->getHP() < 0)//준보스가 죽었으면
		{
			_juneBossAppear = false;//배경이미지 다시재생
		}

		if (_loopY <= 0)//배경이미지가 끝에 도달하면
		{
			_bossAppear = true;//보스등장
		}
		if (_bossAppear)//보스가 등장했으면
		{
			_enemyBoss->fristMove();//보스첫등장 무브 업데이트
		}
		if (_enemyBoss->getBossAppear())//보스가 지정된 위치에 도달했으면
		{
			_bossAttack = true;//보스공격시작
			_enemyBoss->update();//보스 업데이트
		}

		if (!_playerBomb)//플레이어가 폭탄 발사하는 프레임이 끝나기 전까지는 움직이지 못하게 하기위한 조건문
		{
			_player->update();//플레이어 업데이트
		}

		_enemy->update();//적 업데이트

		if (_juneBossAttack)//준보스 공격시작
		{
			_juneBossBulletCount++;
			if (_juneBossBulletCount % 2 == 0)
			{
				for (int i = 0; i < _enemyJuneBoss->getvJuneBoss().size(); i++)
				{
					_enemyJuneBullet->fire(_enemyJuneBoss->getJuneBossX() + 80, _enemyJuneBoss->getJuneBossY() + 50, _enemyJuneBoss->getJuneBossRotation(), 7.0f);//준보스 총알 생성
				}
					_juneBossBulletCount = 0;
			}
		}
		
		if (_bossAttack)//보스의 공격이 트루면
		{
			_bossBulletCount++;
			if (_bossBulletCount % 2 == 0)
			{
				_rotation++;
				for (int i = 0; i < _enemyBoss->getvEnemyBoss().size(); i++)
				{
					_enemyBossBullet->fire((_enemyBoss->getvEnemyBoss()[i].rc.right + _enemyBoss->getvEnemyBoss()[i].rc.left) / 2, (_enemyBoss->getvEnemyBoss()[i].rc.top + _enemyBoss->getvEnemyBoss()[i].rc.bottom) / 2, PI2 / _rotation, 7.0f);
				}
				_bossBulletCount = 0;
			}

			_bossBulletCount2++;
			if (_bossBulletCount2 % 5 == 0)
			{
				for (int i = 0; i < _enemyBoss->getvEnemyBoss().size(); i++)
				{
					if (_enemyBoss->getHP() < 500)//보스의 체력이 절반 미만이면
					{
						_enemyBossBullet2->fire((_enemyBoss->getvEnemyBoss()[i].rc.right + _enemyBoss->getvEnemyBoss()[i].rc.left) / 2, (_enemyBoss->getvEnemyBoss()[i].rc.top + _enemyBoss->getvEnemyBoss()[i].rc.bottom) / 2,
							getAngle(_enemyBoss->getBossX(), _enemyBoss->getBossY(), _player->getPlayerX(), _player->getPlayerY()), 7.0f);//보스 총알 2페이즈 발사
					}
				}
				_bossBulletCount2 = 0;
			}

			if (_rotation >= 5)
			{
				_rotation = 1;
			}
			
		}

		if (_enemyBoss->getHP() < 0)//보스가 죽으면
		{
			for (int i = 0; i < _enemy->getvEnemy().size(); i++)//일반적 제거
			{
				EFFECTMANAGER->play("explosion", _enemy->getvEnemy()[i].x, _enemy->getvEnemy()[i].y);
				_enemy->removeEnemy(i);
				break;
			}
			for (int i = 0; i < _enemy->getvEnemyUfo().size(); i++)//왼쪽에서 오른쪽으로 가는 ufo제거
			{
				EFFECTMANAGER->play("explosion", _enemy->getvEnemyUfo()[i].x, _enemy->getvEnemyUfo()[i].y);
				_enemy->removeEnemyUfo(i);
				break;
			}
			for (int i = 0; i < _enemy->getvEnemyUfo2().size(); i++)//오른쪽에서 왼쪽으로 가는 ufo제거
			{
				EFFECTMANAGER->play("explosion", _enemy->getvEnemyUfo2()[i].x, _enemy->getvEnemyUfo2()[i].y);
				_enemy->removeEnemyUfo2(i);
				break;
			}
			for (int i = 0; i < _enemy->getvEnemyHelicopter().size(); i++)//헬리콥터제거
			{
				EFFECTMANAGER->play("explosion", _enemy->getvEnemyHelicopter()[i].x, _enemy->getvEnemyHelicopter()[i].y);
				_enemy->removeEnemyHelicopter(i);
				break;
			}
			if (!_oneSoundPlay)//사운드를 한번만 재생시키기 위해 필요한 조건문
			{
				_token = "sound/missionComplete!.mp3";
				_vSoundList.push_back(_token);

				SOUNDMANAGER->addSound(_vSoundList[_vSoundList.size() - 1], _vSoundList[_vSoundList.size() - 1], true, false);//음악파일추가
				SOUNDMANAGER->play(_vSoundList[_vSoundList.size() - 1], 1.0f);//음악재생
				_oneSoundPlay = true;
			}

			if (KEYMANAGER->isOnceKeyDown(VK_RETURN))//엔터버튼을 누르면
			{
				SOUNDMANAGER->stop(_vSoundList[_vSoundList.size() - 1]);//게임클리어 사운드 정지
				SCENEMANAGER->changeScene("스타트씬");//게임스타트 화면으로 변경
			}
		}
		
		//일반적 총알발사 시작점
		for (int i = 0; i < _enemy->getvEnemy().size(); i++)
		{
			if (_enemy->getvEnemy()[i].y > 0)//적이 화면안으로 들어왔으면
			{
				if (_enemy->bulletCountfire())//적 총알발사
				{
					_enemyBullet->fire(_enemy->getvEnemy()[i].x, _enemy->getvEnemy()[i].y,
						getAngle(_enemy->getvEnemy()[i].x, _enemy->getvEnemy()[i].y, _player->getPlayerX(), _player->getPlayerY()), 7.0f);//적총알 플레이어 위치로 발사
				}
			}
		}
		//일반적 총알발사 끝점

		//왼쪽에서 오른쪽 ufo적 총알발사 시작점
		for (int i = 0; i < _enemy->getvEnemyUfo().size(); i++)//왼쪽에서 오른쪽 ufo
		{
			if (_enemy->getvEnemyUfo()[i].x > 0 && _enemy->getvEnemyUfo()[i].x < WINSIZEX && _enemy->getvEnemyUfo()[i].y > 0 && _enemy->getvEnemyUfo()[i].y < WINSIZEY)//ufo적이 화면안으로 들어오면
			{
				if (_enemy->bulletCountfire())//적 총알 발사
				{
					_enemyBullet2->fire(_enemy->getvEnemyUfo()[i].x, _enemy->getvEnemyUfo()[i].y,
						getAngle(_enemy->getvEnemyUfo()[i].x, _enemy->getvEnemyUfo()[i].y, _player->getPlayerX(), _player->getPlayerY()),
						7.0f);//ufo 총알 플레이어 좌표로 발사
				}
			}
			
			if (_enemy->getvEnemyUfo()[i].rc.left > WINSIZEX)//ufo이 화면 오른쪽을 넘어가면
			{
				_enemy->removeEnemyUfo(i);//ufo 제거
				break;
			}
			
		}
		//왼쪽에서 오른쪽 ufo적 총알발사 끝점

		//오른쪽에서 왼쪽 ufo적 총알발사 시작점
		for (int i = 0; i < _enemy->getvEnemyUfo2().size(); i++)//오른쪽에서 왼쪽 ufo
		{
			if (_enemy->getvEnemyUfo2()[i].x > 0 && _enemy->getvEnemyUfo2()[i].x < WINSIZEX && _enemy->getvEnemyUfo2()[i].y > 0 && _enemy->getvEnemyUfo2()[i].y < WINSIZEY)//ufo적이 화면안으로 들어오면
			{
				if (_enemy->bulletCountfire())//적 총알 발사
				{
					_enemyBullet2->fire(_enemy->getvEnemyUfo2()[i].x, _enemy->getvEnemyUfo2()[i].y,
						getAngle(_enemy->getvEnemyUfo2()[i].x, _enemy->getvEnemyUfo2()[i].y, _player->getPlayerX(), _player->getPlayerY()),
						7.0f);//ufo 총알 플레이어 좌표로 발사
				}
			}
			
			if (_enemy->getvEnemyUfo2()[i].rc.right < 0)//ufo이 화면 왼쪽을 넘어가면
			{
				_enemy->removeEnemyUfo2(i);//ufo 제거
				break;
			}
			
		}
		//오른쪽에서 왼쪽 ufo적 총알발사 끝점

		//헬리콥터적 총알발사 시작점
		for (int i = 0; i < _enemy->getvEnemyHelicopter().size(); i++)
		{
			if (_enemy->getvEnemyHelicopter()[i].x > 0 && _enemy->getvEnemyHelicopter()[i].x < WINSIZEX && _enemy->getvEnemyHelicopter()[i].y > 0 && _enemy->getvEnemyHelicopter()[i].y < WINSIZEY)//헬리콥터적이 화면안으로 들어오면
			{
				if (_enemy->bulletCountfire())//적총알발사가 참이면
				{
					_enemyBullet3->fire(_enemy->getvEnemyHelicopter()[i].x, _enemy->getvEnemyHelicopter()[i].y, 7.0f);//헬리콥터적 총알 발사
				}
			}
		}
		//헬리콥터적 총알발사 끝점

		//헬리콥터적 총알발사 시작점
		for (int i = 0; i < _enemy->getvEnemyHelicopter2().size(); i++)
		{
			if (_enemy->getvEnemyHelicopter2()[i].x > 0 && _enemy->getvEnemyHelicopter2()[i].x < WINSIZEX && _enemy->getvEnemyHelicopter2()[i].y > 0 && _enemy->getvEnemyHelicopter2()[i].y < WINSIZEY)//헬리콥터적이 화면안으로 들어오면
			{
				if (_enemy->bulletCountfire())//적총알발사가 참이면
				{
					_enemyBullet3->fire(_enemy->getvEnemyHelicopter2()[i].x, _enemy->getvEnemyHelicopter2()[i].y, 7.0f);//헬리콥터적 총알 발사
				}
			}
		}
		//헬리콥터적 총알발사 끝점

		if (_enemyJuneBoss->getHP() < 0)//준보스가 죽었으면
		{
			_enemy->move2();//2페이즈 적 무브
		}
		
		_enemyBullet->update();//일반적총알 업데이트
		_enemyBullet2->update();//ufo적 총알 업데이트
		_enemyBullet3->update();//헬리콥터적 총알 업데이트
		_enemyJuneBullet->update();//준보스 총알 업데이트
		_enemyBossBullet->update();//보스 총알 업데이트
		_enemyBossBullet2->update();//보스 총알 2페이지 업데이트

		if (!_playerBomb)//플레이어가 기본상태일때만 발사가 가능하게 하기위한 조건문
		{
			if (KEYMANAGER->isOnceKeyDown('A'))//스페이스바키 공격
			{
				_token = "sound/playerFire.mp3";
				_vSoundList.push_back(_token);
				SOUNDMANAGER->addSound(_vSoundList[_vSoundList.size() - 1], _vSoundList[_vSoundList.size() - 1], true, false);//음악파일추가
				if (_item->getAttackCount() == 1)//플레이어 총알 기본단계
				{
					SOUNDMANAGER->play(_vSoundList[_vSoundList.size() - 1], 1.0f);//음악재생

					_playerBullet->fire(_player->getPlayerX(), _player->getPlayerY()); //플레이어 총알발사
				}
				if (_item->getAttackCount() == 2)//플레이어 총알 2단계
				{
					SOUNDMANAGER->play(_vSoundList[_vSoundList.size() - 1], 1.0f);//음악재생

					_playerBullet2->fire(_player->getPlayerX() - 15, _player->getPlayerY());//플레이어 총알 2단계 발사
					_playerBullet2->fire(_player->getPlayerX() + 15, _player->getPlayerY());//플레이어 총알 2단계 발사
				}
				if (_item->getAttackCount() == 3)//플레이어 총알 3단계
				{
					SOUNDMANAGER->play(_vSoundList[_vSoundList.size() - 1], 1.0f);//음악재생

					_playerBullet3->fire(_player->getPlayerX() - 30, _player->getPlayerY() + 10);//플레이어 총알 3단계 발사
					_playerBullet3->fire(_player->getPlayerX(), _player->getPlayerY());//플레이어 총알 3단계 발사
					_playerBullet3->fire(_player->getPlayerX() + 30, _player->getPlayerY() + 10);//플레이어 총알 3단계 발사
				}
			}
		}

		//플레이어 총알이 화면상단을 넘어가면 삭제 시작점
		for (int i = 0; i < _playerBullet->getvPlayerBullet().size(); i++)//플레이어 총알
		{
			if (_playerBullet->getvPlayerBullet()[i].y <= 0)
			{
				_playerBullet->removePlayerBullet(i);
				break;
			}
		}
		for (int i = 0; i < _playerBullet2->getvPlayerBullet2().size(); i++)//플레이어 총알 2단계
		{
			if (_playerBullet2->getvPlayerBullet2()[i].y <= 0)
			{
				_playerBullet2->removePlayerBullet2(i);
				break;
			}
		}
		for (int i = 0; i < _playerBullet3->getvPlayerBullet3().size(); i++)//플레이어 총알 3단계
		{
			if (_playerBullet3->getvPlayerBullet3()[i].y <= 0)
			{
				_playerBullet3->removePlayerBullet3(i);
				break;
			}
		}
		//플레이어 총알이 화면상단을 넘어가면 삭제 끝점

		if (!_playerBomb)//플레이어가 기본상태일때만 발사가 가능하게 하기위한 조건문
		{
			if (KEYMANAGER->isOnceKeyDown('S'))//a키 플레이어 폭탄공격
			{
				_bomb->bombFire(_player->getPlayerX(), _player->getPlayerY(), 6.0f);//폭탄공격
				_item->setBobmCountMin(1);//사용한 폭탄 아이템 개수만큼 빼기
				_bomb->setBombMax(_item->getBobmCount());//폭탄개수 빼기

				if (_item->getBobmCount() >= 0)//폭탄이 1개라도 남아있을때만 플레이어가 폭탄을 발사하는 프레임 이미지 재생시키기 위한 조건문
				{
					_playerBomb = true;//플레이어 폭탄 발사하는 프레임
					_bombExplosion = true;//폭탄폭발 프레임 조건여부 확인
					_bombExplosionRc = RectMake(_player->getPlayerX() - 100, _player->getPlayerY() - 300, _bombExplosionImage->getFrameWidth(), _bombExplosionImage->getFrameHeight());
				}
			}
		}

		_playerBullet->update();//플레이어 총알업데이트

		_playerBullet2->update();//플레이어 총알 2단계 업데이트

		_playerBullet3->update();//플레이어 총알 3단계 업데이트

		_bomb->update();//폭탄 업데이트
		
		_progressBar->setX(_player->getPlayerX() - 10);
		_progressBar->setY(_player->getPlayerY() - 15);
		//프로그래스바 게이지 위치 실시간으로 플레이어 위치로 이동

		_progressBar->update();//프로그래스바 업데이트

		_progressBar->setGauge(_player->getCurrentHP(), _player->getMaxHP());//프로그래스바 게이지 변경

		_item->update();//아이템 업데이트

		collision();//충돌감지

		_rndItem = RND->getInt(2);//공격력 강화아이템, 폭탄아이템 둘중 어떤 아이템이 나올지 랜덤으로 정할 변수

		EFFECTMANAGER->update();//적, 플레이어 죽었을때 폭발이펙터 업데이트
	}
	else//플레이어가 죽었으면
	{
		if (KEYMANAGER->isOnceKeyDown(VK_RETURN))//엔터버튼을 누르면
		{
			SCENEMANAGER->changeScene("스타트씬");//게임스타트 화면으로 변경
		}
	}

}

void mainGameScene::render()
{
	_background->loopRender(getMemDC(), &RectMake(0, 0, WINSIZEX, WINSIZEY), 0, _loopY);//배경이미지 무한재생

	if (!_playerBomb)//폭탄발사전 기본 프레임
	{
		_player->render();//플레이어 그리기
	}
	else//폭탄 발사할때의 프레임
	{
		_playerBombMove->frameRender(getMemDC(), _player->getPlayerRC().left - 55, _player->getPlayerRC().top - 50, _playerBombMove->getFrameX(), _playerBombMove->getFrameY());//폭탄발사프레임

		_bobmExplosionCount++;//폭탄폭발 카운트
		if (_bobmExplosionCount > 15 && _bombExplosion)//폭탄폭발할때
		{
			//Rectangle(getMemDC(), _bombExplosionRc);//폭탄 폭발 이미지 렉트범위 확인용
			_bombExplosionImage->frameRender(getMemDC(), _player->getPlayerX() - 100, _player->getPlayerY() - 300, _bombExplosionImage->getFrameX(), _bombExplosionImage->getFrameY());//폭탄폭발 프레임
		}

		_count++;
		if (_count % 5 == 0)
		{
			_playerBombMove->setFrameX(_playerBombMove->getFrameX() + 1);//플레이어가 폭탄 발사하면서 움직이는 프레임
			if (_playerBombMove->getFrameX() >= _playerBombMove->getMaxFrameX())//플레이어의 폭탄발사 프레임 이미지가 끝에 도달한경우
			{
				_playerBombMove->setFrameX(0);//플레이어의 폭탄 발사할때 플레이어의 프레임 이미지 초기화
				_playerBomb = false;//플레이어가 기본상태일때로 되돌리기
			}

			_bombExplosionImage->setFrameX(_bombExplosionImage->getFrameX() + 1);//폭탄폭발 프레임
			if (_bombExplosionImage->getFrameX() >= _bombExplosionImage->getMaxFrameX())//폭탄폭발 프레임이 끝에 도달하면
			{
				_bombExplosionImage->setFrameX(0);//폭탄폭발 프레임 초기화
				_bombExplosion = false;//폭탄폭발 조건 펄스
				_bobmExplosionCount = 0;//폭탄폭발 타이밍 초기화
			}

			_count = 0;
		}
	}
	

	_enemy->render();//적 그리기
	_enemyJuneBoss->render();//준보스 그리기
	_enemyBoss->render();//보스 그리기

	for (int i = 0; i < _enemyBullet->getvEnemyBullet().size(); i++)
	{
		//Rectangle(getMemDC(), _enemyBullet->getvEnemyBullet()[i].rc);//적총알 렉트확인용
	}

	_enemyBullet->render();//일반적 총알 그리기
	_enemyBullet2->render();//ufo적 총알 그리기
	_enemyBullet3->render();//헬리콥터적 총알 그리기
	_enemyJuneBullet->render();//준보스 총알 그리기
	_enemyBossBullet->render();//보스 총알 그리기
	_enemyBossBullet2->render();//보스 총알 2페이지 그리기

	for (int i = 0; i < _playerBullet->getvPlayerBullet().size(); i++)
	{
		//Rectangle(getMemDC(), _playerBullet->getvPlayerBullet()[i].rc);//플레이어 총알 렉트확인용
	}

	_playerBullet->render();//플레이어 총알그리기
	_playerBullet2->render();//플레이어 총알 2단계 그리기
	_playerBullet3->render();//플레이어 총알 3단계 그리기

	_progressBar->render();//프로그래스바 그리기

	_item->render();//아이템 그리기

	_bomb->render();//폭탄 그리기

	if (_death)//플레이어가 죽었으면
	{
		IMAGEMANAGER->findImage("gameOver")->render(getMemDC(), WINSIZEX / 2 - 275, WINSIZEY / 2);//게임오버
		IMAGEMANAGER->findImage("blackScreen")->alphaRender(getMemDC(), 0, 0,_alpha);
	}

	if (_enemyBoss->getHP() < 0)//보스가 죽었으면
	{
		_missionCompleteAlphaCount++;
		if (_missionCompleteAlphaCount % 2 == 0)
		{
			if (_missionCompleteAlpha < 255)
			{
				_missionCompleteAlpha++;
				cout << _missionCompleteAlpha << endl;
			}
			_missionCompleteAlphaCount = 0;
		}
		
	}
	_missionComplete->alphaRender(getMemDC(), 0, 0, _missionCompleteAlpha);//미션클리어 이미지 띄우기

	_deathExplosions->render();//적, 플레이어 폭발 이미지 그리기
	_bossExplosions->render();//보스 죽었을때 폭발 이미지 그리기
	_playerHit->render();//플레이어 히트 이미지 그리기
	EFFECTMANAGER->render();//이펙트매니저 그리기
	TIMEMANAGER->render(getMemDC());
}

void mainGameScene::collision()
{
	RECT temp;

	if (IntersectRect(&temp, &_rc[0], &_player->getPlayerRC()))//왼쪽
	{
		int w = temp.right - temp.left;
		int h = temp.bottom - temp.top;

		_player->setPlayerX(_player->getPlayerX() + w);
	}
	if (IntersectRect(&temp, &_rc[1], &_player->getPlayerRC()))//오른쪽
	{
		int w = temp.right - temp.left;
		int h = temp.bottom - temp.top;

		_player->setPlayerX(_player->getPlayerX() - w);
	}
	if (IntersectRect(&temp, &_rc[2], &_player->getPlayerRC()))//위쪽
	{
		int w = temp.right - temp.left;
		int h = temp.bottom - temp.top;

		_player->setPlayerY(_player->getPlayerY() + h);
	}
	if (IntersectRect(&temp, &_rc[3], &_player->getPlayerRC()))//아래쪽
	{
		int w = temp.right - temp.left;
		int h = temp.bottom - temp.top;

		_player->setPlayerY(_player->getPlayerY() - h);
	}
	//플레이어가 화면밖으로 나가지 못하게

	//플레이어랑 일반적 충돌 시작점!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	for (int i = 0; i < _enemyBullet->getvEnemyBullet().size(); i++)//일반적총알
	{
		if (!_playerBomb)//플레이어가 기본상태일때
		{
			if (IntersectRect(&temp, &_player->getPlayerRC(), &_enemyBullet->getvEnemyBullet()[i].rc))//일반적총알이랑 플레이어랑 충돌처리
			{
				_player->setCurrentHP(5);//플레이어 게이지 줄이기

				_enemyBullet->removeEnemyBullet(i);//적총알제거

				EFFECTMANAGER->play("playerHit", (_player->getPlayerRC().right + _player->getPlayerRC().left) / 2, (_player->getPlayerRC().bottom + _player->getPlayerRC().top) / 2);//적총알이 플레이어에게 충돌했을경우 폭발 이펙트
				if (_player->getCurrentHP() < 0)//플레이어 현재 HP가 0이하가 되면
				{
					_death = true;//플레이어가 죽었다
				}
				break;
			}
		}
	}
	
	for (int i = 0; i < _enemy->getvEnemy().size(); i++)//일반적
	{
		for (int j = 0; j < _playerBullet->getvPlayerBullet().size(); j++)//플레이어 총알
		{
			if (IntersectRect(&temp, &_enemy->getvEnemy()[i].rc, &_playerBullet->getvPlayerBullet()[j].rc))//플레이어 총알이 일반적이랑 충돌시
			{
				EFFECTMANAGER->play("explosion", _enemy->getvEnemy()[i].x, _enemy->getvEnemy()[i].y);//일반적이 플레이어의 총알이랑 부딪혔을경우 폭발 이펙트 그리기
				_playerBullet->removePlayerBullet(j);//플레이어 총알제거
				if (_item->itemCountFire())//아이템이 나올확률이 트루면
				{
					if (_rndItem == 0)//0이면 폭탄
					{
						_item->bombItemFire(_enemy->getvEnemy()[i].x, _enemy->getvEnemy()[i].y);//일반적 위치에 폭탄 아이템 만들기
					}
					else//아니면 공격력 강화아이템
					{
						_item->attackItemFire(_enemy->getvEnemy()[i].x, _enemy->getvEnemy()[i].y);//일반적 위치에 공격력 강화 아이템 만들기
					}
				}
				_enemy->removeEnemy(i);//일반적 제거
				break;
			}
		}
	}

	for (int i = 0; i < _playerBullet2->getvPlayerBullet2().size(); i++)//플레이어 총알 2단계
	{
		for (int j = 0; j < _enemy->getvEnemy().size(); j++)//일반적
		{
			if (IntersectRect(&temp, &_enemy->getvEnemy()[j].rc, &_playerBullet2->getvPlayerBullet2()[i].rc))//일반적이랑 플레이어 총알 2단계랑 충돌시
			{
				EFFECTMANAGER->play("explosion", _enemy->getvEnemy()[j].x, _enemy->getvEnemy()[j].y);//일반적 위치에 폭발 이펙트 발생
				_playerBullet2->removePlayerBullet2(i);//총알벡터 제거

				if (_item->itemCountFire())//아이템이 나올확률이 참이면
				{
					if (_rndItem == 0)//폭탄아이템
					{
						_item->bombItemFire(_enemy->getvEnemy()[j].x, _enemy->getvEnemy()[j].y);//폭탄아이템 일반적 위치에 생성
					}
					if (_rndItem == 1)//공격력 강화 아이템
					{
						_item->attackItemFire(_enemy->getvEnemy()[j].x, _enemy->getvEnemy()[j].y);//공격력 강화 아이템 일반적 위치에 생성
					}
				}

				_enemy->removeEnemy(j);//일반적 벡터 제거
				break;
			}
		}
	}

	for (int i = 0; i < _playerBullet3->getvPlayerBullet3().size(); i++)//플레이어 총알 3단계
	{
		for (int j = 0; j < _enemy->getvEnemy().size(); j++)//일반적
		{
			if (IntersectRect(&temp, &_enemy->getvEnemy()[j].rc, &_playerBullet3->getvPlayerBullet3()[i].rc))//일반적이랑 플레이어 총알 3단계랑 충돌시
			{
				EFFECTMANAGER->play("explosion", _enemy->getvEnemy()[j].x, _enemy->getvEnemy()[j].y);//일반적 위치에 폭발 이펙트 발생
				_playerBullet3->removePlayerBullet3(i);//플레이어 총알 3단계 벡터에서 삭제

				if (_item->itemCountFire())//아이템이 나올 확률이 참이면
				{
					if (_rndItem == 0)//폭탄 아이템
					{
						_item->bombItemFire(_enemy->getvEnemy()[j].x, _enemy->getvEnemy()[j].y);//일반적 위치에 폭탄 아이템 생성
					}
					if (_rndItem == 1)//공격력 강화 아이템
					{
						_item->attackItemFire(_enemy->getvEnemy()[j].x, _enemy->getvEnemy()[j].y);//일반적 위치에 공격력 강화 아이템 생성
					}
				}

				_enemy->removeEnemy(j);//일반적 벡터에서 삭제
				break;
			}
		}
	}
	
	for (int i = 0; i < _enemy->getvEnemy().size(); i++)//일반적
	{
		if (IntersectRect(&temp, &_bombExplosionRc, &_enemy->getvEnemy()[i].rc) && _bombExplosion)//폭탄폭발 렉트에 일반적이 충돌시
		{
			if (_item->itemCountFire())//아이템이 나올 확률이 참이면
			{
				if (_rndItem == 0)//폭탄 아이템
				{
					_item->bombItemFire(_enemy->getvEnemy()[i].x, _enemy->getvEnemy()[i].y);//일반적 위치에 폭탄 아이템 생성
				}
				if (_rndItem == 1)//공격력 강화 아이템
				{
					_item->attackItemFire(_enemy->getvEnemy()[i].x, _enemy->getvEnemy()[i].y);//일반적 위치에 공격력 강화 아이템 생성
				}
			}
			_enemy->removeEnemy(i);//일반적제거
			break;
		}
	}
	//플레이어랑 일반적 충돌 끝점!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	
	//플레이어랑 왼쪽에서 오는 ufo충돌 시작점!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	for (int i = 0; i < _enemyBullet2->getvEnemyBullet2().size(); i++)//ufo적 총알
	{
		if (!_playerBomb)//플레이어가 기본상태일때
		{
			if (IntersectRect(&temp, &_player->getPlayerRC(), &_enemyBullet2->getvEnemyBullet2()[i].rc))//ufo적 총알이 플레이어랑 충돌시
			{
				EFFECTMANAGER->play("playerHit", (_player->getPlayerRC().right + _player->getPlayerRC().left) / 2, (_player->getPlayerRC().bottom + _player->getPlayerRC().top) / 2);//ufo 적총알이 플레이어에게 충돌했을경우 폭발 이펙트

				_player->setCurrentHP(5);//플레이어 게이지 줄이기

				_enemyBullet2->removeEnemyBullet2(i);//ufo 적총알제거
				if (_player->getCurrentHP() < 0)//플레이어 현재 HP가 0이하가 되면
				{
					_death = true;//플레이어가 죽었다
				}
				break;
			}
		}
	}
	
	for (int i = 0; i < _enemy->getvEnemyUfo().size(); i++)//왼쪽에서 오른쪽 ufo적
	{
		for (int j = 0; j < _playerBullet->getvPlayerBullet().size(); j++)//플레이어 총알
		{
			if (IntersectRect(&temp, &_enemy->getvEnemyUfo()[i].rc, &_playerBullet->getvPlayerBullet()[j].rc))//플레이어 총알이 ufo적이랑 충돌시
			{
				EFFECTMANAGER->play("explosion", _enemy->getvEnemyUfo()[i].x, _enemy->getvEnemyUfo()[i].y);//ufo적이 플레이어의 총알이랑 부딪혔을경우 폭발 이펙트 그리기
				_playerBullet->removePlayerBullet(j);//플레이어 총알제거
				if (_item->itemCountFire())//아이템이 나올확률이 트루면
				{
					if (_rndItem == 0)//0이면 폭탄
					{
						_item->bombItemFire(_enemy->getvEnemyUfo()[i].x, _enemy->getvEnemyUfo()[i].y);//ufo적 위치에 폭탄 아이템 만들기
					}
					else//아니면 공격력 강화아이템
					{
						_item->attackItemFire(_enemy->getvEnemyUfo()[i].x, _enemy->getvEnemyUfo()[i].y);//ufo적 위치에 공격력 강화 아이템 만들기
					}
				}
				_enemy->removeEnemyUfo(i);//ufo적 제거
				break;
			}
		}
	}

	for (int i = 0; i < _playerBullet2->getvPlayerBullet2().size(); i++)//플레이어 총알 2단계
	{
		for (int j = 0; j < _enemy->getvEnemyUfo().size(); j++)//ufo적
		{
			if (IntersectRect(&temp, &_enemy->getvEnemyUfo()[j].rc, &_playerBullet2->getvPlayerBullet2()[i].rc))//ufo적이랑 플레이어 총알 2단계랑 충돌시
			{
				EFFECTMANAGER->play("explosion", _enemy->getvEnemyUfo()[j].x, _enemy->getvEnemyUfo()[j].y);//ufo적 위치에 폭발 이펙트 발생
				_playerBullet2->removePlayerBullet2(i);//플레이어 총알 2단계 삭제
				if (_item->itemCountFire())//아이템이 나올확률이 참이면
				{
					if (_rndItem == 0)//폭탄 아이템
					{
						_item->bombItemFire(_enemy->getvEnemyUfo()[j].x, _enemy->getvEnemyUfo()[j].y);//ufo적 위치에 폭탄 아이템 생성
					}
					if (_rndItem == 1)//공격력 강화 아이템
					{
						_item->attackItemFire(_enemy->getvEnemyUfo()[j].x, _enemy->getvEnemyUfo()[j].y);//ufo적 위치에 공격력 강화 아이템 생성
					}
				}
				_enemy->removeEnemyUfo(j);//ufo적 삭제
				break;
			}
		}
	}

	for (int i = 0; i < _playerBullet3->getvPlayerBullet3().size(); i++)//플레이어 총알 3단계
	{
		for (int j = 0; j < _enemy->getvEnemyUfo().size(); j++)//ufo적
		{
			if (IntersectRect(&temp, &_enemy->getvEnemyUfo()[j].rc, &_playerBullet3->getvPlayerBullet3()[i].rc))//ufo적이랑 플레이어 총알 3단계랑 충돌시
			{
				EFFECTMANAGER->play("explosion", _enemy->getvEnemyUfo()[j].x, _enemy->getvEnemyUfo()[j].y);//ufo적 위치에 폭발 이펙트 발생
				_playerBullet3->removePlayerBullet3(i);//플레이어 총알 3단계 벡터에서 삭제

				if (_item->itemCountFire())//아이템이 나올 확률이 참이면
				{
					if (_rndItem == 0)//폭탄 아이템
					{
						_item->bombItemFire(_enemy->getvEnemyUfo()[j].x, _enemy->getvEnemyUfo()[j].y);//ufo적 위치에 폭탄 아이템 생성
					}
					if (_rndItem == 1)//공격력 강화 아이템
					{
						_item->attackItemFire(_enemy->getvEnemyUfo()[j].x, _enemy->getvEnemyUfo()[j].y);//ufo적 위치에 공격력 강화 아이템 생성
					}
				}

				_enemy->removeEnemyUfo(j);//ufo적 벡터에서 삭제
				break;
			}
		}
	}
	
	for (int i = 0; i < _enemy->getvEnemyUfo().size(); i++)//왼쪽에서 오른쪽 ufo적
	{
		if (IntersectRect(&temp, &_bombExplosionRc, &_enemy->getvEnemyUfo()[i].rc) && _bombExplosion)//폭탄폭발 렉트에 ufo적이 충돌시
		{
			if (_item->itemCountFire())//아이템이 나올 확률이 참이면
			{
				if (_rndItem == 0)//폭탄 아이템
				{
					_item->bombItemFire(_enemy->getvEnemyUfo()[i].x, _enemy->getvEnemyUfo()[i].y);//ufo적 위치에 폭탄 아이템 생성
				}
				if (_rndItem == 1)//공격력 강화 아이템
				{
					_item->attackItemFire(_enemy->getvEnemyUfo()[i].x, _enemy->getvEnemyUfo()[i].y);//ufo적 위치에 공격력 강화 아이템 생성
				}
			}
			_enemy->removeEnemyUfo(i);//ufo제거
			break;
		}
	}
	//플레이어랑 왼쪽에서 오는 ufo충돌 끝점!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	
	//플레이어랑 오른쪽에서 오는 ufo충돌 시작점!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	for (int i = 0; i < _enemyBullet3->getvEnemyBullet3().size(); i++)//오른쪽에서 왼쪽 ufo적
	{
		if (!_playerBomb)//플레이어가 기본상태일때
		{
			if (IntersectRect(&temp, &_player->getPlayerRC(), &_enemyBullet3->getvEnemyBullet3()[i].rc))//플레이어에 ufo적 총알이 충돌시
			{
				EFFECTMANAGER->play("playerHit", (_player->getPlayerRC().right + _player->getPlayerRC().left) / 2, (_player->getPlayerRC().bottom + _player->getPlayerRC().top) / 2);//플레이어 좌표에 이펙트 발생
				_player->setCurrentHP(5);//플레이어 게이지 줄이기
				_enemyBullet3->removeEnemyBullet3(i);//ufo적 총알제거
				if (_player->getCurrentHP() < 0)//플레이어 게이지가 0미만이 되면
				{
					_death = true;//플레이어가 죽었다
				}
				break;
			}
		}
	}

	for (int i = 0; i < _enemy->getvEnemyUfo2().size(); i++)//오른쪽에서 왼쪽 ufo적
	{
		for (int j = 0; j < _playerBullet->getvPlayerBullet().size(); j++)//플레이어 총알
		{
			if (IntersectRect(&temp, &_enemy->getvEnemyUfo2()[i].rc, &_playerBullet->getvPlayerBullet()[j].rc))//플레이어 총알이 ufo적이랑 충돌시
			{
				EFFECTMANAGER->play("explosion", _enemy->getvEnemyUfo2()[i].x, _enemy->getvEnemyUfo2()[i].y);//ufo적이 플레이어의 총알이랑 부딪혔을경우 폭발 이펙트 그리기
				_playerBullet->removePlayerBullet(j);//플레이어 총알제거
				if (_item->itemCountFire())//아이템이 나올확률이 트루면
				{
					if (_rndItem == 0)//0이면 폭탄
					{
						_item->bombItemFire(_enemy->getvEnemyUfo2()[i].x, _enemy->getvEnemyUfo2()[i].y);//ufo적 위치에 폭탄 아이템 만들기
					}
					else//아니면 공격력 강화아이템
					{
						_item->attackItemFire(_enemy->getvEnemyUfo2()[i].x, _enemy->getvEnemyUfo2()[i].y);//ufo적 위치에 공격력 강화 아이템 만들기
					}
				}
				_enemy->removeEnemyUfo2(i);//ufo적 제거
				break;
			}
		}
	}

	for (int i = 0; i < _playerBullet2->getvPlayerBullet2().size(); i++)//플레이어 총알 2단계
	{
		for (int j = 0; j < _enemy->getvEnemyUfo2().size(); j++)//ufo적
		{
			if (IntersectRect(&temp, &_enemy->getvEnemyUfo2()[j].rc, &_playerBullet2->getvPlayerBullet2()[i].rc))//ufo적이랑 플레이어 총알 2단계랑 충돌시
			{
				EFFECTMANAGER->play("explosion", _enemy->getvEnemyUfo2()[j].x, _enemy->getvEnemyUfo2()[j].y);//ufo적 위치에 폭발 이펙트 발생
				_playerBullet2->removePlayerBullet2(i);//플레이어 총알 2단계 삭제
				if (_item->itemCountFire())//아이템이 나올확률이 참이면
				{
					if (_rndItem == 0)//폭탄 아이템
					{
						_item->bombItemFire(_enemy->getvEnemyUfo2()[j].x, _enemy->getvEnemyUfo2()[j].y);//ufo적 위치에 폭탄 아이템 생성
					}
					if (_rndItem == 1)//공격력 강화 아이템
					{
						_item->attackItemFire(_enemy->getvEnemyUfo2()[j].x, _enemy->getvEnemyUfo2()[j].y);//ufo적 위치에 공격력 강화 아이템 생성
					}
				}
				_enemy->removeEnemyUfo2(j);//ufo적 삭제
				break;
			}
		}
	}

	for (int i = 0; i < _playerBullet3->getvPlayerBullet3().size(); i++)//플레이어 총알 3단계
	{
		for (int j = 0; j < _enemy->getvEnemyUfo2().size(); j++)//ufo적
		{
			if (IntersectRect(&temp, &_enemy->getvEnemyUfo2()[j].rc, &_playerBullet3->getvPlayerBullet3()[i].rc))//ufo적이랑 플레이어 총알 3단계랑 충돌시
			{
				EFFECTMANAGER->play("explosion", _enemy->getvEnemyUfo2()[j].x, _enemy->getvEnemyUfo2()[j].y);//ufo적 위치에 폭발 이펙트 발생
				_playerBullet3->removePlayerBullet3(i);//플레이어 총알 3단계 벡터에서 삭제

				if (_item->itemCountFire())//아이템이 나올 확률이 참이면
				{
					if (_rndItem == 0)//폭탄 아이템
					{
						_item->bombItemFire(_enemy->getvEnemyUfo2()[j].x, _enemy->getvEnemyUfo2()[j].y);//ufo적 위치에 폭탄 아이템 생성
					}
					if (_rndItem == 1)//공격력 강화 아이템
					{
						_item->attackItemFire(_enemy->getvEnemyUfo2()[j].x, _enemy->getvEnemyUfo2()[j].y);//ufo적 위치에 공격력 강화 아이템 생성
					}
				}

				_enemy->removeEnemyUfo2(j);//ufo적 벡터에서 삭제
				break;
			}
		}
	}

	for (int i = 0; i < _enemy->getvEnemyUfo2().size(); i++)//오른쪽에서 왼쪽 ufo적
	{
		if (IntersectRect(&temp, &_bombExplosionRc, &_enemy->getvEnemyUfo2()[i].rc) && _bombExplosion)//폭탄폭발 렉트에 ufo적이 충돌시
		{
			if (_item->itemCountFire())//아이템이 나올확률이 트루면
			{
				if (_rndItem == 0)//0이면 폭탄
				{
					_item->bombItemFire(_enemy->getvEnemyUfo2()[i].x, _enemy->getvEnemyUfo2()[i].y);//ufo적 위치에 폭탄 아이템 만들기
				}
				else//아니면 공격력 강화아이템
				{
					_item->attackItemFire(_enemy->getvEnemyUfo2()[i].x, _enemy->getvEnemyUfo2()[i].y);//ufo적 위치에 공격력 강화 아이템 만들기
				}
			}
			_enemy->removeEnemyUfo2(i);//ufo제거
			break;
		}
	}
	//플레이어랑 오른쪽에서 오는 ufo충돌 끝점!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	//플레이어랑 헬리콥터적 충돌 시작점!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	for (int i = 0; i < _playerBullet->getvPlayerBullet().size(); i++)//플레이어 총알
	{
		for (int j = 0; j < _enemy->getvEnemyHelicopter().size(); j++)//헬리콥터적
		{
			if (IntersectRect(&temp, &_enemy->getvEnemyHelicopter()[j].rc, &_playerBullet->getvPlayerBullet()[i].rc))//헬리콥터적에 플레이어총알이 충돌시
			{
				EFFECTMANAGER->play("explosion", _enemy->getvEnemyHelicopter()[j].x, _enemy->getvEnemyHelicopter()[j].y);//헬리콥터적 위치에 폭발 이펙트 발생
				_playerBullet->removePlayerBullet(i);//플레이어 총알벡터 삭제

				if (_item->itemCountFire())//아이템이 나올확률이 참이면
				{
					if (_rndItem == 0)//폭탄아이템
					{
						_item->bombItemFire(_enemy->getvEnemyHelicopter()[j].x, _enemy->getvEnemyHelicopter()[j].y);//폭탄아이템 생성
					}
					if (_rndItem == 1)//공격력 강화 아이템
					{
						_item->attackItemFire(_enemy->getvEnemyHelicopter()[j].x, _enemy->getvEnemyHelicopter()[j].y);//공격력 강화 아이템 생성
					}
				}
				_enemy->removeEnemyHelicopter(j);//헬리콥터적제거
				break;
			}
		}
	}
	
	for (int i = 0; i < _playerBullet2->getvPlayerBullet2().size(); i++)//플레이어 총알 2단계
	{
		for (int j = 0; j < _enemy->getvEnemyHelicopter().size(); j++)//헬리콥터적
		{
			if (IntersectRect(&temp, &_enemy->getvEnemyHelicopter()[j].rc, &_playerBullet2->getvPlayerBullet2()[i].rc))//헬리콥터적에 플레이어총알이 충돌시
			{
				EFFECTMANAGER->play("explosion", _enemy->getvEnemyHelicopter()[j].x, _enemy->getvEnemyHelicopter()[j].y);//헬리콥터적적 위치에 폭발 이펙트 발생
				_playerBullet2->removePlayerBullet2(i);//플레이어 총알벡터 삭제

				if (_item->itemCountFire())//아이템이 나올확률이 참이면
				{
					if (_rndItem == 0)//폭탄아이템
					{
						_item->bombItemFire(_enemy->getvEnemyHelicopter()[j].x, _enemy->getvEnemyHelicopter()[j].y);//폭탄아이템 생성
					}
					if (_rndItem == 1)//공격력 강화 아이템
					{
						_item->attackItemFire(_enemy->getvEnemyHelicopter()[j].x, _enemy->getvEnemyHelicopter()[j].y);//공격력 강화 아이템 생성
					}
				}
				_enemy->removeEnemyHelicopter(j);//헬리콥터적제거
				break;
			}
		}
	}

	for (int i = 0; i < _playerBullet3->getvPlayerBullet3().size(); i++)//플레이어 총알 3단계
	{
		for (int j = 0; j < _enemy->getvEnemyHelicopter().size(); j++)//헬리콥터적
		{
			if (IntersectRect(&temp, &_enemy->getvEnemyHelicopter()[j].rc, &_playerBullet3->getvPlayerBullet3()[i].rc))//헬리콥터적에 플레이어총알이 충돌시
			{
				EFFECTMANAGER->play("explosion", _enemy->getvEnemyHelicopter()[j].x, _enemy->getvEnemyHelicopter()[j].y);//헬리콥터적 위치에 폭발 이펙트 발생
				_playerBullet3->removePlayerBullet3(i);//플레이어 총알벡터 삭제

				if (_item->itemCountFire())//아이템이 나올확률이 참이면
				{
					if (_rndItem == 0)//폭탄아이템
					{
						_item->bombItemFire(_enemy->getvEnemyHelicopter()[j].x, _enemy->getvEnemyHelicopter()[j].y);//폭탄아이템 생성
					}
					if (_rndItem == 1)//공격력 강화 아이템
					{
						_item->attackItemFire(_enemy->getvEnemyHelicopter()[j].x, _enemy->getvEnemyHelicopter()[j].y);//공격력 강화 아이템 생성
					}
				}
				_enemy->removeEnemyHelicopter(j);//헬리콥터적제거
				break;
			}
		}
	}

	for (int i = 0; i < _enemyBullet3->getvEnemyBullet3().size(); i++)//헬리콥터적 총알
	{
		if (!_playerBomb)//플레이어가 폭탄발사를 하고있지 않은경우
		{
			if (IntersectRect(&temp, &_player->getPlayerRC(), &_enemyBullet3->getvEnemyBullet3()[i].rc))//플레이어에 헬리콥터적 총알이 충돌시
			{
				EFFECTMANAGER->play("playerHit", (_player->getPlayerRC().right + _player->getPlayerRC().left) / 2, (_player->getPlayerRC().bottom + _player->getPlayerRC().top) / 2);//플레이어 위치에 이펙트 발생

				_player->setCurrentHP(5);//플레이어 데미지 주기

				if (_player->getCurrentHP() < 0)//플레이어 체력이 0미만이 되면
				{
					_death = true;//플레이어가 죽었다
				}
				_enemyBullet3->removeEnemyBullet3(i);//헬리콥터적 총알삭제
				break;
			}
		}
	}

	for (int i = 0; i < _enemy->getvEnemyHelicopter().size(); i++)//헬리콥터적
	{
		if (IntersectRect(&temp, &_bombExplosionRc, &_enemy->getvEnemyHelicopter()[i].rc) && _bombExplosion)//폭탄폭발 렉트에 양옆으로 헬리콥터적이 충돌시
		{
			if (_item->itemCountFire())//아이템이 나올확률이 참이면
			{
				if (_rndItem == 0)//폭탄아이템
				{
					_item->bombItemFire(_enemy->getvEnemyHelicopter()[i].x, _enemy->getvEnemyHelicopter()[i].y);//폭탄아이템 생성
				}
				if (_rndItem == 1)//공격력 강화 아이템
				{
					_item->attackItemFire(_enemy->getvEnemyHelicopter()[i].x, _enemy->getvEnemyHelicopter()[i].y);//공격력 강화 아이템 생성
				}
			}
			_enemy->removeEnemyHelicopter(i);//헬리콥터적제거
			break;
		}
	}
	//플레이어랑 헬리콥터적 충돌 끝점!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	//2페이즈 플레이어랑 헬리콥터적 충돌 시작점!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	for (int i = 0; i < _playerBullet->getvPlayerBullet().size(); i++)//플레이어 총알
	{
		for (int j = 0; j < _enemy->getvEnemyHelicopter2().size(); j++)//헬리콥터적
		{
			if (IntersectRect(&temp, &_enemy->getvEnemyHelicopter2()[j].rc, &_playerBullet->getvPlayerBullet()[i].rc))//헬리콥터적에 플레이어총알이 충돌시
			{
				EFFECTMANAGER->play("explosion", _enemy->getvEnemyHelicopter2()[j].x, _enemy->getvEnemyHelicopter2()[j].y);//헬리콥터적 위치에 폭발 이펙트 발생
				_playerBullet->removePlayerBullet(i);//플레이어 총알벡터 삭제

				if (_item->itemCountFire())//아이템이 나올확률이 참이면
				{
					if (_rndItem == 0)//폭탄아이템
					{
						_item->bombItemFire(_enemy->getvEnemyHelicopter2()[j].x, _enemy->getvEnemyHelicopter2()[j].y);//폭탄아이템 생성
					}
					if (_rndItem == 1)//공격력 강화 아이템
					{
						_item->attackItemFire(_enemy->getvEnemyHelicopter2()[j].x, _enemy->getvEnemyHelicopter2()[j].y);//공격력 강화 아이템 생성
					}
				}
				_enemy->removeEnemyHelicopter2(j);//헬리콥터적제거
				break;
			}
		}
	}

	for (int i = 0; i < _playerBullet2->getvPlayerBullet2().size(); i++)//플레이어 총알 2단계
	{
		for (int j = 0; j < _enemy->getvEnemyHelicopter2().size(); j++)//헬리콥터적
		{
			if (IntersectRect(&temp, &_enemy->getvEnemyHelicopter2()[j].rc, &_playerBullet2->getvPlayerBullet2()[i].rc))//헬리콥터적에 플레이어총알이 충돌시
			{
				EFFECTMANAGER->play("explosion", _enemy->getvEnemyHelicopter2()[j].x, _enemy->getvEnemyHelicopter2()[j].y);//헬리콥터적적 위치에 폭발 이펙트 발생
				_playerBullet2->removePlayerBullet2(i);//플레이어 총알벡터 삭제

				if (_item->itemCountFire())//아이템이 나올확률이 참이면
				{
					if (_rndItem == 0)//폭탄아이템
					{
						_item->bombItemFire(_enemy->getvEnemyHelicopter2()[j].x, _enemy->getvEnemyHelicopter2()[j].y);//폭탄아이템 생성
					}
					if (_rndItem == 1)//공격력 강화 아이템
					{
						_item->attackItemFire(_enemy->getvEnemyHelicopter2()[j].x, _enemy->getvEnemyHelicopter2()[j].y);//공격력 강화 아이템 생성
					}
				}
				_enemy->removeEnemyHelicopter2(j);//헬리콥터적제거
				break;
			}
		}
	}

	for (int i = 0; i < _playerBullet3->getvPlayerBullet3().size(); i++)//플레이어 총알 3단계
	{
		for (int j = 0; j < _enemy->getvEnemyHelicopter2().size(); j++)//헬리콥터적
		{
			if (IntersectRect(&temp, &_enemy->getvEnemyHelicopter2()[j].rc, &_playerBullet3->getvPlayerBullet3()[i].rc))//헬리콥터적에 플레이어총알이 충돌시
			{
				EFFECTMANAGER->play("explosion", _enemy->getvEnemyHelicopter2()[j].x, _enemy->getvEnemyHelicopter2()[j].y);//헬리콥터적 위치에 폭발 이펙트 발생
				_playerBullet3->removePlayerBullet3(i);//플레이어 총알벡터 삭제

				if (_item->itemCountFire())//아이템이 나올확률이 참이면
				{
					if (_rndItem == 0)//폭탄아이템
					{
						_item->bombItemFire(_enemy->getvEnemyHelicopter2()[j].x, _enemy->getvEnemyHelicopter2()[j].y);//폭탄아이템 생성
					}
					if (_rndItem == 1)//공격력 강화 아이템
					{
						_item->attackItemFire(_enemy->getvEnemyHelicopter2()[j].x, _enemy->getvEnemyHelicopter2()[j].y);//공격력 강화 아이템 생성
					}
				}
				_enemy->removeEnemyHelicopter2(j);//헬리콥터적제거
				break;
			}
		}
	}

	for (int i = 0; i < _enemy->getvEnemyHelicopter2().size(); i++)//헬리콥터적
	{
		if (IntersectRect(&temp, &_bombExplosionRc, &_enemy->getvEnemyHelicopter2()[i].rc) && _bombExplosion)//폭탄폭발 렉트에 양옆으로 헬리콥터적이 충돌시
		{
			if (_item->itemCountFire())//아이템이 나올확률이 참이면
			{
				if (_rndItem == 0)//폭탄아이템
				{
					_item->bombItemFire(_enemy->getvEnemyHelicopter2()[i].x, _enemy->getvEnemyHelicopter2()[i].y);//폭탄아이템 생성
				}
				if (_rndItem == 1)//공격력 강화 아이템
				{
					_item->attackItemFire(_enemy->getvEnemyHelicopter2()[i].x, _enemy->getvEnemyHelicopter2()[i].y);//공격력 강화 아이템 생성
				}
			}
			_enemy->removeEnemyHelicopter2(i);//헬리콥터적제거
			break;
		}
	}
	//2페이즈 플레이어랑 헬리콥터적 충돌 끝점!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	//플레이어랑 준보스충돌 시작점!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	for (int i = 0; i < _enemyJuneBullet->getvEnemyJuneBullet().size(); i++)//준보스 총알
	{
		if (!_playerBomb)//플레이어가 기본상태일때
		{
			if (IntersectRect(&temp, &_player->getPlayerRC(), &_enemyJuneBullet->getvEnemyJuneBullet()[i].rc))//플레이어에 준보스 총알이 충돌시
			{
				_player->setCurrentHP(5);//플레이어 게이지 줄이기

				_enemyJuneBullet->removeEnemyJuneBullet(i);//준보스 총알 제거

				EFFECTMANAGER->play("playerHit", _player->getPlayerX(), _player->getPlayerY());//플레이어 위치에 폭발 이펙트발생

				if (_player->getCurrentHP() < 0)//플레이어 현재 HP가 0미만이 되면
				{
					_death = true;//플레이어가 죽었다
				}
				break;
			}
		}
	}

	for (int i = 0; i < _playerBullet->getvPlayerBullet().size(); i++)//플레이어 총알
	{
		for (int j = 0; j < _enemyJuneBoss->getvJuneBoss().size(); j++)//준보스적
		{
			if (_juneBossAttack)
			{
				if (IntersectRect(&temp, &_enemyJuneBoss->getvJuneBoss()[j].rc, &_playerBullet->getvPlayerBullet()[i].rc))//준보스적에 플레이어총알이 충돌시
				{
					_enemyJuneBoss->setHP(5);//준보스 체력 줄이기

					if (_enemyJuneBoss->getHP() < 0)//준보스 체력이 0미만이 되면
					{
						EFFECTMANAGER->play("bossExplosion", _enemyJuneBoss->getJuneBossX() + 80, _enemyJuneBoss->getJuneBossY() + 50);//준보스적 위치에 폭발 이펙트 발생
						
						_item->hpItemFire(_enemyJuneBoss->getJuneBossX() + 80, _enemyJuneBoss->getJuneBossY() + 50);//hp아이템 생성

						_enemyJuneBoss->removeJuneBoss(j);//준보스적
					}
					_playerBullet->removePlayerBullet(i);//플레이어 총알벡터 삭제
					break;
				}
			}
		}
	}

	for (int i = 0; i < _playerBullet2->getvPlayerBullet2().size(); i++)//플레이어 총알 2단계
	{
		for (int j = 0; j < _enemyJuneBoss->getvJuneBoss().size(); j++)//준보스적
		{
			if (_juneBossAttack)
			{
				if (IntersectRect(&temp, &_enemyJuneBoss->getvJuneBoss()[j].rc, &_playerBullet2->getvPlayerBullet2()[i].rc))//준보스적에 플레이어총알이 충돌시
				{
					_enemyJuneBoss->setHP(5);//준보스 체력 줄이기
					if (_enemyJuneBoss->getHP() < 0)//준보스 체력이 0미만이 되면
					{
						EFFECTMANAGER->play("bossExplosion", _enemyJuneBoss->getJuneBossX() + 80, _enemyJuneBoss->getJuneBossY() + 50);//준보스적 위치에 폭발 이펙트 발생

						_item->hpItemFire(_enemyJuneBoss->getJuneBossX() + 80, _enemyJuneBoss->getJuneBossY() + 50);//hp아이템 생성
						_enemyJuneBoss->removeJuneBoss(j);//준보스적제거
					}
					_playerBullet2->removePlayerBullet2(i);//플레이어 총알벡터 삭제
					break;
				}
			}
		}
	}

	for (int i = 0; i < _playerBullet3->getvPlayerBullet3().size(); i++)//플레이어 총알 3단계
	{
		for (int j = 0; j < _enemyJuneBoss->getvJuneBoss().size(); j++)//준보스적
		{
			if (_juneBossAttack)
			{
				if (IntersectRect(&temp, &_enemyJuneBoss->getvJuneBoss()[j].rc, &_playerBullet3->getvPlayerBullet3()[i].rc))//준보스적에 플레이어총알이 충돌시
				{
					_enemyJuneBoss->setHP(5);//준보스 체력 줄이기
					if (_enemyJuneBoss->getHP() < 0)//준보스 체력이 0미만이 되면
					{
						EFFECTMANAGER->play("bossExplosion", _enemyJuneBoss->getJuneBossX() + 80, _enemyJuneBoss->getJuneBossY() + 50);//준보스적 위치에 폭발 이펙트 발생
						
						_item->hpItemFire(_enemyJuneBoss->getJuneBossX() + 80, _enemyJuneBoss->getJuneBossY() + 50);//hp아이템 생성
						_enemyJuneBoss->removeJuneBoss(j);//준보스적제거
					}
					_playerBullet3->removePlayerBullet3(i);//플레이어 총알벡터 삭제
					break;
				}
			}
		}
	}

	for (int i = 0; i < _enemyJuneBoss->getvJuneBoss().size(); i++)//준보스적
	{
		if (_juneBossAttack)
		{
			if (IntersectRect(&temp, &_enemyJuneBoss->getvJuneBoss()[i].rc, &_bombExplosionRc))//준보스랑 폭탄폭발이랑 충돌시
			{
				if (_bombExplosionImage->getFrameX() <= 0)//폭탄폭발 프레임이 0프레임일때만 데미지를 주기위한 조건
				{
					_enemyJuneBoss->setHP(5);//준보스 체력 줄이기
				}

				//cout << _enemyJuneBoss->getHP() << endl;

				if (_enemyJuneBoss->getHP() < 0)//준보스 체력이 0미만이 되면
				{
					EFFECTMANAGER->play("bossExplosion", _enemyJuneBoss->getJuneBossX() + 80, _enemyJuneBoss->getJuneBossY() + 50);//준보스좌표에 폭발 이펙트 발생
					_item->hpItemFire(_enemyJuneBoss->getJuneBossX() + 80, _enemyJuneBoss->getJuneBossY() + 50);//hp아이템 생성
					_enemyJuneBoss->removeJuneBoss(i);//준보스적제거
				}
				break;
			}
		}
	}
	//플레이어랑 준보스충돌 끝점!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	//플레이어랑 보스충돌 시작점!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	for (int i = 0; i < _enemyBossBullet->getvEnemyBossBullet().size(); i++)//보스 총알
	{
		if (!_playerBomb)//플레이어가 기본상태일때
		{
			if (IntersectRect(&temp, &_player->getPlayerRC(), &_enemyBossBullet->getvEnemyBossBullet()[i].rc))//플레이어에 보스 총알이 충돌시
			{
				_player->setCurrentHP(5);//플레이어 게이지 줄이기

				_enemyBossBullet->removeEnemyBossBullet(i);//보스 총알 제거

				EFFECTMANAGER->play("playerHit", _player->getPlayerX(), _player->getPlayerY());//플레이어 위치에 폭발 이펙트발생

				if (_player->getCurrentHP() < 0)//플레이어 현재 HP가 0미만이 되면
				{
					_death = true;//플레이어가 죽었다
				}
				break;
			}
		}
	}

	for (int i = 0; i < _enemyBossBullet2->getvEnemyBossBullet2().size(); i++)//보스 총알 2페이즈
	{
		if (!_playerBomb)//플레이어가 기본상태일때
		{
			if (IntersectRect(&temp, &_player->getPlayerRC(), &_enemyBossBullet2->getvEnemyBossBullet2()[i].rc))//플레이어에 보스 총알이 충돌시
			{
				_player->setCurrentHP(5);//플레이어 게이지 줄이기

				_enemyBossBullet2->removeEnemyBossBullet2(i);//보스 총알 제거

				EFFECTMANAGER->play("playerHit", _player->getPlayerX(), _player->getPlayerY());//플레이어 위치에 폭발 이펙트발생

				if (_player->getCurrentHP() < 0)//플레이어 현재 HP가 0미만이 되면
				{
					_death = true;//플레이어가 죽었다
				}
				break;
			}
		}
	}

	for (int i = 0; i < _playerBullet->getvPlayerBullet().size(); i++)//플레이어 총알
	{
		for (int j = 0; j < _enemyBoss->getvEnemyBoss().size(); j++)//보스적
		{
			if (_bossAttack)
			{
				if (IntersectRect(&temp, &_enemyBoss->getvEnemyBoss()[j].rc, &_playerBullet->getvPlayerBullet()[i].rc))//보스적에 플레이어총알이 충돌시
				{
					_enemyBoss->setHP(5);//보스 체력 줄이기

					if (_enemyBoss->getHP() < 0)//보스 체력이 0미만이 되면
					{
						EFFECTMANAGER->play("bossExplosion", (_enemyBoss->getvEnemyBoss()[j].rc.right + _enemyBoss->getvEnemyBoss()[j].rc.left) / 2, (_enemyBoss->getvEnemyBoss()[j].rc.top + _enemyBoss->getvEnemyBoss()[j].rc.bottom) / 2);//보스적 위치에 폭발 이펙트 발생

						_enemyBoss->removeBoss(j);//보스적
					}
					_playerBullet->removePlayerBullet(i);//플레이어 총알벡터 삭제
					break;
				}
			}
		}
	}

	for (int i = 0; i < _playerBullet2->getvPlayerBullet2().size(); i++)//플레이어 총알 2단계
	{
		for (int j = 0; j < _enemyBoss->getvEnemyBoss().size(); j++)//보스적
		{
			if (_bossAttack)
			{
				if (IntersectRect(&temp, &_enemyBoss->getvEnemyBoss()[j].rc, &_playerBullet2->getvPlayerBullet2()[i].rc))//보스적에 플레이어총알이 충돌시
				{
					_enemyBoss->setHP(5);//보스 체력 줄이기

					if (_enemyBoss->getHP() < 0)//보스 체력이 0미만이 되면
					{
						EFFECTMANAGER->play("bossExplosion", (_enemyBoss->getvEnemyBoss()[j].rc.right + _enemyBoss->getvEnemyBoss()[j].rc.left) / 2, (_enemyBoss->getvEnemyBoss()[j].rc.top + _enemyBoss->getvEnemyBoss()[j].rc.bottom) / 2);//보스적 위치에 폭발 이펙트 발생

						_enemyBoss->removeBoss(j);//보스적
					}
					_playerBullet2->removePlayerBullet2(i);//플레이어 총알벡터 삭제
					break;
				}
			}
		}
	}

	for (int i = 0; i < _playerBullet3->getvPlayerBullet3().size(); i++)//플레이어 총알 3단계
	{
		for (int j = 0; j < _enemyBoss->getvEnemyBoss().size(); j++)//보스적
		{
			if (_bossAttack)
			{
				if (IntersectRect(&temp, &_enemyBoss->getvEnemyBoss()[j].rc, &_playerBullet3->getvPlayerBullet3()[i].rc))//보스적에 플레이어총알이 충돌시
				{
					_enemyBoss->setHP(5);//보스 체력 줄이기

					if (_enemyBoss->getHP() < 0)//보스 체력이 0미만이 되면
					{
						EFFECTMANAGER->play("bossExplosion", (_enemyBoss->getvEnemyBoss()[j].rc.right + _enemyBoss->getvEnemyBoss()[j].rc.left) / 2, (_enemyBoss->getvEnemyBoss()[j].rc.top + _enemyBoss->getvEnemyBoss()[j].rc.bottom) / 2);//보스적 위치에 폭발 이펙트 발생

						_enemyBoss->removeBoss(j);//보스적
					}
					_playerBullet3->removePlayerBullet3(i);//플레이어 총알벡터 삭제
					break;
				}
			}
		}
	}

	for (int i = 0; i < _enemyBoss->getvEnemyBoss().size(); i++)//보스적
	{
		if (_bossAttack)
		{
			if (IntersectRect(&temp, &_enemyBoss->getvEnemyBoss()[i].rc, &_bombExplosionRc))//보스랑 폭탄폭발이랑 충돌시
			{
				if (_bombExplosionImage->getFrameX() <= 0)//폭탄폭발 프레임이 0프레임일때만 데미지를 주기위한 조건
				{
					_enemyBoss->setHP(5);//보스 체력 줄이기
				}

				if (_enemyBoss->getHP() < 0)//보스 체력이 0미만이 되면
				{
					EFFECTMANAGER->play("bossExplosion", (_enemyBoss->getvEnemyBoss()[i].rc.right + _enemyBoss->getvEnemyBoss()[i].rc.left) / 2, (_enemyBoss->getvEnemyBoss()[i].rc.top + _enemyBoss->getvEnemyBoss()[i].rc.bottom) / 2);//보스좌표에 폭발 이펙트 발생
					
					_enemyBoss->removeBoss(i);//보스적제거
				}
				break;
			}
		}
	}
	//플레이어랑 보스충돌 끝점!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	
	//아이템이랑 플레이어 충돌 시작점!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	for (int i = 0; i < _item->getvBombItem().size(); i++)//폭탄아이템
	{
		if (_item->getBobmCount() < 3)//현재 아이템 개수가 3개 미만인 경우에만 플레이어랑 아이템이랑 충돌실행
		{
			if (IntersectRect(&temp, &_player->getPlayerRC(), &_item->getvBombItem()[i].rc))//플레이어랑 아이템이랑 충돌하면
			{
				_item->setBobmCountPlus(1);//폭탄개수 늘리기
				_bomb->setBombMax(_item->getBobmCount());//폭탄개수 늘리기
				_item->removeBombItem(i);//폭탄 아이템 삭제
				break;
			}
		}
	}

	for (int i = 0; i < _item->getvAttackItem().size(); i++)//공격력강화 아이템
	{
		if (_item->getAttackCount() < 3)//현재 공격력 강화 단계가 3개 미만인 경우에만 플레이어랑 아이템이랑 충돌실행
		{
			if (IntersectRect(&temp, &_player->getPlayerRC(), &_item->getvAttackItem()[i].rc))//플레이어랑 공격력강화 아이템이랑 충돌하면
			{
				if (_item->getAttackCount() < 3)//공격력 강화 단계 3단계 까지만 늘릴 수 있는 조건문
				{
					_item->setAttackCount(1);//공격력 강화 단계 늘리기
				}
				_item->removeAttackItem(i);//공격력 아이템 삭제
				break;
			}
		}
	}

	for (int i = 0; i < _item->getvHpItem().size(); i++)//hp 아이템
	{
		if (IntersectRect(&temp, &_player->getPlayerRC(), &_item->getvHpItem()[i].rc))//플레이어랑 hp 아이템이랑 충돌하면
		{
			_player->setCurrentPlusHP(100);//플레이어 hp를 멕스치로

			_item->removeHpItem(i);//hp 아이템 삭제
			break;
		}
	}
	//아이템이랑 플레이어 충돌 끝점!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
}
