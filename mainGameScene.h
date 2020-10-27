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
#define COUNT 4//ȭ����� ��Ʈ�� �� �迭���ȣ

class mainGameScene : public gameNode
{
private:
	effect* _deathExplosions;//�÷��̾ ���� ������ ���� ����Ʈ
	effect* _playerHit;//���Ѿ˿� �÷��̾ ���ݴ��Ҷ� ����Ʈ
	effect* _bossExplosions;//������ �׾����� ���� ����Ʈ

	image* _background;//����̹���
	image* _gameOver;//���ӿ��� �̹���
	image* _blackScrren;//�׾����� ����ȭ�� ����� ���� �̹���
	image* _playerBombMove;//�÷��̾ ��ź�� �߻��Ҷ� �÷��̾��� ������ �̹��� ��¿�
	image* _bombExplosionImage;//��ź ���� ������
	image* _missionComplete;//����Ŭ����

	player* _player;//�÷��̾� ����Ҵ�
	enemy* _enemy;//�� ����Ҵ�
	enemyJuneBoss* _enemyJuneBoss;//�غ��� ����Ҵ�
	enemyBoss* _enemyBoss;//���� ����Ҵ�
	enemyBullet* _enemyBullet;//���Ѿ� ����Ҵ�
	enemyBullet2* _enemyBullet2;//ufo�� �Ѿ� ����Ҵ�
	enemyBullet3* _enemyBullet3;//�︮���� �� �Ѿ� ����Ҵ�
	enemyJuneBullet* _enemyJuneBullet;//�غ��� �Ѿ� ����Ҵ�
	enemyBossBullet* _enemyBossBullet;//���� �Ѿ� ����Ҵ�
	enemyBossBullet2* _enemyBossBullet2;//���� �Ѿ� 2������ ����Ҵ�
	playerBullet* _playerBullet;//�÷��̾� �Ѿ� ����Ҵ�
	playerBullet2* _playerBullet2;//�÷��̾� �Ѿ� 2�ܰ� ����Ҵ�
	playerBullet3* _playerBullet3;//�÷��̾� �Ѿ� 3�ܰ� ����Ҵ�
	progressBar* _progressBar;//���α׷����� ����Ҵ�
	item* _item;//������ ����Ҵ�
	bomb* _bomb;//��ź ����Ҵ�

	string _token;
	vector<string>			_vSoundList;
	vector<string>::iterator	_viSoundList;
	//����

	RECT _rc[COUNT];//�÷��̾ �ʹ����� ������ ���ϰ� �������� ��Ʈ

	RECT _bombExplosionRc;//��ź ���� ��Ʈ
	float _rotation;//�������ݰ���
	int _loopX, _loopY;//����̹��� ���ѷ���
	int _alpha;//����ȭ�� ������ ���� ���İ� 
	int _missionCompleteAlpha;//����Ŭ���� �̹����� ����� ���İ�
	int _missionCompleteAlphaCount;//����Ŭ���� �̹����� ����� ���İ��� ī��Ʈ��
	int _count;//������ ī��Ʈ
	int _bobmExplosionCount;//��ź ���� �����ӿ� ����� ī��Ʈ
	int _rndItem;//���ݷ°�ȭ ������, ��ź������ ���� �������� ���� ������ ���� ����
	int _juneBossBulletCount;//���� �Ѿ� �߻� ī��Ʈ
	int _bossBulletCount;//���� �Ѿ� �߻� ī��Ʈ
	int _bossBulletCount2;//���� �Ѿ� 2������ �߻� ī��Ʈ

	bool _death;//�÷��̾ ������
	bool _playerBomb;//�÷��̾ ��ź �߻��Ҷ� �÷��̾��� ������ �̹��� �۵����� Ȯ��
	bool _bombExplosion;//��ź������ Ʈ������ Ȯ��
	bool _juneBossAttack;//�غ��� ���ݽ���
	bool _juneBossAppear;//�غ��� ����
	bool _bossAttack;//�������ݽ���
	bool _bossAppear;//���� ����
	bool _oneSoundPlay;//���带 �ѹ��� �����Ű�� ���� ����� ����

public:
	mainGameScene();
	~mainGameScene();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void collision();//�浹ó���� ���� �Լ�
};

