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
	//�÷��̾� ����Ҵ�

	_enemy = new enemy;
	_enemy->init();
	//�� ����Ҵ�

	_enemyJuneBoss = new enemyJuneBoss;
	_enemyJuneBoss->init();
	//�غ��� ����Ҵ�

	_enemyBoss = new enemyBoss;
	_enemyBoss->init();
	//���� ����Ҵ�

	_playerBullet = new playerBullet;
	_playerBullet->init(30, WINSIZEY);
	//�÷��̾� �Ѿ� ����Ҵ�

	_playerBullet2 = new playerBullet2;
	_playerBullet2->init(60, WINSIZEY);
	//�÷��̾� �Ѿ� 2�ܰ� ����Ҵ�

	_playerBullet3 = new playerBullet3;
	_playerBullet3->init(90, WINSIZEY);
	//�÷��̾� �Ѿ� 3�ܰ� ����Ҵ�

	_progressBar = new progressBar;
	_progressBar->init(_player->getPlayerX(), _player->getPlayerY(), 50, 10);
	//���α׷����� ����Ҵ�

	_missionComplete = IMAGEMANAGER->addImage("missionComplete", "image/missionComplete!.bmp", 600, 800, true, false, RGB(255, 0, 255));//����Ŭ����

	_enemyBullet = new enemyBullet;
	IMAGEMANAGER->addImage("enemyBullet", "image/enemyBullet.bmp", 12, 10, true, false, RGB(255, 0, 255));
	_enemyBullet->init("enemyBullet", 30, WINSIZEY);
	//�Ϲ��� �Ѿ� ����Ҵ�

	_enemyBullet2 = new enemyBullet2;
	IMAGEMANAGER->addFrameImage("enemyBullet2", "image/enemyBullets.bmp", 72, 20, 6, 1, true, false, RGB(255, 0, 255));
	_enemyBullet2->init("enemyBullet2", 30, WINSIZEY);
	//ufo �Ѿ� ����Ҵ�

	_enemyBullet3 = new enemyBullet3;
	IMAGEMANAGER->addFrameImage("enemyBullet3", "image/enemyBullets2.bmp", 120, 20, 9, 1, true, false, RGB(255, 0, 255));
	_enemyBullet3->init("enemyBullet3", 30, WINSIZEY);
	//�︮���� �Ѿ� ����Ҵ�

	_enemyJuneBullet = new enemyJuneBullet;
	IMAGEMANAGER->addImage("enemyJuneBullet", "image/enemyJuneBossBullet.bmp", 18, 16, true, false, RGB(255, 0, 255));
	_enemyJuneBullet->init("enemyJuneBullet", 60, WINSIZEY);
	//�غ��� �Ѿ� ����Ҵ�
	_juneBossBulletCount = 0;//�غ��� �Ѿ� �߻� ī��Ʈ

	_enemyBossBullet = new enemyBossBullet;
	IMAGEMANAGER->addImage("enemyBossBullet", "image/enemyBossBullet.bmp", 27, 26, true, false, RGB(255, 0, 255));
	_enemyBossBullet->init("enemyBossBullet", 30, WINSIZEY);
	//���� �Ѿ� ����Ҵ�
	_bossBulletCount = 0;
	_bossBulletCount2 = 0;

	_enemyBossBullet2 = new enemyBossBullet2;
	IMAGEMANAGER->addImage("enemyBossBullet2", "image/enemyBossBullet2.bmp", 27, 26, true, false, RGB(255, 0, 255));
	_enemyBossBullet2->init("enemyBossBullet2", 15, WINSIZEY);
	//���� �Ѿ� 2������ ����Ҵ�


	_item = new item;
	_item->init();
	//������ ����Ҵ�

	_bomb = new bomb;
	IMAGEMANAGER->addFrameImage("bomb", "image/playerFire.bmp", 160, 30, 8, 1, true, false, RGB(255, 0, 255));
	_bomb->init("bomb", 100, _item->getBobmCount());
	//��ź ����Ҵ�

	_background = IMAGEMANAGER->addImage("backGround", "image/backGround.bmp", 600, 4288, false, false, RGB(255, 0, 255));//���

	_gameOver = IMAGEMANAGER->addImage("gameOver", "image/gameOver.bmp", 558, 67, true, false, RGB(255, 0, 255));//���ӿ���

	_blackScrren = IMAGEMANAGER->addImage("blackScreen", "image/blackScrren.bmp", 600, 800, false, false, RGB(255, 0, 255));//����ȭ�� ������ ���� �̹���

	_playerBombMove = IMAGEMANAGER->addFrameImage("playerBombMove", "image/playerBombMove.bmp", 7050, 200, 47, 1, true, false, RGB(255, 0, 255));//�÷��̾ ��ź �߻��Ҷ� ������ �̹���
	_playerBomb = false;//�÷��̾ ��ź �߻��Ҷ� �÷��̾��� ��ź�߻� ������ �̹����� �۵�����
	_playerBombMove->setFrameX(0);
	_playerBombMove->setFrameY(0);
	_count = 0;
	//��ź

	_bombExplosionImage = IMAGEMANAGER->addFrameImage("bombExplosion", "image/playerBomb.bmp", 3584, 320, 16, 1, true, false, RGB(255, 0, 255));
	_bombExplosionImage->setFrameX(0);
	_bombExplosionImage->setFrameY(0);
	_bobmExplosionCount = 0;
	_bombExplosion = false;
	_bombExplosionRc = RectMake(_player->getPlayerX() - 100, _player->getPlayerY() - 300, _bombExplosionImage->getFrameWidth(), _bombExplosionImage->getFrameHeight());
	//��ź����

	IMAGEMANAGER->addImage("explosion", "image/deathExplosions.bmp", 612, 72, true, false, RGB(255, 0, 255));//��, �÷��̾� ������ ���� �̹���
	_deathExplosions = new effect;
	_deathExplosions->init(IMAGEMANAGER->findImage("explosion"), 51, 72, 1.0f, 1.0f);
	EFFECTMANAGER->addEffect("explosion", "image/deathExplosions.bmp", 612, 72, 51, 72, 1.0f, 0.5f, 300);
	//��, �÷��̾� �׾����� ���� ����Ʈ �߰�

	IMAGEMANAGER->addImage("bossExplosion", "image/bossExplosions.bmp", 2560, 128, true, false, RGB(255, 0, 255));
	_bossExplosions = new effect;
	_bossExplosions->init(IMAGEMANAGER->findImage("bossExplosion"), 128, 128, 1.0f, 1.0f);
	EFFECTMANAGER->addEffect("bossExplosion", "image/bossExplosions.bmp", 2560, 128, 128, 128, 1.0f, 0.5f, 300);
	//������ �׾����� ���� ����Ʈ �߰�

	IMAGEMANAGER->addImage("playerHit", "image/playerHit.bmp", 200, 20, true, false, RGB(255, 0, 255));
	_playerHit = new effect;
	_playerHit->init(IMAGEMANAGER->findImage("playerHit"), 20, 20, 1.0f, 1.0f);
	EFFECTMANAGER->addEffect("playerHit", "image/playerHit.bmp", 200, 20, 20, 20, 1.0f, 0.5f, 300);
	//�÷��̾� ��Ʈ ����Ʈ �߰�

	_alpha = 100;//���İ�
	_missionCompleteAlpha = 0;//���� Ŭ���� �̹����� ����� ���İ�
	_missionCompleteAlphaCount = 0;//����Ŭ���� �̹����� ����� ���İ��� ī��Ʈ��

	_loopY = 4288 - WINSIZEY;//����̹��� �ؿ������� �����Ű�� ���� �ʱ�ȭ

	_rc[0].left = -10;
	_rc[0].right = 0;
	_rc[0].top = 0;
	_rc[0].bottom = WINSIZEY;
	//����

	_rc[1].left = WINSIZEX;
	_rc[1].right = WINSIZEX + 10;
	_rc[1].top = 0;
	_rc[1].bottom = WINSIZEY;
	//������

	_rc[2].left = 0;
	_rc[2].right = WINSIZEX;
	_rc[2].top = 90;
	_rc[2].bottom = 100;
	//��

	_rc[3].left = 0;
	_rc[3].right = WINSIZEX;
	_rc[3].top = WINSIZEY;
	_rc[3].bottom = WINSIZEY + 10;
	//�Ʒ�

	_death = false;//�÷��̾ �׾����� ���� Ȯ��
	_juneBossAttack = false;//�غ��� ���ݽ���
	_juneBossAppear = false;//�غ��� ����
	_bossAppear = false;//��������
	_bossAttack = false;//�������ݽ���
	_rotation = 1;//�������ݰ���
	_oneSoundPlay = false;//���带 �ѹ��� �����Ű�� ���� ����� ����

	return S_OK;
}

void mainGameScene::release()
{
}

void mainGameScene::update()
{
	if (!_death)//�÷��̾ ���������
	{
		if (!_juneBossAppear && _loopY > 0)//����̹����� ����������
		{
			_loopY -= 1;//����̹��� �������
		}

		if (_loopY <= 2144)//�غ��� ��������
		{
			_juneBossAppear = true;//�غ��� ����
		}
		if(_juneBossAppear && _enemyJuneBoss->getJuneBossY() <= 100)//����̹����� ������ǥ�� �����ϸ� �غ��� ����
		{
			_enemyJuneBoss->update();//�غ��� ������Ʈ
		}
		else if (_enemyJuneBoss->getJuneBossY() >= 100)//�غ����� y��ǥ�� 100�� �����ϸ�
		{
			_juneBossAttack = true;//�غ��� ���ݽ���
		}
		if (_enemyJuneBoss->getHP() < 0)//�غ����� �׾�����
		{
			_juneBossAppear = false;//����̹��� �ٽ����
		}

		if (_loopY <= 0)//����̹����� ���� �����ϸ�
		{
			_bossAppear = true;//��������
		}
		if (_bossAppear)//������ ����������
		{
			_enemyBoss->fristMove();//����ù���� ���� ������Ʈ
		}
		if (_enemyBoss->getBossAppear())//������ ������ ��ġ�� ����������
		{
			_bossAttack = true;//�������ݽ���
			_enemyBoss->update();//���� ������Ʈ
		}

		if (!_playerBomb)//�÷��̾ ��ź �߻��ϴ� �������� ������ �������� �������� ���ϰ� �ϱ����� ���ǹ�
		{
			_player->update();//�÷��̾� ������Ʈ
		}

		_enemy->update();//�� ������Ʈ

		if (_juneBossAttack)//�غ��� ���ݽ���
		{
			_juneBossBulletCount++;
			if (_juneBossBulletCount % 2 == 0)
			{
				for (int i = 0; i < _enemyJuneBoss->getvJuneBoss().size(); i++)
				{
					_enemyJuneBullet->fire(_enemyJuneBoss->getJuneBossX() + 80, _enemyJuneBoss->getJuneBossY() + 50, _enemyJuneBoss->getJuneBossRotation(), 7.0f);//�غ��� �Ѿ� ����
				}
					_juneBossBulletCount = 0;
			}
		}
		
		if (_bossAttack)//������ ������ Ʈ���
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
					if (_enemyBoss->getHP() < 500)//������ ü���� ���� �̸��̸�
					{
						_enemyBossBullet2->fire((_enemyBoss->getvEnemyBoss()[i].rc.right + _enemyBoss->getvEnemyBoss()[i].rc.left) / 2, (_enemyBoss->getvEnemyBoss()[i].rc.top + _enemyBoss->getvEnemyBoss()[i].rc.bottom) / 2,
							getAngle(_enemyBoss->getBossX(), _enemyBoss->getBossY(), _player->getPlayerX(), _player->getPlayerY()), 7.0f);//���� �Ѿ� 2������ �߻�
					}
				}
				_bossBulletCount2 = 0;
			}

			if (_rotation >= 5)
			{
				_rotation = 1;
			}
			
		}

		if (_enemyBoss->getHP() < 0)//������ ������
		{
			for (int i = 0; i < _enemy->getvEnemy().size(); i++)//�Ϲ��� ����
			{
				EFFECTMANAGER->play("explosion", _enemy->getvEnemy()[i].x, _enemy->getvEnemy()[i].y);
				_enemy->removeEnemy(i);
				break;
			}
			for (int i = 0; i < _enemy->getvEnemyUfo().size(); i++)//���ʿ��� ���������� ���� ufo����
			{
				EFFECTMANAGER->play("explosion", _enemy->getvEnemyUfo()[i].x, _enemy->getvEnemyUfo()[i].y);
				_enemy->removeEnemyUfo(i);
				break;
			}
			for (int i = 0; i < _enemy->getvEnemyUfo2().size(); i++)//�����ʿ��� �������� ���� ufo����
			{
				EFFECTMANAGER->play("explosion", _enemy->getvEnemyUfo2()[i].x, _enemy->getvEnemyUfo2()[i].y);
				_enemy->removeEnemyUfo2(i);
				break;
			}
			for (int i = 0; i < _enemy->getvEnemyHelicopter().size(); i++)//�︮��������
			{
				EFFECTMANAGER->play("explosion", _enemy->getvEnemyHelicopter()[i].x, _enemy->getvEnemyHelicopter()[i].y);
				_enemy->removeEnemyHelicopter(i);
				break;
			}
			if (!_oneSoundPlay)//���带 �ѹ��� �����Ű�� ���� �ʿ��� ���ǹ�
			{
				_token = "sound/missionComplete!.mp3";
				_vSoundList.push_back(_token);

				SOUNDMANAGER->addSound(_vSoundList[_vSoundList.size() - 1], _vSoundList[_vSoundList.size() - 1], true, false);//���������߰�
				SOUNDMANAGER->play(_vSoundList[_vSoundList.size() - 1], 1.0f);//�������
				_oneSoundPlay = true;
			}

			if (KEYMANAGER->isOnceKeyDown(VK_RETURN))//���͹�ư�� ������
			{
				SOUNDMANAGER->stop(_vSoundList[_vSoundList.size() - 1]);//����Ŭ���� ���� ����
				SCENEMANAGER->changeScene("��ŸƮ��");//���ӽ�ŸƮ ȭ������ ����
			}
		}
		
		//�Ϲ��� �Ѿ˹߻� ������
		for (int i = 0; i < _enemy->getvEnemy().size(); i++)
		{
			if (_enemy->getvEnemy()[i].y > 0)//���� ȭ������� ��������
			{
				if (_enemy->bulletCountfire())//�� �Ѿ˹߻�
				{
					_enemyBullet->fire(_enemy->getvEnemy()[i].x, _enemy->getvEnemy()[i].y,
						getAngle(_enemy->getvEnemy()[i].x, _enemy->getvEnemy()[i].y, _player->getPlayerX(), _player->getPlayerY()), 7.0f);//���Ѿ� �÷��̾� ��ġ�� �߻�
				}
			}
		}
		//�Ϲ��� �Ѿ˹߻� ����

		//���ʿ��� ������ ufo�� �Ѿ˹߻� ������
		for (int i = 0; i < _enemy->getvEnemyUfo().size(); i++)//���ʿ��� ������ ufo
		{
			if (_enemy->getvEnemyUfo()[i].x > 0 && _enemy->getvEnemyUfo()[i].x < WINSIZEX && _enemy->getvEnemyUfo()[i].y > 0 && _enemy->getvEnemyUfo()[i].y < WINSIZEY)//ufo���� ȭ������� ������
			{
				if (_enemy->bulletCountfire())//�� �Ѿ� �߻�
				{
					_enemyBullet2->fire(_enemy->getvEnemyUfo()[i].x, _enemy->getvEnemyUfo()[i].y,
						getAngle(_enemy->getvEnemyUfo()[i].x, _enemy->getvEnemyUfo()[i].y, _player->getPlayerX(), _player->getPlayerY()),
						7.0f);//ufo �Ѿ� �÷��̾� ��ǥ�� �߻�
				}
			}
			
			if (_enemy->getvEnemyUfo()[i].rc.left > WINSIZEX)//ufo�� ȭ�� �������� �Ѿ��
			{
				_enemy->removeEnemyUfo(i);//ufo ����
				break;
			}
			
		}
		//���ʿ��� ������ ufo�� �Ѿ˹߻� ����

		//�����ʿ��� ���� ufo�� �Ѿ˹߻� ������
		for (int i = 0; i < _enemy->getvEnemyUfo2().size(); i++)//�����ʿ��� ���� ufo
		{
			if (_enemy->getvEnemyUfo2()[i].x > 0 && _enemy->getvEnemyUfo2()[i].x < WINSIZEX && _enemy->getvEnemyUfo2()[i].y > 0 && _enemy->getvEnemyUfo2()[i].y < WINSIZEY)//ufo���� ȭ������� ������
			{
				if (_enemy->bulletCountfire())//�� �Ѿ� �߻�
				{
					_enemyBullet2->fire(_enemy->getvEnemyUfo2()[i].x, _enemy->getvEnemyUfo2()[i].y,
						getAngle(_enemy->getvEnemyUfo2()[i].x, _enemy->getvEnemyUfo2()[i].y, _player->getPlayerX(), _player->getPlayerY()),
						7.0f);//ufo �Ѿ� �÷��̾� ��ǥ�� �߻�
				}
			}
			
			if (_enemy->getvEnemyUfo2()[i].rc.right < 0)//ufo�� ȭ�� ������ �Ѿ��
			{
				_enemy->removeEnemyUfo2(i);//ufo ����
				break;
			}
			
		}
		//�����ʿ��� ���� ufo�� �Ѿ˹߻� ����

		//�︮������ �Ѿ˹߻� ������
		for (int i = 0; i < _enemy->getvEnemyHelicopter().size(); i++)
		{
			if (_enemy->getvEnemyHelicopter()[i].x > 0 && _enemy->getvEnemyHelicopter()[i].x < WINSIZEX && _enemy->getvEnemyHelicopter()[i].y > 0 && _enemy->getvEnemyHelicopter()[i].y < WINSIZEY)//�︮�������� ȭ������� ������
			{
				if (_enemy->bulletCountfire())//���Ѿ˹߻簡 ���̸�
				{
					_enemyBullet3->fire(_enemy->getvEnemyHelicopter()[i].x, _enemy->getvEnemyHelicopter()[i].y, 7.0f);//�︮������ �Ѿ� �߻�
				}
			}
		}
		//�︮������ �Ѿ˹߻� ����

		//�︮������ �Ѿ˹߻� ������
		for (int i = 0; i < _enemy->getvEnemyHelicopter2().size(); i++)
		{
			if (_enemy->getvEnemyHelicopter2()[i].x > 0 && _enemy->getvEnemyHelicopter2()[i].x < WINSIZEX && _enemy->getvEnemyHelicopter2()[i].y > 0 && _enemy->getvEnemyHelicopter2()[i].y < WINSIZEY)//�︮�������� ȭ������� ������
			{
				if (_enemy->bulletCountfire())//���Ѿ˹߻簡 ���̸�
				{
					_enemyBullet3->fire(_enemy->getvEnemyHelicopter2()[i].x, _enemy->getvEnemyHelicopter2()[i].y, 7.0f);//�︮������ �Ѿ� �߻�
				}
			}
		}
		//�︮������ �Ѿ˹߻� ����

		if (_enemyJuneBoss->getHP() < 0)//�غ����� �׾�����
		{
			_enemy->move2();//2������ �� ����
		}
		
		_enemyBullet->update();//�Ϲ����Ѿ� ������Ʈ
		_enemyBullet2->update();//ufo�� �Ѿ� ������Ʈ
		_enemyBullet3->update();//�︮������ �Ѿ� ������Ʈ
		_enemyJuneBullet->update();//�غ��� �Ѿ� ������Ʈ
		_enemyBossBullet->update();//���� �Ѿ� ������Ʈ
		_enemyBossBullet2->update();//���� �Ѿ� 2������ ������Ʈ

		if (!_playerBomb)//�÷��̾ �⺻�����϶��� �߻簡 �����ϰ� �ϱ����� ���ǹ�
		{
			if (KEYMANAGER->isOnceKeyDown('A'))//�����̽���Ű ����
			{
				_token = "sound/playerFire.mp3";
				_vSoundList.push_back(_token);
				SOUNDMANAGER->addSound(_vSoundList[_vSoundList.size() - 1], _vSoundList[_vSoundList.size() - 1], true, false);//���������߰�
				if (_item->getAttackCount() == 1)//�÷��̾� �Ѿ� �⺻�ܰ�
				{
					SOUNDMANAGER->play(_vSoundList[_vSoundList.size() - 1], 1.0f);//�������

					_playerBullet->fire(_player->getPlayerX(), _player->getPlayerY()); //�÷��̾� �Ѿ˹߻�
				}
				if (_item->getAttackCount() == 2)//�÷��̾� �Ѿ� 2�ܰ�
				{
					SOUNDMANAGER->play(_vSoundList[_vSoundList.size() - 1], 1.0f);//�������

					_playerBullet2->fire(_player->getPlayerX() - 15, _player->getPlayerY());//�÷��̾� �Ѿ� 2�ܰ� �߻�
					_playerBullet2->fire(_player->getPlayerX() + 15, _player->getPlayerY());//�÷��̾� �Ѿ� 2�ܰ� �߻�
				}
				if (_item->getAttackCount() == 3)//�÷��̾� �Ѿ� 3�ܰ�
				{
					SOUNDMANAGER->play(_vSoundList[_vSoundList.size() - 1], 1.0f);//�������

					_playerBullet3->fire(_player->getPlayerX() - 30, _player->getPlayerY() + 10);//�÷��̾� �Ѿ� 3�ܰ� �߻�
					_playerBullet3->fire(_player->getPlayerX(), _player->getPlayerY());//�÷��̾� �Ѿ� 3�ܰ� �߻�
					_playerBullet3->fire(_player->getPlayerX() + 30, _player->getPlayerY() + 10);//�÷��̾� �Ѿ� 3�ܰ� �߻�
				}
			}
		}

		//�÷��̾� �Ѿ��� ȭ������ �Ѿ�� ���� ������
		for (int i = 0; i < _playerBullet->getvPlayerBullet().size(); i++)//�÷��̾� �Ѿ�
		{
			if (_playerBullet->getvPlayerBullet()[i].y <= 0)
			{
				_playerBullet->removePlayerBullet(i);
				break;
			}
		}
		for (int i = 0; i < _playerBullet2->getvPlayerBullet2().size(); i++)//�÷��̾� �Ѿ� 2�ܰ�
		{
			if (_playerBullet2->getvPlayerBullet2()[i].y <= 0)
			{
				_playerBullet2->removePlayerBullet2(i);
				break;
			}
		}
		for (int i = 0; i < _playerBullet3->getvPlayerBullet3().size(); i++)//�÷��̾� �Ѿ� 3�ܰ�
		{
			if (_playerBullet3->getvPlayerBullet3()[i].y <= 0)
			{
				_playerBullet3->removePlayerBullet3(i);
				break;
			}
		}
		//�÷��̾� �Ѿ��� ȭ������ �Ѿ�� ���� ����

		if (!_playerBomb)//�÷��̾ �⺻�����϶��� �߻簡 �����ϰ� �ϱ����� ���ǹ�
		{
			if (KEYMANAGER->isOnceKeyDown('S'))//aŰ �÷��̾� ��ź����
			{
				_bomb->bombFire(_player->getPlayerX(), _player->getPlayerY(), 6.0f);//��ź����
				_item->setBobmCountMin(1);//����� ��ź ������ ������ŭ ����
				_bomb->setBombMax(_item->getBobmCount());//��ź���� ����

				if (_item->getBobmCount() >= 0)//��ź�� 1���� ������������ �÷��̾ ��ź�� �߻��ϴ� ������ �̹��� �����Ű�� ���� ���ǹ�
				{
					_playerBomb = true;//�÷��̾� ��ź �߻��ϴ� ������
					_bombExplosion = true;//��ź���� ������ ���ǿ��� Ȯ��
					_bombExplosionRc = RectMake(_player->getPlayerX() - 100, _player->getPlayerY() - 300, _bombExplosionImage->getFrameWidth(), _bombExplosionImage->getFrameHeight());
				}
			}
		}

		_playerBullet->update();//�÷��̾� �Ѿ˾�����Ʈ

		_playerBullet2->update();//�÷��̾� �Ѿ� 2�ܰ� ������Ʈ

		_playerBullet3->update();//�÷��̾� �Ѿ� 3�ܰ� ������Ʈ

		_bomb->update();//��ź ������Ʈ
		
		_progressBar->setX(_player->getPlayerX() - 10);
		_progressBar->setY(_player->getPlayerY() - 15);
		//���α׷����� ������ ��ġ �ǽð����� �÷��̾� ��ġ�� �̵�

		_progressBar->update();//���α׷����� ������Ʈ

		_progressBar->setGauge(_player->getCurrentHP(), _player->getMaxHP());//���α׷����� ������ ����

		_item->update();//������ ������Ʈ

		collision();//�浹����

		_rndItem = RND->getInt(2);//���ݷ� ��ȭ������, ��ź������ ���� � �������� ������ �������� ���� ����

		EFFECTMANAGER->update();//��, �÷��̾� �׾����� ���������� ������Ʈ
	}
	else//�÷��̾ �׾�����
	{
		if (KEYMANAGER->isOnceKeyDown(VK_RETURN))//���͹�ư�� ������
		{
			SCENEMANAGER->changeScene("��ŸƮ��");//���ӽ�ŸƮ ȭ������ ����
		}
	}

}

void mainGameScene::render()
{
	_background->loopRender(getMemDC(), &RectMake(0, 0, WINSIZEX, WINSIZEY), 0, _loopY);//����̹��� �������

	if (!_playerBomb)//��ź�߻��� �⺻ ������
	{
		_player->render();//�÷��̾� �׸���
	}
	else//��ź �߻��Ҷ��� ������
	{
		_playerBombMove->frameRender(getMemDC(), _player->getPlayerRC().left - 55, _player->getPlayerRC().top - 50, _playerBombMove->getFrameX(), _playerBombMove->getFrameY());//��ź�߻�������

		_bobmExplosionCount++;//��ź���� ī��Ʈ
		if (_bobmExplosionCount > 15 && _bombExplosion)//��ź�����Ҷ�
		{
			//Rectangle(getMemDC(), _bombExplosionRc);//��ź ���� �̹��� ��Ʈ���� Ȯ�ο�
			_bombExplosionImage->frameRender(getMemDC(), _player->getPlayerX() - 100, _player->getPlayerY() - 300, _bombExplosionImage->getFrameX(), _bombExplosionImage->getFrameY());//��ź���� ������
		}

		_count++;
		if (_count % 5 == 0)
		{
			_playerBombMove->setFrameX(_playerBombMove->getFrameX() + 1);//�÷��̾ ��ź �߻��ϸ鼭 �����̴� ������
			if (_playerBombMove->getFrameX() >= _playerBombMove->getMaxFrameX())//�÷��̾��� ��ź�߻� ������ �̹����� ���� �����Ѱ��
			{
				_playerBombMove->setFrameX(0);//�÷��̾��� ��ź �߻��Ҷ� �÷��̾��� ������ �̹��� �ʱ�ȭ
				_playerBomb = false;//�÷��̾ �⺻�����϶��� �ǵ�����
			}

			_bombExplosionImage->setFrameX(_bombExplosionImage->getFrameX() + 1);//��ź���� ������
			if (_bombExplosionImage->getFrameX() >= _bombExplosionImage->getMaxFrameX())//��ź���� �������� ���� �����ϸ�
			{
				_bombExplosionImage->setFrameX(0);//��ź���� ������ �ʱ�ȭ
				_bombExplosion = false;//��ź���� ���� �޽�
				_bobmExplosionCount = 0;//��ź���� Ÿ�̹� �ʱ�ȭ
			}

			_count = 0;
		}
	}
	

	_enemy->render();//�� �׸���
	_enemyJuneBoss->render();//�غ��� �׸���
	_enemyBoss->render();//���� �׸���

	for (int i = 0; i < _enemyBullet->getvEnemyBullet().size(); i++)
	{
		//Rectangle(getMemDC(), _enemyBullet->getvEnemyBullet()[i].rc);//���Ѿ� ��ƮȮ�ο�
	}

	_enemyBullet->render();//�Ϲ��� �Ѿ� �׸���
	_enemyBullet2->render();//ufo�� �Ѿ� �׸���
	_enemyBullet3->render();//�︮������ �Ѿ� �׸���
	_enemyJuneBullet->render();//�غ��� �Ѿ� �׸���
	_enemyBossBullet->render();//���� �Ѿ� �׸���
	_enemyBossBullet2->render();//���� �Ѿ� 2������ �׸���

	for (int i = 0; i < _playerBullet->getvPlayerBullet().size(); i++)
	{
		//Rectangle(getMemDC(), _playerBullet->getvPlayerBullet()[i].rc);//�÷��̾� �Ѿ� ��ƮȮ�ο�
	}

	_playerBullet->render();//�÷��̾� �Ѿ˱׸���
	_playerBullet2->render();//�÷��̾� �Ѿ� 2�ܰ� �׸���
	_playerBullet3->render();//�÷��̾� �Ѿ� 3�ܰ� �׸���

	_progressBar->render();//���α׷����� �׸���

	_item->render();//������ �׸���

	_bomb->render();//��ź �׸���

	if (_death)//�÷��̾ �׾�����
	{
		IMAGEMANAGER->findImage("gameOver")->render(getMemDC(), WINSIZEX / 2 - 275, WINSIZEY / 2);//���ӿ���
		IMAGEMANAGER->findImage("blackScreen")->alphaRender(getMemDC(), 0, 0,_alpha);
	}

	if (_enemyBoss->getHP() < 0)//������ �׾�����
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
	_missionComplete->alphaRender(getMemDC(), 0, 0, _missionCompleteAlpha);//�̼�Ŭ���� �̹��� ����

	_deathExplosions->render();//��, �÷��̾� ���� �̹��� �׸���
	_bossExplosions->render();//���� �׾����� ���� �̹��� �׸���
	_playerHit->render();//�÷��̾� ��Ʈ �̹��� �׸���
	EFFECTMANAGER->render();//����Ʈ�Ŵ��� �׸���
	TIMEMANAGER->render(getMemDC());
}

void mainGameScene::collision()
{
	RECT temp;

	if (IntersectRect(&temp, &_rc[0], &_player->getPlayerRC()))//����
	{
		int w = temp.right - temp.left;
		int h = temp.bottom - temp.top;

		_player->setPlayerX(_player->getPlayerX() + w);
	}
	if (IntersectRect(&temp, &_rc[1], &_player->getPlayerRC()))//������
	{
		int w = temp.right - temp.left;
		int h = temp.bottom - temp.top;

		_player->setPlayerX(_player->getPlayerX() - w);
	}
	if (IntersectRect(&temp, &_rc[2], &_player->getPlayerRC()))//����
	{
		int w = temp.right - temp.left;
		int h = temp.bottom - temp.top;

		_player->setPlayerY(_player->getPlayerY() + h);
	}
	if (IntersectRect(&temp, &_rc[3], &_player->getPlayerRC()))//�Ʒ���
	{
		int w = temp.right - temp.left;
		int h = temp.bottom - temp.top;

		_player->setPlayerY(_player->getPlayerY() - h);
	}
	//�÷��̾ ȭ������� ������ ���ϰ�

	//�÷��̾�� �Ϲ��� �浹 ������!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	for (int i = 0; i < _enemyBullet->getvEnemyBullet().size(); i++)//�Ϲ����Ѿ�
	{
		if (!_playerBomb)//�÷��̾ �⺻�����϶�
		{
			if (IntersectRect(&temp, &_player->getPlayerRC(), &_enemyBullet->getvEnemyBullet()[i].rc))//�Ϲ����Ѿ��̶� �÷��̾�� �浹ó��
			{
				_player->setCurrentHP(5);//�÷��̾� ������ ���̱�

				_enemyBullet->removeEnemyBullet(i);//���Ѿ�����

				EFFECTMANAGER->play("playerHit", (_player->getPlayerRC().right + _player->getPlayerRC().left) / 2, (_player->getPlayerRC().bottom + _player->getPlayerRC().top) / 2);//���Ѿ��� �÷��̾�� �浹������� ���� ����Ʈ
				if (_player->getCurrentHP() < 0)//�÷��̾� ���� HP�� 0���ϰ� �Ǹ�
				{
					_death = true;//�÷��̾ �׾���
				}
				break;
			}
		}
	}
	
	for (int i = 0; i < _enemy->getvEnemy().size(); i++)//�Ϲ���
	{
		for (int j = 0; j < _playerBullet->getvPlayerBullet().size(); j++)//�÷��̾� �Ѿ�
		{
			if (IntersectRect(&temp, &_enemy->getvEnemy()[i].rc, &_playerBullet->getvPlayerBullet()[j].rc))//�÷��̾� �Ѿ��� �Ϲ����̶� �浹��
			{
				EFFECTMANAGER->play("explosion", _enemy->getvEnemy()[i].x, _enemy->getvEnemy()[i].y);//�Ϲ����� �÷��̾��� �Ѿ��̶� �ε�������� ���� ����Ʈ �׸���
				_playerBullet->removePlayerBullet(j);//�÷��̾� �Ѿ�����
				if (_item->itemCountFire())//�������� ����Ȯ���� Ʈ���
				{
					if (_rndItem == 0)//0�̸� ��ź
					{
						_item->bombItemFire(_enemy->getvEnemy()[i].x, _enemy->getvEnemy()[i].y);//�Ϲ��� ��ġ�� ��ź ������ �����
					}
					else//�ƴϸ� ���ݷ� ��ȭ������
					{
						_item->attackItemFire(_enemy->getvEnemy()[i].x, _enemy->getvEnemy()[i].y);//�Ϲ��� ��ġ�� ���ݷ� ��ȭ ������ �����
					}
				}
				_enemy->removeEnemy(i);//�Ϲ��� ����
				break;
			}
		}
	}

	for (int i = 0; i < _playerBullet2->getvPlayerBullet2().size(); i++)//�÷��̾� �Ѿ� 2�ܰ�
	{
		for (int j = 0; j < _enemy->getvEnemy().size(); j++)//�Ϲ���
		{
			if (IntersectRect(&temp, &_enemy->getvEnemy()[j].rc, &_playerBullet2->getvPlayerBullet2()[i].rc))//�Ϲ����̶� �÷��̾� �Ѿ� 2�ܰ�� �浹��
			{
				EFFECTMANAGER->play("explosion", _enemy->getvEnemy()[j].x, _enemy->getvEnemy()[j].y);//�Ϲ��� ��ġ�� ���� ����Ʈ �߻�
				_playerBullet2->removePlayerBullet2(i);//�Ѿ˺��� ����

				if (_item->itemCountFire())//�������� ����Ȯ���� ���̸�
				{
					if (_rndItem == 0)//��ź������
					{
						_item->bombItemFire(_enemy->getvEnemy()[j].x, _enemy->getvEnemy()[j].y);//��ź������ �Ϲ��� ��ġ�� ����
					}
					if (_rndItem == 1)//���ݷ� ��ȭ ������
					{
						_item->attackItemFire(_enemy->getvEnemy()[j].x, _enemy->getvEnemy()[j].y);//���ݷ� ��ȭ ������ �Ϲ��� ��ġ�� ����
					}
				}

				_enemy->removeEnemy(j);//�Ϲ��� ���� ����
				break;
			}
		}
	}

	for (int i = 0; i < _playerBullet3->getvPlayerBullet3().size(); i++)//�÷��̾� �Ѿ� 3�ܰ�
	{
		for (int j = 0; j < _enemy->getvEnemy().size(); j++)//�Ϲ���
		{
			if (IntersectRect(&temp, &_enemy->getvEnemy()[j].rc, &_playerBullet3->getvPlayerBullet3()[i].rc))//�Ϲ����̶� �÷��̾� �Ѿ� 3�ܰ�� �浹��
			{
				EFFECTMANAGER->play("explosion", _enemy->getvEnemy()[j].x, _enemy->getvEnemy()[j].y);//�Ϲ��� ��ġ�� ���� ����Ʈ �߻�
				_playerBullet3->removePlayerBullet3(i);//�÷��̾� �Ѿ� 3�ܰ� ���Ϳ��� ����

				if (_item->itemCountFire())//�������� ���� Ȯ���� ���̸�
				{
					if (_rndItem == 0)//��ź ������
					{
						_item->bombItemFire(_enemy->getvEnemy()[j].x, _enemy->getvEnemy()[j].y);//�Ϲ��� ��ġ�� ��ź ������ ����
					}
					if (_rndItem == 1)//���ݷ� ��ȭ ������
					{
						_item->attackItemFire(_enemy->getvEnemy()[j].x, _enemy->getvEnemy()[j].y);//�Ϲ��� ��ġ�� ���ݷ� ��ȭ ������ ����
					}
				}

				_enemy->removeEnemy(j);//�Ϲ��� ���Ϳ��� ����
				break;
			}
		}
	}
	
	for (int i = 0; i < _enemy->getvEnemy().size(); i++)//�Ϲ���
	{
		if (IntersectRect(&temp, &_bombExplosionRc, &_enemy->getvEnemy()[i].rc) && _bombExplosion)//��ź���� ��Ʈ�� �Ϲ����� �浹��
		{
			if (_item->itemCountFire())//�������� ���� Ȯ���� ���̸�
			{
				if (_rndItem == 0)//��ź ������
				{
					_item->bombItemFire(_enemy->getvEnemy()[i].x, _enemy->getvEnemy()[i].y);//�Ϲ��� ��ġ�� ��ź ������ ����
				}
				if (_rndItem == 1)//���ݷ� ��ȭ ������
				{
					_item->attackItemFire(_enemy->getvEnemy()[i].x, _enemy->getvEnemy()[i].y);//�Ϲ��� ��ġ�� ���ݷ� ��ȭ ������ ����
				}
			}
			_enemy->removeEnemy(i);//�Ϲ�������
			break;
		}
	}
	//�÷��̾�� �Ϲ��� �浹 ����!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	
	//�÷��̾�� ���ʿ��� ���� ufo�浹 ������!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	for (int i = 0; i < _enemyBullet2->getvEnemyBullet2().size(); i++)//ufo�� �Ѿ�
	{
		if (!_playerBomb)//�÷��̾ �⺻�����϶�
		{
			if (IntersectRect(&temp, &_player->getPlayerRC(), &_enemyBullet2->getvEnemyBullet2()[i].rc))//ufo�� �Ѿ��� �÷��̾�� �浹��
			{
				EFFECTMANAGER->play("playerHit", (_player->getPlayerRC().right + _player->getPlayerRC().left) / 2, (_player->getPlayerRC().bottom + _player->getPlayerRC().top) / 2);//ufo ���Ѿ��� �÷��̾�� �浹������� ���� ����Ʈ

				_player->setCurrentHP(5);//�÷��̾� ������ ���̱�

				_enemyBullet2->removeEnemyBullet2(i);//ufo ���Ѿ�����
				if (_player->getCurrentHP() < 0)//�÷��̾� ���� HP�� 0���ϰ� �Ǹ�
				{
					_death = true;//�÷��̾ �׾���
				}
				break;
			}
		}
	}
	
	for (int i = 0; i < _enemy->getvEnemyUfo().size(); i++)//���ʿ��� ������ ufo��
	{
		for (int j = 0; j < _playerBullet->getvPlayerBullet().size(); j++)//�÷��̾� �Ѿ�
		{
			if (IntersectRect(&temp, &_enemy->getvEnemyUfo()[i].rc, &_playerBullet->getvPlayerBullet()[j].rc))//�÷��̾� �Ѿ��� ufo���̶� �浹��
			{
				EFFECTMANAGER->play("explosion", _enemy->getvEnemyUfo()[i].x, _enemy->getvEnemyUfo()[i].y);//ufo���� �÷��̾��� �Ѿ��̶� �ε�������� ���� ����Ʈ �׸���
				_playerBullet->removePlayerBullet(j);//�÷��̾� �Ѿ�����
				if (_item->itemCountFire())//�������� ����Ȯ���� Ʈ���
				{
					if (_rndItem == 0)//0�̸� ��ź
					{
						_item->bombItemFire(_enemy->getvEnemyUfo()[i].x, _enemy->getvEnemyUfo()[i].y);//ufo�� ��ġ�� ��ź ������ �����
					}
					else//�ƴϸ� ���ݷ� ��ȭ������
					{
						_item->attackItemFire(_enemy->getvEnemyUfo()[i].x, _enemy->getvEnemyUfo()[i].y);//ufo�� ��ġ�� ���ݷ� ��ȭ ������ �����
					}
				}
				_enemy->removeEnemyUfo(i);//ufo�� ����
				break;
			}
		}
	}

	for (int i = 0; i < _playerBullet2->getvPlayerBullet2().size(); i++)//�÷��̾� �Ѿ� 2�ܰ�
	{
		for (int j = 0; j < _enemy->getvEnemyUfo().size(); j++)//ufo��
		{
			if (IntersectRect(&temp, &_enemy->getvEnemyUfo()[j].rc, &_playerBullet2->getvPlayerBullet2()[i].rc))//ufo���̶� �÷��̾� �Ѿ� 2�ܰ�� �浹��
			{
				EFFECTMANAGER->play("explosion", _enemy->getvEnemyUfo()[j].x, _enemy->getvEnemyUfo()[j].y);//ufo�� ��ġ�� ���� ����Ʈ �߻�
				_playerBullet2->removePlayerBullet2(i);//�÷��̾� �Ѿ� 2�ܰ� ����
				if (_item->itemCountFire())//�������� ����Ȯ���� ���̸�
				{
					if (_rndItem == 0)//��ź ������
					{
						_item->bombItemFire(_enemy->getvEnemyUfo()[j].x, _enemy->getvEnemyUfo()[j].y);//ufo�� ��ġ�� ��ź ������ ����
					}
					if (_rndItem == 1)//���ݷ� ��ȭ ������
					{
						_item->attackItemFire(_enemy->getvEnemyUfo()[j].x, _enemy->getvEnemyUfo()[j].y);//ufo�� ��ġ�� ���ݷ� ��ȭ ������ ����
					}
				}
				_enemy->removeEnemyUfo(j);//ufo�� ����
				break;
			}
		}
	}

	for (int i = 0; i < _playerBullet3->getvPlayerBullet3().size(); i++)//�÷��̾� �Ѿ� 3�ܰ�
	{
		for (int j = 0; j < _enemy->getvEnemyUfo().size(); j++)//ufo��
		{
			if (IntersectRect(&temp, &_enemy->getvEnemyUfo()[j].rc, &_playerBullet3->getvPlayerBullet3()[i].rc))//ufo���̶� �÷��̾� �Ѿ� 3�ܰ�� �浹��
			{
				EFFECTMANAGER->play("explosion", _enemy->getvEnemyUfo()[j].x, _enemy->getvEnemyUfo()[j].y);//ufo�� ��ġ�� ���� ����Ʈ �߻�
				_playerBullet3->removePlayerBullet3(i);//�÷��̾� �Ѿ� 3�ܰ� ���Ϳ��� ����

				if (_item->itemCountFire())//�������� ���� Ȯ���� ���̸�
				{
					if (_rndItem == 0)//��ź ������
					{
						_item->bombItemFire(_enemy->getvEnemyUfo()[j].x, _enemy->getvEnemyUfo()[j].y);//ufo�� ��ġ�� ��ź ������ ����
					}
					if (_rndItem == 1)//���ݷ� ��ȭ ������
					{
						_item->attackItemFire(_enemy->getvEnemyUfo()[j].x, _enemy->getvEnemyUfo()[j].y);//ufo�� ��ġ�� ���ݷ� ��ȭ ������ ����
					}
				}

				_enemy->removeEnemyUfo(j);//ufo�� ���Ϳ��� ����
				break;
			}
		}
	}
	
	for (int i = 0; i < _enemy->getvEnemyUfo().size(); i++)//���ʿ��� ������ ufo��
	{
		if (IntersectRect(&temp, &_bombExplosionRc, &_enemy->getvEnemyUfo()[i].rc) && _bombExplosion)//��ź���� ��Ʈ�� ufo���� �浹��
		{
			if (_item->itemCountFire())//�������� ���� Ȯ���� ���̸�
			{
				if (_rndItem == 0)//��ź ������
				{
					_item->bombItemFire(_enemy->getvEnemyUfo()[i].x, _enemy->getvEnemyUfo()[i].y);//ufo�� ��ġ�� ��ź ������ ����
				}
				if (_rndItem == 1)//���ݷ� ��ȭ ������
				{
					_item->attackItemFire(_enemy->getvEnemyUfo()[i].x, _enemy->getvEnemyUfo()[i].y);//ufo�� ��ġ�� ���ݷ� ��ȭ ������ ����
				}
			}
			_enemy->removeEnemyUfo(i);//ufo����
			break;
		}
	}
	//�÷��̾�� ���ʿ��� ���� ufo�浹 ����!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	
	//�÷��̾�� �����ʿ��� ���� ufo�浹 ������!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	for (int i = 0; i < _enemyBullet3->getvEnemyBullet3().size(); i++)//�����ʿ��� ���� ufo��
	{
		if (!_playerBomb)//�÷��̾ �⺻�����϶�
		{
			if (IntersectRect(&temp, &_player->getPlayerRC(), &_enemyBullet3->getvEnemyBullet3()[i].rc))//�÷��̾ ufo�� �Ѿ��� �浹��
			{
				EFFECTMANAGER->play("playerHit", (_player->getPlayerRC().right + _player->getPlayerRC().left) / 2, (_player->getPlayerRC().bottom + _player->getPlayerRC().top) / 2);//�÷��̾� ��ǥ�� ����Ʈ �߻�
				_player->setCurrentHP(5);//�÷��̾� ������ ���̱�
				_enemyBullet3->removeEnemyBullet3(i);//ufo�� �Ѿ�����
				if (_player->getCurrentHP() < 0)//�÷��̾� �������� 0�̸��� �Ǹ�
				{
					_death = true;//�÷��̾ �׾���
				}
				break;
			}
		}
	}

	for (int i = 0; i < _enemy->getvEnemyUfo2().size(); i++)//�����ʿ��� ���� ufo��
	{
		for (int j = 0; j < _playerBullet->getvPlayerBullet().size(); j++)//�÷��̾� �Ѿ�
		{
			if (IntersectRect(&temp, &_enemy->getvEnemyUfo2()[i].rc, &_playerBullet->getvPlayerBullet()[j].rc))//�÷��̾� �Ѿ��� ufo���̶� �浹��
			{
				EFFECTMANAGER->play("explosion", _enemy->getvEnemyUfo2()[i].x, _enemy->getvEnemyUfo2()[i].y);//ufo���� �÷��̾��� �Ѿ��̶� �ε�������� ���� ����Ʈ �׸���
				_playerBullet->removePlayerBullet(j);//�÷��̾� �Ѿ�����
				if (_item->itemCountFire())//�������� ����Ȯ���� Ʈ���
				{
					if (_rndItem == 0)//0�̸� ��ź
					{
						_item->bombItemFire(_enemy->getvEnemyUfo2()[i].x, _enemy->getvEnemyUfo2()[i].y);//ufo�� ��ġ�� ��ź ������ �����
					}
					else//�ƴϸ� ���ݷ� ��ȭ������
					{
						_item->attackItemFire(_enemy->getvEnemyUfo2()[i].x, _enemy->getvEnemyUfo2()[i].y);//ufo�� ��ġ�� ���ݷ� ��ȭ ������ �����
					}
				}
				_enemy->removeEnemyUfo2(i);//ufo�� ����
				break;
			}
		}
	}

	for (int i = 0; i < _playerBullet2->getvPlayerBullet2().size(); i++)//�÷��̾� �Ѿ� 2�ܰ�
	{
		for (int j = 0; j < _enemy->getvEnemyUfo2().size(); j++)//ufo��
		{
			if (IntersectRect(&temp, &_enemy->getvEnemyUfo2()[j].rc, &_playerBullet2->getvPlayerBullet2()[i].rc))//ufo���̶� �÷��̾� �Ѿ� 2�ܰ�� �浹��
			{
				EFFECTMANAGER->play("explosion", _enemy->getvEnemyUfo2()[j].x, _enemy->getvEnemyUfo2()[j].y);//ufo�� ��ġ�� ���� ����Ʈ �߻�
				_playerBullet2->removePlayerBullet2(i);//�÷��̾� �Ѿ� 2�ܰ� ����
				if (_item->itemCountFire())//�������� ����Ȯ���� ���̸�
				{
					if (_rndItem == 0)//��ź ������
					{
						_item->bombItemFire(_enemy->getvEnemyUfo2()[j].x, _enemy->getvEnemyUfo2()[j].y);//ufo�� ��ġ�� ��ź ������ ����
					}
					if (_rndItem == 1)//���ݷ� ��ȭ ������
					{
						_item->attackItemFire(_enemy->getvEnemyUfo2()[j].x, _enemy->getvEnemyUfo2()[j].y);//ufo�� ��ġ�� ���ݷ� ��ȭ ������ ����
					}
				}
				_enemy->removeEnemyUfo2(j);//ufo�� ����
				break;
			}
		}
	}

	for (int i = 0; i < _playerBullet3->getvPlayerBullet3().size(); i++)//�÷��̾� �Ѿ� 3�ܰ�
	{
		for (int j = 0; j < _enemy->getvEnemyUfo2().size(); j++)//ufo��
		{
			if (IntersectRect(&temp, &_enemy->getvEnemyUfo2()[j].rc, &_playerBullet3->getvPlayerBullet3()[i].rc))//ufo���̶� �÷��̾� �Ѿ� 3�ܰ�� �浹��
			{
				EFFECTMANAGER->play("explosion", _enemy->getvEnemyUfo2()[j].x, _enemy->getvEnemyUfo2()[j].y);//ufo�� ��ġ�� ���� ����Ʈ �߻�
				_playerBullet3->removePlayerBullet3(i);//�÷��̾� �Ѿ� 3�ܰ� ���Ϳ��� ����

				if (_item->itemCountFire())//�������� ���� Ȯ���� ���̸�
				{
					if (_rndItem == 0)//��ź ������
					{
						_item->bombItemFire(_enemy->getvEnemyUfo2()[j].x, _enemy->getvEnemyUfo2()[j].y);//ufo�� ��ġ�� ��ź ������ ����
					}
					if (_rndItem == 1)//���ݷ� ��ȭ ������
					{
						_item->attackItemFire(_enemy->getvEnemyUfo2()[j].x, _enemy->getvEnemyUfo2()[j].y);//ufo�� ��ġ�� ���ݷ� ��ȭ ������ ����
					}
				}

				_enemy->removeEnemyUfo2(j);//ufo�� ���Ϳ��� ����
				break;
			}
		}
	}

	for (int i = 0; i < _enemy->getvEnemyUfo2().size(); i++)//�����ʿ��� ���� ufo��
	{
		if (IntersectRect(&temp, &_bombExplosionRc, &_enemy->getvEnemyUfo2()[i].rc) && _bombExplosion)//��ź���� ��Ʈ�� ufo���� �浹��
		{
			if (_item->itemCountFire())//�������� ����Ȯ���� Ʈ���
			{
				if (_rndItem == 0)//0�̸� ��ź
				{
					_item->bombItemFire(_enemy->getvEnemyUfo2()[i].x, _enemy->getvEnemyUfo2()[i].y);//ufo�� ��ġ�� ��ź ������ �����
				}
				else//�ƴϸ� ���ݷ� ��ȭ������
				{
					_item->attackItemFire(_enemy->getvEnemyUfo2()[i].x, _enemy->getvEnemyUfo2()[i].y);//ufo�� ��ġ�� ���ݷ� ��ȭ ������ �����
				}
			}
			_enemy->removeEnemyUfo2(i);//ufo����
			break;
		}
	}
	//�÷��̾�� �����ʿ��� ���� ufo�浹 ����!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	//�÷��̾�� �︮������ �浹 ������!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	for (int i = 0; i < _playerBullet->getvPlayerBullet().size(); i++)//�÷��̾� �Ѿ�
	{
		for (int j = 0; j < _enemy->getvEnemyHelicopter().size(); j++)//�︮������
		{
			if (IntersectRect(&temp, &_enemy->getvEnemyHelicopter()[j].rc, &_playerBullet->getvPlayerBullet()[i].rc))//�︮�������� �÷��̾��Ѿ��� �浹��
			{
				EFFECTMANAGER->play("explosion", _enemy->getvEnemyHelicopter()[j].x, _enemy->getvEnemyHelicopter()[j].y);//�︮������ ��ġ�� ���� ����Ʈ �߻�
				_playerBullet->removePlayerBullet(i);//�÷��̾� �Ѿ˺��� ����

				if (_item->itemCountFire())//�������� ����Ȯ���� ���̸�
				{
					if (_rndItem == 0)//��ź������
					{
						_item->bombItemFire(_enemy->getvEnemyHelicopter()[j].x, _enemy->getvEnemyHelicopter()[j].y);//��ź������ ����
					}
					if (_rndItem == 1)//���ݷ� ��ȭ ������
					{
						_item->attackItemFire(_enemy->getvEnemyHelicopter()[j].x, _enemy->getvEnemyHelicopter()[j].y);//���ݷ� ��ȭ ������ ����
					}
				}
				_enemy->removeEnemyHelicopter(j);//�︮����������
				break;
			}
		}
	}
	
	for (int i = 0; i < _playerBullet2->getvPlayerBullet2().size(); i++)//�÷��̾� �Ѿ� 2�ܰ�
	{
		for (int j = 0; j < _enemy->getvEnemyHelicopter().size(); j++)//�︮������
		{
			if (IntersectRect(&temp, &_enemy->getvEnemyHelicopter()[j].rc, &_playerBullet2->getvPlayerBullet2()[i].rc))//�︮�������� �÷��̾��Ѿ��� �浹��
			{
				EFFECTMANAGER->play("explosion", _enemy->getvEnemyHelicopter()[j].x, _enemy->getvEnemyHelicopter()[j].y);//�︮�������� ��ġ�� ���� ����Ʈ �߻�
				_playerBullet2->removePlayerBullet2(i);//�÷��̾� �Ѿ˺��� ����

				if (_item->itemCountFire())//�������� ����Ȯ���� ���̸�
				{
					if (_rndItem == 0)//��ź������
					{
						_item->bombItemFire(_enemy->getvEnemyHelicopter()[j].x, _enemy->getvEnemyHelicopter()[j].y);//��ź������ ����
					}
					if (_rndItem == 1)//���ݷ� ��ȭ ������
					{
						_item->attackItemFire(_enemy->getvEnemyHelicopter()[j].x, _enemy->getvEnemyHelicopter()[j].y);//���ݷ� ��ȭ ������ ����
					}
				}
				_enemy->removeEnemyHelicopter(j);//�︮����������
				break;
			}
		}
	}

	for (int i = 0; i < _playerBullet3->getvPlayerBullet3().size(); i++)//�÷��̾� �Ѿ� 3�ܰ�
	{
		for (int j = 0; j < _enemy->getvEnemyHelicopter().size(); j++)//�︮������
		{
			if (IntersectRect(&temp, &_enemy->getvEnemyHelicopter()[j].rc, &_playerBullet3->getvPlayerBullet3()[i].rc))//�︮�������� �÷��̾��Ѿ��� �浹��
			{
				EFFECTMANAGER->play("explosion", _enemy->getvEnemyHelicopter()[j].x, _enemy->getvEnemyHelicopter()[j].y);//�︮������ ��ġ�� ���� ����Ʈ �߻�
				_playerBullet3->removePlayerBullet3(i);//�÷��̾� �Ѿ˺��� ����

				if (_item->itemCountFire())//�������� ����Ȯ���� ���̸�
				{
					if (_rndItem == 0)//��ź������
					{
						_item->bombItemFire(_enemy->getvEnemyHelicopter()[j].x, _enemy->getvEnemyHelicopter()[j].y);//��ź������ ����
					}
					if (_rndItem == 1)//���ݷ� ��ȭ ������
					{
						_item->attackItemFire(_enemy->getvEnemyHelicopter()[j].x, _enemy->getvEnemyHelicopter()[j].y);//���ݷ� ��ȭ ������ ����
					}
				}
				_enemy->removeEnemyHelicopter(j);//�︮����������
				break;
			}
		}
	}

	for (int i = 0; i < _enemyBullet3->getvEnemyBullet3().size(); i++)//�︮������ �Ѿ�
	{
		if (!_playerBomb)//�÷��̾ ��ź�߻縦 �ϰ����� �������
		{
			if (IntersectRect(&temp, &_player->getPlayerRC(), &_enemyBullet3->getvEnemyBullet3()[i].rc))//�÷��̾ �︮������ �Ѿ��� �浹��
			{
				EFFECTMANAGER->play("playerHit", (_player->getPlayerRC().right + _player->getPlayerRC().left) / 2, (_player->getPlayerRC().bottom + _player->getPlayerRC().top) / 2);//�÷��̾� ��ġ�� ����Ʈ �߻�

				_player->setCurrentHP(5);//�÷��̾� ������ �ֱ�

				if (_player->getCurrentHP() < 0)//�÷��̾� ü���� 0�̸��� �Ǹ�
				{
					_death = true;//�÷��̾ �׾���
				}
				_enemyBullet3->removeEnemyBullet3(i);//�︮������ �Ѿ˻���
				break;
			}
		}
	}

	for (int i = 0; i < _enemy->getvEnemyHelicopter().size(); i++)//�︮������
	{
		if (IntersectRect(&temp, &_bombExplosionRc, &_enemy->getvEnemyHelicopter()[i].rc) && _bombExplosion)//��ź���� ��Ʈ�� �翷���� �︮�������� �浹��
		{
			if (_item->itemCountFire())//�������� ����Ȯ���� ���̸�
			{
				if (_rndItem == 0)//��ź������
				{
					_item->bombItemFire(_enemy->getvEnemyHelicopter()[i].x, _enemy->getvEnemyHelicopter()[i].y);//��ź������ ����
				}
				if (_rndItem == 1)//���ݷ� ��ȭ ������
				{
					_item->attackItemFire(_enemy->getvEnemyHelicopter()[i].x, _enemy->getvEnemyHelicopter()[i].y);//���ݷ� ��ȭ ������ ����
				}
			}
			_enemy->removeEnemyHelicopter(i);//�︮����������
			break;
		}
	}
	//�÷��̾�� �︮������ �浹 ����!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	//2������ �÷��̾�� �︮������ �浹 ������!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	for (int i = 0; i < _playerBullet->getvPlayerBullet().size(); i++)//�÷��̾� �Ѿ�
	{
		for (int j = 0; j < _enemy->getvEnemyHelicopter2().size(); j++)//�︮������
		{
			if (IntersectRect(&temp, &_enemy->getvEnemyHelicopter2()[j].rc, &_playerBullet->getvPlayerBullet()[i].rc))//�︮�������� �÷��̾��Ѿ��� �浹��
			{
				EFFECTMANAGER->play("explosion", _enemy->getvEnemyHelicopter2()[j].x, _enemy->getvEnemyHelicopter2()[j].y);//�︮������ ��ġ�� ���� ����Ʈ �߻�
				_playerBullet->removePlayerBullet(i);//�÷��̾� �Ѿ˺��� ����

				if (_item->itemCountFire())//�������� ����Ȯ���� ���̸�
				{
					if (_rndItem == 0)//��ź������
					{
						_item->bombItemFire(_enemy->getvEnemyHelicopter2()[j].x, _enemy->getvEnemyHelicopter2()[j].y);//��ź������ ����
					}
					if (_rndItem == 1)//���ݷ� ��ȭ ������
					{
						_item->attackItemFire(_enemy->getvEnemyHelicopter2()[j].x, _enemy->getvEnemyHelicopter2()[j].y);//���ݷ� ��ȭ ������ ����
					}
				}
				_enemy->removeEnemyHelicopter2(j);//�︮����������
				break;
			}
		}
	}

	for (int i = 0; i < _playerBullet2->getvPlayerBullet2().size(); i++)//�÷��̾� �Ѿ� 2�ܰ�
	{
		for (int j = 0; j < _enemy->getvEnemyHelicopter2().size(); j++)//�︮������
		{
			if (IntersectRect(&temp, &_enemy->getvEnemyHelicopter2()[j].rc, &_playerBullet2->getvPlayerBullet2()[i].rc))//�︮�������� �÷��̾��Ѿ��� �浹��
			{
				EFFECTMANAGER->play("explosion", _enemy->getvEnemyHelicopter2()[j].x, _enemy->getvEnemyHelicopter2()[j].y);//�︮�������� ��ġ�� ���� ����Ʈ �߻�
				_playerBullet2->removePlayerBullet2(i);//�÷��̾� �Ѿ˺��� ����

				if (_item->itemCountFire())//�������� ����Ȯ���� ���̸�
				{
					if (_rndItem == 0)//��ź������
					{
						_item->bombItemFire(_enemy->getvEnemyHelicopter2()[j].x, _enemy->getvEnemyHelicopter2()[j].y);//��ź������ ����
					}
					if (_rndItem == 1)//���ݷ� ��ȭ ������
					{
						_item->attackItemFire(_enemy->getvEnemyHelicopter2()[j].x, _enemy->getvEnemyHelicopter2()[j].y);//���ݷ� ��ȭ ������ ����
					}
				}
				_enemy->removeEnemyHelicopter2(j);//�︮����������
				break;
			}
		}
	}

	for (int i = 0; i < _playerBullet3->getvPlayerBullet3().size(); i++)//�÷��̾� �Ѿ� 3�ܰ�
	{
		for (int j = 0; j < _enemy->getvEnemyHelicopter2().size(); j++)//�︮������
		{
			if (IntersectRect(&temp, &_enemy->getvEnemyHelicopter2()[j].rc, &_playerBullet3->getvPlayerBullet3()[i].rc))//�︮�������� �÷��̾��Ѿ��� �浹��
			{
				EFFECTMANAGER->play("explosion", _enemy->getvEnemyHelicopter2()[j].x, _enemy->getvEnemyHelicopter2()[j].y);//�︮������ ��ġ�� ���� ����Ʈ �߻�
				_playerBullet3->removePlayerBullet3(i);//�÷��̾� �Ѿ˺��� ����

				if (_item->itemCountFire())//�������� ����Ȯ���� ���̸�
				{
					if (_rndItem == 0)//��ź������
					{
						_item->bombItemFire(_enemy->getvEnemyHelicopter2()[j].x, _enemy->getvEnemyHelicopter2()[j].y);//��ź������ ����
					}
					if (_rndItem == 1)//���ݷ� ��ȭ ������
					{
						_item->attackItemFire(_enemy->getvEnemyHelicopter2()[j].x, _enemy->getvEnemyHelicopter2()[j].y);//���ݷ� ��ȭ ������ ����
					}
				}
				_enemy->removeEnemyHelicopter2(j);//�︮����������
				break;
			}
		}
	}

	for (int i = 0; i < _enemy->getvEnemyHelicopter2().size(); i++)//�︮������
	{
		if (IntersectRect(&temp, &_bombExplosionRc, &_enemy->getvEnemyHelicopter2()[i].rc) && _bombExplosion)//��ź���� ��Ʈ�� �翷���� �︮�������� �浹��
		{
			if (_item->itemCountFire())//�������� ����Ȯ���� ���̸�
			{
				if (_rndItem == 0)//��ź������
				{
					_item->bombItemFire(_enemy->getvEnemyHelicopter2()[i].x, _enemy->getvEnemyHelicopter2()[i].y);//��ź������ ����
				}
				if (_rndItem == 1)//���ݷ� ��ȭ ������
				{
					_item->attackItemFire(_enemy->getvEnemyHelicopter2()[i].x, _enemy->getvEnemyHelicopter2()[i].y);//���ݷ� ��ȭ ������ ����
				}
			}
			_enemy->removeEnemyHelicopter2(i);//�︮����������
			break;
		}
	}
	//2������ �÷��̾�� �︮������ �浹 ����!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	//�÷��̾�� �غ����浹 ������!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	for (int i = 0; i < _enemyJuneBullet->getvEnemyJuneBullet().size(); i++)//�غ��� �Ѿ�
	{
		if (!_playerBomb)//�÷��̾ �⺻�����϶�
		{
			if (IntersectRect(&temp, &_player->getPlayerRC(), &_enemyJuneBullet->getvEnemyJuneBullet()[i].rc))//�÷��̾ �غ��� �Ѿ��� �浹��
			{
				_player->setCurrentHP(5);//�÷��̾� ������ ���̱�

				_enemyJuneBullet->removeEnemyJuneBullet(i);//�غ��� �Ѿ� ����

				EFFECTMANAGER->play("playerHit", _player->getPlayerX(), _player->getPlayerY());//�÷��̾� ��ġ�� ���� ����Ʈ�߻�

				if (_player->getCurrentHP() < 0)//�÷��̾� ���� HP�� 0�̸��� �Ǹ�
				{
					_death = true;//�÷��̾ �׾���
				}
				break;
			}
		}
	}

	for (int i = 0; i < _playerBullet->getvPlayerBullet().size(); i++)//�÷��̾� �Ѿ�
	{
		for (int j = 0; j < _enemyJuneBoss->getvJuneBoss().size(); j++)//�غ�����
		{
			if (_juneBossAttack)
			{
				if (IntersectRect(&temp, &_enemyJuneBoss->getvJuneBoss()[j].rc, &_playerBullet->getvPlayerBullet()[i].rc))//�غ������� �÷��̾��Ѿ��� �浹��
				{
					_enemyJuneBoss->setHP(5);//�غ��� ü�� ���̱�

					if (_enemyJuneBoss->getHP() < 0)//�غ��� ü���� 0�̸��� �Ǹ�
					{
						EFFECTMANAGER->play("bossExplosion", _enemyJuneBoss->getJuneBossX() + 80, _enemyJuneBoss->getJuneBossY() + 50);//�غ����� ��ġ�� ���� ����Ʈ �߻�
						
						_item->hpItemFire(_enemyJuneBoss->getJuneBossX() + 80, _enemyJuneBoss->getJuneBossY() + 50);//hp������ ����

						_enemyJuneBoss->removeJuneBoss(j);//�غ�����
					}
					_playerBullet->removePlayerBullet(i);//�÷��̾� �Ѿ˺��� ����
					break;
				}
			}
		}
	}

	for (int i = 0; i < _playerBullet2->getvPlayerBullet2().size(); i++)//�÷��̾� �Ѿ� 2�ܰ�
	{
		for (int j = 0; j < _enemyJuneBoss->getvJuneBoss().size(); j++)//�غ�����
		{
			if (_juneBossAttack)
			{
				if (IntersectRect(&temp, &_enemyJuneBoss->getvJuneBoss()[j].rc, &_playerBullet2->getvPlayerBullet2()[i].rc))//�غ������� �÷��̾��Ѿ��� �浹��
				{
					_enemyJuneBoss->setHP(5);//�غ��� ü�� ���̱�
					if (_enemyJuneBoss->getHP() < 0)//�غ��� ü���� 0�̸��� �Ǹ�
					{
						EFFECTMANAGER->play("bossExplosion", _enemyJuneBoss->getJuneBossX() + 80, _enemyJuneBoss->getJuneBossY() + 50);//�غ����� ��ġ�� ���� ����Ʈ �߻�

						_item->hpItemFire(_enemyJuneBoss->getJuneBossX() + 80, _enemyJuneBoss->getJuneBossY() + 50);//hp������ ����
						_enemyJuneBoss->removeJuneBoss(j);//�غ���������
					}
					_playerBullet2->removePlayerBullet2(i);//�÷��̾� �Ѿ˺��� ����
					break;
				}
			}
		}
	}

	for (int i = 0; i < _playerBullet3->getvPlayerBullet3().size(); i++)//�÷��̾� �Ѿ� 3�ܰ�
	{
		for (int j = 0; j < _enemyJuneBoss->getvJuneBoss().size(); j++)//�غ�����
		{
			if (_juneBossAttack)
			{
				if (IntersectRect(&temp, &_enemyJuneBoss->getvJuneBoss()[j].rc, &_playerBullet3->getvPlayerBullet3()[i].rc))//�غ������� �÷��̾��Ѿ��� �浹��
				{
					_enemyJuneBoss->setHP(5);//�غ��� ü�� ���̱�
					if (_enemyJuneBoss->getHP() < 0)//�غ��� ü���� 0�̸��� �Ǹ�
					{
						EFFECTMANAGER->play("bossExplosion", _enemyJuneBoss->getJuneBossX() + 80, _enemyJuneBoss->getJuneBossY() + 50);//�غ����� ��ġ�� ���� ����Ʈ �߻�
						
						_item->hpItemFire(_enemyJuneBoss->getJuneBossX() + 80, _enemyJuneBoss->getJuneBossY() + 50);//hp������ ����
						_enemyJuneBoss->removeJuneBoss(j);//�غ���������
					}
					_playerBullet3->removePlayerBullet3(i);//�÷��̾� �Ѿ˺��� ����
					break;
				}
			}
		}
	}

	for (int i = 0; i < _enemyJuneBoss->getvJuneBoss().size(); i++)//�غ�����
	{
		if (_juneBossAttack)
		{
			if (IntersectRect(&temp, &_enemyJuneBoss->getvJuneBoss()[i].rc, &_bombExplosionRc))//�غ����� ��ź�����̶� �浹��
			{
				if (_bombExplosionImage->getFrameX() <= 0)//��ź���� �������� 0�������϶��� �������� �ֱ����� ����
				{
					_enemyJuneBoss->setHP(5);//�غ��� ü�� ���̱�
				}

				//cout << _enemyJuneBoss->getHP() << endl;

				if (_enemyJuneBoss->getHP() < 0)//�غ��� ü���� 0�̸��� �Ǹ�
				{
					EFFECTMANAGER->play("bossExplosion", _enemyJuneBoss->getJuneBossX() + 80, _enemyJuneBoss->getJuneBossY() + 50);//�غ�����ǥ�� ���� ����Ʈ �߻�
					_item->hpItemFire(_enemyJuneBoss->getJuneBossX() + 80, _enemyJuneBoss->getJuneBossY() + 50);//hp������ ����
					_enemyJuneBoss->removeJuneBoss(i);//�غ���������
				}
				break;
			}
		}
	}
	//�÷��̾�� �غ����浹 ����!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	//�÷��̾�� �����浹 ������!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	for (int i = 0; i < _enemyBossBullet->getvEnemyBossBullet().size(); i++)//���� �Ѿ�
	{
		if (!_playerBomb)//�÷��̾ �⺻�����϶�
		{
			if (IntersectRect(&temp, &_player->getPlayerRC(), &_enemyBossBullet->getvEnemyBossBullet()[i].rc))//�÷��̾ ���� �Ѿ��� �浹��
			{
				_player->setCurrentHP(5);//�÷��̾� ������ ���̱�

				_enemyBossBullet->removeEnemyBossBullet(i);//���� �Ѿ� ����

				EFFECTMANAGER->play("playerHit", _player->getPlayerX(), _player->getPlayerY());//�÷��̾� ��ġ�� ���� ����Ʈ�߻�

				if (_player->getCurrentHP() < 0)//�÷��̾� ���� HP�� 0�̸��� �Ǹ�
				{
					_death = true;//�÷��̾ �׾���
				}
				break;
			}
		}
	}

	for (int i = 0; i < _enemyBossBullet2->getvEnemyBossBullet2().size(); i++)//���� �Ѿ� 2������
	{
		if (!_playerBomb)//�÷��̾ �⺻�����϶�
		{
			if (IntersectRect(&temp, &_player->getPlayerRC(), &_enemyBossBullet2->getvEnemyBossBullet2()[i].rc))//�÷��̾ ���� �Ѿ��� �浹��
			{
				_player->setCurrentHP(5);//�÷��̾� ������ ���̱�

				_enemyBossBullet2->removeEnemyBossBullet2(i);//���� �Ѿ� ����

				EFFECTMANAGER->play("playerHit", _player->getPlayerX(), _player->getPlayerY());//�÷��̾� ��ġ�� ���� ����Ʈ�߻�

				if (_player->getCurrentHP() < 0)//�÷��̾� ���� HP�� 0�̸��� �Ǹ�
				{
					_death = true;//�÷��̾ �׾���
				}
				break;
			}
		}
	}

	for (int i = 0; i < _playerBullet->getvPlayerBullet().size(); i++)//�÷��̾� �Ѿ�
	{
		for (int j = 0; j < _enemyBoss->getvEnemyBoss().size(); j++)//������
		{
			if (_bossAttack)
			{
				if (IntersectRect(&temp, &_enemyBoss->getvEnemyBoss()[j].rc, &_playerBullet->getvPlayerBullet()[i].rc))//�������� �÷��̾��Ѿ��� �浹��
				{
					_enemyBoss->setHP(5);//���� ü�� ���̱�

					if (_enemyBoss->getHP() < 0)//���� ü���� 0�̸��� �Ǹ�
					{
						EFFECTMANAGER->play("bossExplosion", (_enemyBoss->getvEnemyBoss()[j].rc.right + _enemyBoss->getvEnemyBoss()[j].rc.left) / 2, (_enemyBoss->getvEnemyBoss()[j].rc.top + _enemyBoss->getvEnemyBoss()[j].rc.bottom) / 2);//������ ��ġ�� ���� ����Ʈ �߻�

						_enemyBoss->removeBoss(j);//������
					}
					_playerBullet->removePlayerBullet(i);//�÷��̾� �Ѿ˺��� ����
					break;
				}
			}
		}
	}

	for (int i = 0; i < _playerBullet2->getvPlayerBullet2().size(); i++)//�÷��̾� �Ѿ� 2�ܰ�
	{
		for (int j = 0; j < _enemyBoss->getvEnemyBoss().size(); j++)//������
		{
			if (_bossAttack)
			{
				if (IntersectRect(&temp, &_enemyBoss->getvEnemyBoss()[j].rc, &_playerBullet2->getvPlayerBullet2()[i].rc))//�������� �÷��̾��Ѿ��� �浹��
				{
					_enemyBoss->setHP(5);//���� ü�� ���̱�

					if (_enemyBoss->getHP() < 0)//���� ü���� 0�̸��� �Ǹ�
					{
						EFFECTMANAGER->play("bossExplosion", (_enemyBoss->getvEnemyBoss()[j].rc.right + _enemyBoss->getvEnemyBoss()[j].rc.left) / 2, (_enemyBoss->getvEnemyBoss()[j].rc.top + _enemyBoss->getvEnemyBoss()[j].rc.bottom) / 2);//������ ��ġ�� ���� ����Ʈ �߻�

						_enemyBoss->removeBoss(j);//������
					}
					_playerBullet2->removePlayerBullet2(i);//�÷��̾� �Ѿ˺��� ����
					break;
				}
			}
		}
	}

	for (int i = 0; i < _playerBullet3->getvPlayerBullet3().size(); i++)//�÷��̾� �Ѿ� 3�ܰ�
	{
		for (int j = 0; j < _enemyBoss->getvEnemyBoss().size(); j++)//������
		{
			if (_bossAttack)
			{
				if (IntersectRect(&temp, &_enemyBoss->getvEnemyBoss()[j].rc, &_playerBullet3->getvPlayerBullet3()[i].rc))//�������� �÷��̾��Ѿ��� �浹��
				{
					_enemyBoss->setHP(5);//���� ü�� ���̱�

					if (_enemyBoss->getHP() < 0)//���� ü���� 0�̸��� �Ǹ�
					{
						EFFECTMANAGER->play("bossExplosion", (_enemyBoss->getvEnemyBoss()[j].rc.right + _enemyBoss->getvEnemyBoss()[j].rc.left) / 2, (_enemyBoss->getvEnemyBoss()[j].rc.top + _enemyBoss->getvEnemyBoss()[j].rc.bottom) / 2);//������ ��ġ�� ���� ����Ʈ �߻�

						_enemyBoss->removeBoss(j);//������
					}
					_playerBullet3->removePlayerBullet3(i);//�÷��̾� �Ѿ˺��� ����
					break;
				}
			}
		}
	}

	for (int i = 0; i < _enemyBoss->getvEnemyBoss().size(); i++)//������
	{
		if (_bossAttack)
		{
			if (IntersectRect(&temp, &_enemyBoss->getvEnemyBoss()[i].rc, &_bombExplosionRc))//������ ��ź�����̶� �浹��
			{
				if (_bombExplosionImage->getFrameX() <= 0)//��ź���� �������� 0�������϶��� �������� �ֱ����� ����
				{
					_enemyBoss->setHP(5);//���� ü�� ���̱�
				}

				if (_enemyBoss->getHP() < 0)//���� ü���� 0�̸��� �Ǹ�
				{
					EFFECTMANAGER->play("bossExplosion", (_enemyBoss->getvEnemyBoss()[i].rc.right + _enemyBoss->getvEnemyBoss()[i].rc.left) / 2, (_enemyBoss->getvEnemyBoss()[i].rc.top + _enemyBoss->getvEnemyBoss()[i].rc.bottom) / 2);//������ǥ�� ���� ����Ʈ �߻�
					
					_enemyBoss->removeBoss(i);//����������
				}
				break;
			}
		}
	}
	//�÷��̾�� �����浹 ����!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	
	//�������̶� �÷��̾� �浹 ������!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	for (int i = 0; i < _item->getvBombItem().size(); i++)//��ź������
	{
		if (_item->getBobmCount() < 3)//���� ������ ������ 3�� �̸��� ��쿡�� �÷��̾�� �������̶� �浹����
		{
			if (IntersectRect(&temp, &_player->getPlayerRC(), &_item->getvBombItem()[i].rc))//�÷��̾�� �������̶� �浹�ϸ�
			{
				_item->setBobmCountPlus(1);//��ź���� �ø���
				_bomb->setBombMax(_item->getBobmCount());//��ź���� �ø���
				_item->removeBombItem(i);//��ź ������ ����
				break;
			}
		}
	}

	for (int i = 0; i < _item->getvAttackItem().size(); i++)//���ݷ°�ȭ ������
	{
		if (_item->getAttackCount() < 3)//���� ���ݷ� ��ȭ �ܰ谡 3�� �̸��� ��쿡�� �÷��̾�� �������̶� �浹����
		{
			if (IntersectRect(&temp, &_player->getPlayerRC(), &_item->getvAttackItem()[i].rc))//�÷��̾�� ���ݷ°�ȭ �������̶� �浹�ϸ�
			{
				if (_item->getAttackCount() < 3)//���ݷ� ��ȭ �ܰ� 3�ܰ� ������ �ø� �� �ִ� ���ǹ�
				{
					_item->setAttackCount(1);//���ݷ� ��ȭ �ܰ� �ø���
				}
				_item->removeAttackItem(i);//���ݷ� ������ ����
				break;
			}
		}
	}

	for (int i = 0; i < _item->getvHpItem().size(); i++)//hp ������
	{
		if (IntersectRect(&temp, &_player->getPlayerRC(), &_item->getvHpItem()[i].rc))//�÷��̾�� hp �������̶� �浹�ϸ�
		{
			_player->setCurrentPlusHP(100);//�÷��̾� hp�� �߽�ġ��

			_item->removeHpItem(i);//hp ������ ����
			break;
		}
	}
	//�������̶� �÷��̾� �浹 ����!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
}
